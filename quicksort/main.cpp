#include "quicksort.cpp"
#include <fstream>
int main()
{
	ofstream fout("tmcsm.txt");
	for (int len=1000;len<1000000;len=len+1000)	
	{
		vector<int> a= rndvct(len);
		clock_t start = clock();
		quicksort(a);
		clock_t end = clock();
		double dur = end - start;
		fout << len <<"\t" << dur <<endl;
    }
	return 0;	
}
