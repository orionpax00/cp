#include <bits/stdc++.h>
using namespace std;

int digit(long long n){
	int ans = 0;
	while(n){
		n /= 10;
		ans++;
	}
	return ans;
}

void solve(long long n){	
	if(n < 10) {cout << n << "\n"; return;}
	int digits = digit(n);
	
	int c = 0;
	int digits2 = digits;
	while(digits--){
		c++;
		cout << c ;
	}
	c--;
	while(digits2--){
		c--;
		cout << c;
	}

	cout << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	//int tt = 1; cin >> tt;
	ifstream iFile("input.txt");

	while(true){
		long long n; iFile >> n;
		if(iFile.eof()) break;
		solve(n);
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
