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
    ListNode* removeNthFromEnd(ListNode* start, int n) {
        ListNode *a=start,*b=start,*c=NULL;
        int m=1;
        if(start==NULL)
        {
            return start;
        }
        if(start->next==NULL && n==1)
        {
            return NULL;
        }
        for(int i=1;i<n;i++)
        {
            b=b->next;
            m++;
        }
        while(b->next!=NULL)
        {
            c=a;
            a=a->next;
            b=b->next;
            m++;
        }
        
        if(n==m)
        {
            start=start->next;
            return start;
        }
        else if(n==1)
        {
            c->next=NULL;
            return start;
        }
        else if(b==start)
        {
            return NULL;
        }
        
        c->next=a->next;
        return start;
    }
};