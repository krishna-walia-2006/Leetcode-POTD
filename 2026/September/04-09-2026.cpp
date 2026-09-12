
#include <algorithm>
#include <climits>
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
    int ans = 0;

    int dfs(TreeNode* node) {
        if (!node) return INT_MIN;
        int l = dfs(node->left);
        int r = dfs(node->right);
        int mx = max({l, r, node->val});
        if (mx == node->val) ans++;
        return mx;
    }

public:
    int countDominantNodes(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
