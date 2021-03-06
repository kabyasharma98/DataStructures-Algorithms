// A critical connection is a connection that, if removed, will 
// make some server unable to reach some other server.

// Return all critical connections in the network in any order.

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.

// Tarjans Algo
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> low;
    vector<int> order;
    int count = 0;
    vector<vector<int>> bridges;
    
    void dfs(int node, int parent)
    {
        visited[node] = true;
        low[node] = order[node] = count;
        count++;
        
        for(int neighbor : adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor, node);
                
                low[node] = min(low[node], low[neighbor]);
                
                if(order[node] < low[neighbor])
                    bridges.push_back({node, neighbor});
            }
            else if(neighbor != parent)
                low[node] = min(low[node], order[neighbor]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.resize(n, false);
        low.resize(n, 0);
        order.resize(n, 0);
        
        for(auto edges : connections)
        {
            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
        return bridges;
    }
};

// another same solution
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> low;
    vector<int> in;
    vector<vector<int>> bridge;
    int timer = 0;
    
    void dfs(int node, int parent)
    {
        visited[node] = true;
        low[node] = in[node] = timer;
        timer++;
        
        for(auto neighbor : adj[node])
        {
            if(visited[neighbor] && neighbor != parent)
                low[node] = min(low[node], in[neighbor]);
            else if(!visited[neighbor])
            {
                dfs(neighbor, node);
                
                low[node] = min(low[node], low[neighbor]);
                
                if(low[neighbor] > in[node])
                    bridge.push_back({node, neighbor});
            }
        }
        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visited.resize(n, false);
        in.resize(n, 0);
        low.resize(n, 0);
        adj.resize(n);
        
        for(auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(i, -1);
        }
            
        return bridge;
    }
};


