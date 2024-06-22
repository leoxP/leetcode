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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* res=temp1;
        ListNode* temp2=list2;

        int x=a;
        int y=b+1;
        a=x-1;
        while(a--){
            temp1=temp1->next;
        }
        ListNode* temp=res;
        while(y--){
            temp=temp->next;
        }

        temp1->next=temp2;
        while(temp2->next!=NULL){
            temp2=temp2->next;
            temp1=temp1->next;
            temp1->next=temp2;
        }
        temp2->next=temp;
        return res;
    }
};