/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
        
    bool isfound= false;
    ListNode* st=A;
    ListNode* ft=A;
    while(ft->next !=NULL && st != NULL && ft != NULL){
        st=st->next;
        ft=ft->next->next;
        
        if(st==ft){
            st=A;
            while(st != ft){
                st=st->next;
                ft=ft->next;
            }
            return st;
        }
    }if(!isfound) return NULL;
    
}




ListNode* Solution::detectCycle(ListNode* A) {
        
   if(A == nullptr) {
        return nullptr;
    }
    bool has_cycle = false;
    ListNode *slow_p = A, *fast_p = A;
    while(slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p) {
            has_cycle = true;
            break;
        }
    }
    
    if(!has_cycle) {
        return nullptr;
    }
    
    slow_p = A;
    while(slow_p != fast_p) {
        slow_p = slow_p->next;
        fast_p = fast_p->next;
    }
    
    return slow_p;
    
}
