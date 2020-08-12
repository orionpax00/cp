/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int time1 = 0;
        int time2 = 0;
        while(t1 != NULL){
            t1 = t1 -> next;
            time1++;
        }
        while(t2 != NULL){
            t2 = t2 -> next;
            time2++;
        }
        if(time1 >= time2){
            t1 = headA;
            t2 = headB;
            int tempt = 0;
            while(tempt < time1 - time2){
                tempt++;
                t1 = t1 -> next;
            }
            while((t1 != NULL && t2 != NULL) && t1 != t2){
                t1 = t1->next;
                t2 = t2->next;
            }
            if(t1 == t2) return t1;
            return NULL;
        }else{
            t2 = headB;
            t1 = headA;
            int tempt = 0;
            while(tempt < time2 - time1){
                tempt++;
                t2 = t2 -> next;
            }
            while((t1 != NULL && t2 != NULL) && t1 != t2){
                t1 = t1->next;
                t2 = t2->next;
            }
            if(t1 == t2) return t1;
            return NULL;
        }
    }
};
// @lc code=end

