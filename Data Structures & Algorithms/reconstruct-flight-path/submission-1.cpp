class Solution {
public:
    void DFS(string root,unordered_map<string,priority_queue<string,vector<string>,greater<string>>>&adj,vector<string> &ord){
        while(adj[root].size()!=0){
            string node = adj[root].top();
            adj[root].pop();
            DFS(node,adj,ord);
        }
        ord.push_back(root);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
        for(auto tk:tickets){
            adj[tk[0]].push(tk[1]);
        }
        vector<string> ord;
        DFS("JFK",adj,ord);
        reverse(ord.begin(),ord.end());
        return ord;
    }
};
