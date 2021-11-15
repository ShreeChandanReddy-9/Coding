int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0)
                nums[i]+=nums[i-1];
            if(nums[i]==goal)
                ans++;
            if(m.find(nums[i]-goal)!=m.end())
                ans+=m[nums[i]-goal];
            m[nums[i]]++;
        }
        return ans;
    }
