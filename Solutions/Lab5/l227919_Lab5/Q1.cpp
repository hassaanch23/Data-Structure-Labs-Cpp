//#include <iostream>
//using namespace std;
//
//template <class T>
//class DoubleLinkedList {
//    class Node {
//    public:
//        T data;
//        Node* prev;
//        Node* next;
//
//        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
//    };
//
//    Node* head;
//    Node* tail;
//
//public:
//    DoubleLinkedList() : head(nullptr), tail(nullptr) {}
//
//    void Insert(T value) {
//        Node* newNode = new Node (value);
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
//    void Remove(T value) {
//        Node* current = head;
//        while (current) {
//            if (current->data == value) {
//                if (current == head) {
//                    head = current->next;
//                    if (head) {
//                        head->prev = nullptr;
//                    }
//                }
//                else if (current == tail) {
//                    tail = current->prev;
//                    if (tail) {
//                        tail->next = nullptr;
//                    }
//                }
//                else {
//                    current->prev->next = current->next;
//                    current->next->prev = current->prev;
//                }
//                delete current;
//                return;
//            }
//            current = current->next;
//        }
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
//    void Reverse() {
//        Node* current = head;
//        while (current) {
//            Node* temp = current->next;
//            current->next = current->prev;
//            current->prev = temp;
//            if (!temp) {
//                head = current;
//            }
//            current = temp;
//        }
//    }
//
//    bool IsPalindrome() {
//
//        if (!head || !head->next) {
//            return true;
//        }
//
//        Node* newHead = head;
//        Node* newTail = tail;
//
//        while (newHead != newTail) {
//            if (newHead->data != newTail->data) {
//                return false;
//            }
//            newHead = newHead->next;
//            newTail = newTail->prev;
//        }
//
//        return true;
//    }
//
//    void Reorder() {
//
//        if (!head || !head->next) {
//            return;
//        }
//
//        Node* slow = head;
//        Node* fast = head;
//        while (fast->next && fast->next->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        Node* firstHalf = head;
//        Node* secondHalf = slow->next;
//        slow->next = nullptr;
//
//        Node* prev = nullptr;
//        Node* next = nullptr;
//        Node* current = secondHalf;
//        while (current) {
//            next = current->next;
//            current->next = prev;
//            current->prev = next;
//            prev = current;
//            current = next;
//        }
//        secondHalf = prev;
//
//        Node* p1 = firstHalf;
//        Node* p2 = secondHalf;
//        while (p2) {
//            Node* temp1 = p1->next;
//            Node* temp2 = p2->next;
//
//            p1->next = p2;
//            p2->prev = p1;
//            p2->next = temp1;
//            if (temp1) {
//                temp1->prev = p2;
//            }
//
//            p1 = temp1;
//            p2 = temp2;
//        }
//    }
//
//    void RemoveNodesWithEvenDigitSum() {
//        Node* current = head;
//        while (current) {
//            int digitSum = 0;
//            int num = current->data;
//
//            while (num > 0) {
//                digitSum += num % 10;
//                num /= 10;
//            }
//
//            if (digitSum % 2 == 0) {
//                Node* temp = current;
//                if (current->prev) {
//                    current->prev->next = current->next;
//                }
//                else {
//                    head = current->next;
//                }
//                if (current->next) {
//                    current->next->prev = current->prev;
//                }
//                current = current->next;
//                delete temp;
//            }
//            else {
//                current = current->next;
//            }
//        }
//    }
//
//    int CalculateSum() {
//        int sum = 0;
//        Node* current = head;
//        while (current) {
//            sum += current->data;
//            current = current->next;
//        }
//        return sum;
//    }
//
//    int CalculateProduct() {
//        int product = 1;
//        Node* current = head;
//        while (current) {
//            product *= current->data;
//            current = current->next;
//        }
//        return product;
//    }
//
//    void SwapNodes(int T)
//    {
//
//        Node* temp = head;
//        Node* temp0 = nullptr;
//        Node* temporary = nullptr;
//        Node* temporary1 = nullptr;
//        Node* temporary2 = nullptr;
//        Node* temporary3 = nullptr;
//        Node* temporary4 = nullptr;
//        while (temp->next != nullptr)
//        {
//
//            temp = temp->next;
//        }
//        Node* temp1 = head;
//        int count = 1;
//        while (temp1 != nullptr)
//        {
//            if (count == T)
//            {
//
//
//                temporary = temp1;
//                temp0 = temp;
//                temporary1 = temp1->next;
//                temporary2 = temp1->prev;
//                temporary3 = temp0->next;
//                temporary4 = temp0->prev;
//                /*	if (temp1->next == temp)
//                    {
//                        temp->next = temp1;
//                        temp->prev = temporary2;
//                        temporary3->prev = temp1;
//                        temporary4->next = temp;
//                        temp1->next = temporary3;
//                        temp1->prev=
//                    }*/
//
//                temp0->next = temporary1;
//                temp0->prev = temporary2;
//
//                temporary2->next = temp0;
//
//                temporary1->prev = temp0;
//                temp1->next = temporary3;
//                temp1->prev = temporary4;
//
//                temporary4->next = temp1;
//
//                temporary3->prev = temp1;
//                break;
//
//            }
//            temp1 = temp1->next;
//            temp = temp->prev;
//            count++;
//
//        }
//    }
//
//
//    ~DoubleLinkedList() {
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//};
//
//int main() {
//    DoubleLinkedList<int> list;
//    list.Insert(1);
//    list.Insert(2);
//    list.Insert(3);
//    list.Insert(4);
//    list.Insert(5);
//    list.Insert(6);
//    list.Insert(7);
//    list.Insert(8);
//    list.Insert(9);
//
//    cout << "List 1: ";
//    list.Display();
//
//    list.Remove(3);
//    list.Remove(1);
//
//    cout << endl;
//    cout << "Modified List After Deletion of Elements: ";
//    list.Display();
//
//    cout << endl;
//    list.Reverse();
//
//    cout << "Reversed List: ";
//    list.Display();
//
//    cout << endl;
//   
//    DoubleLinkedList<int> list1;
//    list1.Insert(3);
//    list1.Insert(5);
//    list1.Insert(4);
//    list1.Insert(5);
//    list1.Insert(3);
//
//    cout << endl;
//    cout << "List 2: ";
//    list1.Display();
//    if (list1.IsPalindrome()) {
//        cout << "List 2 is Palindrome." << endl;
//    }
//    else {
//        cout << "List 2 is not Palindrome." << endl;
//    }
//
//    cout << endl;
//    list.Reorder();
//    cout << "Re-Ordered List 1: ";
//    list.Display();
//
//    list1.Reorder();
//    cout << "Re-ordered List 2: ";
//    list1.Display();
//    
//    cout << endl;
//    list.SwapNodes(2);
//    cout << "Swaping Elements of Index 2 of List 1: ";
//    list.Display();
//
//    cout << endl;
//    list.RemoveNodesWithEvenDigitSum();
//    cout << "List 1 After Deletion of Nodes With Even Digit Sum: ";
//    list.Display();
//
//    list1.RemoveNodesWithEvenDigitSum();
//    cout << "List 2 After Deletion of Nodes With Even Digit Sum: ";
//    list1.Display();
//
//    int sum = list.CalculateSum();
//    int sum1 = list1.CalculateSum();
//    int product = list.CalculateProduct();
//    int product1 = list1.CalculateProduct();
//
//    cout << endl;
//    cout << "Sum of Remaining Elements of List 1: " << sum << endl;
//    cout << "Sum of Remaining Elements of List 2: " << sum1 << endl << endl;
//    cout << "Product of Remaining Elements of List 1: " << product << endl;
//    cout << "Product of Remaining Elements of List 2: " << product1 << endl;
//
//    return 0;
//}