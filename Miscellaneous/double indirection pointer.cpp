#include <iostream>
using namespace std;

int main()
{
    int var = 50;
    int *ptr1;
    int ** ptr2;
    cout<<"var: " << var<<endl;
    cout<<"address of var: "<< &var<<endl;
    
    ptr1 = &var;
    cout<< "ptr1 val: "<<*ptr1<<endl;
    cout<< "ptr1 reference: " << ptr1<<endl;
    
    ptr2 = &ptr1;
    cout<< "ptr2 address: "<<ptr2<<endl;
    cout<< "*ptr2 address: "<< *ptr2 <<endl;
    cout<<"value: "<< **ptr2<<endl;
    
}