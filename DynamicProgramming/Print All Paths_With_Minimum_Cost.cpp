#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Pair{
    int i;
    int j;
    int c;
    string path;
    Pair(int _i,int _j,int _c,string _path)
    {
        i=_i;
        j=_j;
        c=_c;
        path=_path;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> >g(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    vector<vector<int> >grid(n,vector<int>(m,0));
    grid[n-1][m-1]=g[n-1][m-1];
    for(int i=n-2;i>=0;i--)
        grid[i][m-1]=grid[i+1][m-1]+g[i][m-1];
    for(int i=m-2;i>=0;i--)
        grid[n-1][i]=grid[n-1][i+1]+g[n-1][i];
    for(int i=n-2;i>=0;i--)
        for(int j=m-2;j>=0;j--)
        {
            grid[i][j]=min(grid[i+1][j],grid[i][j+1])+g[i][j];
        }
    cout<<grid[0][0]<<endl;
    queue<Pair>q;
    q.push(Pair(0,0,grid[0][0],""));
    while(q.size())
    {
        auto rem=q.front();
        q.pop();
        if(rem.i==n-1&&rem.j==m-1)
            cout<<rem.path<<endl;
        else if(rem.i==n-1)
        {
            q.push(Pair(n-1,rem.j+1,grid[n-1][rem.j+1],rem.path+"H"));
        }
        else if(rem.j==m-1)
        {
            q.push(Pair(rem.i+1,m-1,grid[rem.i+1][m-1],rem.path+"V"));
        }
        else
        {
            if(grid[rem.i][rem.j+1]<grid[rem.i+1][rem.j])
            {
                q.push(Pair(rem.i,rem.j+1,grid[rem.i][rem.j+1],rem.path+"H"));
            }
            else if(grid[rem.i][rem.j+1]>grid[rem.i+1][rem.j])
            {
                q.push(Pair(rem.i+1,rem.j,grid[rem.i+1][rem.j],rem.path+"V"));
            }
            else
            {
                q.push(Pair(rem.i+1,rem.j,grid[rem.i+1][rem.j],rem.path+"V"));
                q.push(Pair(rem.i,rem.j+1,grid[rem.i][rem.j+1],rem.path+"H"));
            }
        }
    }
    return 0;
}
