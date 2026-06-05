// Last updated: 5/6/2026, 5:05:38 pm
class Solution {
public:
    double getarea(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if(a+b<=c) return {};
        double area = getarea(a,b,c);
        double h = (2*area)/c;
        vector<double> angle(3);
        double pi = 3.14159265358979323846;
        angle[0] = asin(h/b)*180/pi;
        angle[1] = asin(h/a)*180/pi;
        angle[2] = 180-angle[0]-angle[1];
        return angle;
    }
};