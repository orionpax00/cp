//	
//	implementation
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n;cin>>n;string s;cin>>s;
  string ans="";
  for(int i=0; i<n;i++){
    if(i%2 == 0 && i != 0 && i !=n-1){
      ans+= "-";
      ans += s[i];
    }else{
      ans+=s[i];
    }
  }
  cout<<ans;
  return 0;
}