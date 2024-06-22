#include <iostream>
#include<cmath>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* res=new ListNode();
        ListNode* p=res;
        temp=temp->next;
        while(temp){
            int sum=0;
            while(temp->val!=0){
                sum+=temp->val;
                temp=temp->next;
            }

            res->next=new ListNode(sum);
            res=res->next;
            temp=temp->next;
        }
        return p->next;
    }
};