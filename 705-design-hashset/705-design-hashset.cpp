class MyHashSet {
public:
    const int ans_size=100;
    vector<int>ans[100];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index=key%ans_size;
        if(!contains(key))
            ans[index].push_back(key);
    }
    
    void remove(int key) {
        int index=key%ans_size;
        for(int i=0;i<ans[index].size();i++)
        {
            if(ans[index][i]==key)
            {
                ans[index].erase(ans[index].begin()+i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int index=key%ans_size;
        for(int i=0;i<ans[index].size();i++)
        {
            if(ans[index][i]==key)
            {
                return true;
            }
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