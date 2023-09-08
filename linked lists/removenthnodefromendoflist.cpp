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
    ListNode* removeNthFromEnd(ListNode* &head, int n) {
        if(head==NULL){
            return head;
        }

        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }

        if(n>=i){
            temp=head->next;
            delete(head);
            return temp;
        }

        i=i-n-1;

        temp=head;
        while(i>0){
            temp=temp->next;
            i--;
        }

        ListNode* temp1=temp->next;
        temp->next=temp->next->next;
        delete temp1;
        return head;
    }
};