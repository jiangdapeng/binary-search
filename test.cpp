#include <iostream>
#include <time.h>
#include <assert.h>
#include "binsearch.h"

using namespace std;

const int maxsize=1000000;
int x[maxsize];

void timedriver()
{
    int n,algn,repeat;//sizeof array,algorithm,repeat times
    cout<<"input algorithm repeat n"<<endl;
    cin>>algn>>repeat>>n;
    assert(n<maxsize);
    for(int i=0;i<n;++i)
        x[i]=i;
    int start=clock();
    for(int j=0;j<repeat;++j)
    {
        for(int k=0;k<n;++k)
        {
            switch(algn)
            {
                case 0:
                    assert(BinSearch(x,n,k)==k);
                    break;
                case 1:
                    assert(BinSearchR(x,n,k)==k);
                    break;
            }
        }
    }
    double time=(double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"algorithm:"<<algn<<" n:"<<n<<" repeat:"<<repeat<<endl;
    cout<<"time cost:"<<time<<" sec"<<endl;
}

int main()
{
    timedriver();
	return 0;
}
