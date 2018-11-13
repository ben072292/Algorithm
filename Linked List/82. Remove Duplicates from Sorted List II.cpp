/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

/* 
 * Idea: Create a new linked list and track the provided linked list separately, if a item is satisfied to 
 * to put into the new linked list, add it. Remember to put NULL at the end of the new linked list
 */

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = new ListNode(-1);
        ListNode* res = node;
        
        while(head){
            if(!head->next || head->val != head->next->val){
                node->next = head;
                node = node->next;
                head = head->next;
                continue;
            }
            while(head->next && head->val == head->next->val) head = head->next;
            head = head->next;
        }
        node->next = 0; // append end, very important
        return res->next;
    }
};
