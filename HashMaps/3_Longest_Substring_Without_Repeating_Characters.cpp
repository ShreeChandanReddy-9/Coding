    int lengthOfLongestSubstring(string s) {
        int j=0,i=0;
        unordered_map<char,int>m;
        int ans=0;
        for(i=0;i<s.size();i++)
        {
            m[s[i]]++;
                while(m[s[i]]>1)
                {
                    m[s[j]]--;
                    j++;
                }
            ans=max(ans,i-j+1);  
        }
        return ans;
    }
