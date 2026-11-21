class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currNode, string& s, vector<int>& parent) {
        int c = s[currNode] - 'a';
        int nearestAncestor = last[c];

        // Set currNode as the latest ancestor with character 'c' for its descendants
        last[c] = currNode;

        for (int child : adj[currNode]) {
            dfs(child, s, parent);
        }

        // Backtrack: restore previous nearest ancestor for character 'c'
        last[c] = nearestAncestor;

        // Attach to nearest matching ancestor if one exists; otherwise keep original parent
        if (currNode != 0) {
            int newParent = (nearestAncestor != -1) ? nearestAncestor : parent[currNode];
            parent[currNode] = newParent;
            resultSize[newParent] += resultSize[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        adj.clear();

        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        resultSize.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return resultSize;
    }
};
