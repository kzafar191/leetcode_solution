// Last updated: 5/6/2026, 5:08:34 pm
class Robot {
    int w, h, p, s = 0;
    bool f = false;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        p = 2 * (w + h - 2);
    }
    
    void step(int n) {
        if (n > 0) f = true;
        s = (s + n) % p;
    }
    
    vector<int> getPos() {
        if (s < w) return {s, 0};
        if (s < w + h - 1) return {w - 1, s - w + 1};
        if (s < 2 * w + h - 2) return {2 * w + h - 3 - s, h - 1};
        return {0, p - s};
    }
    
    string getDir() {
        if (!f || (s > 0 && s < w)) return "East";
        if (s >= w && s < w + h - 1) return "North";
        if (s >= w + h - 1 && s < 2 * w + h - 2) return "West";
        return "South"; 
    }
};