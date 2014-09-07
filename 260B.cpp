/*
 *
 * B. Ancient Prophesy
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A recently found Ancient Prophesy is believed to contain the exact Apocalypse date. The prophesy is a string that only consists of digits and characters "-".

We'll say that some date is mentioned in the Prophesy if there is a substring in the Prophesy that is the date's record in the format "dd-mm-yyyy". We'll say that the number of the date's occurrences is the number of such substrings in the Prophesy. For example, the Prophesy "0012-10-2012-10-2012" mentions date 12-10-2012 twice (first time as "0012-10-2012-10-2012", second time as "0012-10-2012-10-2012").

The date of the Apocalypse is such correct date that the number of times it is mentioned in the Prophesy is strictly larger than that of any other correct date.

A date is correct if the year lies in the range from 2013 to 2015, the month is from 1 to 12, and the number of the day is strictly more than a zero and doesn't exceed the number of days in the current month. Note that a date is written in the format "dd-mm-yyyy", that means that leading zeroes may be added to the numbers of the months or days if needed. In other words, date "1-1-2013" isn't recorded in the format "dd-mm-yyyy", and date "01-01-2013" is recorded in it.

Notice, that any year between 2013 and 2015 is not a leap year.

Input
The first line contains the Prophesy: a non-empty string that only consists of digits and characters "-". The length of the Prophesy doesn't exceed 105 characters.

Output
In a single line print the date of the Apocalypse. It is guaranteed that such date exists and is unique.
 */
#include <cstring>
int max_m = {31,28,31,30,31,30,31,31,30,31,30,31};

int strToNum(char *str)
{
        int len,num;
        len = strlen(str);
        int weight;
        int i;
        for(i = len-1, num=0, weight=1; i >= 0; --i, weight *= 10)
        {
                num += (str[i] - '0')*weight;
        }

        return num;
}

int GetYear(char *year)
{
        int y = strToNum(year);
       if(y >= 2013 && y <= 2015)
               return y;
       else
               return -1;
}

int GetMonth(char *month, char *day)
{
        int m = strToNum(month);
       if( m >= 1 && m <= 12 )
               return m;
       return -1;
}

int GetDay(char *day, int m)
{
        int d = strToNum(day);
        if ( d >= 1 && d <= max_m[m-1])
                return d;
        else
                return -1;
}


char inputString[100000 + 1];
int main()
{
        scanf("%s",inputString);
        int pos=0;
        int len=strlen(inputString);
        while(pos < len)
        {
                while(inputString[pos] != '-' && pos < len) pos++;
                if(pos + 2 < len && inputString[pos+2] == '-')
                        nextPos = pos+2;

        }
}

