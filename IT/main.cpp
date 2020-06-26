#include "OST.cpp"
int main()
{
	OST<int> A;//use constructor 1
	A.OS_INSERT(1);
	A.OS_INSERT(5);
	A.OS_INSERT(8);
	A.OS_INSERT(4);
	A.OS_INSERT(13);// 5 nodes in total
	std::cout<< A.OS_SELECT(A.root,2)->key<<std::endl;//test OS_SELECT function
	std::cout << A.OS_RANK(A.root->right)<<std::endl;// test OS_RANK function
	std::cout<< "All work is done!"<<std::endl;//give a signal before completement
	return 0;
}
