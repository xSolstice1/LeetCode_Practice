class RandomizedSet {
private:
    vector<int> vals;
    unordered_map<int,int> idxMap; //maps val -> index

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (idxMap.count(val)) return false; //check if val is already in map
        vals.push_back(val);
        idxMap[val] = vals.size()-1; //update index mapping
        return true;
    }
    
    bool remove(int val) {
        if (!idxMap.count(val)) return false; //val not in map

        int last = vals.back();
        int pos = idxMap[val];

        //move last element to position of val
        vals[pos] = last;
        idxMap[last] = pos;

        vals.pop_back();
        idxMap.erase(val);

        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */