#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int array[26]={0};

int cmp(const void *a,const void *b)
{
        int *pa = (int *)a;
        int *pb = (int *)b;

        if(*pa > *pb)
                return -1;
        else if(*pa == *pb)
                return 0;

        return 1;
}

int main()
{
        int n,k;
        cin>>n>>k;
        char c;
        for(int i=0;i<n;++i)
        {
                cin>>c;
                array[c-'A'] += 1;
        }
        int cnt=0;
        int pos=0;
        qsort(array,26,sizeof(int),cmp);

        while(k > 0)
        {
                if(k >= array[pos])
                {
                        cnt += array[pos]*array[pos];
                        k -= array[pos];
                }
                else
                {
                        cnt += k*k;
                        k=0;
                }

                pos++;
        }



        cout<<cnt<<endl;

        return 0;
}
