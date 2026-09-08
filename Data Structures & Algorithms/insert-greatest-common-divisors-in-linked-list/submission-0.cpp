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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)return head;
        ListNode* h1 = head;
        ListNode* h2 = h1->next;
        while(h2){
            int x = gcd(h1->val,h2->val);
            ListNode* temp = new ListNode(x);
            h1->next = temp;
            temp->next = h2;
            h1=h2;
            h2=h2->next;
        }
        return head;
    }
};