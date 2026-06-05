// Last updated: 5/6/2026, 5:05:29 pm
class Solution {
public:
    string trafficSignal(int timer) {
        if(timer==0) return "Green";
        if(timer<=90 && timer>30) return "Red";
        if(timer==30) return "Orange";
        return "Invalid";
    }
};