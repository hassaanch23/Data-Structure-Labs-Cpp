//#include <iostream>
//using namespace std;
//
//template <typename T>
//class SinglyLinkedList {
//    class Node {
//    public:
//        T data;
//        Node* next;
//
//        Node(T value) : data(value), next(nullptr) {}
//    };
//
//    class LisIterator {
//        Node* current;
//
//    public:
//        LisIterator(Node* start) : current(start) {}
//
//        bool NotNull() {
//            return current != nullptr;
//        }
//
//        bool NextNotNull() {
//            return current != nullptr && current->next != nullptr;
//        }
//
//        Node* First() {
//            return current;
//        }
//
//        Node* Next() {
//            if (current) {
//                current = current->next;
//            }
//            return current;
//        }
//    };
//
//    Node* head;
//
//public:
//    SinglyLinkedList() : head(nullptr) {}
//
//    void insert(T const element) {
//        Node* newNode = new Node(element);
//        if (!head) {
//            head = newNode;
//        }
//        else {
//            newNode->next = head;
//            head = newNode;
//        }
//    }
//
//    void print() {
//        Node* current = head;
//        while (current) {
//            std::cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//    static SinglyLinkedList<T> unionLists(const SinglyLinkedList<T>& list1, const SinglyLinkedList<T>& list2) {
//        SinglyLinkedList<T> result;
//        SinglyLinkedList<T> tempList;
//
//        LisIterator iterator1(list1.head);
//        LisIterator iterator2(list2.head);
//
//        while (iterator1.NotNull()) {
//            T data = iterator1.First()->data;
//            if (!tempList.search(data)) {
//                tempList.insert(data);
//            }
//            iterator1.Next();
//        }
//
//        while (iterator2.NotNull()) {
//            T data = iterator2.First()->data;
//            if (!tempList.search(data)) {
//                tempList.insert(data);
//            }
//            iterator2.Next();
//        }
//
//        LisIterator tempListIterator(tempList.head);
//
//        while (tempListIterator.NotNull()) {
//            T data = tempListIterator.First()->data;
//            insertInAscendingOrder(result, data);
//            tempListIterator.Next();
//        }
//
//        return result;
//    }
//
//    bool search(T const& element) {
//        LisIterator iterator(head);
//        while (iterator.NotNull()) {
//            if (iterator.First()->data == element) {
//                return true;
//            }
//            iterator.Next();
//        }
//        return false;
//    }
//
//    static void insertInAscendingOrder(SinglyLinkedList<T>& list, T element) {
//        Node* newNode = new Node(element);
//
//        if (!list.head || element < list.head->data) {
//            newNode->next = list.head;
//            list.head = newNode;
//        }
//        else {
//            Node* current = list.head;
//            while (current->next && current->next->data < element) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }
//};
//
//int main() {
//    SinglyLinkedList<int> list1;
//    list1.insert(3);
//    list1.insert(8);
//    list1.insert(9);
//    list1.insert(13);
//    list1.insert(11);
//    list1.insert(4);
//
//    SinglyLinkedList<int> list2;
//    list2.insert(6);
//    list2.insert(12);
//    list2.insert(1);
//    list2.insert(8);
//    list2.insert(7);
//
//    std::cout << "List 1: ";
//    list1.print();
//
//    std::cout << "List 2: ";
//    list2.print();
//
//    SinglyLinkedList<int> unionList = SinglyLinkedList<int>::unionLists(list1, list2);
//
//    std::cout << "Union: ";
//    unionList.print();
//
//    return 0;
//}
