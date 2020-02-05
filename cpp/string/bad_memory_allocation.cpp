#include <bits/stdc++.h>

using namespace std;

static uint32_t s_Allocated = 0;
void* operator new(size_t size) {
  s_Allocated++;
  cout<<"Allocating: "<< size<<" bytes";
  return malloc(size);
}

void printName(const string& name){
  cout<<name;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string name = "Durgesh Kumar";
  printName(name);
  
  cout<<"\nNumber of allocations: "<<s_Allocated;
  return 0;
}