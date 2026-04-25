class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        unordered_map<int,vector<int>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> dist(V, -1);
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int w = dist[u];
            for(auto ne : adj[u]){
                if(dist[ne] == -1){
                    dist[ne] = w + 1;
                    q.push(ne);
                }
            }
        }
        return dist;
    }
};
