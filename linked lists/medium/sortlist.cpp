#include <iostream>
#include <map>
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
    ListNode* sortList(ListNode* &head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        map<int,int> m;
        while(temp){
            m[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        for(auto i:m){
            temp->val=i.first;
            i.second--;
            temp=temp->next;
            while(i.second>0){
                temp->val=i.first;
                i.second--;
                temp=temp->next;
            }
        }
        
        return head;
    }
};