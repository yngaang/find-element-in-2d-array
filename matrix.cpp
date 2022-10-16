#include "matrix.h"
#include <locale>
#include <iostream>


int main() {
	using namespace std;
	matrix m;
	m.number = 9;
	cout << m.number << endl;
	m.randSet();
	m.newMatrix();
	m.printMatrix();
	int n;
	cin >> n;
	m.findEl(n);
	
	



}
