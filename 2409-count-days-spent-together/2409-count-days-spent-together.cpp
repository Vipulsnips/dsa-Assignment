class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrbobdate=stoi(arriveBob.substr(3)),arrbobmonth=stoi(arriveBob.substr(0, 2));
        int leavebobdate=stoi(leaveBob.substr(3)),leavebobmonth=stoi(leaveBob.substr(0, 2));
        int arralicedate=stoi(arriveAlice.substr(3)),arralicemonth=stoi(arriveAlice.substr(0, 2));
        int leavealicedate=stoi(leaveAlice.substr(3)),leavealicemonth=stoi(leaveAlice.substr(0, 2));
        vector<int> months={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<months.size();i++) months[i]+=months[i-1];
        int ans=0;
        for(int i=1;i<=365;i++){
            int a1=months[arralicemonth-1]+arralicedate,a2=months[leavealicemonth-1]+leavealicedate;
            int b1=months[arrbobmonth-1]+arrbobdate,b2=months[leavebobmonth-1]+leavebobdate;
            if(a1<=i && a2>=i && b1<=i & b2>=i) ans++;
        }
        return ans;
    }
};