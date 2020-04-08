//	Square digit summ equals 1 - leetcode
//	maths
#include <bits/stdc++.h>

using namespace std;

int ans(int n){
  int sum = 0;
  while(n>0){
    int digit = n%10;
    n /= 10;
    sum += digit * digit;
  }
  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;cin>>n;
  unordered_set<int> isvisited;
  while(true){
    if(n==1){cout<<"True";return 0;}
    int n2 = ans(n);
    n = n2;
    if(isvisited.count(n) == 1){
      cout<<"False";
      return 0;
    }
    isvisited.insert(n);
  }
  return 0;
}

// for 10 digit number max sum 10*81 --> 810 
// it will also be equal to total number of repetations
// i.e while loop in main() as 1-->810 number can occur
// no bouncing between numbers becuase of isvisited_set