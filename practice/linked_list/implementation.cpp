#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* next;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  Node* n;Node* h;Node* t;
  //First node
  n = new Node();
  n->value = 5;
  n->next = NULL;

  t=n;
  h=n;

  for(int i=0; i<10; ++i){
    n=new Node();
    n->value =i;
    t->next = n;
    t=n;
  }
  Node* temp;
  temp = h;
  while(temp->next != NULL){
    cout<<temp->value;
    temp=temp->next;
  }

  return 0;
}