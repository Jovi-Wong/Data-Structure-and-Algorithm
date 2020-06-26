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
class OST
{
	private:
		int LEFT_ROTATE(Node<type>* x); // part of FIXUP function
		int RIGHT_ROTATE(Node<type>* x); //part of FIXUP function
		int OS_INSERT_FIXUP(Node<type>* z);//part of insert function targets at fitting rule of red black tree
		int OS_DELETE_FIXUP(Node<type>* x);
		int OS_TRANSPLANT(Node<type>* u, Node<type>* v);//part of DELETE function
		Node<type>* TREE_MINIMUM(Node<type>* x);

	public:
		int OS_INSERT(Node<type>* z);
		int OS_DELETE(Node<type>* z);//this function will not be used in this program
		Node<type>* root;
		Node<type> NIL;
		Node<type>* nil; //point to NIL defined in constructor
		OST<type>(Node<type>* a);
		OST<type>();
		int OS_INSERT(type num);
		Node<type>* OS_SELECT(Node<type>* x, int i);//return node ranked i in the specific subtree
		int OS_RANK(Node<type>* x);//return the rank of specific node
};


