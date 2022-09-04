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
    ListNode* deleteDuplicates(ListNode* s) {
        if(s==NULL || s->next==NULL)
        {
            return s;
        }
    
        ListNode *a=s,*b=s->next;
        while(a!=NULL && b!=NULL)
        {
            if(a->val==b->val)
            {
                while(b!=NULL && a->val==b->val)
                {
                    b=b->next;
                }
                if(b==NULL)
                {
                    a->next=NULL;
                    break;
                }
                else
                {
                    a->next=b;
                }
            }
            a=b;
            b=a->next;
        }
        
        return s;
    }
};