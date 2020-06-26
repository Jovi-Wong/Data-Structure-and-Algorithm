template<typename T>
class BinarySearchTree: public BinaryTree<T>
{
private:
	Node<T>* root = NULL;
	int inorderwalk(Node<T>* curnode);
	T TreeMax(Node<T>* node);
	T TreeMin(Node<T>* node);
	int del(Node<T>* x);

public:
	BinarySearchTree(){};
	BinarySearchTree(T val);
	Node<T>* getroot() const{return root;};
	int addnode(T num);
	int inorderwalk();
	int transplant(BinarySearchTree<T> BTS, Node<T>* newnd, Node<T>* pos);
	Node<T>* predecessor(Node<T>* x);
	Node<T>* successor(Node<T>* x);
	T TreeMax();
	T TreeMin();
	int del();
};
