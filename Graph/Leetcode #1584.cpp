class Solution {
public:
    int dis(vector<int>& v1, vector<int>& v2) {
        return abs(abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1) return 0;
        vector<vector<pair<int, int>>> edge(points.size());
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                edge[i].push_back({j, dis(points[i], points[j])});
                edge[j].push_back({i, dis(points[i], points[j])}); //undirected graph
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(points.size(), false);
        pq.push({0, 0}); //start pos
        int cost = 0;

        //prim's algo.
        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (vis[node]) continue; 
            vis[node] = true; //visited

            cost += weight; // add weight 

            for (auto& [adj, adjweight] : edge[node]) {
                if (!vis[adj]) {
                    pq.push({adjweight, adj});
                }
            }
        }
        return cost;
    }
};
