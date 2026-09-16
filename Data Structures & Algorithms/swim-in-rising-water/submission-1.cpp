class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<bool>> vis(n,vector<bool> (m,false));

        vis[0][0] = true;
        pq.push({grid[0][0],{0,0}});

        while(pq.size()!=0){
            int cst = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            if(i==n-1 && j==m-1)return cst;
            pq.pop();

            int dx[4] = {0,0,1,-1}; 
            int dy[4] = {1,-1,0,0}; 
            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];

                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                    vis[x][y] = true;
                    pq.push({max(cst,grid[x][y]),{x,y}});
                }
            }
        }
        return 0;
    }
};