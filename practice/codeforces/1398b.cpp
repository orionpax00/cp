#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename A>
string tostring(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail >
void debug_out(Head H, Tail... T) {
	cerr << " " << tostring(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int c = 0;
		vector<int> v;
		for(int i = 0; i < (int)s.length();){
			while(i < (int)s.length() && s[i] == '1'){
				c++; i++;
			}
			if(s[i] != '1') i++;
			v.push_back(c);
			c = 0;
		}
//		debug(v, v);
		sort(v.begin(), v.end(), greater<int>());
		int ans1 = 0;
		int ans2 = 0;
		for(int i = 0 ; i < (int)v.size(); i++){
			if(i&1) ans2 += v[i];
			else ans1 += v[i];
		}
		cout << ans1 << "\n";
	}

  return 0;
}
