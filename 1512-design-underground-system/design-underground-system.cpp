class UndergroundSystem {
public:
unordered_map <int, pair<string,int>> checkIns;
unordered_map <string, pair<int,int>> travelTimes;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
    auto checkInInfo = checkIns[id];
    checkIns.erase(id);

    string journey = checkInInfo.first + "-" + stationName;
    int travelTime = t- checkInInfo.second;
    travelTimes[journey].first += travelTime;
    travelTimes[journey].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
     string journey = startStation + "-" + endStation;
     auto travelInfo = travelTimes[journey];
     return (double) travelInfo.first/travelInfo.second;

    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */