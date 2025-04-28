//#include<iostream>
//using namespace std;
//
//template<class k, class v>
//class BST {
//	class TNode {
//    public:
//		k key;
//		v value;
//		TNode* leftChild;
//		TNode* rightChild;
//        
//        TNode(k const& k, v const& val) : key(k), value(val), leftChild(nullptr), rightChild(nullptr) {}
//	};
//
//	TNode* root;
//
//public:
//    BST() : root(nullptr) {}
//
//    // Copy Constructor
//    BST(const BST& other) {
//        root = copyTree(other.root);
//    }
//
//    // Destructor
//    ~BST() {
//        destroyTree(root);
//    }
//
//    void insertRec(k const k, v const val) {
//        root = insertRecHelper(root, k, val);
//    }
//
//    void inOrderTraversal() const {
//        inOrderTraversalHelper(root);
//        cout << endl;
//    }
//
//    void Height() const {
//        int height = findHeight(root);
//        cout << "Height of the tree: " << height << endl;
//    }
//
//    int Leaf() const {
//        int leafCount = countLeaves(root);
//        cout << "Number of leaf nodes: " << leafCount << endl;
//        return leafCount;
//    }
//
//    TNode* sortedArrayToBST(k sortedArray[], int start, int end) {
//        if (start > end) {
//            return nullptr;
//        }
//
//        int mid = start + (end - start) / 2;
//        TNode* newNode = new TNode(sortedArray[mid], v());
//        newNode->leftChild = sortedArrayToBST(sortedArray, start, mid - 1);
//        newNode->rightChild = sortedArrayToBST(sortedArray, mid + 1, end);
//
//        return newNode;
//    }
//
//    BST(k sortedArray[], int size) {
//        root = sortedArrayToBST(sortedArray, 0, size - 1);
//    }
//
//    v sumSmallerThanOrEqualK(int k) const {
//        return sumSmallerThanOrEqualKHelper(root, k);
//    }
//
//    void displayBST() const {
//        displayBSTHelper(root, 0);
//    }
//
//private:
//    TNode* copyTree(TNode* node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//
//        TNode* newNode = new TNode(node->key, node->value);
//        newNode->leftChild = copyTree(node->leftChild);
//        newNode->rightChild = copyTree(node->rightChild);
//
//        return newNode;
//    }
//
//    void destroyTree(TNode* node) {
//        if (node == nullptr) {
//            return;
//        }
//
//        destroyTree(node->leftChild);
//        destroyTree(node->rightChild);
//        delete node;
//    }
//
//    TNode* insertRecHelper(TNode* node, k const& k, v const& val) {
//        if (node == nullptr) {
//            return new TNode(k, val);
//        }
//
//        if (k < node->key) {
//            node->leftChild = insertRecHelper(node->leftChild, k, val);
//        }
//        else if (k > node->key) {
//            node->rightChild = insertRecHelper(node->rightChild, k, val);
//        }
//        else {
//            node->value = val;
//        }
//
//        return node;
//    }
//
//    void inOrderTraversalHelper(TNode* node) const {
//        if (node == nullptr) {
//            return;
//        }
//
//        inOrderTraversalHelper(node->leftChild);
//        cout << node->key << " ";
//        inOrderTraversalHelper(node->rightChild);
//    }
//
//    int findHeight(TNode* node) const {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        int leftHeight = findHeight(node->leftChild);
//        int rightHeight = findHeight(node->rightChild);
//
//        return max(leftHeight, rightHeight) + 1;
//    }
//
//    int countLeaves(TNode* node) const {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        if (node->leftChild == nullptr && node->rightChild == nullptr) {
//            return 1;
//        }
//
//        return countLeaves(node->leftChild) + countLeaves(node->rightChild);
//    }
//
//    v sumSmallerThanOrEqualKHelper(TNode* node, int& k) const {
//        if (node == nullptr || k <= 0) {
//            return v(); 
//        }
//
//        v leftSum = sumSmallerThanOrEqualKHelper(node->leftChild, k);
//
//        if (k == 0) {
//            return leftSum;
//        }
//
//        k--;
//
//        v currentSum = node->value;
//        v rightSum = sumSmallerThanOrEqualKHelper(node->rightChild, k);
//
//        return leftSum + currentSum + rightSum;
//    }
//
//    void displayBSTHelper(TNode* node, int depth) const {
//        if (node == nullptr) {
//            return;
//        }
//
//        displayBSTHelper(node->rightChild, depth + 1);
//
//        /*for (int i = 0; i < depth; i++) {
//            cout << "  ";
//        }*/
//
//        cout << node->key << " ";
//
//        displayBSTHelper(node->leftChild, depth + 1);
//    }
//};
//
//int main() {
//    BST<int, int> bst;
//    int limit, val;
//    cout << "Enter the limit of tree: ";
//    cin >> limit;
//    
//    cout << "Enter elements for BST" << endl;
//    for (int i = 0; i < limit; i++) {
//        cout << "Index " << i << "; ";
//        cin >> val;
//        bst.insertRec(val, i * 2);
//    }
//
//    //bst.displayBST();
//
//    cout << "\nInorder Traversal of the BST: ";
//    bst.inOrderTraversal();
//
//    cout << endl;
//    bst.Height();
//
//    cout << endl;
//    int leafCount = bst.Leaf();
//
//    int sortedArray[] = { 12, 14, 20, 21, 33, 39, 47 };
//    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
//    BST<int, int> balancedBST(sortedArray, size);
//    cout << "\nInorder Traversal of the Balanced BST: ";
//    balancedBST.inOrderTraversal();
//
//    int k = 4;
//    int sum = bst.sumSmallerThanOrEqualK(k);
//    std::cout << "\nSum of elements smaller than or equal to the " << k << "th smallest element: " << sum << std::endl;
//
//    return 0;
//}
