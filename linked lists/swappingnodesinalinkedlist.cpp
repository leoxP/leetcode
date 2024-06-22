#include <iostream>
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
    ListNode* swapNodes(ListNode* &head, int k) {
        ListNode* temp=head;
        int x=0;
        while(temp!=NULL){
            temp=temp->next;
            x++;
        }
        temp=head;
        int a=k-1;
        int b=x-k;
        while(a--){
            temp=temp->next;
        }
        ListNode* temp1=temp;
        a=temp1->val;
        temp=head;
        while(b--){
            temp=temp->next;
        }
        temp1->val=temp->val;
        temp->val=a;
        
        return head;
    }
};