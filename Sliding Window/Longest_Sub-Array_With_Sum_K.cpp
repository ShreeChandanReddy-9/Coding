int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<long long,int>m;
        long long sum=0;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            // m[sum]=i;
            if(sum==K)
                ans=max(ans,i+1);
            if(m.find(sum)==m.end())
                m[sum]=i;
            if(m.find(sum-K)!=m.end())
                ans=max(ans,i-m[sum-K]);
                
        }
        return ans;
    } 
