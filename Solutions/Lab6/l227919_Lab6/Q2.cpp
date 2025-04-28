//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template<class T>
//class Stack {
//	T* arr;
//	int top;
//	int size;
//public:
//	Stack(int s) {
//		size = s;
//		top = -1;
//		arr = new T[size];
//	}
//
//	~Stack() {
//		arr = nullptr;
//		delete[] arr;
//	}
//
//	void push(T val) {
//		if (isFull()) {
//			cout << "Stack is Full. Cannot push more elements " << endl;
//			return;
//		}
//		else {
//			top++;
//			arr[top] = val;
//		}
//	}
//
//	bool isFull() {
//
//		if (top == size) {
//			return true;
//		}
//		else
//			return false;
//	}
//
//	bool isEmpty() {
//
//		if (top == -1)
//			return true;
//
//		else
//			return false;
//	}
//
//	void pop() {
//
//		if (top == -1) {
//			cout << "The stack is already empty." << endl;
//			return;
//		}
//
//		top--;
//		
//	}
//
//	int Size() {
//
//		if (top == -1) {
//			cout << "Stack is Empty." << endl;
//			return -1;
//		}
//
//		return top + 1;
//	}
//
//	bool Top(T& element) {
//		if (isEmpty()) {
//			return false;
//		}
//		element = arr[top];
//		return true;
//	}
//
//	void display() {
//		for (int i = 0; i <= top; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//};
//
//bool isBalanced(const string& exp) {
//    Stack<char> charStack(exp.size());
//
//    for (char ch : exp) {
//        if (ch == '(' || ch == '[' || ch == '{') {
//            charStack.push(ch);
//        }
//        else if (ch == ')' || ch == ']' || ch == '}') {
//            if (charStack.isEmpty()) {
//                return false;
//            }
//            char top;
//            charStack.Top(top);
//            charStack.pop();
//            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
//                return false;
//            }
//        }
//    }
//    return charStack.isEmpty();
//}
//
//int main() {
//    string expression1 = "{[{}{}]}[()]";
//    string expression2 = "{{}{}}";
//    string expression3 = "[]{}()";
//    string expression4 = "{()}[)";
//    string expression5 = "{(})";
//
//    cout << "Expression 1 is balanced: " << boolalpha << isBalanced(expression1) << endl;
//    cout << "Expression 2 is balanced: " << boolalpha << isBalanced(expression2) << endl;
//    cout << "Expression 3 is balanced: " << boolalpha << isBalanced(expression3) << endl;
//    cout << "Expression 4 is balanced: " << boolalpha << isBalanced(expression4) << endl;
//    cout << "Expression 5 is balanced: " << boolalpha << isBalanced(expression5) << endl;
//
//    return 0;
//}
