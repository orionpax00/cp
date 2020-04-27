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
  
  unordered_set<char> se;
  string s;
  int n,k;
  cin >> n>> k >> s;
  for(int i = 0; i < k ; i++){
    char c;
    cin>>c;
    se.insert(c);
  }
  int arr[n];
  long long int counter = 0;
  long long int ans=0;
  for(int i=0; i<n;i++){
    if(se.count(s[i]) != 0){
      counter++;
    }else{
      ans += ((counter) * (counter+1))/2;
      counter = 0;
    }
  }
  ans += ((counter) * (counter+1))/2;

  cout<<ans;
  
  return 0;
}
