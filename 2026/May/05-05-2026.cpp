class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        ListNode* tail=head;
        int n=1;
        while(tail->next) {
            tail=tail->next;
            n++;
        }
        k=k%n;
        tail->next=head;
        k=n-k-1;
        ListNode* newtail=head;
        while(k!=0) {
            k--;
            newtail=newtail->next;
        }
        cout<<newtail->val;
        ListNode* ans=newtail->next;
        newtail->next=nullptr;
        return ans;
    }
};
