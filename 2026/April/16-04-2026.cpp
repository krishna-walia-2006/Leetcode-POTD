class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for (int q : queries) {
            auto &vec = mp[nums[q]];

            if (vec.size() == 1) {
                result.push_back(-1);
                continue;
            }

            // find position of q in vec
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int left = vec[(pos - 1 + vec.size()) % vec.size()];
            int right = vec[(pos + 1) % vec.size()];

            int d1 = abs(q - left);
            int d2 = abs(q - right);

            int ans = min({d1, n - d1, d2, n - d2});

            result.push_back(ans);
        }

        return result;
    }
};
