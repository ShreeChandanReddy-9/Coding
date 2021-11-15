bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size())
            return false;
        int k=s1.size();
        vector<int>p(26,0),t(26,0);
        for(int i=0;i<s1.size();i++)
            p[s1[i]-'a']++;
        for(int i=0;i<s1.size();i++)
            t[s2[i]-'a']++;
        int start=0;
        for(int i=k;i<s2.size();i++)
        {
            if(p==t)
                return true;
            t[s2[start++]-'a']--;
            t[s2[i]-'a']++;
        }
        if(p==t)
            return true;
        return false;
    }
