#include<iostream>
using namespace std;


int** createPascalTriangle(int n)
{
	int** Pascal = new int* [n];

	for (int i = 0; i < n; i++) {
		Pascal[i] = new int[i + 1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {

			if (j == 0||j==i) {
				Pascal[i][j] = 1;
			}
			else
				Pascal[i][j] =Pascal[i-1][j-1]+Pascal[i-1][j];
		}
	}

	return Pascal;
}

void displayPascalTriangle(int** pt, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << pt[i][j] << " ";
		}
		cout << endl;
	}
}

void deallocatePascalTriangle(int** pt, int n) {

	for (int i = 0; i < n; i++) {
		delete[] pt[i];
		pt[i] = nullptr;
	}
	delete pt;
	pt = nullptr;
}

int main() {

	int n;
	cout << "Enter value of n for Size of Pascal Triangle: ";
	cin >> n;
	int **ptr= createPascalTriangle(n);
	displayPascalTriangle(ptr, n);


	return 0;
}