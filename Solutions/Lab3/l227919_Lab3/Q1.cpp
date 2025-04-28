#include <iostream>
using namespace std;

class list {
private:
    int* array;
    int maxsize;
    int listsize;
    int currposition;

public:
    list(int size) {
        maxsize = size;
        array = new int[maxsize];
        listsize = 0;
        currposition = -1;
    }

    ~list() {
        delete[] array;
    }

    void insertatstart(int n) {
        if (listsize < maxsize) {
            for (int i = listsize; i > 0; i--) {
                array[i] = array[i - 1];
            }
            array[0] = n;
            listsize++;
        }
    }

    void insertatend(int n) {
        if (listsize < maxsize) {
            array[listsize] = n;
            listsize++;
        }
    }

    void deleteatstart() {
        if (listsize > 0) {
            for (int i = 0; i < listsize - 1; i++) {
                array[i] = array[i + 1];
            }
            listsize--;
        }
    }

    void deleteatend() {
        if (listsize > 0) {
            listsize--;
        }
    }

    void print() {
        for (int i = 0; i < listsize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    int size() {
        return listsize;
    }

    void insertafter(int val, int key) {
        int i;
        for (i = 0; i < listsize; i++) {
            if (array[i] == val) {
                break;
            }
        }
        if (i == listsize) {
            // Value 'val' not found, insert at the end
            insertatend(key);
        }
        else {
            if (listsize < maxsize) {
                for (int j = listsize; j > i + 1; j--) {
                    array[j] = array[j - 1];
                }
                array[i + 1] = key;
                listsize++;
            }
        }
    }

    int FindMax() const {
        if (listsize == 0) {
            cerr << "List is empty." << endl;
            return -1; // Return a sentinel value indicating an error
        }
        int max = array[0];
        for (int i = 1; i < listsize; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    void prev() {
        if (currposition > 0) {
            currposition--;
        }
    }

    void next() {
        if (currposition < listsize - 1) {
            currposition++;
        }
    }

    int currpos() {
        return currposition;
    }
};

int main() {
    list myList(10); // Create a list with a maximum size of 10

    myList.insertatstart(5);
    myList.insertatend(8);
    myList.insertatend(10);
    myList.insertatstart(12);

    cout << "List size: " << myList.size() << endl;
    cout << "List elements: ";
    myList.print();

    myList.deleteatstart();
    myList.deleteatend();

    cout << "List size after deletions: " << myList.size() << endl;
    cout << "List elements after deletions: ";
    myList.print();

    cout << "Maximum element in the list: " << myList.FindMax() << endl;

    myList.insertafter(10, 20);
    myList.insertafter(7, 25);

    cout << "List size after insertions: " << myList.size() << endl;
    cout << "List elements after insertions: ";
    myList.print();

    myList.prev();
    myList.next();

    cout << "Current position in the list: " << myList.currpos() << endl;

    return 0;
}
