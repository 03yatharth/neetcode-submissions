class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
        [](const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        });

        int cnt=0,lastEnd = INT_MIN;

        for(auto &i:intervals){
            if(lastEnd <= i[0]){
                cnt++;
                lastEnd = i[1];
            }
        }
        return intervals.size() - cnt;
    }
};