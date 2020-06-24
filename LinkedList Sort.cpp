/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merger(ListNode* l1, ListNode* l2){
    ListNode* dummy=new ListNode(-1),*tail=dummy;
       for(;l1 and l2;tail=tail->next)
           if(l1->val<=l2->val){
               tail->next=l1;
               l1=l1->next;
           }else{
               tail->next=l2;
               l2=l2->next;
           }
    for(ListNode* temp=l1?l1:l2;temp;temp=temp->next,
            tail=tail->next)
        tail->next=temp;
        return dummy->next;
           
    }
    ListNode* mergeSort(ListNode* anchor){
        if(!anchor || !anchor->next)
            return anchor;
        // find mid value
        ListNode* slow=anchor,*prev,*fast=anchor;
        while(fast->next){
            prev=slow;
            slow=slow->next;
            for(int i=0;fast->next && i<2;i++,fast=fast->next);
        }
        prev->next=NULL;
        ListNode* l1=mergeSort(anchor);
        ListNode* l2=mergeSort(slow);
        return merger(l1,l2);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
