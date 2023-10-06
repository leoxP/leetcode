#include <iostream>
#include <map>
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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int> m;
        ListNode* temp=head;
        while(temp){
            int x=temp->val;
            if(m.find(temp)==m.end()) m[temp]=x;
            else return true;
            temp=temp->next;
        }
        return false;
    }
};

//Using slow and fast pointers:
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};