#include <bits/stdc++.h>
using namespace std;

int main()
{   int n = 17;
    n++;
    int count = 0;
    for(int x = 2; x/2 <n; x = x*2)
    {
        int quotient = n/x;
        count += quotient * x/2;
        int remainder = n%x;
        if (remainder > x/2)
            count += remainder - x/2;
    }
    cout<< count;
}