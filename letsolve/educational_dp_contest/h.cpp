#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define mod 1e9+7
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int h , w; cin>> h >> w;

  char arr[h][w];

  for(int i =0; i<h ; i++){
    for( int j = 0; j < w ; j++){
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(h+1, vector<int>(w+1,0));
  // memset(dp, 0, (h+1)*(w+1)*sizeof(int)
  for( int i = 0 ; i<=h ; i++){
    if(arr[i][0] != '#'){
      dp[i][0] = 1;
    }else{
      break;
    }
  }
  for( int i = 0 ; i<=w ; i++){
    if(arr[0][i] != '#')
    {
       dp[0][i] = 1;
    }else{
       break;
    }
  }

  for(int i = 1; i<=h; i++){
    for(int j = 1; j <=w; j++){
      if(arr[i][j] != '#'){
        if(arr[i-1][j] != '#')
          dp[i][j] += dp[i-1][j] % (1000000007);
        if(arr[i][j-1] != '#')
          dp[i][j] += dp[i][j-1] % (1000000007);
      }
      dp[i][j] = dp[i][j]%(1000000007);
    }
  }

// for(int i = 0; i<=h; i++){
//   for(int j = 0; j <=w; j++){
//     cout<<dp[i][j]<<" ";
//   }
//   cout<<"\n"; 
// }

// for(int i = 0; i<h; i++){
//   for(int j = 0; j <w; j++){
//     cout<<arr[i][j]<<" ";
//   }
//   cout<<"\n";
// }
  cout<< dp[h-1][w-1];

  return 0;
}