int longestKSubstr(string s, int k) {
    // your code here
    int ans=-1;
    int i=0,j=0;
    unordered_map<char,int>m;
    while(j<s.size())
    {
        m[s[j]]++;
        if(m.size()<k)
        {
            j++;
        }
        else if(m.size()==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(m.size()>k)
        {
            while(m.size()>k)
            {
                if(m[s[i]]==1)
                    m.erase(s[i]);
                else
                    m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
    }
    return ans;
    }
