//#include<iostream>
//using namespace std;
//
//int *Check(int *ptr, int N){
//	int *ArrangedPositive = new int[N];
//	int *ArrangedNegative = new int[N];
//	int PosCount = 0, NegCount = 0;
//	for (int i = 0; i < N; i++){
//		if (ptr[i]>0){
//			ArrangedPositive[PosCount++] = ptr[i];
//		}
//		else if (ptr[i] < 0){
//			ArrangedNegative[NegCount++] = ptr[i];
//		}
//	}
//
//	int i = 0, j = 0, k = 0;
//	int *Arranged = new int[N];
//	while (i < PosCount || j < NegCount){
//		if (i < PosCount){
//			Arranged[k++] = ArrangedPositive[i++];
//		}
//		if (j < NegCount){
//			Arranged[k++] = ArrangedNegative[j++];
//		}
//	}
//	delete[] ArrangedPositive;
//	delete[] ArrangedNegative;
//
//	return Arranged;
//}
//
//int main(){
//	int n;
//	cout << "Enter the size for array: ";
//	cin >> n;
//
//	int *ptr = new int[n];
//
//	for (int i = 0; i < n; i++){
//		cout << "Enter value for Index " << i << ": ";
//		cin >> ptr[i];
//	}
//
//	int *Arrange=Check(ptr, n);
//
//	for (int i = 0; i < n; i++){
//		cout << Arrange[i] << " ";
//	}
//	cout << endl;
//
//
//	
//	delete[] ptr;
//	delete[] Arrange;
//
//	system("pause");
//	return 0;
//}