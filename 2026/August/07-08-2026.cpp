// LeetCode 3348. Smallest Divisible Digit Product II
// Daily challenge: 2026-08-07
//

#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        int A = 0, B = 0, C = 0, D = 0;
        long long tt = t;
        while (tt % 2 == 0) { tt /= 2; A++; }
        while (tt % 3 == 0) { tt /= 3; B++; }
        while (tt % 5 == 0) { tt /= 5; C++; }
        while (tt % 7 == 0) { tt /= 7; D++; }
        if (tt != 1) return "-1"; // t has a prime factor no digit can supply

        static const int dv[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
        };

        int dimA = A + 1, dimB = B + 1, dimC = C + 1, dimD = D + 1;
        auto idx = [&](int a, int b, int c, int d) {
            return ((a * dimB + b) * dimC + c) * dimD + d;
        };

        // h[state] = minimum number of extra digits needed to go from `state`
        // (accumulated exponents, saturated at target) up to the full target.
        vector<int> h(dimA * dimB * dimC * dimD, INT_MAX);
        vector<array<int,4>> states;
        for (int a = 0; a <= A; a++)
            for (int b = 0; b <= B; b++)
                for (int c = 0; c <= C; c++)
                    for (int d = 0; d <= D; d++)
                        states.push_back({a, b, c, d});
        sort(states.begin(), states.end(), [](const array<int,4>& x, const array<int,4>& y) {
            return (x[0]+x[1]+x[2]+x[3]) > (y[0]+y[1]+y[2]+y[3]);
        });

        h[idx(A, B, C, D)] = 0;
        for (auto& st : states) {
            int a = st[0], b = st[1], c = st[2], d = st[3];
            int cur = idx(a, b, c, d);
            if (h[cur] == 0) continue; // target itself
            int best = INT_MAX;
            for (int dig = 1; dig <= 9; dig++) {
                int na = min(A, a + dv[dig][0]);
                int nb = min(B, b + dv[dig][1]);
                int nc = min(C, c + dv[dig][2]);
                int nd = min(D, d + dv[dig][3]);
                int nxt = idx(na, nb, nc, nd);
                if (nxt == cur) continue;
                if (h[nxt] != INT_MAX) best = min(best, 1 + h[nxt]);
            }
            h[cur] = best;
        }

        auto remaining = [&](int a, int b, int c, int d) { return h[idx(a, b, c, d)]; };

        function<string(int,int,int,int,int)> buildSuffix =
            [&](int length, int a, int b, int c, int d) -> string {
            string res;
            for (int i = 0; i < length; i++) {
                for (int dig = 1; dig <= 9; dig++) {
                    int na = min(A, a + dv[dig][0]);
                    int nb = min(B, b + dv[dig][1]);
                    int nc = min(C, c + dv[dig][2]);
                    int nd = min(D, d + dv[dig][3]);
                    if (remaining(na, nb, nc, nd) <= length - i - 1) {
                        res.push_back('0' + dig);
                        a = na; b = nb; c = nc; d = nd;
                        break;
                    }
                }
            }
            return res;
        };

        int n = num.size();
        function<bool(int,bool,int,int,int,int,string&)> solve =
            [&](int i, bool tight, int a, int b, int c, int d, string& out) -> bool {
            if (i == n) return a == A && b == B && c == C && d == D;
            int digitHere = num[i] - '0';
            int lowd = tight ? max(1, digitHere) : 1;
            for (int dig = lowd; dig <= 9; dig++) {
                bool ntight = tight && (dig == digitHere);
                int na = min(A, a + dv[dig][0]);
                int nb = min(B, b + dv[dig][1]);
                int nc = min(C, c + dv[dig][2]);
                int nd = min(D, d + dv[dig][3]);
                int rem = n - i - 1;
                if (ntight) {
                    string tmp;
                    if (solve(i + 1, true, na, nb, nc, nd, tmp)) {
                        out.push_back('0' + dig);
                        out += tmp;
                        return true;
                    }
                } else if (remaining(na, nb, nc, nd) <= rem) {
                    out.push_back('0' + dig);
                    out += buildSuffix(rem, na, nb, nc, nd);
                    return true;
                }
            }
            return false;
        };

        string result;
        if (solve(0, true, 0, 0, 0, 0, result)) return result;

        // Same length impossible: grow the length by one and fill greedily.
        int length = n + 1;
        return buildSuffix(length, 0, 0, 0, 0);
    }
};
