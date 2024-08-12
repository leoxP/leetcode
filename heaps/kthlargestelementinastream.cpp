#include<iostream>
#include<queue>
using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> heap; //min heap
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;

        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(heap.size()<k || heap.top()<val){
            heap.push(val);
            if(heap.size()>k) heap.pop();
        }
        return heap.top();
    }
};