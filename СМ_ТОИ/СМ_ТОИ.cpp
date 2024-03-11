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
void print(Node* node)
{
    while (node != nullptr) {
        std::cout << "Год: " << node->year << std::endl;
        std::cout << "Художник: " << node->artist << std::endl;
        std::cout << "Название: " << node->picture << std::endl;
        node = node->next;
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

int main() {
    setlocale(LC_ALL, "Russian");
    int year;
    std::string picture;

    Node* head = CreateFIFO(nullptr);
    print(head);
    insertNode(head);
    print(head);
    std::cin >> year;
    head = Delete(year, head);
    print(head);
    std::cin >> picture;
    Delete(picture, head);
    print(head);
    std::cin >> year;
    Change(year, head);
    print(head);
    std::cin >> picture;
    Change(picture, head);
    print(head);

    // Освобождение памяти
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}