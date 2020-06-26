#include "BinarySearchTree.cpp"
int main()
{
	BinarySearchTree<int> A;
	BinarySearchTree<int> B;
	A.addnode(8);
	A.addnode(3);
 	A.addnode(5);
	A.addnode(5);
	A.addnode(8); 
	A.addnode(17);
	A.addnode(2);
	A.addnode(69);
	A.addnode(877);
	std::cout<<"A in order tree walk fisrt time"<<std::endl;
	A.inorderwalk();
	std::cout<< std::endl;
	B.addnode(11);
	B.addnode(12);
	B.addnode(1);
	std::cout<<"B in order tree walk fisrt time"<<std::endl;
	B.inorderwalk();
	std::cout<<std::endl;
	std::cout<<"A in order tree walk second time"<<std::endl;
	A.inorderwalk();
	std::cout<<std::endl;
	std::cout<<"A in order tree walk second time after del"<<std::endl;
	A.del();
	A.inorderwalk();
	std::cout<<std::endl;
	return 0;
}
