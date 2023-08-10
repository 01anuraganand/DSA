#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    vector<int> isPrime(3001, 1);
    vector<int> smallestPrimeFactor(3001, -1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    
    for(int i = 2; i*i<= 3000; i++)
    {
        if(isPrime[i])
        {
            for(int j = i; i*j <= 3000; j++)
            {
                
                isPrime[i*j] = 0;
                smallestPrimeFactor[i*j] = i;
            }
        }
    }
    
    vector<int> prefixCountOfDivisors(3001, 0);
    int countDiv = 0;
    for(int i = 1; i<=3000; i++)
    {
        int count = 0;
        int n = i;
        while(smallestPrimeFactor[n] != -1)
        {
            int smf = smallestPrimeFactor[n];
            
            while(n % smf == 0)
            {
                n /= smf;
            }
            count++;
        }
        if(n != 1)
            count++;
        if(count == 2)
            prefixCountOfDivisors[i] += ++countDiv;
        else
            prefixCountOfDivisors[i] = countDiv;
    }
    
    int n;
    cin>>n;
    cout<<prefixCountOfDivisors[n]<<endl;
    
    return 0;
}