#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

bool check(int m){
	if(m < 1 || m == n - 1){
		return false;
	}
	
	if(v[m] > v[m-1] && v[m] > v[m+1]) return true;
	
	return false;
}

int solve(int L, int R){
	int mid, l = L, r = R;
	 while(l < r){
		mid = (l+r)/2;
		if(check(mid)) return mid;
		else if(v[mid] > v[mid + 1]) r = mid;
		else l = mid;
	 }

	 return -1;
}

int main(){
	cin >> n;
	v.resize(n);
	for(auto & x: v) cin >> x;

	int x1 = solve(0, n - 1);
	int x2 = solve(0, x1);
	int x3 = solve(x1 + 1, n - 1);

	vector<int> ans = {x1, x2, x3};
	sort(ans.begin(), ans.end());

	cout << ans[1] << " " << ans[2] << "\n";

	return 0;
}
