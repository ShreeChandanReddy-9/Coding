int toyCount(int N, int K, vector<int> arr)
    {
        // code here
        int i=0,j=0;
        int ans=0;
        int sum=0;
        sort(arr.begin(),arr.end());
        while(j<arr.size())
        {
            sum+=arr[j];
            if(sum<=K)
                ans=max(ans,j-i+1);
            else 
            {
                while(sum>K)
                {
                    sum-=arr[i];
                    i++;
                }
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
