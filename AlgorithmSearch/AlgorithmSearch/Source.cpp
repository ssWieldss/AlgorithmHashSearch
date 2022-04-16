#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void hash_search(int arr[], int table[], int max, int size, int count){

	auto startall = chrono::steady_clock::now();

	for (int i = 0; i < size; i++) {
		table[i] = arr[i] % (max / 2);
	}

	vector<int> table_temp;


	for (int i = 0; i < size; i++) {
		if (count % (max / 2) == table[i]) {
			table_temp.push_back(i);
		}
	}

	bool flag = false;

	for (int i = 0; i < table_temp.size(); i++)
		if (arr[table_temp[i]] == count) {
			cout << "Найденное число находится на позиции: " << table_temp[i] + 1 << endl;
			flag = true;
			break;
		}
	if (flag == false)
		cout << "Заданное число не найденно" << endl;

	auto endall = chrono::steady_clock::now();

	cout << endl << "Время общее: " << (endall - startall).count() / 1'000'000'000.0
		<< " seconds" << endl;

}

int main() {

	srand(time(NULL));
	system("chcp 1251");

	int n1[1900];
	int n2[2700];
	int n3[8000];

	int max_1 = -1;
	int max_2 = -1;
	int max_3 = -1;

	//Random values for arrays

	for (int i = 0; i < 1900; i++) {
		n1[i] = rand() % 10000 + 0;
		if (n1[i] > max_1)
			max_1 = n1[i];
	}

	for (int i = 0; i < 2700; i++) {
		n2[i] = rand() % 10000 + 0;
		if (n2[i] > max_2)
			max_2 = n2[i];
	}

	for (int i = 0; i < 8000; i++) {
		n3[i] = rand() % 10000 + 0;
		if (n3[i] > max_3)
			max_3 = n3[i];
	}

	//Create Hash-Tables

	int table_1[1900];
	int table_2[2700];
	int table_3[8000];
	
	//Example
	cout << "862 число из массива 1900 чисел " << n1[861] << endl;

	//Search for first array
	cout << "Введите число, которые хотите найти(поиск будет вестись по массиву из 1900эл." << endl;
	int count = 0;
	cin >> count;

	hash_search(n1, table_1, max_1, 1900, count);

	//Search for second array

	//Example
	cout << "1357 число из массива 2700 чисел " << n2[1356] << endl;
	cout << "Введите число, которые хотите найти(поиск будет вестись по массиву из 1900эл." << endl;
	cin >> count;

	hash_search(n2, table_2, max_2, 2700, count);

	//Search for third array

	//Example
	cout << "4300 число из массива 8000 чисел " << n3[4299] << endl;

	cout << "Введите число, которые хотите найти(поиск будет вестись по массиву из 1900эл." << endl;
	cin >> count;
	hash_search(n3, table_3, max_3, 8000, count);

	return 0;
}