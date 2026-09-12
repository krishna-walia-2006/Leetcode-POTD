// LeetCode 3093. Longest Common Suffix Queries
// Daily challenge: 2026-05-28

#include <string>
#include <vector>
#include <climits>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    int bestIdx = -1;
    int bestLen = INT_MAX;
};

class Solution {
    TrieNode* root = new TrieNode();

    void update(TrieNode* node, int len, int idx) {
        if (len < node->bestLen) { node->bestLen = len; node->bestIdx = idx; }
    }

    void insert(const string& w, int idx) {
        TrieNode* node = root;
        update(node, w.size(), idx);
        for (int i = (int)w.size() - 1; i >= 0; i--) {
            int c = w[i] - 'a';
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
            update(node, w.size(), idx);
        }
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        for (int i = 0; i < (int)wordsContainer.size(); i++) insert(wordsContainer[i], i);

        vector<int> ans;
        for (auto& q : wordsQuery) {
            TrieNode* node = root;
            int best = node->bestIdx;
            for (int i = (int)q.size() - 1; i >= 0; i--) {
                int c = q[i] - 'a';
                if (!node->children[c]) break;
                node = node->children[c];
                best = node->bestIdx;
            }
            ans.push_back(best);
        }
        return ans;
    }
};
