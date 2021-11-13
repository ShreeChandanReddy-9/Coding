int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans=INT_MAX;
    int a,b,c;
    for(int i=0;i<A.size();i++)
    {
        a=A[i];
        b=*lower_bound(B.begin(),B.end(),A[i]);
        c=*lower_bound(C.begin(),C.end(),A[i]);
        ans=min(ans,max(abs(a-b),max(abs(b-c),abs(c-a))));
    }
    for(int i=0;i<B.size();i++)
    {
        a=*lower_bound(A.begin(),A.end(),B[i]);
        b=B[i];
        c=*lower_bound(C.begin(),C.end(),B[i]);
        ans=min(ans,max(abs(a-b),max(abs(b-c),abs(c-a))));
    }
    for(int i=0;i<C.size();i++)
    {
        a=*lower_bound(A.begin(),A.end(),C[i]);
        b=*lower_bound(B.begin(),B.end(),C[i]);
        c=C[i];
       ans=min(ans,max(abs(a-b),max(abs(b-c),abs(c-a))));
    }
    return ans;
}
