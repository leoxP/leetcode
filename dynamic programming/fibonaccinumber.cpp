#include<iostream>
#include<vector>
using namespace std;

//Using tabulation:
class Solution {
public:
    int fib(int n) {
        int prev=0;
        int next=1;
        int cur;
        if(n<=1) return n;
        for(int i=2;i<=n;i++){
            cur=prev+next;
            prev=next;
            next=cur;
        }
        return cur;
    }
};

//Using memoization:
int calcfib(int n,vector<int> &arr){
    if(n<=1) return n;
    if(arr[n]!=-1) return arr[n];

    return arr[n]=calcfib(n-1,arr)+calcfib(n-2,arr);
}
class Solution {
public:
    int fib(int n) {
        vector<int> v(n+1,-1);
        return calcfib(n,v);
    }
};