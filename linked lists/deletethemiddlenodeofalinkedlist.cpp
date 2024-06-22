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
    ListNode* deleteMiddle(ListNode* &head) {
        ListNode* temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length==1) return head->next;
        length=length/2-1;
        temp=head;
        while(length--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};