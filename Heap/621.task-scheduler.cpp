/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
struct sortMe{
    bool operator()(pair<int, char> &a, pair<int, char> &b){
        return a.first <= b.first;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            1. When we have a cooldown period or any job, first job that we 'll try to 
            put would be the one with maximum instances sort these in reverse order
            2. Keep track when the cooldown period is over O(26 * N) = O(N)
            3. {occurence_remaining, process_ID} --> MaxHeap
            minTimeForRun[process] = t --> Initially 0 for all
            When we use CPU for a process, minTimeForRun[process] = t+n
        */
        if(n == 0) return tasks.size();
        unordered_map<char, int> minRunTime; // {pName, firstTimeAvailable}
        unordered_map<char, int> cntRemaining; // {processName, count}
        for(char ch: tasks){
            minRunTime[ch] = 0;
            cntRemaining[ch]++;
        } 
        // cntRemaining = ["A": 3, "B": 2, "C":1, "D": 4]
        // minRunTime = ["A": 4, "B": 0, "C": 0, "D": 3]
        // O(26**3 * N)
        int time = 1;
        while(cntRemaining.size() > 0){
            priority_queue<pair<int, char>, vector<pair<int, char>>, sortMe> pq;
            for(auto pp: cntRemaining){
                if(minRunTime[pp.first] <= time){
                    pq.push({pp.second, pp.first});
                }
            }
            // pq = [{4, 'D'},{3, 'A'}, {2, 'B}, {1, 'C'}]
            // Using the process at the top
            if(!pq.empty()){
                auto top = pq.top(); pq.pop();
                minRunTime[top.second] = time + n+1;
                cntRemaining[top.second]--;
                if(cntRemaining[top.second] == 0)
                    cntRemaining.erase(top.second);
            }
            time++;
        }
        return time-1;
    }
};
// @lc code=end

