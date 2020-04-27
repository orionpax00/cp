#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n ;
  int inf = 1e8+7;
  unordered_map<string, int> dp={
    {"A",inf},
    {"B",inf},
    {"C",inf},
    {"AB",inf},
    {"AC",inf},
    {"BC",inf},
    {"ABC",inf},
  };
  for(int i = 0 ; i < n ; i++){
    int t; string s; cin >> t >> s;
    sort(s.begin(), s.end());
    dp[s] = min(dp[s], t);
  }
  int ans1 = dp["A"]+dp["B"]+dp["C"];
  int ans2 = min({dp["AB"] + dp["C"], dp["AB"] + dp["BC"],dp["AB"] + dp["AC"] });
  int ans3 = min({dp["AC"] + dp["B"],dp["AC"] + dp["AB"], dp["AC"] + dp["BC"],});
  int ans4 = min({dp["BC"] + dp["A"], dp["BC"] + dp["AB"], dp["BC"] + dp["AC"]});
  int ans5 = dp["ABC"];
  int ans = min({ans1, ans2, ans3, ans4, ans5});
  ans = {ans == inf ? -1 : ans};
  cout<< ans;
  return 0;
}