#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

////����������
//bool isFirst = true;
//Node* head = nullptr;
//
////������� ������
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
////���� ��������� FIFO
//Node insertNodeFIFO() {
//	std::string input;
//	int year;
//	std::string artist, picture;
//	while (true)
//	{
//		std::cout << "������� ��� ��� 'Stop' ��� ��������� �����: ";
//		std::cin >> input;
//
//		if (input == "Stop") {
//			return;
//		}
//
//		std::istringstream(input) >> year;
//
//		std::cout << "������� ������� ��������� : ";
//		std::cin >> artist;
//		std::cout << "������� �������� �������: ";
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
////����� FIFO
//void print(Node* node)
//{
//	if (node == nullptr)
//		return;
//	print(node -> next);
//	std::cout << "���: " << node->year << "��������: " << node->artist << "��������: " << node->picture << std::endl;
//}
//
//int main() {
//	insertNodeFIFO();
//	print(head);
//}