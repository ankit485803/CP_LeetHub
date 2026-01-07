class MyHashSet {
private:
    vector<bool> hash;   //booleanArr approach

public:
    MyHashSet() {
        hash.resize(1000001, false);
    }
    
    void add(int key) {  //O(1) tc
        hash[key] = true;
    }
    
    void remove(int key) {  //O(1)
        hash[key] = false;
    }
    
    bool contains(int key) {  //O(1)
        return hash[key];
    }
};
