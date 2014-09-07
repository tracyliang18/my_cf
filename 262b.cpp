#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

int a,b,c;
int fx(int sx);
int get_maxsum(int x);
int get_sum(int x);
int get_upbound();

int fx(int sx)
{
        int t = pow((float)sx,a);
        return b*t+c;
}
int main()
{

        cin>>a>>b>>c;
        int bound = get_upbound();
        int count=0;
        vector<int> vec;
        int max_sum = -1;
        int cur_sum;
        for(int i=fx(1);i<=bound;i++)
        {
                cur_sum = get_sum(i);
                if (cur_sum >= max_sum && i ==fx(cur_sum))
                {
                      count++;
                      vec.push_back(i);
                      max_sum = cur_sum;
                }
        }

        cout<<count<<endl;
        if(count > 0)
        {
                for(int i=0;i<count;i++)
                        cout<<vec[i]<<" ";
                cout<<endl;
        }

        return 0;

}
int get_maxsum(int x)
{
        int count = 0;
        while(x > 0)
        {
                x = x/10;
                count++;
        }

        int first_digit = x / ((int)pow((float)10,count-1));

        return first_digit + 9 * (count-1);
}



int get_sum(int x)
{
        int count = 0;
        while(x > 0)
        {
               count += x%10;
                x = x / 10;
        }

        return count;
}


int get_upbound()
{
        int last,now =  fx(81);
        do
        {
                last =now;
                now = fx( get_maxsum(now));
        }while(last <= now);


        return last;
}


