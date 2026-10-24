class Solution {
    int dayOfYear(string a,vector<int> &prefix) {
        int month=stoi(a.substr(0,2));
        int date=stoi(a.substr(3,2));
        return prefix[month-1]+date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(13,0);
        for(int i=1;i<12;i++) {
            prefix[i]=prefix[i-1]+monthDays[i-1];
        }
        int aliceArr=dayOfYear(arriveAlice,prefix);
        int aliceLeav=dayOfYear(leaveAlice,prefix);
        int bobArr=dayOfYear(arriveBob,prefix);
        int bobLeav=dayOfYear(leaveBob,prefix);
        return max(0,min(aliceLeav,bobLeav)-max(aliceArr,bobArr)+1);
    }
};
