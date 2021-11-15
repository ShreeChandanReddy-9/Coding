vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int>q;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            while(q.size()>0&& a[q.back()]<a[i])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(a[q.front()]);
        for(int i=k;i<a.size();i++)
        {
            if(q.front()==i-k)
                q.pop_front();
            while(q.size()>0&& a[q.back()]<a[i])
                q.pop_back();
            q.push_back(i);
            ans.push_back(a[q.front()]);
        }
        return ans;
    }
