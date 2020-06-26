class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        unordered_set<ListNode* > s;
        while(temp1!= NULL)
        {
            s.insert(temp1);
            temp1 = temp1->next;
        }
        while(temp2!= NULL){
            if(s.find(temp2) != s.end())
                return temp2;
            temp2 = temp2->next;
        }
        return NULL;
        
    }
};
