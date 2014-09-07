/*
 * Flipping_Game.c
 *
 *  Created on: 2013-7-4
 *      Author: tracyliang
 */


#define MAXN 100

#include <iostream>

using namespace std;


int zerooneContinuous[MAXN];
int count;

int main()
{
        int i,j,last,tmp;
        int start,cursum;
        int max;
        int mark_start,mark_end;
        int res;
        int beginonecount=0;
        cin>>count;
        for(i = 0; i < count; ++i)
        {
                cin>>tmp;
                if(tmp == 0)
                        break;
                ++beginonecount;
        }

        if(i == count)
        {
                cout<<count-1<<endl;
                return 0;
        }

        j=0;
        ++i;
        zerooneContinuous[0]=1;
        while(i<count)
        {
                last = tmp;
                while(i<count)
                {
                        cin>>tmp;
                        ++i;
                        if(tmp == last)
                        {
                                zerooneContinuous[j]++;
                        }
                        else
                        {
                                ++j;
                                zerooneContinuous[j]=1;
                                break;
                        }
                }

        }

        for(i=1; i <= j; i+=2)
                zerooneContinuous[i] = -zerooneContinuous[i];
#ifdef DEBUG
        for(i=0;i<=j;++i)
                cout<<zerooneContinuous[i]<<endl;
#endif


        max = 0;
        i=0;
        cursum = 0;
        start = 0;
        while(i <= j)
        {
                while(cursum >=0 && i <= j)
                {
                        cursum += zerooneContinuous[i];
                        if(cursum > max)
                        {
                                mark_start = start;
                                mark_end = i;
                                max=cursum;
                        }
                        ++i;
                }

                cursum = cursum - zerooneContinuous[start] - zerooneContinuous[start+1];
                start += 2;
        }
        res=0;
        for(i=0;i<=j; ++i)
        {
                if(i % 2 == 0)
                {
                        if(i >= mark_start && i <= mark_end )
                                res += zerooneContinuous[i];
                }
                else
                {
                        if(i < mark_start || i > mark_end )
                                res += -zerooneContinuous[i];
                }
        }
        cout<<res+beginonecount<<endl;
        return 0;
}
