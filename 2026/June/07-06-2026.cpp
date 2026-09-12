// LeetCode 2196. Create Binary Tree From Descriptions
// Daily challenge: 2026-06-07
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (auto& d : descriptions) {
            int p = d[0], c = d[1], isLeft = d[2];
            if (!nodes.count(p)) nodes[p] = new TreeNode(p);
            if (!nodes.count(c)) nodes[c] = new TreeNode(c);
            if (isLeft) nodes[p]->left = nodes[c];
            else nodes[p]->right = nodes[c];
            children.insert(c);
        }
        for (auto& [val, node] : nodes) {
            if (!children.count(val)) return node;
        }
        return nullptr;
    }
};
