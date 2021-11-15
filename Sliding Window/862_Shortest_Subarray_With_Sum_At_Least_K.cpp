int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();int res=n+1;
        deque<int>q;
        for(int i=0;i<n;i++)
        {
            if(i>0)
                nums[i]+=nums[i-1];
            if(nums[i]>=k)
                res=min(res,i+1);
            while(q.size()>0&& nums[i]-nums[q.front()]>=k)
                res=min(res,i-q.front()),q.pop_front();
            while(q.size()>0&&nums[i]<=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        if(res==n+1)
            return -1;
        return res;
    }
