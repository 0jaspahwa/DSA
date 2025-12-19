class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
    void reset(int i) {
        parent[i] = i;
    }
    bool isConnected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        dsu.unite(0, firstPerson);

        int i = 0;
        int m = meetings.size();
        while (i < m) {
            int currentTime = meetings[i][2];
            vector<int> pool;
            
            int start = i;
            while (i < m && meetings[i][2] == currentTime) {
                dsu.unite(meetings[i][0], meetings[i][1]);
                pool.push_back(meetings[i][0]);
                pool.push_back(meetings[i][1]);
                i++;
            }

            for (int person : pool) {
                if (!dsu.isConnected(person, 0)) {
                    dsu.reset(person);
                }
            }
        }

        vector<int> ans;
        for (int j = 0; j < n; j++) {
            if (dsu.isConnected(j, 0)) ans.push_back(j);
        }
        return ans;
    }
};