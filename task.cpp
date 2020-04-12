#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, w;cin >> n >> w;
  int arr[n][2];

  for(int i =0 ; i< n ; i++){
    cin>>arr[i][0] >> arr[i][1]; 
  }
  vector<long long> dp(w+1, 0);

  for(int i=0; i <=w ; i++){
    for(int j=0; j<n; j++){
      if(!istaken[i-arr[j][0]] && i-arr[j][0] >= 0){
        dp[i] = max(dp[i], dp[i- arr[j][0]]+arr[j][1]);
        istaken[i] = 1;
      }
    }
    for(int x: istaken) cout<<x<<" ";
    cout<<"\n";
  }
  cout<<dp[3];

  return 0;
}

