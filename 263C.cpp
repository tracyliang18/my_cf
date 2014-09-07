#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cmp(const void *a,const void *b)
{
        int *pa = (int *)a;
        int *pb = (int *)b;

        if(*pa > *pb)
                return 1;
        else if(*pa == *pb)
                return 0;

        return -1;
}

#define MAXN 300005
int array[MAXN];
int main()
{
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
                cin>>array[i];
        qsort(array,n,sizeof(int),cmp);
        int depth = ceil(log(n)/log(2))+1;
        int score=0;
        for(int i=0;i<n;++i)
                score += array[i]*(depth-1);

        int k=2*(n - pow(2,(int)(log(n)/log(2))));

        //cout<<"K "<<k<<endl;

        for(int i=0; i <k;++i)
        {
                score += array[n-1-i];
        }

        if(n==1)
                cout<<array[0]<<endl;
        else
                cout<<score<<endl;

        return 0;

}
