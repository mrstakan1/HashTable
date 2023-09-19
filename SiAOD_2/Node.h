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
			return "Пусто";
		}
		string tmp = "Студент: номер зачетной книжки - " + to_string(key) + ", номер группы - " + to_string(groupNumber) + ", ФИО - " + name;
		return tmp;
	}
};
#endif // !NODE_H