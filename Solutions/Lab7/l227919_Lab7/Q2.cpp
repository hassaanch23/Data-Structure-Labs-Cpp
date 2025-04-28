//#include <iostream>
//using namespace std;
//
//void getCombinations(int arr[], int data[], int start, int end, int index, int r) {
//    if (index == r)
//    {
//        for (int i = 0; i < r; i++) {
//            cout << data[i] << " ";
//        }
//       cout << endl;
//        return;
//    }
//
//    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
//        data[index] = arr[i];
//        getCombinations(arr, data, i + 1, end, index + 1, r);
//    }
//}
//
//void Display(int arr[], int n, int r) {
//    int* data = new int[r]; 
//    getCombinations(arr, data, 0, n - 1, 0, r);
//    delete[] data; 
//}
//
//int main() {
//    int Arr[] = { 3,4,5,6 };
//    int n = sizeof(Arr) / sizeof(Arr[0]);
//
//    for (int i = 0; i < n; i++) {
//        cout << Arr[i] << " ";
//    }
//    cout << endl << endl;
//
//    int r;
//    cout << "Enter value for r (between 1 and 4): ";
//    cin >> r;
//    while (r >= n) {
//        cout << "r must be less than 4, Enter again: ";
//        cin >> r;
//    }
//
//    Display(Arr, n, r);
//    return 0;
//}
//
