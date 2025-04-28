//#include <iostream>
//#include <string>
//
//using namespace std;
//template<class T>
//class Stack {
//    T* arr;
//    int top;
//    int size;
//
//public:
//    Stack(int s) {
//        size = s;
//        top = -1;
//        arr = new T[size];
//    }
//
//    ~Stack() {
//        delete[] arr;
//    }
//
//    void push(T val) {
//        if (isFull()) {
//            cout << "Stack is Full. Cannot push more elements " << endl;
//            return;
//        }
//        else {
//            top++;
//            arr[top] = val;
//        }
//    }
//
//    bool isFull() {
//        if (top == size - 1) {
//            return true;
//        }
//        else
//            return false;
//    }
//
//    bool isEmpty() {
//        if (top == -1)
//            return true;
//        else
//            return false;
//    }
//
//    void pop() {
//        if (top == -1) {
//            cout << "The stack is already empty." << endl;
//            return;
//        }
//        top--;
//    }
//
//    int Size() {
//        if (top == -1) {
//            cout << "Stack is Empty." << endl;
//            return -1;
//        }
//        return top + 1;
//    }
//
//    bool Top(T& element) {
//        if (isEmpty()) {
//            return false;
//        }
//        element = arr[top];
//        return true;
//    }
//
//    void display() {
//        for (int i = 0; i <= top; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//class MediaPlayer {
//private:
//    Stack<string> playlist;
//
//public:
//    MediaPlayer() : playlist(10) {}
//
//    void addToPlaylist(const string& media) {
//        playlist.push(media);
//        cout << "Added \"" << media << "\" to the playlist." << endl;
//    }
//
//    void removeFromPlaylist() {
//        if (!playlist.isEmpty()) {
//            string media;
//            playlist.Top(media);
//            playlist.pop();
//            cout << "Removed \"" << media << "\" from the playlist." << endl;
//        }
//        else {
//            cout << "Playlist is empty. Nothing to remove." << endl;
//        }
//    }
//
//    void play() {
//        if (!playlist.isEmpty()) {
//            string media;
//            playlist.Top(media);
//            cout << "Now playing: \"" << media << "\"" << endl;
//        }
//        else {
//            cout << "Playlist is empty. Nothing to play." << endl;
//        }
//    }
//
//    void displayPlaylist() {
//        cout << "Playlist contents:" << endl;
//        Stack<string> tempStack = playlist;
//        while (!tempStack.isEmpty()) {
//            string media;
//            tempStack.Top(media);
//            cout << "- " << media << endl;
//            tempStack.pop();
//        }
//    }
//};
//
//int main() {
//    MediaPlayer player;
//    player.addToPlaylist("Song 1");
//    player.addToPlaylist("Song 2");
//    player.addToPlaylist("Song 3");
//    player.displayPlaylist();
//    player.play();
//    player.removeFromPlaylist();
//    player.displayPlaylist();
//
//    return 0;
//}
