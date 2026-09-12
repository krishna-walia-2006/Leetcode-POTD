// LeetCode 2126. Destroying Asteroids
// Daily challenge: 2026-05-31
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long currentMass = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) currentMass += asteroid;
            else return false;
        }
        return true;
    }
};
