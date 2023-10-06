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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        vector<ListNode*> v;
        while(temp1){
            v.push_back(temp1);
            temp1=temp1->next;
        }
        while(temp2){
            if(find(v.begin(),v.end(),temp2)!=v.end()){
                return temp2;
                break;
            }
            temp2=temp2->next;
        }
        return temp2;
    }
};

//O(n) solution:-
ListNode* loc(ListNode* x,int cnt){
    ListNode* temp=x;
    while(cnt--) temp=temp->next;
    return temp;
}

int len(ListNode* x){
    if(!x) return 0;
    return 1+len(x->next);
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int m=len(temp1);
        int n=len(temp2);

        if(m>n) headA=loc(headA,abs(m-n));
        else headB=loc(headB,abs(m-n));
        
        while(headA){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};