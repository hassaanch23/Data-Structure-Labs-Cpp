//#include <iostream>
//
//using namespace std;
//
//template <typename T>
//class Node {
//public:
//    T data;
//    Node* next;
//
//    Node(const T& element) : data(element), next(nullptr) {}
//};
//
//template <typename T>
//class SinglyLinkedList {
//private:
//    Node<T>* head;
//    Node<T>* tail;
//    int size;
//
//public:
//    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
//
//    void insertAtStart(const T& element) {
//        Node<T>* newNode = new Node<T>(element);
//        if (!head) {
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            newNode->next = head;
//            head = newNode;
//        }
//        size++;
//    }
//
//    void insertAtEnd(const T& element) {
//        Node<T>* newNode = new Node<T>(element);
//        if (!head) {
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//        size++;
//    }
//
//    void print() const {
//        Node<T>* current = head;
//        while (current) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//
//    bool search(const T& element) const {
//        Node<T>* current = head;
//        while (current) {
//            if (current->data == element) {
//                return true;
//            }
//            current = current->next;
//        }
//        return false;
//    }
//
//    bool isEmpty() const {
//        return size == 0;
//    }
//
//    void DeleteStart() {
//        if (!head) {
//            return;
//        }
//        Node<T>* temp = head;
//        head = head->next;
//        delete temp;
//        size--;
//    }
//
//    void DeleteEnd() {
//        if (!head) {
//            return;
//        }
//        if (head == tail) {
//            delete head;
//            head = nullptr;
//            tail = nullptr;
//        }
//        else {
//            Node<T>* current = head;
//            while (current->next != tail) {
//                current = current->next;
//            }
//            delete tail;
//            tail = current;
//            tail->next = nullptr;
//        }
//        size--;
//    }
//
//    bool insertAfter(const T& v1, const T& v2) {
//        Node<T>* current = head;
//        while (current) {
//            if (current->data == v1) {
//                Node<T>* newNode = new Node<T>(v2);
//                newNode->next = current->next;
//                current->next = newNode;
//                size++;
//                return true;
//            }
//            current = current->next;
//        }
//        return false;
//    }
//
//    void deleteAll(const T& value) {
//        while (head && head->data == value) {
//            DeleteStart();
//        }
//        Node<T>* current = head;
//        while (current && current->next) {
//            if (current->next->data == value) {
//                Node<T>* temp = current->next;
//                current->next = current->next->next;
//                delete temp;
//                size--;
//            }
//            else {
//                current = current->next;
//            }
//        }
//    }
//
//    void removeDuplicates() {
//        Node<T>* current = head;
//        while (current) {
//            Node<T>* runner = current;
//            while (runner->next) {
//                if (runner->next->data == current->data) {
//                    Node<T>* temp = runner->next;
//                    runner->next = runner->next->next;
//                    delete temp;
//                    size--;
//                }
//                else {
//                    runner = runner->next;
//                }
//            }
//            current = current->next;
//        }
//    }
//
//    bool IsSorted() const {
//        if (isEmpty() || size == 1) {
//            return true;
//        }
//        else {
//            Node<T>* curr = head;
//            while (curr->next != nullptr) {
//                if (curr->data > curr->next->data) {
//                    return false;
//                }
//                curr = curr->next;
//            }
//            return true;
//        }
//    }
//
//    static SinglyLinkedList mergeSortedLists(const SinglyLinkedList& List1, const SinglyLinkedList& List2) {
//        SinglyLinkedList merged_List;
//        Node<T>* curr_1 = List1.head;
//        Node<T>* curr_2 = List2.head;
//
//        while (curr_1 != NULL && curr_2 != NULL) {
//            if (curr_1->data < curr_2->data) {
//                merged_List.insertAtEnd(curr_1->data);
//                curr_1 = curr_1->next;
//            }
//            else {
//                merged_List.insertAtEnd(curr_2->data);
//                curr_2 = curr_2->next;
//            }
//        }
//        while (curr_1 != NULL) {
//            merged_List.insertAtEnd(curr_1->data);
//            curr_1 = curr_1->next;
//        }
//        while (curr_2 != NULL) {
//            merged_List.insertAtEnd(curr_2->data);
//            curr_2 = curr_2->next;
//        }
//
//        return merged_List;
//    }
//
//    ~SinglyLinkedList() {
//        while (!isEmpty()) {
//            DeleteStart();
//        }
//    }
//
//};
//
//int main() {
//
//
//    SinglyLinkedList<int> myList;
//
//    myList.insertAtStart(5);
//    myList.insertAtStart(3);
//    myList.insertAtStart(2);
//
//
//    myList.insertAtEnd(9);
//
//
//    myList.insertAtStart(8);
//    myList.insertAtStart(7);
//    myList.insertAtStart(6);
//
//
//    myList.deleteAll(7);
//
//
//    cout << "Linked List: ";
//    myList.print();
//
//
//    int num1 = 2, num2 = 9, num3 = 10;
//    cout << num1 << " found: " << (myList.search(num1) ? "Yes" : "No") << endl;
//    cout << num2 << " found: " << (myList.search(num2) ? "Yes" : "No") << endl;
//    cout << num3 << " found: " << (myList.search(num3) ? "Yes" : "No") << endl;
//
//
//    myList.DeleteStart();
//    cout << "After deleting from start: ";
//    myList.print();
//
//
//    SinglyLinkedList<int> list1;
//    list1.insertAtEnd(1);
//    list1.insertAtEnd(3);
//    list1.insertAtEnd(5);
//
//    SinglyLinkedList<int> list2;
//    list2.insertAtEnd(2);
//    list2.insertAtEnd(4);
//    list2.insertAtEnd(6);
//
//    cout << "Merged List: ";
//    SinglyLinkedList<int> mergedList = SinglyLinkedList<int>::mergeSortedLists(list1, list2);
//    mergedList.print();
//
//}
