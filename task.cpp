    #include <bits/stdc++.h>
     
    using namespace std;
     
    void solution(vector<int> s,int n){
    	int ans = 0;
    	vector<int> arr2(n+1,0);
    	for (int i = 0; i < n-1; i++)
    	{
    		if(arr2[s[i]]) continue;
    		else{
    			arr2[s[i]]=1;
    			vector<int> arr(n+1,0);
    			for (int j = i+1; j < n; j++)
    			{
    				if(arr[s[j]]) continue;
    				else {arr[s[j]]=1; ans++;}
    			}		
    		}
    	}
    	cout<<ans;	
    }
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
    	int n;cin>>n;
    	vector<int> v(n);
    	for (size_t i = 0; i < n; i++)
    	{
    		cin>>v[i];
    	}
    	solution(v,n);
    	return 0;
    }