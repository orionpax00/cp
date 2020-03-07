#include <bits/stdc++.h>
using namespace std;

vector<int> v(10, 0);
bool check(int n){
    while (n){
    int t1= n%10;
    if(v[t1]) return false;
    n /= 10;
  }
  return true;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n,k;
  cin>>n>>k;
  
  while(k--){
    int temp;
    cin>>temp;
    v[temp] = 1;
  }

  for(int k = n ; k<1e10; k++){
    if(check(k)) {cout<<k; break;}
  }



  return 0;
}