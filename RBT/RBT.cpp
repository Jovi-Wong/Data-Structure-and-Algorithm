#include "RBT.h"

template<typename type>
int RBT<type>::RB_INSERT(type num)
{
	Node<type>* a = new Node<type>;
	a->key = num;
	RB_INSERT(a);
	return 0;
};

template<typename type>
RBT<type>::RBT(Node<type>* a)
{
	root->key = a->key;
	root->p = a->p;
	root->left = a->left;
	root->right = a->right;
	root->color = a->color;
};

template<typename type>
int RBT<type>::LEFT_ROTATE(Node<type>* x)
{
	Node<type>* y = x->right;
	x->right = y->left;
	if (y->left != nil)
	{
		y->left->p = x;
	}
	y->p = x->p;
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
	y->left = x;
	x->p = y;
	return 0;
};

template<typename type>
int RBT<type>::RIGHT_ROTATE(Node<type>* x)
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
	return 0;
};

template<typename type>
int RBT<type>::RB_INSERT_FIXUP(Node<type>* z)
{
	while (z->p->color == RED)
	{
		if (z->p == z->p->p->left)
		{
			Node<type>* y = z->p->p->right;
			if (y->color = RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else
			{
				if (z==z->p->right)
				{
					z = z->p;
					LEFT_ROTATE(z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				RIGHT_ROTATE(z->p->p);
			}
		}
		else
		{
			Node<type>* y = z->p->p->left;
			if (y->color = RED)
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
}

template<typename type>
int RBT<type>::RB_INSERT(Node<type>* z)
{
	Node<type>* y = nil;
	Node<type>* x = root;
	while(x != nil)
	{
		y = x;
		if(z->key < x->key)
		{
			x = x->left;
		}
		else 
		{
			x = x->right;
		}
	} 
	z->p = y;
	if(y == nil)
	{
		root = z;
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
    }
    z->left = nil;
    z->right = nil;
    z->color = RED;
    RB_INSERT_FIXUP(z);
    return 0;
};

template<typename type>
int RBT<type>::RB_TRANSPLANT(Node<type>* u, Node<type>* v)
{
	if (u->p == this->nil)
	{
		this->root = v;
	}
	else
	{
		if(u == u->p->left)
		{
			u->p->left = v;
		}	
		else
		{
			u->p->right = v;
		}	
	}
	v->p = u->p;
	return 0;
}

template<typename type>
Node<type>* RBT<type>::TREE_MINIMUM(Node<type>* x)
{
	Node<type>* y = x;
	while(y->left != this->nil)
	{
		y = y->left;
	}
	return y;
}

template<typename type>
int RBT<type>::RB_DELETE_FIXUP(Node<type>* x)
{
	while(x != this->root and x->color == BLACK)
	{
		if (x == x->p->left)
		{
			Node<type>* w = x->p->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				LEFT_ROTATE(x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK and w->right->color == BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					RIGHT_ROTATE(w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				LEFT_ROTATE(x->p);
				x = this->root;
			}
		}
		else
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
}
