#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        vector<int> v;

        if(fast==NULL) return true;
        
        while(fast!=NULL && fast->next!=NULL){
            int x=slow->val;
            v.push_back(x);
            slow=slow->next;
            fast=fast->next->next;
        }
        //Alternative is to reverse first half of list and check

        int x=slow->val;
        v.push_back(x);
        int len=v.size()-1;

        if(fast!=NULL) //middle node skipped if odd number of elements
            slow=slow->next;

        while(slow!=NULL){
            if(slow->val!=v[len]) return false;
            slow=slow->next;
            len--;
        }
        return true;
    }
};