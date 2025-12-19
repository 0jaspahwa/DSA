class Solution {
public:
    typedef pair<int, int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> secretTime(n, INT_MAX);

        secretTime[0] = 0;
        secretTime[firstPerson] = 0;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [t, person] = pq.top();
            pq.pop();

            if (t > secretTime[person]) continue;

            for (auto& nbr : adj[person]) {
                int v = nbr.first;
                int mt = nbr.second;

                if (mt >= t && secretTime[v] > mt) {
                    secretTime[v] = mt;
                    pq.push({mt, v});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (secretTime[i] != INT_MAX) result.push_back(i);
        }
        return result;
    }
};