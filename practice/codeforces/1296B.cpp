#include <bits/stdc++.h>

using namespace std;

int ans(int x) {
  int temp = x;

  long long int an=0;
  while(x>=10){
    int y = x/10;
    x = y + x%10;
    an += y;
  }
  return an+temp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--){
    int x;
    cin>>x;
    int a = ans(x);
    cout<<a<<"\n";
  }
  return 0;
}

