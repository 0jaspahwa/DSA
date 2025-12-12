#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineTime(numberOfUsers, 0);

        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b){
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) return timeA < timeB;
            return b[0] < a[0];
        });

        for (const auto &event : events) {
            if (event[0] == "MESSAGE") {
                handleMessage(event, mentions, offlineTime);
            } else if (event[0] == "OFFLINE") {
                handleOffline(event, offlineTime);
            }
        }

        return mentions;
    }

private:
    void handleMessage(const vector<string>& event, vector<int>& mentions, vector<int>& offlineTime) {
        int timestamp = stoi(event[1]);
        string content = (event.size() > 2) ? event[2] : "";

        stringstream ss(content);
        string token;
        while (ss >> token) {
            if (token == "ALL") {
                for (size_t i = 0; i < mentions.size(); ++i) mentions[i]++;
            } 
            else if (token == "HERE") {
                for (size_t i = 0; i < mentions.size(); ++i) {
                    if (offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) mentions[i]++;
                }
            } 
            else {
                if (token.size() > 2) {
                    string idStr = token.substr(2);
                    try {
                        int id = stoi(idStr);
                        if (id >= 0 && id < (int)mentions.size()) mentions[id]++;
                    } catch (...) {}
                }
            }
        }
    }

    void handleOffline(const vector<string>& event, vector<int>& offlineTime) {
        int timestamp = stoi(event[1]);
        int id = stoi(event[2]);
        if (id >= 0 && id < (int)offlineTime.size()) offlineTime[id] = timestamp;
    }
};
