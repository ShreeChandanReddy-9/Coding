vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int>m;
        int i=0,j=k;
        for(int l=0;l<k;l++)
            m[A[l]]++;
        vector<int>ans;
        while(j<n)
        {
            ans.push_back(m.size());
            m[A[j++]]++;
            if(m[A[i]]==1)
                m.erase(A[i]);
            else
                m[A[i]]--;
            i++;
        }
        ans.push_back(m.size());
        return ans;
    }
