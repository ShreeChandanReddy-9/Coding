int diffPossible(vector<int> &A, int k) {
        sort(A.begin(),A.end());
    int l=0,h=1;
    while(l<A.size()&&h<A.size())
    {
        if(l!=h&&A[h]-A[l]==k)
        {
            return 1;
        }
        else if(A[h]-A[l]<k)
        {
            h++;
        }
        else
        {
            l++;
        }
    }
    return 0;
}
