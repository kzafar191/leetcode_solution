// Last updated: 5/6/2026, 5:05:36 pm
class EventManager {
    unordered_map <int,int> idtoprio;
    set <pair<int,int>> active;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto &e :events){
            idtoprio[e[0]] = e[1];
            active.insert({-e[1],e[0]});
            
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        active.erase({-idtoprio[eventId],eventId});
        idtoprio[eventId] = newPriority;
        active.insert({-newPriority,eventId});
    }
    
    int pollHighest() {
        if(active.empty()) return -1;
        int id = active.begin()->second;
        active.erase(active.begin());
        idtoprio.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */