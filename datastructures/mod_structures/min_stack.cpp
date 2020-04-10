//	Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//	Stack Extra-function
#include <bits/stdc++.h>
using namespace std;

class MinStack {
  public:
  stack<long long int> s;
  int m = INT_MAX;

  MinStack() {

  };

  void push(int x){
    if(s.empty()){
      s.push(x);
      m = x;
    }else{
      if(x<m){
        long long int t = 2 * (long long int) x - m;
        s.push(t);
        m = x;
      }
    }
  }

  void pop(){
    long long int t = s.top();
    s.pop();
    if(t<m){
      m = 2 * m - t;
    }
  }

  int top() {
    long long int t = s.top();
    if(t < m) return m;
    else return t; 
  }

  int getMin() {
    return m;
  }

};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  MinStack s; 
  s.push(3); 
  s.push(5); 
  cout<<s.getMin()<<"\n"; 
  s.push(2); 
  s.push(1); 
  cout<<s.getMin()<<"\n"; 
  s.pop(); 
  cout<<s.getMin()<<"\n"; 
  s.pop(); 
  
  return 0;
}