//	Median of the linek list
//	LinkedList floyd-algo
#include <bits/stdc++.h>

using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode* i = head;
    ListNode* j = head;
    
    while(j != NULL && j->next != NULL){
        i = i->next;
        j = j->next->next;
    }
    return i;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  //call function with head node
  
  return 0;
} 