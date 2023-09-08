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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        int check=1;
        int carry=0;
        int x,y;
        while(l1!=NULL || l2!=NULL || carry!=0){
            if(l1==NULL){
                x=0;
            }
            else{
                x=l1->val;
            }
            if(l2==NULL){
                y=0;
            }
            else{
                y=l2->val;
            }

            int sum=x+y+carry;
            carry=sum/10;
            int digit=sum%10;

            ListNode* Digit=new ListNode(digit);
            temp->next=Digit;
            temp=temp->next;

            l1=(l1!=NULL) ? l1->next : NULL ;
            l2=(l2!=NULL) ? l2->next : NULL ;
        }
        ListNode* result=res->next;
        delete(res);
        return result;
    }
};