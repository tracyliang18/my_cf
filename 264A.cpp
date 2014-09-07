#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
        int x,y;
};
#define MAXN 102
node array[MAXN];
int n,s;
//int cmp(const void *a,const void *b)
//{
//        node *pa = (node *)a;
//        node *pb = (node *)b;
//
//        if(pa->x - pb->x)
//        {
//                return pa->x - pb->x;
//        }
//        else
//        {
//                return pa->y - pb->y;
//        }
//}
int main()
{
        cin>>n>>s;
        for(int i=0;i<n;++i)
                cin>>array[i].x>>array[i].y;

//        qsort(array,n,sizeof(node),cmp);
        int maxchange=-1;
        int cur;
        for(int i=0;i<n;++i)
        {
                cur = -1;
                if(s>array[i].x)
                {
                        if(array[i].y)
                                cur = 100 - array[i].y;
                        else
                                cur=0;

                }
                else if(s == array[i].x)
                {
                        if(array[i].y == 0)
                                cur = 0;
                }

                if(cur > maxchange)
                        maxchange = cur;
        }

        if(maxchange != -1)
                cout<<maxchange<<endl;
        else
                cout<<"-1"<<endl;

        return 0;

}


