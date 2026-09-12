// LeetCode 2213. Longest Substring of One Repeating Character
// Daily challenge: 2026-08-13
//
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int len = 0, best = 0, leftRun = 0, rightRun = 0;
    char leftChar = 0, rightChar = 0;
};

class Solution {
    vector<Node> tree;
    string s;
    int n;

    Node merge(const Node& L, const Node& R) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;
        Node res;
        res.len = L.len + R.len;
        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;
        res.leftRun = L.leftRun + ((L.leftRun == L.len && L.leftChar == R.leftChar) ? R.leftRun : 0);
        res.rightRun = R.rightRun + ((R.rightRun == R.len && R.rightChar == L.rightChar) ? L.rightRun : 0);
        res.best = max(L.best, R.best);
        if (L.rightChar == R.leftChar) res.best = max(res.best, L.rightRun + R.leftRun);
        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, c);
        else update(2 * node + 1, mid + 1, end, idx, c);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string sInit, string queryCharacters, vector<int>& queryIndices) {
        s = sInit;
        n = s.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);
        vector<int> ans;
        for (int i = 0; i < (int)queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            s[idx] = c;
            update(1, 0, n - 1, idx, c);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};
