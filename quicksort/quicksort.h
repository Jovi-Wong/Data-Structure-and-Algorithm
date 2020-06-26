#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 

using namespace std;

int partition(std::vector<int>& a, int p, int r);

int quicksort(std::vector<int>& a, int p = 0, int r = -404);
//if default numbers are given in the decleration,
//they should not appear in realization again.

vector<int> rndvct(int len);
