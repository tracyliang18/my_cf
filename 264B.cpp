/*
 * 264B.cpp
 *
 *  Created on: 2014-8-30
 *      Author: tracyliang
 */

#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
int array[MAXN];
int n;
int main()
{
        cin>>n;
        array[0]=0;
        for(int i=1;i<=n;++i)
                cin>>array[i];
        long long energy=0;
        int res=0;
        for(int i=0;i<n;++i)
        {
                energy += array[i]-array[i+1];
                if(energy < 0 )
                {
                        if(-energy > res)
                                res = -energy;
                }

        }
        cout<<res<<endl;

        return 0;
}


