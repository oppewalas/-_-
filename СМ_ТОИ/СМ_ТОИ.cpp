// СМ_ТОИ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

// Элемент списка
struct Node
{
    int year;
    std::string artist;
    std::string picture;
    Node* next;

    Node(int Year, std::string Artist, std::string Picture, Node* Next)
    {
        year = Year;
        artist = Artist;
        picture = Picture;
        next = Next;
    }
};

// Ввод элементов FIFO
Node* CreateFIFO(Node* next) {
    std::string input;
    int year;
    std::string artist, picture;

    std::cout << "Введите год или 'Stop' для окончания ввода: ";
    std::cin >> input;

    if (input == "Stop") {
        return nullptr;
    }

    std::istringstream(input) >> year;

    std::cout << "Введите фамилию художника : ";
    std::cin >> artist;
    std::cout << "Введите название картины: ";
    std::cin >> picture;

    Node* newNode = new Node(year, artist, picture, CreateFIFO(next));

    return newNode;
}

// Вывод FIFO
void printFIFO(Node* node)
{
    while (node != nullptr) {
        std::cout << "Год: " << node->year << std::endl;
        std::cout << "Художник: " << node->artist << std::endl;
        std::cout << "Название: " << node->picture << std::endl;
        node = node->next;
    }
}

void printLIFO(Node* node)
{
    if (node != nullptr)
    {
        printLIFO(node->next);
        std::cout << "Год: " << node->year << std::endl;
        std::cout << "Художник: " << node->artist << std::endl;
        std::cout << "Название: " << node->picture << std::endl;
    }
}

//Добавление элементов
void insertNode(Node* node)
{
    while (node->next != nullptr)
    {
        node = node->next;
    }
    node->next = CreateFIFO(node);
}

//Удаление элемента
Node* Delete(int year, Node* head)
{
    if (head->year == year)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* current = head;
    if (current->next == nullptr)
    {
        std::cout << "Такого элемента нет" << std::endl;
        return head;
    }
    while (current->next->year != year)
    {
        if (current->next->next == nullptr)
        {
            std::cout << "Такого элемента нет" << std::endl;
            return head;
        }
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

Node* Delete(std::string picture, Node* head)
{
    if (head->picture == picture)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* current = head;
    if (current->next == nullptr)
    {
        std::cout << "Такого элемента нет" << std::endl;
        return head;
    }
    while (current->next->picture != picture)
    {
        if (current->next->next == nullptr)
        {
            std::cout << "Такого элемента нет" << std::endl;
            return head;
        }
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

//Редактирование элементов
void Change(int year, Node* head)
{
    //Проход до нужного элемента
    Node* current = head;
    while (current->year != year)
    {
        if (current->next == nullptr)
        {
            std::cout << "Такого элемента в списке нет";
            return;
        }
        current = current->next;
    }

    //Замена элемента
    std::cout << "Введите фамилию год: ";
    std::cin >> current->year;
    std::cout << "Введите фамилию художника: ";
    std::cin >> current->artist;
    std::cout << "Введите название картины: ";
    std::cin >> current->picture;
}

void Change(std::string picture, Node* head)
{
    //Проход до нужного элемента
    Node* current = head;
    while (current->picture != picture)
    {
        if (current->next == nullptr)
        {
            std::cout << "Такого элемента в списке нет";
            return;
        }
        current = current->next;
    }

    //Замена элемента
    std::cout << "Введите фамилию год: ";
    std::cin >> current->year;
    std::cout << "Введите фамилию художника: ";
    std::cin >> current->artist;
    std::cout << "Введите название картины: ";
    std::cin >> current->picture;
}

//Сортировка по названию LIFO
void SortLIFO(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        // Базовый случай: если список пуст или содержит только один элемент, нет необходимости сортировать
        return;
    }

    Node* maxNode = head; // Находим узел с максимальным значением picture
    Node* prev = nullptr;
    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->picture > maxNode->picture) {
            maxNode = current->next;
            prev = current;
        }
        current = current->next;
    }

    if (maxNode != head) {
        // Перемещаем узел с максимальным значением picture в начало списка
        prev->next = maxNode->next;
        maxNode->next = head;
        head = maxNode;
    }

    // Рекурсивно сортируем оставшуюся часть списка
    SortLIFO(head->next);
}

//Сортировка по году FIFO
void SortFIFO(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        // Если список пуст или содержит только один элемент, сортировка не требуется
        return;
    }

    Node* current = head;
    Node* nextNode = nullptr;
    Node* temp = nullptr;
    bool swapped;

    do {
        swapped = false;
        current = head;
        while (current->next != nextNode) {
            if (current->year > current->next->year) {
                // Меняем местами узлы, не меняя ссылок
                temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (current == head) {
                    head = temp;
                }
                swapped = true;
            }
            current = current->next;
        }
        nextNode = current;
    } while (swapped);
}

//Бинарное дерево
// структура дерева
struct Root
{
    Root* left;
    Root* right;
    Node* elem;

    Root(Node* Elem)
    {
        left = nullptr;
        right = nullptr;
        elem = Elem;
    }
};

//Добавление элемента в бинарное дерево
Root* InsertBinaryTree(Node* node, Root* current)
{
    if (current == nullptr)
    {
        Root* newRoot = new Root(node);
        return newRoot;
    }

    if (node->year < current->elem->year)
    {
        current->left = InsertBinaryTree(node, current->left);
    }
    else if (node->year > current->elem->year)
    {
        current->right = InsertBinaryTree(node, current->right);
    }

    return current;
}

//Создание бинарного дерева
Root* CreateBinaryTree(Node* head)
{
    Root* root = nullptr;
    Root* prevRoot = nullptr;

    while (head != nullptr)
    {
        root = InsertBinaryTree(head, root);
        head = head->next;
    }

    return root;
}

//Бинарный поиск
void BinarySearch(int year, Root* root)
{
    if (root == nullptr || root->elem == nullptr)
    {
        std::cout << "Такого элемента нет";
        return;
    }
    if (year == root->elem->year)
    {
        std::cout << year << std::endl;
        std::cout << root->elem->artist << std::endl;
        std::cout << root->elem->picture << std::endl;
        return;
    }
    if (year < root->elem->year)
    {
        return BinarySearch(year, root->left);
    }
    else
    {
        return BinarySearch(year, root->right);
    }

}

int main() {
    setlocale(LC_ALL, "Russian");
    int year;
    std::string picture;
    Node* head = CreateFIFO(nullptr);
    printFIFO(head);
    SortLIFO(head);
    printFIFO(head);
    Root* root = CreateBinaryTree(head);
    BinarySearch(5, root);
    SortFIFO(head);
    printFIFO(head);
    insertNode(head);
    printFIFO(head);
    std::cin >> year;
    Delete(year, head);
    printFIFO(head);
    std::cin >> picture;
    Delete(picture, head);
    printFIFO(head);
    std::cin >> year;
    Change(year, head);
    printFIFO(head);
    std::cin >> picture;
    Change(picture, head);
    printFIFO(head);

    return 0;
}