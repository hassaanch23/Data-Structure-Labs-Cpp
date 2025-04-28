//#include <iostream>
//using namespace std;
//
//template<class T>
//class DoublyLinkedList {
//    class Node {
//    public:
//        T data;
//        Node* prev;
//        Node* next;
//
//        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
//    };
//public:
//    Node* head;
//    Node* tail;
//
//    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
//
//    void Insert(T value) {
//        Node* newNode = new Node(value);
//        if (!head) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//    }
//
//    int CountTriplets(DoublyLinkedList<T>& list, int x) {
//        Node* current = list.head;
//        int count = 0;
//
//        while (current) {
//            Node* left = current->next;
//            Node* right = list.tail;
//
//            while (left && left != right) {
//                int sum = current->data + left->data + right->data;
//                if (sum == x) {
//                    count++;
//                    left = left->next;
//                    right = right->prev;
//                }
//                else if (sum < x) {
//                    left = left->next;
//                }
//                else {
//                    right = right->prev;
//                }
//            }
//
//            current = current->next;
//        }
//
//        return count;
//    }
//
//    void Display() {
//        Node* current = head;
//        while (current) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//};
//
//int main() {
//    DoublyLinkedList<int> list;
//    list.Insert(1);
//    list.Insert(2);
//    list.Insert(4);
//    list.Insert(5);
//    list.Insert(6);
//    list.Insert(8);
//    list.Insert(9);
//
//    cout << "List: ";
//    list.Display();
//
//    int x = 8;
//    int tripletsCount = list.CountTriplets(list, x);
//
//    cout << "Number of triplets that produce a sum up to " << x << ": " << tripletsCount << endl;
//
//    return 0;
//}
