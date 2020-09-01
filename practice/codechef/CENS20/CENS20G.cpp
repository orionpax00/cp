#include <bits/stdc++.h>
//#define int long long

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

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int a, b; cin >> a >> b;
		int n = s.length();
		vector< int > v(4,0); 
   
		for(int i = 0; i < n; i++){
			if(s[i] == 'L') v[0]++;
			else if(s[i] == 'R') v[1]++;
			else if(s[i] == 'U') v[2]++;
			else v[3]++;
		}


		int q; cin >> q;
		while(q--) {
			long long x2,y2;
			cin>>x2>>y2;
			long long reqX = (x2-a);
			long long reqY = (y2-b);
			bool satX=false, satY=false;
			///how to check for quadrants in 2d if origin is shifted at x1, y1
			if(reqX > 0) {
				if(reqX <= v[1])
					satX = true;
			}
			else if(reqX < 0) {
				if(abs(reqX) <= v[0])
					satX = true;
			}
			else
				satX=true;
 
			if(reqY > 0) {
				if(reqY <= v[2])
					satY = true;
			}
			else if(reqY < 0) {
				if(abs(reqY) <= v[3])
					satY = true;
			}
			else
				satY=true;
 
			if(satX && satY) {
				cout<<"YES "<<abs(reqX) + abs(reqY)<<"\n";
			}
			else
				cout<<"NO\n";
		}
	}
  return 0;
}
