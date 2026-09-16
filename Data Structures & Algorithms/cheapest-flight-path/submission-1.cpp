class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int> glbCst(n,1e9);
        glbCst[src]=0;
        queue<vector<int>> que;
        que.push({0,src}); // cost|node 
        int stp=0;
        while(que.size()!=0 && stp<=k+1){
            int sz = que.size();
            for(int i=0;i<sz;i++){
                int cst = que.front()[0];
                int cur = que.front()[1];
                que.pop();
                glbCst[cur] = min(glbCst[cur],cst);
                for(auto nd:adj[cur]){
                    if(glbCst[nd.first]>nd.second+cst)
                    que.push({nd.second+cst,nd.first});
                }
            }
            stp++;
        }
        return glbCst[dst]==1e9 ? -1 : glbCst[dst];
    }
};