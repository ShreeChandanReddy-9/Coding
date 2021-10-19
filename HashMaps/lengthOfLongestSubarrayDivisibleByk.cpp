	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>m;
	    int sum=0,maxi=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        if(sum%k==0)
	        {
	            maxi=max(maxi,i+1);
	        }
	        else if(m.find((sum%k+k)%k)==m.end())
	            m[(sum%k+k)%k]=i;
	        else
	            maxi=max(maxi,i-m[(sum%k+k)%k]);
	    }
	    return maxi;
	}
