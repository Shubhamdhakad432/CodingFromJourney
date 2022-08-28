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
    ListNode* reverseBetween(ListNode* s, int i, int j) {
        ListNode *ed=NULL,*trv2=NULL,*trv1=s,*back=NULL,*tail=NULL,*start=s,*mid=s;
        bool rev=false,tal=true;
        int k=1;
        
        if(i==j) return s;
        
        while(k!=j)
        {
            if(k==i)
            {
                ed=trv2;
                if(ed!=NULL)
                    ed->next=NULL;
                rev=true;
            }
            
            if(rev)
            {
                if(tal)
                {
                    tail=trv1;
                    tal=false;
                }
                if(trv1!=NULL)
                {
                    start=trv1->next;
                }
                trv1->next=back;
                back=trv1;
                trv1=start;
            }
            else
            {
                trv2=trv1;
                trv1=trv1->next;
            }
            
            k++;
        }
        
        if(trv1!=NULL)
        {
            start=trv1->next;
            trv1->next=back;
        }
        
        back=trv1;
        tail->next=start;
        
        if(ed!=NULL)
        {
            ed->next=back;
            return s;
        }
        else
        {
            return back;
        }
    }
};