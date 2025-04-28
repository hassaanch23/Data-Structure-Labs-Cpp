//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cout << "Enter the size of Array: ";
//	cin >> n;
//
//	int *Array = new int[n];
//
//	for (int i = 0; i < n; i++){
//		cout << "Enter value for Index " << i << ": ";
//		cin >> Array[i];
//	}
//
//	int *Reverse = new int[n];
//	int size = n-1;
//	for (int i = 0; i < n; i++){
//		Reverse[i] = Array[size--];
//	}
//
//	for (int i = 0; i < n; i++){
//		cout << Reverse[i] << " ";
//	}
//	cout << endl;
//
//	delete[]Array;
//	delete[] Reverse;
//
//	system("pause");
//	return 0;
//}