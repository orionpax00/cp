#include <bits/stdc++.h>
#define int long long
int M = 1e9 + 7;
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n; cin >> n;
	vector<int> a(n); vector<int> r(n);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	for(int i = 0 ; i < n; i++){
		cin >> r[i];
	}

	int min_ = INT_MAX;
	int min_idx = 0;
	for(int i = 0; i < n ;i++){
		if(a[i] < min_){
			min_idx = i;
			min_ = a[i];
		}
	}
	bool isamin = false;
	for(int i = 0; i < n ;i++){
		if(r[i] < min_){
			min_idx = i;
			min_ = r[i];
			isamin = true;
		}
	}
	///cerr << min_ << " : " << min_idx;  
	int ans = 0;
	min_ %= M;
	if(isamin){
		for(int i = 0 ; i < n ; i++){
			if(i == min_idx) continue;
			else{
				ans += ((a[i]%M) * min_)%M;
		//		cerr << i << ": " << ans << "\n"; 
    	}
		}
	}else{
		for(int i = 0 ; i < n ; i++){
			if(i == min_idx) continue;
			else{
				ans += ((r[i] % M) * min_)%M;
			}
		}
	}

	cout << ans << "\n";	

  return 0;
}
