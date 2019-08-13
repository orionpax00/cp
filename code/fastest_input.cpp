#include <stdio.h> 
#include <algorithm>

using namespace std;

void fastscanint(int &x){
    bool neg=false;
    register int c;
    x = 0;
    c = getchar();
    if(c == '-'){
        neg= true;
        c =getchar();
    }
    for(;(c>47);c=getchar())
        x = (x<<1) + (x<<3) +c -48;

    if(neg)
        x *=-1;
}

int main()
{
    int num_test_case;
    fastscanint(num_test_case);
    while(num_test_case--){
        printf("%d\n",num_test_case);
    }
    return 0;
}