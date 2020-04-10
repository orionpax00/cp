//	
//	
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t;cin>>t;
  while(t--){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int x, y, x1, y1, x2, y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    if((x-a+b)<=x2 && (x-a+b)>=x1 &&  <= y2 && (y-c+d) >= y1 && (x2>x1||a+b==0)&&(y2>y1||c+d==0)){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
  
  return 0;
}
