#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

////Переменные
//bool isFirst = true;
//Node* head = nullptr;
//
////Элемент списка
//struct Node
//{
//	int year;
//	std::string artist;
//	std::string picture;
//	Node* next;
//
//	Node(int year, std::string artist, std::string picture, Node* next)
//	{
//
//	}
//};
//
////Ввод элементов FIFO
//Node insertNodeFIFO() {
//	std::string input;
//	int year;
//	std::string artist, picture;
//	while (true)
//	{
//		std::cout << "Введите год или 'Stop' для окончания ввода: ";
//		std::cin >> input;
//
//		if (input == "Stop") {
//			return;
//		}
//
//		std::istringstream(input) >> year;
//
//		std::cout << "Введите фамилию художника : ";
//		std::cin >> artist;
//		std::cout << "Введите название картины: ";
//		std::cin >> picture;
//		Node newNode = Node(year, artist, picture, &insertNodeFIFO());
//		if (isFirst)
//		{
//			head = &newNode;
//			isFirst = false;
//		}
//	}
//}
//
////Вывод FIFO
//void print(Node* node)
//{
//	if (node == nullptr)
//		return;
//	print(node -> next);
//	std::cout << "Год: " << node->year << "Художник: " << node->artist << "Название: " << node->picture << std::endl;
//}
//
//int main() {
//	insertNodeFIFO();
//	print(head);
//}