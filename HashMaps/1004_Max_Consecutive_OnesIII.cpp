int longestOnes(vector<int>& nums, int k) {
        int zero_count=0;
        int ans=0,l=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero_count++;
            if(zero_count<=k)
                ans=max(ans,i-l);
            else
            {
                while(zero_count>k)
                {
                    l++;
                    if(nums[l]==0)
                        zero_count--;
                }
            }
        }
        return ans;
    }
