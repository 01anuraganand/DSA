#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, m;
    cin>> n >> m;
    unordered_map<string, string> mpp;
    for(int i = 0; i<n; i++)
    {
        string name, ip;
        cin>>name >> ip;
        mpp[ip] = name;
    }
    
    
    for(int i = 0; i<m; i++)
    {   
        string command, ip;
        cin>> command >> ip;
        ip.pop_back();
        cout<<command << " "<< ip<<"; #"<< mpp[ip]<<endl;  
    }
}