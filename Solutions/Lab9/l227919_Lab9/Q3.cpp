//#include <iostream>
//
//using namespace std;
//
//class Tree
//{
//	struct Node
//	{
//		int data;
//		int height;
//		Node* left;
//		Node* right;
//		Node() : left(NULL), right(NULL) { data = 0, height = 0; }
//		Node(int d, Node* l, Node* r) : left(l), right(r) { data = d, height = 0; }
//	};
//	Node* root;
//
//public:
//	Tree() : root(NULL) {}
//
//	void PreOrderPrint()
//	{
//		//cout << "Pre order print: ";
//		PreOrderPrint(root);
//		cout << endl;
//	}
//
//	void PreOrderPrint(Node* n)
//	{
//		if (n) {
//			cout << n->data << " ";
//			PreOrderPrint(n->left);
//			PreOrderPrint(n->right);
//		}
//	}
//
//	int Height(Node* node) {
//
//		if (!node)
//			return -1;
//
//		int l = -1, r = -1;
//		if (node->left)
//			l = node->left->height;
//		if (node->right)
//			r = node->right->height;
//
//		return max(l, r) + 1;
//	}
//
//	void RotateRight(Node*& x) {
//		Node* orphan = x->left->right;
//		Node* y = x->left;
//		y->right = x;
//		x->left = orphan;
//		x->height = Height(x);
//		y->height = Height(y);
//		x = y;
//	}
//	void RotateLeft(Node*& x) {
//		Node* orphan = x->right->left;
//		Node* y = x->right;
//		y->left = x;
//		x->right = orphan;
//		x->height = Height(x);
//		y->height = Height(y);
//		x = y;
//	}
//	void LRrotation(Node*& n) {
//		RotateLeft(n->left);
//		RotateRight(n);
//	}
//	void RLrotation(Node*& n) {
//		RotateRight(n->right);
//		RotateLeft(n);
//	}
//
//	int BalanceFactor(Node* node) {
//		if (!node)
//			return 0;
//		return Height(node->left) - Height(node->right);
//	}
//	void Insert(int x)
//	{
//		Insert(root, x);
//	}
//
//	void Insert(Node*& t, int x) {
//		if (t == NULL) {
//			t = new Node(x, NULL, NULL);
//		}
//		else if (x < t->data) {
//			Insert(t->left, x);
//		}
//		else if (t->data < x) {
//			Insert(t->right, x);
//		}
//		t->height = 1 + max(Height(t->left), Height(t->right));
//
//		if (t->right && t->left) {
//			if (BalanceFactor(t) > 1) {
//				if (x < t->left->data) {
//					RotateRight(t);
//				}
//				else {
//					LRrotation(t);
//				}
//			}
//			else if (BalanceFactor(t) < -1) {
//				if (x > t->right->data) {
//					RotateLeft(t);
//				}
//				else {
//					RLrotation(t);
//				}
//			}
//		}
//	}
//
//	bool isAVL() {
//		return isAVL(root);
//	}
//
//	bool isAVL(Node* node) {
//		if (!node)
//			return true;
//
//		if (BalanceFactor(node) < -1 || BalanceFactor(node) > 1) {
//			return false;
//		}
//		return !isAVL(node->left) && !isAVL(node->right);
//	}
//
//	bool Search(int val) {
//		return Search(root, val);
//	}
//	int Min() {
//		return Min(root);
//	}
//	int Min2() {
//		int firstMin = root->data;
//		int secondMin = -1;
//		Min2(root, firstMin, secondMin);
//		return secondMin;
//	}
//
//	bool Search(Node* node, int val) {
//		if (node != NULL) {
//			if (node->data == val) {
//				return true;
//			}
//			else if (val < node->data) {
//				return Search(node->left, val);
//			}
//			else if (val > node->data) {
//				return Search(node->right, val);
//			}
//		}
//		return false;
//	}
//	int Min(Node* node) {
//		if (node != NULL) {
//			if (!node->left)
//				return node->data;
//			return Min(node->left);
//		}
//		else
//			return -1;
//	}
//
//	void Min2(Node* node, int& first, int& second) {
//		if (node == NULL)
//			return;
//
//		if (node->data < first) {
//			second = first;
//			first = node->data;
//		}
//		else if (node->data > first && (second == -1 || node->data < second)) {
//			second = node->data;
//		}
//
//		Min2(node->left, first, second);
//		Min2(node->right, first, second);
//	}
//
//
//	void deleteNodes(Node* node) {
//		if (node) {
//			deleteNodes(node->left);
//			deleteNodes(node->right);
//			delete node;
//		}
//	}
//
//	~Tree()
//	{
//		deleteNodes(root);
//	}
//};
//
//int main()
//{
//	Tree t;
//	t.Insert(2);
//	t.Insert(7);
//	t.Insert(9);
//	t.Insert(3);
//	t.Insert(5);
//	t.Insert(14);
//	t.Insert(11);
//
//	t.PreOrderPrint();
//
//	if (t.isAVL())
//		cout << "Is an AVL " << endl;
//	else
//		cout << "Is not an AVL " << endl;
//
//	int s;
//	cout << "Enter num to search: ";
//	cin >> s;
//
//	if (t.Search(s))
//		cout << "Num Found";
//	else
//		cout << "Num Not found.";
//	cout << endl;
//
//	cout << "Min value: " << t.Min() << endl;
//	cout << "2nd Min value: " << t.Min2() << endl;
//
//
//	system("pause");
//}
