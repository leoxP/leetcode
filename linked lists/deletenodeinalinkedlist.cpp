#include <iostream>
#include<cmath>
#include<stack>
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
    void deleteNode(ListNode* node) {
        while(node){
            node->val=node->next->val;
            if(node->next->next==NULL){
                node->next=NULL;
            }
            node=node->next;
        }
    }
};

//O(1) solution:
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};