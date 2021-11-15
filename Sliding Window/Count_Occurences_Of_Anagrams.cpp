int search(string pat, string txt) {
	    // code here
	    vector<int>p(26,0),t(26,0);
	    for(int i=0;i<pat.size();i++)
	        p[pat[i]-'a']++;
	    for(int i=0;i<pat.size();i++)
	        t[txt[i]-'a']++;
	    int i=0,j=pat.size();
	    int ans=0;
	    while(j<txt.size())
	    {
	        if(p==t)
	            ans++;
	       t[txt[i++]-'a']--;
	       t[txt[j++]-'a']++;
	    }
	    if(p==t)
	        ans++;
	    return ans;
	}
