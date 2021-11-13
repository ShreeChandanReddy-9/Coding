int solve(vector<int> &A, int B) {
    int l=0,h=0,n=A.size();
    int sum=A[0],ans=0;
    while(l<n&&h<n)
    {
        if(sum<B)
        {
            h++;
            if(h>=l)
                ans+=h-l;
            if(h<n)
                sum+=A[h];
        }
        else if(sum>=B)
        {
            // l++;
            sum-=A[l];
            l++;
        }
    }
    return ans;
}
