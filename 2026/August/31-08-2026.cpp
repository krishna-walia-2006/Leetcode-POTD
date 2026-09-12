// LeetCode 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Daily challenge: 2026-08-31
#include <vector>
#include <climits>
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        while (curr->next) {
            ListNode* nextNode = curr->next;
            if ((curr->val > prev->val && curr->val > nextNode->val) ||
                (curr->val < prev->val && curr->val < nextNode->val)) {
                criticalPoints.push_back(idx);
            }
            prev = curr;
            curr = nextNode;
            idx++;
        }
        if (criticalPoints.size() < 2) return {-1, -1};
        int minDistance = INT_MAX;
        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        return {minDistance, maxDistance};
    }
};
