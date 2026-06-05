// Last updated: 5/6/2026, 5:07:05 pm
class RideSharingSystem {
public:
    deque <int> drivers;
    deque <int> riders;
    RideSharingSystem() {
        //queue <int> drivers;
        //queue <int> riders;
    }
    
    void addRider(int riderId) {
        riders.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(drivers.empty() | riders.empty()) return {-1,-1};
        vector<int> ans(2);
        ans = {drivers.front(),riders.front()};
        drivers.pop_front(); riders.pop_front();
        return ans;
    }
    
    void cancelRider(int riderId) {
        stack <int> temp;
        while(!riders.empty()){
            if(riderId != riders.front()){
                temp.push(riders.front());
                riders.pop_front();
            }
            else{
                riders.pop_front();
                break;
            }
        }
        while(!temp.empty()){
            riders.push_front(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */