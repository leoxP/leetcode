#include <iostream>
#include<cmath>
#include<stack>
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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp;
        ListNode* temp1=head;
        ListNode* temp2=NULL;
        ListNode* next=slow;
        while(next){
            temp=next->next;
            next->next=temp2;
            temp2=next;
            next=temp;
        }
        int sum=0;
        while(head && temp2){
            sum=max(sum,head->val+temp2->val);
            head=head->next;
            temp2=temp2->next;
        }
        return sum;
    }
};

//Using stack:
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        int sum=0;
        while(slow){
            int k=st.top();
            st.pop();
            sum=max(sum,k+slow->val);
            slow=slow->next;
        }
        return sum;
    }
};