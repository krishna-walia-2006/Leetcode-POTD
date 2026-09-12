// LeetCode 2130. Maximum Twin Sum of a Linked List
// Daily challenge: 2026-06-14
#include <vector>
#include <algorithm>
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
    int pairSum(ListNode* head) {
        vector<int> vals;
        while (head) { vals.push_back(head->val); head = head->next; }
        int n = vals.size(), maxSum = 0;
        for (int i = 0; i < n/2; i++) maxSum = max(maxSum, vals[i] + vals[n-1-i]);
        return maxSum;
    }
};
