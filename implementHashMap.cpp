class MyHashMap {
    vector<list<pair<int, int>>> m;
    int siz;
public:
    MyHashMap() {
        siz = 1000;
        m.resize(siz);
    }
    
    int hash(int key) {
        return key % siz;
    }
    
    list<pair<int, int>> :: iterator search(int key) {
        int index = hash(key);
        list<pair<int, int>> :: iterator it = m[index].begin();
        while(it != m[index].end()) {
            if(it ->  first == key)
                return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it == m[i].end()) 
            return -1;
        else 
            return it -> second; 
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        if(it != m[i].end())
            m[i].erase(it);
    }
};
