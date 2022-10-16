#pragma once
#include <iostream>
#include <set>
using namespace std;

class matrix
{
public:
	int number;

	void randSet() {   //create random set
		int i = 0;
		int random = rand()% 10000;
		randomas.insert(random);
		while (randomas.size() < number*number) {
			random = rand();
			randomas.insert(random);
		}
	}

	void randSetPrint() {  //принт сета
		set <int>::iterator it = randomas.begin();
		for (int i = 1; it != randomas.end(); i++, it++) {
			cout << *it << " ";
		}
	}

	void newMatrix() {						//create 2d array
		for (int i = 0; i < number; ++i)
			mas[i] = new int[number];
		set <int>::iterator it = randomas.begin();
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++, it++) {
				mas[i][j] = *it;
			}
		}
	}

	void printMatrix() {  //print array
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
	}


	void findEl(int n) {  //find element 
		int left = 0;
		int n1 = n;
		int j = 0;
		int right = number-1;
		while (left != right) {
			if (right - left == 2) {
				if (n == mas[j][left + 1]) {
					cout << "Element = " << n << " on [" << j << "," << right << "]" << endl;
					left = right;
				}
				else if (n == mas[j][left]) {
					cout << "Element = " << n << " on [" << j << "," << left << "]" << endl;
					left = right;
				}
				else if (n == mas[j][right]) {
					cout << "Element = " << n << " on [" << j << "," << right << "]" << endl;
					left = right;
				}
				else {
					cout << "Matrix doesnt have this element" << endl;
					left = right;
				}
			}
			else if (mas[j][right] > n) {
					if (mas[j][left] < n) {
						left = left + 1;
						right = right - 1;
					}
					else if (mas[j][left] == n) {
						cout << "Element = " << n << " on [" << j << "," << left<< "]" << endl;
						left = right;
					}
					else if (mas[j][left] > n) {
						cout << "Matrix doesnt have this element" << endl;
						left = right;
					}
			}
			else if (mas[j][right] == n){
				cout << "Element = " << n << " on [" << j << "," << right << "]" << endl;
				left = right;
				}
			else if (j == number - 1 and mas[j][right] < n) {
				cout << "Matrix doesnt have this element" << endl;
				left = right;
			}
			else {
				j = j + 1;
			}
		}
	}

private:
	int** mas = new int* [number];
	set <int> randomas  ;
};

