#include<bits/stdc++.h>
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
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]", debug_out(__VA_ARGS__) 
#else
#define debug(...) 1
#endif

int main() {
	vector<char> v= {'1','2','4','5','a'};
	debug(v, v);
	return 0;
}
