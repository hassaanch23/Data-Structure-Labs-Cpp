//#include<iostream>
//using namespace std;
//
//class PersonNode {
//    friend class JosephusList;
//
//public:
//    int id;
//    PersonNode* next;
//};
//
//class JosephusList {
//private:
//    PersonNode* head;
//
//public:
//    JosephusList(int n) {
//        if (n <= 0) {
//            head = nullptr;
//            return;
//        }
//        head = new PersonNode;
//        head->id = 1;
//        PersonNode* temp = head;
//        for (int i = 2; i <= n; i++) {
//            PersonNode* newNode = new PersonNode;
//            newNode->id = i;
//            temp->next = newNode;
//            temp = newNode;
//        }
//        temp->next = head; // Make it circular
//    }
//
//    void display() {
//        if (head == nullptr) {
//            cout << "List is empty." << endl;
//            return;
//        }
//
//        PersonNode* temp = head;
//
//        do {
//            cout << temp->id << " ";
//            temp = temp->next;
//        } while (temp != head);
//
//        cout << endl;
//    }
//
//    int getWinner(int M) {
//        cout << "Eliminated Data Accordingly: ";
//        PersonNode* temp = head;
//        PersonNode* temp1 = head;
//        if (M == 0) {
//            while (temp->next == head) {
//                cout << temp->id << ",";
//                temp1 = temp;
//                temp = temp->next;
//                delete temp1;
//            }
//            return temp->id;
//        }
//        while (temp->next != temp) {
//            for (int i = 0; i < M; i++) {
//                temp1 = temp;
//                temp = temp->next;
//            }
//            cout << temp->id << ",";
//            temp1->next = temp->next;
//            delete temp;
//            temp = temp1->next;
//        }
//        cout << endl;
//        return temp1->id;
//    }
//};
//
//int main() {
//    JosephusList j(5);
//    j.display();
//    cout << "Winner: " << j.getWinner(0) << endl;
//    //j.display();
//    return 0;
//}
//
//
