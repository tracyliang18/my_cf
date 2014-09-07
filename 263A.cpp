#include<iostream>
#include <vector>

using namespace std;
#define MAXN 102
char map[MAXN][MAXN];
int n;

bool check_bound(int x,int y)
{
        return x>=0 && x < n && y >= 0 && y <n;
}

int get_cnt(char c)
{
        if(c == 'o')
                return 1;

        return 0;
}

bool check(int x,int y)
{
        int cnt=0;
        if(check_bound(x-1,y))
        {
                cnt += get_cnt(map[x-1][y]);
        }

        if(check_bound(x+1,y))
        {
                cnt += get_cnt(map[x+1][y]);
        }

        if(check_bound(x,y-1))
        {
                cnt += get_cnt(map[x][y-1]);
        }

        if(check_bound(x,y+1))
        {
                cnt += get_cnt(map[x][y+1]);
        }

        return cnt % 2 == 0;
}

int main()
{


       bool cool=true;
       bool isbreak = false;

        cin>>n;

        for(int i=0;i<n;++i)
        {
                cin>>map[i];
        }

        for(int i=0;i<n && !isbreak;++i)
                for(int j=0;j<n;++j)
                {
                        if(!check(i,j))
                        {
                                cool=false;
                                isbreak=true;
                                break;
                        }
                }

        if(cool)
                cout<<"YES"<<endl;
        else
                cout<<"NO"<<endl;

        return 0;



}
