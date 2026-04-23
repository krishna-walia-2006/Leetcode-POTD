class Solution {
public:

    vector<int> parent;
    vector<int> size;

    void makeSet(int n) {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;  // each node is its own set initially
        }
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY) return;

        // attach smaller set under bigger set
        if(size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        size[rootX] += size[rootY];  // update size
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        makeSet(n);
        for(auto &vec:allowedSwaps) {
            Union(vec[0],vec[1]);
        }
        unordered_map<int,unordered_map<int,int>> groupFreq;
        for(int i=0;i<n;i++) {
            int curr=source[i];
            int parent=find(i);

            groupFreq[parent][curr]++;
        }

        int hDist=0;
        for(int i=0;i<n;i++) {
            
            int parent=find(i);
            if(groupFreq[parent][target[i]]>0) {
                groupFreq[parent][target[i]]--;
            }
            else {
                hDist++;
            }
        }
        return hDist;
    }
};
