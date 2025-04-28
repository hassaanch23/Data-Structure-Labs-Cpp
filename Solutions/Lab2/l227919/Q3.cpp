//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "Enter size of Array: ";
//	cin >> n;
//	int *Array = new int[n];
//
//	for (int i = 0; i < n; i++){
//		cout << "Enter value for Index " << i << ": ";
//		cin >> Array[i];
//	}
//
//	int counter=1;
//	while (counter < n) {
//		for (int i = 0; i < n-counter; i++) {
//			if (Array[i] > Array[i + 1]) {
//				int temp = Array[i];
//				Array[i] = Array[i + 1];
//				Array[i + 1] = temp;
//			}
//		}
//		counter++;
//	}
//	cout << endl;
//
//	int k;
//	cout << "Enter Index value, you have to find in array: ";
//	cin >> k;
//	while (k >= n) {
//		cout << "Invalid Index !!" << endl;
//		cin >> k;
//	}
//
//	cout << Array[k] << endl;
//
//
//	system("pause");
//	return 0;
//}