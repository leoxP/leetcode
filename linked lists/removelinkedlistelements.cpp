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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        if(!temp) return temp;
        while(temp && temp->val==val){
            ListNode* Delete=temp;
            temp=temp->next;
            delete Delete;
        }
        
        ListNode* res=temp;
        while(temp && temp->next){
            if(temp->next->val==val){
                ListNode* Delete=temp->next;
                temp->next=temp->next->next;
                delete Delete;
            }
            else temp=temp->next;
        }
        if(temp && temp->val==val){
            return temp->next;
        }
        return res;
    }
};