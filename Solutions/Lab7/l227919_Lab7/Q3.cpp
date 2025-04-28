#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    T* data;
    int capacity;
    int Front;
    int Rear;
    int currSize;

public:
    Queue(int size) : capacity(size), Front(0), Rear(-1), currSize(0) {
        data = new T[capacity];
    }

    int size() {
        return currSize;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool front(T& element) {
        if (isEmpty()) {
            return false;
        }
        element = data[Front];
        return true;
    }

    int getFront() const {
        return front;
    }

    void setFront(int index) {
        front = index;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is already empty." << endl;
            return;
        }
        Front = (Front + 1) % capacity;
        currSize--;
    }

    void enqueue(const T& element) {
        if (currSize < capacity) {
            Rear = (Rear + 1) % capacity;
            data[Rear] = element;
            currSize++;
        }
        else {
            cout << "Queue is full." << endl;
        }
    }

    T secondHighest() {
        if (currSize < 2) {
            cout << "Not enough elements in Queue." << endl;
            return T();
        }
        T firstMax = data[0];
        T secondMax = data[1];
        for (int i = 2; i < currSize; i++) {
            if (data[i] > firstMax) {
                secondMax = firstMax;
                firstMax = data[i];
            }
            else if (data[i] > secondMax && data[i] != firstMax) {
                secondMax = data[i];
            }
        }
        return secondMax;
    }

    void intersection(const Queue<T>& otherQueue)
    {
        Queue<T> resultQueue(capacity);
        for (int i = 0; i < currSize; i++) {
            T element;
            if (otherQueue.contains(data[i]) && !resultQueue.contains(data[i])) {
                resultQueue.enqueue(data[i]);
            }
        }
        *this = resultQueue;
    }

    bool contains(const T& element) const {
        for (int i = 0; i < currSize; i++) {
            if (data[i] == element) {
                return true;
            }
        }
        return false;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int current = Front;
        for (int i = 0; i < currSize; i++) {
            cout << data[current] << " ";
            current = (current + 1) % capacity;
        }
        cout << endl << endl;
    }
};

int main() {
    Queue<int> queue(10);

    // Enqueue some elements
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);
    queue.enqueue(30);
    queue.enqueue(35);

    cout << "Elements of Queue: ";
    queue.Display();

    cout << "Queue Size: " << queue.size() << endl << endl;
    // Check the front element
    int frontElement;
    if (queue.front(frontElement)) {
        cout << "Front element of the Queue: " << frontElement << endl << endl;
    }

    // Dequeue an element
    queue.dequeue();
    queue.dequeue();
    cout << "Queue size after dequeue (2 times) is: " << queue.size() << endl << endl;

    // Find the second highest element
    int secondHighest = queue.secondHighest();
    cout << "Second highest element in the Queue: " << secondHighest << endl << endl;

    // Create another queue
    Queue<int> anotherQueue(5);
    anotherQueue.enqueue(30);
    anotherQueue.enqueue(40);
    anotherQueue.enqueue(50);
    anotherQueue.enqueue(10);
    anotherQueue.enqueue(25);

    cout << "2nd Queue Elements: ";
    anotherQueue.Display();

    // Calculate the intersection of queues
    queue.intersection(anotherQueue);
    cout << "Taking Intersection of queues:" << endl;
    while (!queue.isEmpty()) {
        int element;
        if (queue.front(element)) {
            cout << element << " ";
            queue.dequeue();
        }
    }
    cout << endl << endl;
    return 0;
}

