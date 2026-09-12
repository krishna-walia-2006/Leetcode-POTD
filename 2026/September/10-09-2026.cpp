
#include <utility>
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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }

private:
    pair<int,int> dfs(TreeNode* node, int& count) {
        if (!node) return {0, 0};

        auto left = dfs(node->left, count);
        auto right = dfs(node->right, count);

        int currentSum = left.first + right.first + node->val;
        int currentNodes = left.second + right.second + 1;

        if (currentSum / currentNodes == node->val) count++;

        return {currentSum, currentNodes};
    }
};
