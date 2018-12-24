#define MAX_SIZE 100000
class MyHashMap {
private:
    bool mask[MAX_SIZE];
    int key_pool[MAX_SIZE];
    int value_pool[MAX_SIZE];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (int i = 0; i < MAX_SIZE; ++i) {
            mask[i] = false;
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int start = key % MAX_SIZE;
        for (int i = 0; i < MAX_SIZE; ++i) {
            int loc = (start + i) % MAX_SIZE;
            if (mask[loc] == false || key_pool[loc] == key) {
                mask[loc] = true;
                key_pool[loc] = key; 
                value_pool[loc] = value;
                break;
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int start = key % MAX_SIZE;
        for (int i = 0; i < MAX_SIZE && mask[(start + i) % MAX_SIZE]; ++i) {
            if (key_pool[(start + i) % MAX_SIZE] == key)
                return value_pool[(start + i) % MAX_SIZE];
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int start = key % MAX_SIZE;
        for (int i = 0; i < MAX_SIZE && mask[(start + i) % MAX_SIZE]; ++i) {
            if (key_pool[(start + i) % MAX_SIZE] == key)
                mask[(start + i) % MAX_SIZE] = false;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */