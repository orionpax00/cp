#include <bits/stdc++.h>
//#define int long long

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


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--){
		string s; cin >> s;
		int n = s.length();
		//vector<int> v(26);
		map<char, int> m;
	//	vector<int> v(n + 1);
		
		for(int i = 0; i < n; i++){
			m[s[i]]++;
		}
		
		int diff = m.size();
		int ml = INT_MAX;
		string ans;
		for(int i = 0 ; i < n ; i++){
			int count = 0;
			vector<int> visited(256);
			string sub_str = "";
			for(int j = i; j < n; j++){
				if(visited[s[j] - 'a'] == 0){
					count++;
					visited[s[j] - 'a'] = 1;
				}
				sub_str += s[j];
				if(count == diff) break;
			}
			if((int)sub_str.length() < ml && count == diff) ans == sub_str;
		}
		string fans = "";
		cout << ans << "\n";
		for(char x : ans){
			fans += to_string(x - 'a' + 1);
		}

		cout << fans << "\n";
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
