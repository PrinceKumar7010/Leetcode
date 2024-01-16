class RandomizedSet {
public:
    unordered_set<int> us;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(us.find(val) == us.end()) {
            us.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(us.find(val) != us.end()) {
            us.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return *next(us.begin(),rand() % us.size());
    }
};

