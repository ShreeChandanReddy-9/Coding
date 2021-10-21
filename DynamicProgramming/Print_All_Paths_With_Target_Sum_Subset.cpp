#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Pair{
    int i;
    int j;
    string s;
    Pair(int _i,int _j,string _s)
        {i=_i;
        j=_j;
        s=_s;    
        }
};
int main()
{
    int n,tar;
    cin>>n;
    vector<int>ele(n);
    for(auto &x:ele)
        cin>>x;
    cin>>tar;
    vector<vector<int> >grid(n+1,vector<int>(tar+1,0));
    for(int i=0;i<=n;i++)
        grid[i][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=tar;j++)
        {
            if(grid[i-1][j]==1)
                grid[i][j]=1;
            if(j==ele[i-1])
                grid[i][j]=1;
            else if(j>ele[i-1]&&grid[i-1][j-ele[i-1]]==1)
                grid[i][j]=1;
        }
    if(grid[n][tar]==1)
        cout<<"true"<<endl;
    else
    {
        cout<<"false"<<endl;
        return 0;
    }
    queue<Pair>q;
    q.push(Pair(n,tar,""));
    while(q.size())
    {
        auto rem=q.front();
        q.pop();
        if(rem.i==0||rem.j==0)
            {cout<<rem.s<<endl;continue;}
        if(rem.j>ele[rem.i-1]>=0&&grid[rem.i-1][rem.j-ele[rem.i-1]]==1)
            q.push(Pair(rem.i-1,rem.j-ele[rem.i-1],to_string(rem.i-1)+" "+rem.s));
        if(grid[rem.i-1][rem.j]==1)
            q.push(Pair(rem.i-1,rem.j,rem.s));
        
    }
    return 0;
}
