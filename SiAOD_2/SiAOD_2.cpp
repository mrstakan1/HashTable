#include "HashTable.h"

int main() {
	// table
	setlocale(0, "RU-ru");
	HashTable table = HashTable();
	// fill
	cout << "ВЫВОД 1 наполнение таблицы------------------------------------------------------------------------------" << endl;
	table.fill();
	table.output();
	// push
	cout << "ВЫВОД 2 добавление в таблицу------------------------------------------------------------------------------" << endl;
	table.push(Node("Павел", 10000, 123));
	table.output();
	// pop
	cout << "ВЫВОД 3 удаление из таблицы------------------------------------------------------------------------------" << endl;
	table.pop(123);
	table.pop(122);
	table.output();
	// find 
	cout << "ВЫВОД 4 поиск по таблице------------------------------------------------------------------------------" << endl;
	table.push(Node("Павел", 10000, 122));
	cout << table.find(123).toString() << endl;
	cout << table.find(122).toString() << endl;
	// rehash
	table.rehash();
	table.output();
}