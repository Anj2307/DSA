class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(fabs(30.0*hour-5.5*minutes)>180)
        return 360.0-fabs(30.0*hour-5.5*minutes);
        return fabs(30.0*hour-5.5*minutes);
    }
};