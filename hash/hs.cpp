#include <iostream>

int hash(long num, int slot)
{
	return num % slot;
}

int main()
{
    int slot, length;
	std::cin >> slot >> length;
	int ary[slot];
	long ipt[length];
	for (int i=0; i<slot; i++)
	{
		ary[i] = -1;
	}

	for (int i=0;i<length;i++)
	{
		long num;
		std::cin >> num;
		ipt[i] = num;
	}

	for (int i=0; i<length; i++)
	{
		int hsrst;
		hsrst = hash(ipt[i], slot);
		if (ary[hsrst] != -1)
		{
			std::cout << i+1;
			return 0;
		}
		else
		{
			ary[hsrst] = ipt[i];
		}
	}
	std::cout << -1;
	return 0;
}
