//#include <iostream>
//
//using namespace std;
//
////template<class T>
//class AVLTree {
//    class Node {
//    public:
//        int data;
//        Node* left;
//        Node* right;
//        int height;
//
//        Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
//    };
//public:
//    Node* root;
//
//    AVLTree() : root(nullptr) {}
//
//    int height(Node* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        return node->height;
//    }
//
//    int getBalance(Node* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        return height(node->left) - height(node->right);
//    }
//
//    Node* leftRotate(Node* x) {
//        Node* y = x->right;
//        Node* T2 = y->left;
//
//        y->left = x;
//        x->right = T2;
//
//        x->height = 1 + max(height(x->left), height(x->right));
//        y->height = 1 + max(height(y->left), height(y->right));
//
//        return y;
//    }
//
//    void insert(int key) {
//        root = insertHelper(root, key);
//    }
//
//    Node* insertHelper(Node* node, int key) {
//        if (node == nullptr) {
//            return new Node(key);
//        }
//
//        if (key < node->data) {
//            node->left = insertHelper(node->left, key);
//        }
//        else if (key > node->data) {
//            node->right = insertHelper(node->right, key);
//        }
//        else {
//            return node;
//        }
//
//        node->height = 1 + max(height(node->left), height(node->right));
//
//        int balance = getBalance(node);
//
//        // Left Left Case
//        if (balance > 1 && key < node->left->data) {
//            return rightRotate(node);
//        }
//
//        return node;
//    }
//
//    Node* rightRotate(Node* y) {
//        Node* x = y->left;
//        Node* T2 = x->right;
//
//        x->right = y;
//        y->left = T2;
//
//        y->height = 1 + max(height(y->left), height(y->right));
//        x->height = 1 + max(height(x->left), height(x->right));
//
//        return x;
//    }
//
//    void preOrder() {
//        preOrderHelper(root);
//    }
//
//    void preOrderHelper(Node *root) {
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
//    AVLTree avlTree;
//
//    avlTree.insert(20);
//    avlTree.insert(15);
//    avlTree.insert(10);
//    avlTree.insert(5);
//    avlTree.insert(3);
//    avlTree.insert(25);
//
//    avlTree.preOrder();
//
//    cout << endl;
//    system("pause");
//}
