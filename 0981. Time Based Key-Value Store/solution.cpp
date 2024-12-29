#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> keyTimeValueStore; // key, {value, timestamp}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeValueStore[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = keyTimeValueStore.find(key);
        if (it == keyTimeValueStore.end()) {
            return "";
        }

        vector<pair<string, int>>& timeValuePair = it->second;
        int low = 0;
        int high = timeValuePair.size() - 1;

        while (low <= high) {
            int mid = low + ( high - low ) / 2;
            int storeTime = timeValuePair[mid].second;
            if (storeTime == timestamp) {
                return timeValuePair[mid].first;
            } else if (storeTime < timestamp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high >= 0? timeValuePair[high].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    return 0;
}
