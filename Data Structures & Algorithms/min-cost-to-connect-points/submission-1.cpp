class Solution {
public:
    vector<int> par,rank;
    int findPar(int node){
        if(par[node] == node)return node;
        return par[node] = findPar(par[node]);
    }
    void myUnion(int u,int v){
        int ultU = findPar(u);
        int ultV = findPar(v);
        if(rank[ultU]>rank[ultV]){
            par[ultV] = ultU;
        }
        else if(rank[ultU]<rank[ultV]){
            par[ultU] = ultV;
        }
        else{
            par[ultU] = ultV;
            rank[ultV]++;
        }
    }
    void DSU(int n){
        par.resize(n);
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU(n);
        priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1]; 
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                int dis = abs(x2-x1) + abs(y2-y1); 
                pq.push({dis,{i,j}});
            }
        }
        int ans=0;
        while(pq.size()!=0){
            int dis = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(findPar(u) != findPar(v)){
                myUnion(u,v);
                ans+=dis;
            }
        }
        return ans;
    }
};

// find all distace 
// push them in pq
// if not making cycle add edge 