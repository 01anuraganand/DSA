#include <iostream>
#include <set>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int> a;
        for(int i = 0; i<n; i++)
        { 
            int val;
            cin>>val;
            a.insert(val);
        }
        int count = 0;
        while(!a.empty())
        {
            
            int num = *a.rbegin();
            a.erase(num);
            if(num % 2 == 0)
            {    
                a.insert(num/2);
                count++;
            }
        }
        cout<<count<<endl;   
    }
}