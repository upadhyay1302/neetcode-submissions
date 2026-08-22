class MyHashSet {
public:
    vector<int> hash;
    MyHashSet() {
        
    }
    
    void add(int key) {
        hash.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0; i < hash.size(); i++){
            if(hash[i] == key){
                hash[i] = INT_MAX;
            };
        }

    }
    
    bool contains(int key) {
        for(int i = 0; i < hash.size(); i++){
            if(hash[i] == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */