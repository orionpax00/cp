#include <bits/stdc++.h>

using namespace std;



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



int solve(vector<int> & v){
	long long sum = 0;
	for(int x : v) sum += x;

	if(sum%3) return 0;
	int n = v.size();
	vector<int> v2(n);
	
	v2[0] = v[0];
	for(int i = 1; i < n ; i++) v2[i] = v[i] + v2[i-1];

	long long s = sum/3;
	int t1 = 0, t2 = 0;
	int i = 0;
	bool ok = false;
	for(; i < n - 2; i++){
		if(v2[i] == s) {t1++; ok = true;}
		else{ if(ok) break;}
	}
	ok = false;

	for(int j = 1; j < n - 1; j++){
		if(v2[j] == 2 * s) {t2++; ok = true;}
		else{ if(ok) break;}
	}
		

	debug(t1, t2, v2);

	int ans = t1 * t2;

	return ans;
}




int main(){
		
		int n; cin >> n;
		vector<int> v(n);
		for(int& x: v) cin >> x;
		
		cout << solve(v);

		return 0;
}
