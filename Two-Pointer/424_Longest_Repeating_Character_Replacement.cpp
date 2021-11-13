int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int maxf=0;
        int start=0,end=0;
        for(end=0;end<s.size();end++)
        {
            count[s[end]-'A']++;
            maxf=max(maxf,count[s[end]-'A']);
            if(end-start+1>maxf+k)
            {
                count[s[start]-'A']--;
                start++;
            }
        }
        return s.size()-start;
    }
