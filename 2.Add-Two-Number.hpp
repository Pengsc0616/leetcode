/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* addpoint = new ListNode(l1->val+l2->val);
        ListNode* addstart = addpoint; //start from addstart
        addpoint->next = ((l1->next!=NULL)||(l2->next!=NULL)||(addpoint->val >=10))?new ListNode(addpoint->val/10):NULL;
        addpoint->val %=10;
        if((l1->next==NULL)&&(l2->next==NULL))  return addstart;
        addpoint = addpoint->next; /*result line move*/
        int xxx, yyy;
        //int flagx=0, flagy=0;
        int flagx = (l1->next==NULL)?1:0;
        int flagy = (l2->next==NULL)?1:0;
        l1 = (flagx)?l1:l1->next;
        l2 = (flagy)?l2:l2->next;
        while(1){
            xxx = (!flagx)?l1->val:0;
            yyy = (!flagy)?l2->val:0;
            /////// if(flagx&&flagy)    return addstart;

            //afterward, flag value change
            flagx = (l1->next==NULL)?1:0;
            flagy = (l2->next==NULL)?1:0;
            addpoint->val += (xxx+yyy);

            addpoint->next = (!flagx || !flagy || (addpoint->val >=10))?new ListNode(addpoint->val/10):NULL;//use new flag value
            addpoint->val %=10;
            if(flagx&&flagy)  return addstart;
            addpoint = addpoint->next; /*result line move*/
            l1 = (flagx)?l1:l1->next;
            l2 = (flagy)?l2:l2->next;
        }
    }
};
