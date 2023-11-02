class MyHashSet {
    bitset<1000001> bs;
public:
    MyHashSet() {}
    void add(int key) { bs.set(key); }
    void remove(int key) { bs.reset(key); }
    bool contains(int key) { return bs.test(key); }
};
