#include <bits/stdc++.h>

using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* h;

void Insert(int N){
  Node* n;
  n = new Node();
  n->value = N;
  n->next = h;
  h = n;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  h=NULL;
  int n;
  scanf("%d", &n);
  while(n--){
    int tn;
    scanf("%d", &tn);
    Insert(tn);
  }

  Node* temp;
  temp = h;
  cout<<"----------\n";
  while(temp->next != NULL){
    cout<<temp->value<<"\n";
    temp=temp->next;
  }cout<<temp->value<<"\n";

  return 0;
}