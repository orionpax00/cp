#include <bits/stdc++.h>
#define int long long

using namespace std;

long long occ(int n){
	long long ans = 0;
	for(int i = 0; i <= n ; i++){
		string s = to_string(i);
		for(char c : s){
			if(c - '0' == 0) ans++;
			else if (c - '2' == 0) ans++;
			else if( c - '4' == 0) ans++;
		}
	}
	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	cout << occ(n);
    

  return 0;
}
