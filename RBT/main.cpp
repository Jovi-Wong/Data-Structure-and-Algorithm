#include "RBT.cpp"
int main()
{
	RBT<int> A;
	A.RB_INSERT(1);
	A.RB_INSERT(5);
	A.RB_INSERT(8);
	A.RB_INSERT(4);
	std::cout<< "All work is done!"<<std::endl;
	return 0;
}
