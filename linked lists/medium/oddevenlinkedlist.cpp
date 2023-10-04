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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=head;
        if(!odd || !odd->next) return head;
        ListNode* even=head->next;
        ListNode* temp=even;
        ListNode* res=odd;
        while(odd->next && even->next){
            odd->next=even->next;
            odd=odd->next;
            if(!odd->next){
                even->next=NULL;
                odd->next=temp;
                break;
            }
            even->next=odd->next;
            even=even->next;
            if(!even->next) {
                even->next=NULL;
                odd->next=temp;
                break;
            }
        }
        return res;
    }
};