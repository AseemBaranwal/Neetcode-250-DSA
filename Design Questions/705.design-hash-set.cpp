/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class MyHashSet {
    // A very easy approach is to use a hashmap to solve the problem. However, without
    // using any datastructures, we can do it using the Linked List and hashing.
    // Whenever we face collision, we would put the node at the tail at the hashed key
    int prime = 10007;
    vector<list<int>> lst = vector<list<int>>(prime);
    list<int>::iterator searchList(int key){
        int h = key%prime;
        return find(lst[h].begin(), lst[h].end(), key);
    }
public:
    MyHashSet() {}
    void add(int key) {
        int h = key%prime;
        if(!contains(key)){
            lst[h].push_back(key);
        }
    }
    
    void remove(int key) {
        int h = key%prime;
        auto it = searchList(key);
        if(it != lst[h].end()){
            lst[h].erase(it);
        }
    }
    
    bool contains(int key) {
        int h = key%prime;
        return searchList(key) != lst[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

