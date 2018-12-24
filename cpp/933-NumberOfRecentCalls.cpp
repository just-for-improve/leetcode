class RecentCounter {
private:
    queue<int> ping_history;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        int ping_times = 0;
        int time_begin = t - 3000;
        while (!ping_history.empty() && ping_history.front() < time_begin) {
            ping_history.pop();
        }
        ping_history.push(t);
        return ping_history.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */