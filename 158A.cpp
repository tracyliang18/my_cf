/*
 *
 * A. Adding Digits
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has got two number: a and b. However, Vasya finds number a too short. So he decided to repeat the operation of lengthening number a n times.

One operation of lengthening a number means adding exactly one digit to the number (in the decimal notation) to the right provided that the resulting number is divisible by Vasya's number b. If it is impossible to obtain the number which is divisible by b, then the lengthening operation cannot be performed.

Your task is to help Vasya and print the number he can get after applying the lengthening operation to number a n times.

Input
The first line contains three integers: a, b, n (1 ≤ a, b, n ≤ 10^5).

Output
In a single line print the integer without leading zeros, which Vasya can get when he applies the lengthening operations to number a n times. If no such number exists, then print number -1. If there are multiple possible answers, print any of them.
 */
#include <cstdio>
int a,b,n;
bool found = false;
void add_digit(int,int);
int main()
{
        scanf("%d%d%d",&a,&b,&n);
        add_digit(0,a);
        if(!found)
                printf("-1");

        return 0;
}

char str[100000+1];

void add_digit(int pos,int cura)
{
        if(pos >= n)
        {
                /*success*/
                str[pos]='\0';
                printf("%d%s\n",a,str);
                found = true;
                return;
        }
        int tail;
        int newa;
        for(tail = 0; tail <= 9; ++tail)
        {
                newa = cura*9+tail;
                if (newa % b == 0)
                {
                        str[pos]='0'+tail;
                        add_digit(pos+1,newa/b);
                }
                if(found)
                        return;
        }
}


