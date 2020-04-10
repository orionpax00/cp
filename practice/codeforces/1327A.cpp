//	
// Maths
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t, a, b;cin>>t;
  while (t--)
  {
    cin>>a>>b;
    long long int x = (long long int) b * (long long int) b;
    if((a%2 == b%2) && (x <= (long long int) a)) cout<<"YES\n";
    else cout<<"NO\n";
  }
  
  return 0;
}