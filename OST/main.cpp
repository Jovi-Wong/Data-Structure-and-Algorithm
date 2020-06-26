#include "OST.cpp"
int main()
{
	RBT<int> A;
	A.RB_INSERT(1);
	A.RB_INSERT(5);
	A.RB_INSERT(8);
	A.RB_INSERT(4);
	A.RB_INSERT(13);
	A.OS_SELECT(A.root,2);
	std::cout<< "All work is done!"<<std::endl;
	return 0;
}
