#include <iostream>

/**
 * binary search
 *
 */
template<class T>
int BinSearch(T x[],int n,T v)
{
	int low=0;
	int high=n-1;
	int m=0;
	int p=-1;
	while(low<=high)
	{
		m=low+(high-low)/2;
		if(v==x[m])
		{
			p=m;
			break;
		}
		else if (v<x[m])
		{
			high=m-1;
		}
		else
			low=m+1;
	}
	return p;
}

/**
 * binary search recursivly
 *
 */
template<class T>
int BinSearchR(T x[],int n,T v)
{
	if(n<1)
		return -1;
	int m=(n-1)/2;
	if(x[m]==v)
		return m;
	else if(x[m]>v)
		return BinSearchR(x,m,v);
	else 
	{
		int p=BinSearchR(x+m+1,n-m-1,v);
		if(p!=-1)
			return m+1+p;
		else
			return -1;
	}
}
