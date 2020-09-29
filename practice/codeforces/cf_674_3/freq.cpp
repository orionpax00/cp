#include <bits/stdc++.h>
using namespace std;



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif




void solve(){
	map<char, vector<int>> m;
	string s; cin >> s;
	int n = s.length();
	vector<char> order;
	for(int i = 0; i < n; i++){
		if(m.count(s[i]) == 0) order.push_back(s[i]);
		m[s[i]].push_back(i);
	}
	
	map<int, vector<char>> mc;



	string ans = "";
	string ss = "" ;
	for(char c: order) ans += c, ans += " " , ans += to_string(m[c].size()), ans += " ", ss += c;

	cout << ans << "\n";

	int t; cin >> t;
	vector<int> v(t); for(int& x : v) cin >> x; 
	
	vector<int> visited(30);

	s = ss;
	n = s.length();
	for(int i =0 ; i < (int)s.length(); i++){
		m[s[i]].push_back(i);
	}

	for(auto x: m) 
		mc[x.second.size() - 1].push_back(x.first);

	for(int i = 0; i < t; i++){
		visited.assign(30, 0);
		string pref = "";
		string suff = "";
		string ans = "";
		string middle = "";
		string middle2 = "";
		string mid = "";
		vector<char> vc = mc[v[i]];
		vector<int> vttt;
		string ss = "";

		for(char c : vc){
			int ttt = m[c].back();
			vttt.push_back(ttt);
		}
		debug(vttt);
		int t1 = *min_element(vttt.begin(), vttt.end());
		int t2 = *max_element(vttt.begin(), vttt.end());
			for(int k = t1; k <= t2; k++){
				if(m[s[k]].size() - 1 < v[i]){
					if(!visited[s[k] - 'a'])
						pref += s[k], pref += " ", pref += to_string(m[s[k]].size() - 1), pref += " ";
					visited[s[k] - 'a'] = 1;
				}
				else if(m[s[k]].size() - 1 > v[i]){
					if(!visited[s[k] - 'a']) 
						suff += s[k], suff += " ", suff += to_string(m[s[k]].size() - 1), suff += " ";
					visited[s[k] - 'a'] = 1;
				}
			}
		

		
			for(int j = 0; j <= t1; j++){
				if(m[s[j]].size() - 1== v[i]) continue;
				else if(!visited[s[j] - 'a'])
					middle += s[j], middle += " ", middle += to_string(m[s[j]].size() - 1), middle += " ";
				visited[s[j] - 'a'] = 1;
			}
			for(int j = t2; j < n; j++){
				if(m[s[j]].size() - 1 == v[i]) continue;
				else if(!visited[s[j] - 'a'])
					middle2 += s[j], middle2 += " ", middle2 += to_string(m[s[j]].size() - 1), middle2 += " ";
				visited[s[j] - 'a'] = 1;
			}
			


			for(char c : vc)
				mid += c, mid += " ", mid += to_string(v[i]), mid += " ";

		ans += pref;
		ans += middle;
		ans += mid;
		ans += middle2;
		ans += suff;

		debug(pref);
		debug(middle);
		debug(mid);
		debug(middle2);
		debug(suff);


		cout << ans << "\n";
	
		for(char c: ans)
			if(!isdigit(c) && c != ' ') ss += c;

		s = ss;
		n = s.length();
		for(int i =0 ; i < (int)s.length(); i++){
			m[s[i]].pop_back();
			m[s[i]].push_back(i);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; //cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
