#include <iostream>
#include <vector>
using namespace std;

// Factorial of N Natural Number

class Factorial
{public:

    // RR : factorial(N-1)*N;
    //Start from last number
    int factorialNL(int number)
    {
        if(number == 0) return 1;
        return factorialNL(number-1)*number;
    }

    // RR : N*factorial(N+1);
    // Start from index = 1 to N
    int factorialNF(int index, int number)
    {
        if(index == number) return number;
        return index * factorialNF(index + 1, number);
    }

};

// 

int main()
{
    int N = 5;
    Factorial obj;
    cout<<obj.factorialNL(N)<<endl;
    cout<<obj.factorialNF(1, N)<<endl;
}