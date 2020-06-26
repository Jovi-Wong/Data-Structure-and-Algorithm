template<typename T>
struct Node
{
	Node* left = NULL;
	Node* right = NULL;
	Node* parent = NULL;
	T data;
};

template<typename T>
class BinaryTree
{
public:
	Node<T> node;
	BinaryTree(){};
	BinaryTree(T num){node.data = num;};
};
