static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end(),cmp);
        
        int n = a.size();
        if(n==0) return {};
        
        int f = a[0][0];
        int l = a[0][1];
    
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++){
            if(l >= a[i][0]) l = max(l, a[i][1]);
            else{
                ans.push_back({f, l});
                f = a[i][0];
                l = a[i][1];
            }
        }
        
        ans.push_back({f, l});
                    
       return ans; 
    }
