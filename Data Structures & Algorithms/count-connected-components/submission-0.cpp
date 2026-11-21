class Solution {
public:
    void DFS(int sourceNode, vector<bool>& visited, unordered_map<int, vector<int>>& adjList){

        visited[sourceNode] = true;

        for(auto neighbours : adjList[sourceNode]){

            if(visited[neighbours] == false){
                DFS(neighbours, visited, adjList);
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adjList;

        for(int i = 0; i < edges.size(); i++){

            int node1 = edges[i][0];
            int node2 = edges[i][1];

            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);

        }

        vector<bool> visited(n, false);

        int count = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                DFS(i, visited, adjList);
                count++;
            }
        }

        return count;
    }
};
