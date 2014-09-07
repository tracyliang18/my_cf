#include<iostream>
#include <vector>

using namespace std;

const int maxn = 10e5;

int n,m,w;

int array[maxn];
int prefixsum[maxn];

void get_minpos(vector<int> &vec);
int get_minsumbypos(int pos, int &startmark);
void update(int start);

void get_minpos(vector<int> &vec)
{
        int min = array[0];
        vec.push_back(0);

        for(int i=1;i<n;++i)
        {
                if(array[i] < min)
                {
                        min = array[i];
                        vec.clear();
                        vec.push_back(i);
                }
                else if (array[i] == min)
                {
                        vec.push_back(i);
                }
        }

        return;
}

int get_minsumbypos(int pos, int &startmark)
{
        int start,end;
        if (pos - w + 1 < 0)
                start = 0;
        else
                start = pos - w + 1;
        if(pos + w - 1 >= n)
                end = n - 1 - w + 1;
        else
                end = pos;
        int min=prefixsum[start+w-1] - prefixsum[start] + array[start];
        int cursum;
        int mark = start;
        for(int i=start+1; i <= end; i++)
        {
                cursum =prefixsum[i+w-1] - prefixsum[i] + array[i];
                if(cursum < min)
                {
                        min = cursum;
                        mark = i;
                }
        }

        startmark = mark;

        return min;
}

void update(int start)
{
        for(int i=start;i<=start+w-1;++i)
        {
                array[i]++;
        }

        for(int i=start,  j=1;i<=start+w-1;++i,++j)
        {
                prefixsum[i] += j;
        }

        for(int i = start + w; i < n; ++i)
        {
                prefixsum[i] += w;
        }

        return;

}
int main()
{
        cin >> n>>m>>w;
        for(int i=0; i < n; ++i)
        {
                cin >> array[i];
        }
        prefixsum[0] = array[0];
        for(int i = 1; i < n; i++)
        {
                prefixsum[i] = prefixsum[i-1] + array[i];
        }
        vector<int> minpos;
        for(int i=0; i < m; ++i)
        {
                minpos.clear();
                get_minpos(minpos);
                vector<int>::iterator it = minpos.begin();
                int mark;
                int tmp;
                int cur;
                int min = get_minsumbypos(*it,tmp);
                ++it;
                mark = tmp;
                for(;it != minpos.end();++it)
                {
                        if((cur = get_minsumbypos(*it,tmp)) < min)
                        {
                                min = cur;
                                mark = tmp;
                        }
                }

                update(mark);
        }
        int min=array[0];
        for(int i=1;i<n;++i)
        {
                if(array[i] < min)
                        min = array[i];
        }

        cout<<min<<endl;

        return 0;
}
