#include "quicksort.h"
vector<int> rndvct(int len)
{
	vector<int> rt(len);
	srand((int)time(0));
	for (int i; i<len; i++)
	{
		rt[i] = rand();
	}
	return rt;
};

int partition(std::vector<int>& a, int p, int r)
{
	srand((int)time(0));
	int rdidx = rand()%(r-p+1)+p;
	swap(a[rdidx], a[r]);
	int sd = a[r];
	int i = p-1;
	for (int j=p; j<r; j++)
	{
		if (a[j] < sd)
		{
			i = i + 1;
			swap(a[i],a[j]); 
		}
	}
    swap(a[r],a[i+1]);
	i=i+1;
	return i;	
}; 

int quicksort(vector<int>& a, int p , int r)
{
	if (r == -404)
    {
		r =a.size()-1;
    }	
	
	if (r-p>2)
	{	
		
		int q = partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
	else    //insert sort algorithm
	{
    	for(int cur=p+1; cur<=r ;cur++)
    	{
			for(int bfcur=cur-1; bfcur>=0; bfcur--)
			{
				if (a[bfcur]>a[bfcur+1])
				{
					swap(a[bfcur], a[bfcur+1]);
				}
       		}
    	}	
	}
	return 0;
};


