class RandomizedSet {
private:
    unordered_set<int> randSet;

public:
    /** Initialize your data structure here. */
    //RandomizedSet() {
        
    //}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto ret = randSet.insert(val);
        return ret.second;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = randSet.find(val);

        if (it == randSet.end()) return false;

        randSet.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rnd = rand() % randSet.size();

        auto it = randSet.begin();

        for (int i = 0; i < rnd; ++i){
            it++;
        }

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
