void solve(long long n){	
	if(n==0) {cout << 0 << "\n"; return;}
	string ans = "";
	while(n){
		ans = to_string(n%9) + ans;
		n /= 9;
	}
	cout << ans << "\n";
}
