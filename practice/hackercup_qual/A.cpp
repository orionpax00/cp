#include <bits/stdc++.h>
//#define int long long

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:",debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
int32_t main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);	

	int t; cin >> t;
	int ii = 1;
	while(t--){
		int n ; cin >> n ;
		vector<char> iv(n);
		vector<char> ov(n);
		for(auto &x: iv) cin >> x;
		for(auto &x: ov) cin >> x;
		cout << "Case #" << ii << ":" << "\n";
	
		vector< vector<char> > ans(n, vector<char>(n, 'N'));
		for(int i = 0 ; i < n ; i++) ans[i][i] = 'Y';
		for(int i = 0 ; i < n ; i++){
			int k = i;
			while(k < n - 1){
				if(ov[k] == 'Y' && iv[k+1] == 'Y') {ans[i][k+1] = 'Y'; k++;}
				else break;
			}
			k = i;
			while(k >= 1){
				if(ov[k] == 'Y' && iv[k-1] == 'Y') {ans[i][k-1] = 'Y'; k--;}
				else break;
			}
		}
			debug(iv);
//		if(ov[0] == 'Y' && iv[1] == 'Y') ans[0][1] = 'Y';
	//	if(ov[n-1] == 'Y' && iv[n-2] == 'Y') ans[n-1][n-2] = 'Y';
//		for(auto x : ans) {
	//		for(char c : x) cout << c;
		//	cout << "\n";
	//	}
		ii++;
	}
    

  return 0;
}
