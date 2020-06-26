#include "OST.h"
template<typename type>
OST<type>::OST()
{
	NIL.color = BLACK;
	nil = &NIL;
	root = nil;
};

template<typename type>
int OST<type>::OS_RANK(Node<type>* x)
{
	int r = x->left->size + 1;//store the boundary value 
	Node<type>* y = x;//copy x to y
	while(y != this->root) // condition to end loop
	{
		if (y == y->p->right)
		{
			r = r + y->p->left->size + 1;//add the amount of node under y's uncle node's subtree 
		}
		y = y->p; //move to next node which is y'parent
	}
	return r;
};

template<typename type>
Node<type>* OST<type>::OS_SELECT(Node<type>* x, int i)
{
	int r = x->left->size + 1;
	if ( i == r) // only this statement is true, the recursion will break
	{
		return x;
	}
	else // choose one side to recur 
	{
		if (i<r)
		{
			return OS_SELECT(x->left, i);
		}
		else
		{
			return OS_SELECT(x->right, i-r);
		}
	}
};

template<typename type>
int OST<type>::OS_INSERT(type num)//creat a new node whose key is num
{
	Node<type>* a = new Node<type>;
	a->key = num;
	OS_INSERT(a);
	return 0;
};

template<typename type>
OST<type>::OST(Node<type>* a)//constructor 1
{
	root->key = a->key;
	root->p = a->p;
	root->left = a->left;
	root->right = a->right;
	root->color = a->color;//copy a's property to root to replace default ones
};

template<typename type>
int OST<type>::LEFT_ROTATE(Node<type>* x)
{
	Node<type>* y = x->right;//set y
	x->right = y->left;// turn y's left subtree into x's right
	if (y->left != nil)
	{
		y->left->p = x;
	}
	y->p = x->p;//link x's parent to y
	if (x->p == nil)
	{
		this->root = y;
	}
	else	
	{
		if(x == x->p->left)
		{
			x->p->left = y;
		}
		else 
		{
			x->p->right = y; 	
		}
	}
	y->left = x;//put x on y's left
	x->p = y;
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;//update size  
	return 0;
};

template<typename type>
int OST<type>::RIGHT_ROTATE(Node<type>* x)//same as LEFT_ROTATE
{
	Node<type>* y = x->left;
	x->left = y->right;
	if (y->right != nil)
	{
		y->right->p = x;
	}	
	y->p = x->p;
	if (x->p == nil)
	{	
		this->root = y;
	}
	else	
	{
		if(x == x->p->right)
		{
			x->p->right = y;
		}
		else 	
		{
			x->p->left = y;
		}
	}
	y->right = x;
	x->p = y;
	y->size = x->size;
	x->size = x->right->size + x->left->size + 1;
	return 0;
};

template<typename type>
int OST<type>::OS_INSERT_FIXUP(Node<type>* z)// adjust structure to fit in rule of red black tree
{
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			Node<type>* y = z->p->p->right;
			if (y->color == RED)
			{
				z->p->color = BLACK;//case 1
				y->color = BLACK;//case 1
				z->p->p->color = RED;//case 1
				z = z->p->p;//case 1
			}

			else
			{
				if (z==z->p->right)
				{
					z = z->p;//case 2
					LEFT_ROTATE(z);//case 2
				}
				z->p->color = BLACK;//case 3
				z->p->p->color = RED;//case 3
				RIGHT_ROTATE(z->p->p);//case 3
			}
		}

		else//same as upper content
		{
			Node<type>* y = z->p->p->left;
			if (y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if (z==z->p->left)
				{
					z = z->p;
					LEFT_ROTATE(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				LEFT_ROTATE(z->p->p);
			}
		}
	}
	root->color = BLACK;
	return 0;
};

template<typename type>
int OST<type>::OS_INSERT(Node<type>* z)
{
	Node<type>* y = nil;
	Node<type>* x = root;
	while(x != nil)//find the right leaf node
	{
		y = x;
		if(z->key < x->key)
		{
			x->size = x->size+1;
			x = x->left;
		}
		else 
		{
			x->size = x->size + 1;
			x = x->right;
		}
	} 
	z->p = y;
	if (y == nil)//change y's property
	{
		root = z;
		root->size = root->size +1;
	}	
	else	
	{
		if (z->key < y->key)
		{
			y->left = z;
		}
		else 
		{
			y->right = z;
		}	
		z->size = z->size+1;
    }
    z->left = nil;
    z->right = nil;
    z->color = RED;
    OS_INSERT_FIXUP(z);//change structure
    return 0;
};

template<typename type>
int OST<type>::OS_TRANSPLANT(Node<type>* u, Node<type>* v)
{
	if (u->p == this->nil)
	{
		this->root = v;
	}
	else
	{
		if(u == u->p->left)//estimate u is in left subtree or right subtree
		{
			u->p->left = v;
		}	
		else
		{
			u->p->right = v;
		}	
	}
	v->p = u->p; //mutual relation establishs
	return 0;
};

template<typename type>
Node<type>* OST<type>::TREE_MINIMUM(Node<type>* x)//return the minimum of subtree
{
	Node<type>* y = x;
	while(y->left != this->nil)
	{
		y = y->left;
	}
	return y;
};

template<typename type>
int OST<type>::OS_DELETE_FIXUP(Node<type>* x)
{
	while(x != this->root and x->color == BLACK)
	{
		if (x == x->p->left)
		{
			Node<type>* w = x->p->right;
			if (w->color == RED)
			{
				w->color = BLACK;// case 1
				x->p->color = RED;//case 1
				LEFT_ROTATE(x->p);//case 1
				w = x->p->right;//case 1
			}
			if (w->left->color == BLACK and w->right->color == BLACK)
			{
				w->color = RED;//case 2
				x = x->p;//case 2
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;//case 3
					w->color = RED;//case 3
					RIGHT_ROTATE(w);//case 3
					w = x->p->right;//case 3
				}
				w->color = x->p->color;//case 4
				x->p->color = BLACK;//case 4
				LEFT_ROTATE(x->p);//case 4
				x = this->root;//case 4
			}
		}
		else//another situation accordingly
		{
			Node<type>* w = x->p->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				RIGHT_ROTATE(x->p);
				w = x->p->right;
			}
			if (w->right->color == BLACK and w->left->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color =RED;
					LEFT_ROTATE(w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				RIGHT_ROTATE(x->p);
				x = this->root;
			}
		}
	}
	x->color = BLACK;
	return 0;
};
