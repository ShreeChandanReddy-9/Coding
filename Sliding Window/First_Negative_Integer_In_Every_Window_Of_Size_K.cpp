vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         long long int start=0,end=0;   
         vector<long long>ans;
         queue<long long int>q;
         for(end=0;end<K;end++)
         {
             if(A[end]<0)
                q.push(end);
         }
         for(end=K;end<N;end++,start++)
         {
             if(q.size()==0)
                ans.push_back(0);
            else
            {
                ans.push_back(A[q.front()]);
                if(start==q.front())
                {
                    q.pop();
                }
            }
            if(A[end]<0)
                q.push(end);
         }
         if(q.size()>0)
            ans.push_back(A[q.front()]);
         else
            ans.push_back(0);
         return ans;
 }
