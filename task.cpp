#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
  cin>>t;
	while(t--){
	  int n;
	  cin>>n;
	  int arr1[n];
	  int arr2[n];
	  for(int i=0;i<n;++i){
	    cin>>arr1[i];
	  }
	  for(int i=0;i<n;++i){
	    cin>>arr2[i];
	  }
	  
	  sort(arr1, arr1+n);
	  sort(arr2, arr2+n);
	  long long int ans =0;
	  for(int i=0;i<n;++i){
	   ans += min(arr1[i],arr2[i]);
	  }
	  
	  cout<<ans<<"\n";
	}
	return 0;
}
