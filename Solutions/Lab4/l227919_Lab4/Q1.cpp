#include<iostream>
using namespace std;

template<class T>
class SinglyLinkedList {
	class Node {
	public:
		T data;
		Node* next;

		Node(const T& val) : data(val), next(nullptr) {}

		~Node() {
			next = nullptr;
			delete next;
		}
	};

	Node* head;
	Node* tail;
	int size = 0;
public:

	void InsertAtStart(T const element) {
		Node* newNode = new Node <T>(element);

		if (!head) {
			head = newNode;
			tail = newNode;
		}

		newNode->next = head;
		head = newNode;
		size++;
	}

	void InsertAtEnd(T const element) {
		Node* newNode = new Node <T>(element);

		if (!head) {
			head = newNode;
			tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
		size++;
	}

	void Print() const {
		Node* newNode = head;

		while (newNode) {
			cout << newNode->data << " -> ";
			newNode = newNode->next;
		}
		cout << " -> NULL " << endl;
	}

	bool Search(T const& element) const {
		Node* newNode = head;

		while (newNode) {
			if (newNode->data == element)
				return true;
			newNode = newNode->next;
		}

		return false;
	}

	bool isEmpty() const {
		if size == 0;
		return true;

		else return false;
	}

	void DeleteStart() {
		Node* temp = head;

		if (!head) {
			return;
		}

		head = head->next;
		delete temp;
		size--;
	}

	void DeleteEnd() {
		Node* temp = tail;

		if (!head) {
			return;
		}

		if (head == tail) {
			delete head;
			head = tail = nullptr;
			size--;
			return;
		}

		else {
			Node* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			delete tail;
			tail = current;
			tail->next = nullptr;

			size--;
		}
	}

	bool InsertAfter (T const v1,T const v2){
		Node* current = head;

		while (current) {
			if (current->data == v1) {
				Node* newNode = new Node <T> v2;
				newNode->next = current->next
				current->next = newNode;
				size++;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void DeleteAll(T const value) {

		while (head && head->data == value) {
			DeleteStart();
		}

		Node* current = head;
		while (current && current->next) {
			if (current->next->data == value) {
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				size--;
			}
			else
				current = current->next;
		}
	}

	void RemoveDuplicates() {
		Node* current = head;

		while (current) {
			Node* run = current;
			while (run->next) {
				if (run->next->data == current->data) {
					Node* temp = run->next;
					run->next = run->next->next;
					delete temp;
					size--;
				}
				else run = run->next;
			}
			current = current->next;
		}
	}

	bool isSorted() const {
		if (isEmpty() || size == 1) {
			return true;
		}
		else {
			Node* current = head;
			while (current->next) {
				if (current->data > current->next->data) {
					return false;
				}
				current = current->next;
			}
			return true;
		}
	}


};
int main() {

}

