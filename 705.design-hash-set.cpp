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
    // Whenever we face collision, we would put the node at the head at the hashed key
    int prime = 10007;
    vector<list<int>> lst = vector<list<int>>(prime);
    list<int>::iterator searchList(int key){
        key %= prime;
        return find(lst[key].begin(), lst[key].end(), key);
    }
public:
    MyHashSet() {}
    void add(int key) {
        key %= prime;
        if(!contains(key)){
            lst[key].push_back(key);
        }
    }
    
    void remove(int key) {
        key %= prime;
        auto it = searchList(key);
        if(it != lst[key].end()){
            lst[key].erase(it);
        }
    }
    
    bool contains(int key) {
        key %= prime;
        return searchList(key) != lst[key].end();
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

