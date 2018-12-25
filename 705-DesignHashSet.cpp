class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        for (int i = 0; i < 100001; ++i) {
            hashpool[i] = -1;
        }
    }
    
    void add(int key) {
        int pos = key % 100001;
        while (hashpool[pos] != -1) {
            pos = (++pos) % 100001;
        }
        hashpool[pos] = key;
    }
    
    void remove(int key) {
        int pos = key % 100001;
        while (hashpool[pos] != key && hashpool[pos] != -1) {
            pos = (++pos) % 100001;
        }
        hashpool[pos] = -1;
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int pos = key % 100001;
        while (hashpool[pos] != key && hashpool[pos] != -1) {
            pos = (++pos) % 100001;
        }
        if (hashpool[pos] == key)
            return true;
        return false;
    }
private:
    int hashpool[100001];
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */