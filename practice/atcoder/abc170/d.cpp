#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int n;cin>>n;
	vector<int> v(n);
 	vector<int> frec(1000001);
	
	for(int i =0 ; i <n ; i++){
		int t; cin>>t; v[i] = t; frec[t]++;
	}
	sort(v.begin(), v.end());
	int ans = n;
	for(int i = 0 ; i < n ; i++){
		if(frec[v[i]] > 1) {ans--; continue;}
		for(int j = 0 ; j < i ; j++){
			if(v[i] % v[j] == 0) {
				ans--;
				break;
			}
		}
				
	}

	cout<<ans;
    

  return 0;
}
