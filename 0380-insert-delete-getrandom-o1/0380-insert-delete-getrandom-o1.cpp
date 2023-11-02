class RandomizedSet {
public:
    vector<int> ans;
    unordered_map<int,int> map;

    RandomizedSet() {
    }
    
    bool insert(int val) {
    if (map.find(val) == map.end()){
        ans.push_back(val);
        map[val] = ans.size()-1;
        return true;

    }
    else{
    return false;
    }
    }
    
    bool remove(int val) {
    if(map.find(val) == map.end())
        return false;
    else{
            int last=ans.back();  
            ans[map[val]]=ans.back(); 		                
            ans.pop_back();	    
            map[last]=map[val];	    
            map.erase(val);	    
            return true;         
    }
}
    
    int getRandom() {
        return ans[rand() % ans.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */