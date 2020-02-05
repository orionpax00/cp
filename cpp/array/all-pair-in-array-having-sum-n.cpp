#include <bits/stdc++.h>

using namespace std;

binarySearch(vector<int> a, int l, int r, int b){
  
  while(l<=r){
    int mid = l+(r-l)/2;
    if(b==a[mid])return mid;
    if(b>a[mid]) l=mid+1;
    else r=mid-1;
  }
  return -1;
}

// Solving using binary search
int countSolBS(vector<int> &v, int x){
  int n=v.size();
  sort(v.begin(), v.end());
  int count = 0;
  for(int i=0; i<n;++i){
    // if(v[i] == x)count++; // uncomment if you want single number can also ber counted
    int l=i+1, r=n-1;
    int b = x - v[i];
    if(binarySearch(v, l, r, b) != -1) count++;
  }
  return count;
}

// Solving using two pointer problem
int countSolTP(vector<int> &v, int x){
  int count=0;
  for(int i=0; i<v.size(); ++i){
    for(int j=i+1; j<v.size(); ++j){
      if(v[i] == (x-v[j])) count++;
    }
  }
  return count;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> v={11,13,12,1,232,21,3};
  cout<<countSolBS(v, 12);
  cout<<"\n";
  cout<<countSolTP(v, 12);
  return 0;
}