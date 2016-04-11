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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // iterator through list
        ListNode* iterator = new ListNode(0);
        // store the head
        ListNode* head = iterator;
        // carry bit
        int c = 0;
        // when l1 and l2 is not NULL and carry bit is not zero
        while(l1 || l2 || c!=0){
            iterator->next = new ListNode(0);

            int l1v = 0, l2v = 0;
            
            if(l1){
                l1v = l1->val;
                l1 = l1->next;
            }
            if(l2){
                l2v = l2->val;
                l2 = l2->next;
            }
            
            iterator->next->val = (l1v+l2v+c)%10;
            c = (l1v+l2v+c)/10;
            iterator = iterator->next;
        }
        // read the new head
        return head->next;
    }
};