#include <bits/stdc++.h>

using namespace std;

bool disgitsum(int n){
  int sum=0;
  while(n){
    sum += n%10;
    n /=10;
  }
  return (sum == 10 ? true : false);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  long long int ans=19;
  int i=1;
  while(i<=n){  
    int tans = ans;
    bool found = false;
    while(true && !found){
      if(disgitsum(tans)){
        i++;
        ans = tans+1; found=true;
      }else{
        tans++;
      }
    }
  }
  cout<<ans-1;
  return 0;
}