#include<iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=nullptr;
        ListNode* head=nullptr;
        if(temp1 && temp2 && temp1->val<temp2->val){ 
            //chooses temp2 with ll of first value higher
            temp2=list1;
            temp1=list2;
        }
        if(temp2){
            temp=new ListNode(temp2->val);
            head=temp;
        }
        else{
            return temp1;
        }
        temp2=temp2->next;


        while(temp1!=NULL || temp2!=NULL){
            if(temp1==NULL){
                ListNode* digit=new ListNode(temp2->val);
                temp->next=digit;
                temp2=temp2->next;
            }
            else if(temp2==NULL){
                ListNode* digit=new ListNode(temp1->val);
                temp->next=digit;
                temp1=temp1->next;
            }
            else if(temp1->val>=temp->val && temp1->val<=temp2->val){
                ListNode* digit=new ListNode(temp1->val);
                temp->next=digit;
                temp1=temp1->next;
            }
            else{  
                ListNode* digit=new ListNode(temp2->val);
                temp->next=digit;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        return head;
    }
};