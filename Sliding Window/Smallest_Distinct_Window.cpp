string findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>p,t;
        for(int i=0;i<str.size();i++)
            p[str[i]]++;
        int ans=INT_MAX;
        string ansString;
        int i=0,j=0;
        while(j<str.size())
        {
            t[str[j]]++;
            if(t.size()<p.size())
                j++;
            else if(t.size()==p.size())
            {
                while(t.size()==p.size())
                {
                    if(ans>j-i+1)
                    {
                        ans=j-i+1;
                        ansString = str.substr(i,j-i+1);
                    }
                    if(t[str[i]]==1)
                        t.erase(str[i]);
                    else
                        t[str[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ansString;
    }
