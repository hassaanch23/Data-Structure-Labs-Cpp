//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//class queue {
//private:
//    struct Node {
//        int data;
//        Node* next;
//        Node(int val) : data(val), next(nullptr) {}
//    };
//    Node* front;
//    Node* rear;
//
//public:
//    queue() : front(nullptr), rear(nullptr) {}
//
//    void enqueue(int val) {
//        Node* newNode = new Node(val);
//        if (isEmpty()) {
//            front = rear = newNode;
//        }
//        else {
//            rear->next = newNode;
//            rear = newNode;
//        }
//    }
//    int dequeue() {
//        if (isEmpty()) {
//            cerr << "Queue is already empty." << endl;
//            return -1;
//        }
//
//        Node* temp = front;
//        int val = temp->data;
//        front = front->next;
//        delete temp;
//
//        if (!front) {
//            rear = nullptr;
//        }
//
//        return val;
//    }
//
//    bool isEmpty() const {
//        return front == nullptr;
//    }
//};
//
//string decodeString(string s) {
//    stack<int> counts;
//    stack<string> result;
//    string current;
//    int count = 0;
//
//    for (char c : s) {
//        if (isdigit(c)) {
//            count = count * 10 + (c - '0');
//        }
//        else if (c == '[') {
//            counts.push(count);
//            count = 0;
//            result.push(current);
//            current = "";
//        }
//        else if (c == ']') {
//            int k = counts.top();
//            counts.pop();
//            string tmp = current;
//            for (int i = 1; i < k; i++) {
//                current += tmp;
//            }
//            current = result.top() + current;
//            result.pop();
//        }
//        else {
//            current += c;
//        }
//    }
//
//    return current;
//}
//
//int main() {
//    string input = "2[a3[hij]2[xyz]]";
//    string input1 = "3[a]2[bc]";
//    string input2 = "3[a2[c]]";
//    string input3 = "2[abc]3[cd]ef";
//
//    cout << "Input 1: " << input << endl;
//    cout << "Decoded Result: " << decodeString(input) << endl << endl;
//
//    cout << "Input 2: " << input1 << endl;
//    cout << "Decoded Result 1: " << decodeString(input1) << endl << endl;
//
//    cout << "Input 3: " << input2 << endl;
//    cout << "Decoded Result 2: " << decodeString(input2) << endl << endl;
//
//    cout << "Input 4: " << input3 << endl;
//    cout << "Decoded Result 3: " << decodeString(input3) << endl << endl;
//
//    return 0;
//}