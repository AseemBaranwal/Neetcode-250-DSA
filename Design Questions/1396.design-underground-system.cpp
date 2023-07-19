/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> inStation; // {in-station, in-time}
    unordered_map<string, pair<double, int>> avgTime; // Average time taken is stored in format IND-USA {averageTime, totalTimesCalulated}
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        inStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int timeTaken = t-inStation[id].second;
        string journey = inStation[id].first + "-" + stationName;
        inStation.erase(id); // Very essential as the number of passengers could be a lot
        if(avgTime.count(journey) > 0){
            double currentAvg = avgTime[journey].first;
            int numPrevJourneys = avgTime[journey].second;
            double newAvgTime = (currentAvg*numPrevJourneys + timeTaken)/(numPrevJourneys+1);
            avgTime[journey] = {newAvgTime, numPrevJourneys+1};
        }else{
            avgTime[journey] = {timeTaken, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journeyStr = startStation + "-" + endStation;
        return avgTime[journeyStr].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

