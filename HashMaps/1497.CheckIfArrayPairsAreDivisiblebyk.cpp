    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
            m[(arr[i]%k+k)%k]++;
        if(m[0]%2!=0)
            return false;
        if(k%2==0&&m[k/2]%2!=0)
            return false;
        for(int i=1;i<=k/2;i++)
            if(m[i]!=m[k-i])
                return false;
        return true;
    }
