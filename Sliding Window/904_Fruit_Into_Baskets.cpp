int totalFruit(vector<int>& fruits) {
        if(fruits.size()==0||fruits.size()==1)
            return fruits.size();
        unordered_map<int,int>m;
        int i=0,j=0;
        int ans=0;
        while(j<fruits.size())
        {
            m[fruits[j]]++;
            if(m.size()<2)
                {ans=max(ans,j-i+1);j++;}
            else if(m.size()==2)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            {
                while(m.size()>2)
                {
                    if(m[fruits[i]]==1)
                        m.erase(fruits[i]);
                    else
                        m[fruits[i]]--;
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
