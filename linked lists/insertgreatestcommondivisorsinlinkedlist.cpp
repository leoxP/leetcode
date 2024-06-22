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

int gcd(int x,int y){
     int res=min(x,y);
     while(res>0){
        if(x%res==0 && y%res==0)
            return res;
        res--;
     }
     return res;
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        ListNode* res=temp;
        while(temp->next){
            int x=gcd(temp->val,temp->next->val);
            ListNode* gcd=new ListNode(x);

            gcd->next=temp->next;
            temp->next=gcd;

            temp=gcd->next;
        }
        return res;
    }
};