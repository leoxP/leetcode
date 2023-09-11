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
    long long getDecimalValue(ListNode* head) {
        long long sum=0;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        while(temp!=NULL){
            sum+=temp->val*pow(2,len-1);
            len--;
            temp=temp->next;
        }
        return sum;
    }
};