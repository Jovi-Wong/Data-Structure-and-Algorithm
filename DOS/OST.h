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
	int size = 0;//set default value to every property
};

template<typename type>
class RBT
{
	private:
		int LEFT_ROTATE(Node<type>* x); // part of FIXUP function
		int RIGHT_ROTATE(Node<type>* x); //part of FIXUP function
		int RB_INSERT_FIXUP(Node<type>* z);//part of insert function targets at fitting rule of red black tree
		int RB_DELETE_FIXUP(Node<type>* x);
		int RB_TRANSPLANT(Node<type>* u, Node<type>* v);//part of DELETE function
		Node<type>* TREE_MINIMUM(Node<type>* x);

	public:
		int RB_INSERT(Node<type>* z);
		int RB_DELETE(Node<type>* z);//this function will not be used in this program
		Node<type>* root;
		Node<type> NIL;
		Node<type>* nil; //point to NIL defined in constructor
		RBT<type>(Node<type>* a);
		RBT<type>()
		{
			NIL.color = BLACK;
			nil = &NIL;
			root = nil;
		};      //another constructor realized right here
		int RB_INSERT(type num);
		Node<type>* OS_SELECT(Node<type>* x, int i);//return node ranked i in the specific subtree
		int OS_RANK(Node<type>* x);//return the rank of specific node
};


