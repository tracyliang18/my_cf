#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

/**
 * 按制定顺序遍历叶子节点，且要求每条边只能访问两遍，输出2n-1个顶点访问序列，否则输出-1
 *
 * 树作为一种特殊的无向图（不可能有两个节点同时只想你）
 *
 * 树里任意两个节点的最小距离是固定的。（相互不断向上寻找父亲直到相交）
 *
 * 证明为何每条边只访问两次的约束去从root出发按序访问叶子节点并最后回到root的路径一定包含2n-1个节点（n为书的总节点数）
 *
 * 设k个叶子节点 n-k个非叶子
 *
 * 首先证明一棵树一定可以从根出发然后每天边访问两遍回到根
 *
 * 访问节点数 = 所有叶子访问一次 + 所有非叶子节点入度  + 所有非叶子节点出度 = 2n-1
 * k + (n-k) + n-1 = 2n - 1
 *
 */
const int mm=310;
int f[mm],ff[mm],q[mm];
vector<int>g[mm],p;
int n;
void dfs(int u,int fa)
{
  f[u]=fa;///存路径
  for(int i=0;i<g[u].size();i++)
    if(g[u][i]^fa)
    dfs(g[u][i],u);
}
void add(int u,int v)///增加从u到v的路径
{ memset(ff,0,sizeof(ff));
  memset(q,0,sizeof(q));
  int k=0;
  while(v>0){ff[v]=k;q[k++]=v;v=f[v];}///从v开始回找记录
  while(u>0)///有解
  {
    if(ff[u]>0)///从u开始到v有路径
    {
      for(int i=ff[u]-1;i>=0;i--)p.push_back(q[i]);
      break;
    }
    ///如果当前u到v没路径，继续下走
    u=f[u];
    p.push_back(u);
  }
}
int main()
{
  while(cin>>n)
  { int a,b;
     p.clear();
    for(int i=0;i<mm;i++)g[i].clear();
    for(int i=0;i<n-1;i++)
    {
      cin>>a>>b;g[a].push_back(b);g[b].push_back(a);
    }
      dfs(1,-1);///遍历一遍，存遍历路径
      //cout<<"yes";
      int u=1,v;
      for(int i=2;i<=n;i++)
        if(g[i].size()==1)
        { int z;cin>>z;
          add(u,z);u=z;
        }
        ///cout<<'U'<<u<<endl;
        add(u,1);
        n=n+n-1;
        if(p.size()!=n)cout<<"-1\n";
        else
        {
          cout<<1;
          for(int i=0;i<p.size()-1;i++)
            cout<<" "<<p[i];
          cout<<"\n";
       }
  }
}

