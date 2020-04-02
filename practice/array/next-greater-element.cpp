/*
  Title: Next Greater Element
  Description: Next greater element is defined as the next element that has value more then the
               current element
  Example:
      input: arr = {11,13,12,1,232,21,3}
      output: 13 232 232 232 -1 -1 -1 //-1 if value doen't present
  tags: array, stack

  questions to ask:
    1. Do we have keep track of postion of element whose value we are finding
      for example: I one or II one
        I:
          11-->13
          1-->232
          12-->232
          13-->232
          3-->-1
          21-->-1
          232-->-1
        II:
          11-->13
          13-->232
          12-->232
          1-->232
          232-->-1
          21-->-1
          3-->-1
*/

#include <bits/stdc++.h>

using namespace std;

// Naive implementation complexity O(n^2)
void printNGEnaive(int a[], int n){
  for(int i=0; i < n;++i){
    int nge = -1;
    for(int j = i+1; j < n; ++j){
      if(a[j] > a[i]) {nge = a[j];break;}
    }
    cout<<nge<<" ";
  }
}

// Implementation complexity O(n)
void printNGE(int a[], int n){
  stack<int> s;

  for(int i =0; i<n; ++i){
    if(s.empty()){
      s.push(a[i]);
      continue;
    };
    while(!s.empty() && a[i] > s.top()){
      cout<<s.top()<<"-->"<<a[i]<<"\n";
      s.pop();
    }
    s.push(a[i]);
  }

  while(!s.empty()){
    cout<<s.top()<<"-->"<<-1<<"\n";
    s.pop();
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int arr[7] = {11,13,12,1,232,21,3};
  printNGE(arr,7);
  printNGEnaive(arr, 7);
  return 0;
}