#include <bits/stdc++.h>
using namespace std;

#define printv(v) for(auto x: v) cerr<<x<<" ";

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin>>n;
  int a[n];
  for(int i = 0 ; i< n ; i++){
    cin>>a[i];
  }

// method to find the optimal peak I don't know how it works but it works.. :(
  vector<int> s;
  vector<long long> newv(n);
  long long sum=0;
  for(int i = 0 ; i< n; i++){
    while(!s.empty() && a[i] <= a[s.back()]){
      int j = s.back();
      s.pop_back();
      sum -= 1ll * (j-(s.empty() ? -1 : s.back()))*a[j];
    }
    sum += 1ll * (i-(s.empty() ? -1 : s.back()))*a[i];
    newv[i] += sum;
    s.push_back(i);
  }
  // printv(newv);
  // cerr<<"\n";
  sum =0;
  s.clear();

  for(int i = n-1 ; i>=0; i--){
    while(!s.empty() && a[i] <= a[s.back()]){
      int j = s.back();
      s.pop_back();
      sum -= 1ll * ((s.empty() ? n : s.back()) - j)*a[j];
    }
    sum += 1ll * ((s.empty() ? n : s.back()) - i)*a[i];
    newv[i] += sum - a[i];
    s.push_back(i);
  }

  // printv(newv);
  // cerr<<"\n";

  int p = max_element(newv.begin(), newv.end()) - newv.begin();

  for(int i = p-1; i>=0; i--){
    a[i] = min(a[i], a[i+1]);
  }
  for(int i = p+1; i<n; i++){
    a[i] = min(a[i], a[i-1]);
  }
  

  for (int i = 0; i < n; ++i)
    cout << a[i] << " \n"[i == n - 1];
  return 0;
}