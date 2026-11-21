class Solution {
public:
    bool bfs(int source, int target, unordered_map<int, vector<int>>& graph, vector<bool>&visited){
        visited[source] = true;

        queue<int>q;
        q.push(source);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neighbour : graph[node]){

                if(neighbour == target) return true;

                if(visited[neighbour] == false){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for(auto edge : edges){
            int from = edge[0];
            int to = edge[1];

            vector<bool> visited(edges.size() + 1, false);

            if(bfs(from, to, graph, visited)){
                return edge;
            }

            graph[from].push_back(to);
            graph[to].push_back(from);
        }


        return {};
    }
};
