int Solution::maxArea(vector<int> &A) {
    if(A.size()==0||A.size()==1)
        return 0;
    int l=0,h=A.size()-1;
    int ans=INT_MIN;
    while(l<h)
    {
        ans=max(ans,(h-l)*min(A[l],A[h]));
        if(A[l]<A[h])
            l++;
        else if(A[h]<A[l])
            h--;
        else
            l++,h--;
    }
    return ans;
}
