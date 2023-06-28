/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class MyHashMap {
    int prime = 10007;
    vector<list<pair<int, int>>> hashMap = vector<list<pair<int, int>>>(prime);
    list<pair<int, int>>::iterator findIterator(list<pair<int, int>> &lst, int key){
        list<pair<int, int>>::iterator it = lst.begin();
        while(it != lst.end()){
            if(it->first == key){
                return it;
            }
        }
        return it;
    }
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        int h = key%prime;
        if(get(key) == -1){
            hashMap[h].push_back({key, value});
        }else{
            auto it = findIterator(hashMap[h], key);
            it->second = value;
        }
    }
    
    int get(int key) {
        int h = key%prime;
        auto it = findIterator(hashMap[h], key);
        return it == hashMap[h].end() ? -1 : it->second;
    }
    
    void remove(int key) {
        int h = key%prime;
        if(get(key) != -1){
            auto it = findIterator(hashMap[h], key);
            hashMap[h].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

