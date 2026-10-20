class Solution {
    vector<int> lpsArray(vector<int>& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        return lps;
    }

    bool KMPSearch(vector<int>& pattern, vector<int>& text) {
        vector<int> lps = lpsArray(pattern);
        int i = 0, j = 0;

        while (i < (int)text.size()) {
            if (pattern[j] == text[i]) {
                i++;
                j++;

                if (j == (int)pattern.size()) {
                    return true;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2) {
        if (vec1.size() != vec2.size()) {
            return false;
        }

        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());

        return KMPSearch(vec1, text);
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);

                if (!isRotationPossible(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result += k;
            }
        }

        return result;
    }
};
