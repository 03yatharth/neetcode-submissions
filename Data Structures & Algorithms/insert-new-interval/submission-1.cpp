class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int s=newInterval[0],e=newInterval[1],i=0;
        vector<vector<int>> ans;
        // before starting of newInterval
        while(i<n && s>intervals[i][1]){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        // handling overlapping interval
        while(i<n && e>=intervals[i][0]){
            s = min(s,intervals[i][0]);
            e = max(e,intervals[i][1]);
            i++;
        }
        // insert after merge 
        ans.push_back({s,e});
        while(i<n){
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        return ans;
    }
};