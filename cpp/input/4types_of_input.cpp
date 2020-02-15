#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int nrows = 5;
  int cols = 3;
  int vec[5][3];

  // KN KN (r,c)

  // while(nrows--){
  //   int temp = cols;
  //   while(temp--){
  //     cin>>vec[nrows][temp];
  //   }
  // }

  //unkown number of entries spread over unknown number of lines (means total count is known)

  // vector<int> v;
  // int n;
  // for(int i=0; i<3; ++i){
  //   if(cin>>n) v.push_back(n);
  // }
  // for(int x: v) cout<<x;

  // unknown number of entries in a single line

  // vector<int> v;
  // string s;
  // getline(cin, s);
  // istringstream sstr(s);
  // int n;
  // while(sstr>>n) v.push_back(n);

  // for(int x: v) cout<<x;

  // unknown number of entries in each line spread acroos known number of lines
  // vector<int> v;
  // int rows=2;
  // while(rows--){
  //   string s;
  //   getline(cin, s);
  //   istringstream sstr(s);
  //   int n;
  //   while(sstr>>n) v.push_back(n);
  // }
  // for(int x: v) cout<<x;

  // unknown number of entries in a row and unknown number of rows
  string s;
  vector<int> v;
  while(getline(cin, s)){ // loop end via EOF signal i.e ctrl+c
    istringstream sstr(s);
    int n;
    while(sstr>>n) v.push_back(n);
  }
  for(auto x:v) cout<<x;

  return 0;
}