class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<vector<int>> glbCst(k+2,vector<int> (n,1e9)); // glbCost[step][node]
        glbCst[0][src]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,src});
        while(pq.size()!=0){
            int cst = pq.top()[0];
            int stp = pq.top()[1];
            int cur = pq.top()[2];
            pq.pop();
            if(stp>k+1 || cst>glbCst[stp][cur])continue;
            if(cur == dst)return glbCst[stp][cur];
            if(stp<k+1){
                for(auto nd:adj[cur]){
                    int nextNode = nd.first;
                    int price = nd.second;
                    if(price+cst<glbCst[stp+1][nextNode]){
                        glbCst[stp+1][nextNode] = cst+price;
                        pq.push({price+cst,stp+1,nextNode});
                    }
                    
                }
            }
        }
        return -1;
    }
};