#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>> cell(n, vector<char>(m));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cin>>cell[i][j];
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(cell[i][j] == '.')
            {
                if((i+j) % 2 == 0)
                    cell[i][j] = 'B';
                else
                    cell[i][j] = 'W';
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            cout<<cell[i][j];
        cout<<endl;
    }
}