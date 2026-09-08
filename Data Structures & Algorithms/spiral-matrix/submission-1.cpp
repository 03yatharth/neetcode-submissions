class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ord;
        int rs=0,re=matrix.size()-1,cs=0,ce=matrix[0].size()-1;
        while(rs<=re && cs<=ce){
            // left
            for(int j=cs;j<=ce;j++)ord.push_back(matrix[rs][j]);
            rs++;
            // down
            if(rs<=re && cs<=ce)
            for(int i=rs;i<=re;i++)ord.push_back(matrix[i][ce]);
            ce--;
            // up
            if(rs<=re && cs<=ce)
            for(int j=ce;j>=cs;j--)ord.push_back(matrix[re][j]);
            re--;
            // right
            if(rs<=re && cs<=ce)
            for(int i=re;i>=rs;i--)ord.push_back(matrix[i][cs]);
            cs++;
        }
        return ord;
    }
};