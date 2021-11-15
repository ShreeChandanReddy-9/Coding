int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i=0,j=0;
        int ans=0;
        while(j<s.size())
        {
            m[s[j]]++;
            if(m.size()==j-i+1)
                ans=max(ans,j-i+1);
            else
            {
                while(m.size()!=j-i+1)
                {
                    if(m[s[i]]==1)
                        m.erase(s[i]);
                    else
                        m[s[i]]--;
                    i++;
                }
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
