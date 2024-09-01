 unordered_map<int,int> mp;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end())
            {
                mp[arr[i]]++;
            }
            else 
            {
                mp[arr[i]]=1;
            }
        }
        pair<int,int> ct;
        ct.first=arr[n-1];
        ct.second=mp[arr[n-1]];
        st.push(ct);
        vector<int> ans(n);
        int i=n-1;
        while(i>=0)
        {
            pair<int,int> ct=st.top();
            int k=mp[arr[i]];
            while(st.size()>0&&ct.second<=k)
            {
              st.pop();
             if(st.size()>0) ct=st.top();
            }
            if(st.size()==0)
            { 
              ans[i]=-1;
            }
            else if(ct.second>k)
            {
              pair<int,int> mt=st.top();
              ans[i]=mt.first;
            }
            pair<int,int>pt;
            pt.first=arr[i];
            pt.second=k;
            st.push(pt);
            i--;
        }
        return ans;
