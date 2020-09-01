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

	int n, k, s; cin >> n >> k >> s;
	vector<int> v(n + 1);
	for(int i = 1 ; i <= n; i++){ int t; cin >> t; v[i] = t + v[i - 1];}
	
	int min_len = INT_MAX;
	
	int start = 1;
	debug(v);
	cout << "MIN: ";
	for(int i = 1; i <= n; i++){
		cout << min_len << " ";
		if(i - start < k || s > v[i] - v[start]) continue;
		else{
			int x = v[i] - s;
			while(i - start > k && x > 0){
				if(start >= 0 && start < n){
					x -= v[start]; start++;
				}
			}
			min_len = min(min_len, i - start + 1);
		}
	}		
	cout << endl;
	cout << min_len;

  return 0;
}
