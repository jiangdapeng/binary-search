#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
static int MASK = 1;
static const int BLOCK_SIZE=32;
static const int BUFF_SIZE=10^7;
static int bg[BUFF_SIZE/BLOCK_SIZE+1];

/**
 * clear all bits to zero
 * */
void clear()
{
	memset(bg,0,sizeof(bg)/sizeof(bg[0]));	
}

/**
 * set bits n to 1
 * n counting from zero
 */
void set(int n)
{
	bg[n/BLOCK_SIZE] |= MASK << (n%BLOCK_SIZE);
}

/**
 * test whether bit n is 1
 */
bool test(int n)
{
	return (bg[n/BLOCK_SIZE] & (MASK <<  (n%BLOCK_SIZE)))!=0 ;
}

int main()
{
	ifstream data("data.txt");
	int tmp;
	int max=0;
	clear();
	while(data>>tmp)
	{
		cout<<tmp<<endl;
		set(tmp);
		max=tmp>max?tmp:max;
	}
	ofstream result("r.txt");
	for(int i=0;i<=max;++i)
	{
		cout<<"i="<<i<<endl;
		if(test(i))
		{
			result<<i<<endl;
		}
	}
}
