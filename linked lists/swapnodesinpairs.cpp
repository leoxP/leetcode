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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1=head;
        if(!p1 || !p1->next) return head;
        ListNode* p2=head->next;
        ListNode* temp=p2;
        while(p2){
            ListNode* temp;
            p1->next=p2->next;
            p2->next=p1;
            temp=p1;
            p1=p1->next;
            if(p1==NULL || p1->next==NULL){
                break;
            }
            p2=p1->next;
            temp->next=p2;
        }
        return temp;
    }
};