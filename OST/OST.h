#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <limits>
#define RED true
#define BLACK false
using namespace std;
template<typename type>
struct Node
{
	type key = std::numeric_limits<type>::min();
	bool color = RED;
	Node<type>* p = NULL;
	Node<type>* left = NULL;
	Node<type>* right = NULL;
	int size = 1;
};

template<typename type>
class RBT
{
	private:
		int LEFT_ROTATE(Node<type>* x);
		int RIGHT_ROTATE(Node<type>* x);
		int RB_INSERT_FIXUP(Node<type>* z);
		int RB_DELETE_FIXUP(Node<type>* x);
		int RB_TRANSPLANT(Node<type>* u, Node<type>* v);
		Node<type>* TREE_MINIMUM(Node<type>* x);

	public:
		int RB_INSERT(Node<type>* z);
		int RB_DELETE(Node<type>* z);
		Node<type>* root;
		Node<type> NIL;
		Node<type>* nil;
		RBT<type>(Node<type>* a);
		RBT<type>(){NIL.color = BLACK;
		nil = &NIL;root = nil;};
		int RB_INSERT(type num);
		Node<type>* OS_SELECT(Node<type>* x, int i);
		int OS_RANK(Node<type>* x);
};


