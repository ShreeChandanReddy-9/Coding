int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int> >ma(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++)
            ma[m-1][i]=matrix[m-1][i],ans+=ma[m-1][i];
        for(int i=0;i<m;i++)
            ma[i][n-1]=matrix[i][n-1],ans+=ma[i][n-1];
        if(ma[m-1][n-1]==1)
            ans--;
        for(int i=m-2;i>=0;i--)
            for(int j=n-2;j>=0;j--)
            {
                if(matrix[i][j]==1)
                {
                    ma[i][j]=min(ma[i+1][j],min(ma[i+1][j+1],ma[i][j+1]))+1;
                    ans+=ma[i][j];
                }
            }
        return ans;
    }
