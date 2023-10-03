/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Twitter {
   public:
    long long timer;
    unordered_map<int, vector<pair<int, int>>> tMap;
    unordered_map<int, unordered_set<int>> foMap;

    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) {
        tMap[userId].push_back({timer, tweetId});
        timer++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        // Adding self tweetIds into PQ
        for (auto &pp : tMap[userId]) {
            pq.push(pp);
        }

        // Adding tweetIds of people who are being followed
        for (auto &pp : foMap[userId]) {
            for (auto &pp1 : tMap[pp]) {
                pq.push(pp1);
            }
        }

        vector<int> res;
        int cnt = 10;
        while (cnt > 0 and pq.size() > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        foMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        foMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
