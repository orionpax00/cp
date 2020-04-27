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
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int lc = 0;
    int maxlc = 0;
    for(int i = 0 ; i < s.length(); i++){
      if (s[i] == 'L') {lc++;maxlc = max(lc, maxlc);}
      else {
        lc = 0;
      }
    }
    cout<<maxlc+1<<"\n";
  }
  return 0;
}