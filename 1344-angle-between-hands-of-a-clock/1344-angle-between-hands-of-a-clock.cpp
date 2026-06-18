class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double ang = abs( (30*hour) - (5.5*minutes));
        return min( ang,360-ang );
    }
};