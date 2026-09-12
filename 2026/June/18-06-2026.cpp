// LeetCode 1344. Angle Between Hands of a Clock
// Daily challenge: 2026-06-18
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute_angle = minutes * 6.0;
        double hour_angle = (hour % 12) * 30.0 + (minutes / 60.0) * 30.0;
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360.0 - diff);
    }
};
