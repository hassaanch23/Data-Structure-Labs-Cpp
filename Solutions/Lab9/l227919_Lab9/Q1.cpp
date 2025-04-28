//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//template<class T>
//class BST {
//    class Node {
//    public:
//        T data;
//        Node* left;
//        Node* right;
//
//        Node(T key) : data(key), left(nullptr), right(nullptr) {}
//    };
//
//public:
//    Node* root;
//
//    BST() : root(nullptr) {}
//
//    void insert(T key) {
//        root = insertHelper(root, key);
//    }
//
//    bool isSkewed() {
//        bool result = isSkewedHelper(root);
//        cout << "Tree is " << (result ? "skewed." : "not skewed.") << endl;
//        return result;
//    }
//
//    void balanceBST() {
//        int n = countNodes(root);
//        Node* balancedRoot = sortedArrayToBST(n);
//        root = balancedRoot;
//    }
//
//    void preOrder() {
//        preOrderHelper(root);
//    }
//
//private:
//    Node* insertHelper(Node* root, T key) {
//        if (root == nullptr) {
//            return new Node(key);
//        }
//
//        if (key < root->data) {
//            root->left = insertHelper(root->left, key);
//        }
//        else if (key > root->data) {
//            root->right = insertHelper(root->right, key);
//        }
//
//        return root;
//    }
//
//    bool isSkewedHelper(Node* root) {
//        if (root == nullptr) {
//            return true;
//        }
//
//        if (root->left != nullptr && root->right != nullptr) {
//            return false;
//        }
//
//        return isSkewedHelper(root->left) && isSkewedHelper(root->right);
//    }
//
//    int countNodes(Node* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        return 1 + countNodes(root->left) + countNodes(root->right);
//    }
//
//    Node* sortedArrayToBSTUtil(T sortedArray[], int start, int end) {
//        if (start > end) {
//            return nullptr;
//        }
//
//        int mid = (start + end) / 2;
//        Node* newNode = new Node(sortedArray[mid]);
//
//        newNode->left = sortedArrayToBSTUtil(sortedArray, start, mid - 1);
//        newNode->right = sortedArrayToBSTUtil(sortedArray, mid + 1, end);
//
//        return newNode;
//    }
//
//    Node* sortedArrayToBST(int n) {
//        T* sortedArray = new T[n];
//        int index = 0;
//        sortedArrayToBSTHelper(sortedArray, root, index);
//        return sortedArrayToBSTUtil(sortedArray, 0, n - 1);
//    }
//
//    void sortedArrayToBSTHelper(T sortedArray[], Node* root, int& index) {
//        if (root == nullptr) {
//            return;
//        }
//
//        sortedArrayToBSTHelper(sortedArray, root->left, index);
//        sortedArray[index++] = root->data;
//        sortedArrayToBSTHelper(sortedArray, root->right, index);
//    }
//
//    void preOrderHelper(Node* root) {
//        if (root == nullptr) {
//            return;
//        }
//
//        cout << root->data << " ";
//        preOrderHelper(root->left);
//        preOrderHelper(root->right);
//    }
//};
//
//int main() {
//    BST<int> bst1;
//    bst1.insert(3);
//    bst1.insert(2);
//    bst1.insert(1);
//
//    bst1.preOrder();
//    cout << endl;
//    bst1.isSkewed();
//    bst1.balanceBST();
//    cout << "Balanced Tree: ";
//    bst1.preOrder();
//    cout << endl;
//
//    BST<int> bst2;
//    bst2.insert(4);
//    bst2.insert(7);
//    bst2.insert(15);
//    bst2.insert(30);
//
//    cout << endl;
//    bst2.preOrder();
//    cout << endl;
//    bst2.isSkewed();
//    bst2.balanceBST();
//    cout << "Balanced Tree: ";
//    bst2.preOrder();
//    cout << endl;
//
//    BST<int> bst3;
//    bst3.insert(4);
//    bst3.insert(3);
//    bst3.insert(5);
//    bst3.insert(2);
//    bst3.insert(6);
//    bst3.insert(1);
//    bst3.insert(7);
//
//    cout << endl;
//    bst3.preOrder();
//    cout << endl;
//    bst3.isSkewed();
//    bst3.balanceBST();
//    cout << "Balanced Tree: ";
//    bst3.preOrder();
//    cout << endl;
//
//    return 0;
//}
