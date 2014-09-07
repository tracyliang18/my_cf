#include<iostream>
#include <vector>

using namespace std;

int n,m,w;
int array[100005];
//#define debug
int main()
{
        int min;
        int mark;
        int i,j,k;
        cin>>n>>m>>w;
        for(i=0; i < n; ++i)
        {
                cin >> array[i];
        }

        for(j=0;j<m;j++)
        {
                min = array[0];
                mark = 0;
                for(i=1;i<n;i++)
                {
                        if(array[i] < min)
                        {
                                min = array[i];
                                mark = i;
                        }
                }
                for( k=mark;k <=mark + w - 1 && k < n; ++k)
                {
                        ++array[k];
                }

#ifdef debug
                for(int z=0;z<n;++z)
                        cout<<array[z]<<" ";
                cout<<endl;
#endif
        }
        min = array[0];
        for(i=1;i<n;++i)
        {
                if(array[i] < min)
                        min = array[i];
        }

        cout << min << endl;

        return 0;
}
