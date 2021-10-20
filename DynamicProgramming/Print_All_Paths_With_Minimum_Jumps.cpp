#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct minJumps{
    int i;          
    int s;
    int j;
    string path;
    minJumps(int _i,int _s,int _j,string _path)
    {
        i=_i;
        j=_j;
        s=_s;
        path=_path;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>jumps(n);
    for(int i=0;i<n;i++)
        cin>>jumps[i];
    vector<int>dp(n,INT_MAX);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        int steps=jumps[i];
        
        int mini=INT_MAX;
        for(int j=1;j<=steps;j++)
        {
            if(i+j<n)
            {
                mini=min(mini,dp[i+j]);
            }
        }
        if(mini!=INT_MAX)
            dp[i]=mini+1;
    }
    cout<<dp[0]<<endl;
    deque<minJumps>q;
    q.push_back(minJumps(0,jumps[0],dp[0],"0"));
    while(q.size())
    {
        auto p=q.front();
        q.pop_front();
        if(p.j==0)
            cout<<p.path+" ."<<endl;
        for(int j=1;j<=p.s&&p.i+j<n;j++)
        {
            int ci=p.i+j;
            if(dp[ci]==p.j-1)
            {
                q.push_back(minJumps(ci,jumps[ci],dp[ci],p.path+" -> "+to_string(ci)));
            }
        }
    }
    return 0;
}
