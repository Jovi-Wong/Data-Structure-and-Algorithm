#include <iostream> 
#include "BinaryTree.h"
#include "BinarySearchTree.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
int BinarySearchTree<T>::transplant(BinarySearchTree<T> BTS, Node<T>* newnd, Node<T>* pos)
{
	Node<T>* posfather = pos->parent;
	if (posfather->left == pos)
	{
		BTS.del(pos);
		posfather->left = newnd;
	}
	else
	{
		BTS.del(pos);
		posfather->right = newnd;
	}
	if(newnd->parent != NULL and newnd->parent->left == newnd)
	{
		newnd->parent->left=NULL;
		newnd->parent=posfather;
	}
	else
	{
		newnd->parent->right= NULL;
		newnd->parent=posfather;
	}
	return 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
int BinarySearchTree<T>::del(Node<T>* x)
{
	if (x !=  NULL)
	{
		del(x->left);
		del(x->right);
//		x->data = 0;
//		std::cout<<x<<"\t"<<x->data << std::endl;
		delete x;
	}	
	return 0;	//This function has been already tested, if wanna retest cancel annotation above.
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
int BinarySearchTree<T>::del()
{
	Node<T>* x= getroot();
	del(x);
	root = NULL;
	return 0; 
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T BinarySearchTree<T>::TreeMin(Node<T>* node)
{
	Node<T>* curnode = getroot();
	while(curnode->left != NULL)	
	{
		curnode = curnode->left;
	}
	return curnode->data;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T BinarySearchTree<T>::TreeMax(Node<T>* node)
{
	Node<T>* curnode = getroot();
	while(curnode->right != NULL)	
	{
		curnode = curnode->right;
	}
	return curnode->data;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T BinarySearchTree<T>::TreeMin()
{
	Node<T>* node = getroot();
	return TreeMin(node);
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
T BinarySearchTree<T>::TreeMax()
{
	Node<T>* node = getroot();
	return TreeMax(node);
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Node<T>* BinarySearchTree<T>::predecessor(Node<T>* x)
{
	if (x.left != NULL)
		return TreeMin(x.left);
	Node<T>* y = x.parent;
	while (y != NULL and y.left == x)
	{	
	    x = y;
		y = y.parent;
	}	
	return y;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Node<T>* BinarySearchTree<T>::successor(Node<T>* x)
{
	if (x.right != NULL)
		return TreeMin(x.right);
	Node<T>* y = x.parent;
	while (y != NULL and y.right == x)
	{	
	    x = y;
		y = y.parent;
	}	
	return y;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BinarySearchTree<T>::inorderwalk(Node<T>* curnode)
{
	if (curnode->left == NULL)
	{
		std::cout << curnode->data <<"\t";
	}  
	else 
	{
		inorderwalk(curnode->left);
		std::cout << curnode->data <<"\t";
    }
	if (curnode -> right != NULL)
	{
		inorderwalk(curnode->right);
	}
	return 0;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BinarySearchTree<T>::inorderwalk()
{
//	Node<T>* curnode = root;
//	inorderwalk(curnode);
	if (root != NULL)
	{
		inorderwalk(root->left);
		std::cout << root->data << "\t";
		inorderwalk(root->right);
	}
	else
		std::cout <<"this is a empty tree" << std::endl;
	return 0;	
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BinarySearchTree<T>::addnode(T num)
{
	if (root == NULL)
	{
		root = new Node<T>;
		root->data = num;
	}
	else
	{
		Node<T>* curnode = root;
		Node<T>* last_node = curnode;
		while (curnode != NULL)
		{
			if (num > curnode->data)
			{
				last_node = curnode;
				curnode = curnode -> right;
			}
			else
			{
				last_node = curnode;
				curnode = curnode -> left;
			}
		}
    	Node<T>* p = new Node<T>;
    	p->data = num;
    	p->parent = last_node;
		if (num > last_node->data)
		{
			last_node->right = p;
		} 
		else
		{
			last_node->left = p;
		}
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
BinarySearchTree<T>::BinarySearchTree(T val)
{
	root = new Node<T>;
	root->data = val;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

