// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Well, one way to do this is using a priority queue.
// put all the lists into this priority queue pull one elemenet per time from the que.
// That element must be a head of one of the lists.
// We then delete the element (a.k.a the smallest "head")
// we then add the element after this deleted element ("head"->next) to the priority queue.
// repeat this process till we pull all the elements out!

// Here is the code:

class Solution {

public:

	// one way to write the weak order for priority queue is to generate a comparison object and 
	// overload its () operator
    struct compare{
	    bool operator ()(ListNode* l1, ListNode* l2){
		    return l1->val > l2->val;
	    }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> que;// literally pain in the ass
        
        ListNode* newList = new ListNode(0);// fake head
        ListNode* temp = newList;// iterate head
        
        int siz = lists.size();
        for(int i = 0;i < siz;i++){
        	// get rid of all the NULL lists
        	// like [[],[]]
            if(lists[i] != NULL){
                que.push(lists[i]);
            }
        }
        
        while(!que.empty()){
            temp->next = que.top();// get the smallest head
            temp = temp->next;
            ListNode* n = (que.top())->next;// get the element after the smallest head
            que.pop();// pop the head
            if(n != NULL){
                que.push(n);// if its not NULL put it in que
            }
        }
        
        return newList->next;// return the true head
        
    }
};