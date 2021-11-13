vector<int> partitionLabels(string s) {
        vector<int>letter(26,0);
        for(int i=0;i<s.size();i++)
            letter[s[i]-'a']=i;
        vector<int>ans;
        int maxID=-1,lowID=0;
        for(int i=0;i<s.size();i++)
        {
            maxID=max(maxID,letter[s[i]-'a']);
            if(i==maxID)
            {
                ans.push_back(i-lowID+1);
                lowID=i+1;
            }
        }
        return ans;
    }
