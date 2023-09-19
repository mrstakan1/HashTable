#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include "Node.h"

class HashTable {
private:
	int size = 10;
	vector <Node> table;
	int hash(Node node) {
		return node.key % this->size;
	}
	int hash(int code) {
		return code % this->size;
	}
	bool exists(int code) {
		int index = hash(code);
		for (int i = index; i < size; i++) {
			if (table[i].key == code) {
				return true;
			}
		}
		return false;
	}
public:
	HashTable() {
		for (int i = 0; i < size; i++) {
			table.push_back(Node("N/A", 0, 0));
		}
	}

	Node find(int code) {
		int index = hash(code);
		for (int i = index; i < size; i++) {
			if (table[i].key == code) {
				return table[i];
			}
		}
		return Node("N/A", 0, 0);
	}
	void push(Node newNode) {
		int index = hash(newNode);
		int i;
		for (i = index; i < size && !table[i].isEmpty(); i++);
		if (!table[i].isEmpty()) return;
		table[i] = newNode;
	}
	void pop(int code) {
		if (!exists(code)) {
			cout << "Запись с таким ключом отсутствует!" << endl;
			return;
		}
		int index = hash(code);
		table[index].name = "N/A";
	}
	void output() {
		for (int i = 0; i < this->table.size(); i++) {
			cout << i + 1 << ") ";
			if (!table[i].isEmpty()) {
				cout << table[i].toString();
			}
			cout << endl;
		}
	}
	void fill() {
		for (int j = 1; j < 6; j++) {
			int index = hash(j);
			int i;
			for (i = index; i < size && !table[i].isEmpty(); i++);
			if (!table[i].isEmpty()) return;
			table[i] = Node("Имя" + to_string(j), 100000 + j, 200000 - j);
		}
	}
	void rehash() {
		vector <Node> newTable;
		table.push_back(Node("N/A", 0, 0));
		this->size++;
		for (int i = 0; i < this->table.size(); i++) {
			newTable.push_back(Node("N/A", 0, 0));
		}
		for (int i = 0; i < this->table.size(); i++) {
			if (!table[i].isEmpty()) {
				int index = hash(table[i].key);
				newTable[index] = table[i];
			}
		}
		table = newTable;
	}
};

#endif // !HASHTABLE_H