#ifndef NODE_H
#define NODE_H
using namespace std;

#include <iostream>
#include <string>

struct Node {
	string name;
	int groupNumber;
	int key;

	Node(string name, int group, int key) {
		this->name = name;
		this->groupNumber = group;
		this->key = key;
	}

	bool isEmpty() {
		return name == "N/A";
	}

	string toString() {
		if (name == "N/A") {
			return "�����";
		}
		string tmp = "�������: ����� �������� ������ - " + to_string(key) + ", ����� ������ - " + to_string(groupNumber) + ", ��� - " + name;
		return tmp;
	}
};
#endif // !NODE_H