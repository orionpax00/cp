//	Kadanes algorithm
//	array
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;cin>>n; 
  vector<int> nums(n);
  for(int i=0 ; i<n; i++){
    cin>>nums[i];
  }
  int ans = INT_MIN, temp=0;
  for(int x: nums){
    temp += x;
    ans = max(ans, temp);
    temp = max(temp, 0);
  }
  cout<<ans;
  return 0;
}