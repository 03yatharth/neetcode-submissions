class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0,ans=0,sum=0,n=gas.size();
        for(int i=0;i<n;i++)sum+=gas[i];
        for(int i=0;i<n;i++)sum-=cost[i];
        if(sum<0)return -1;
        for(int i=0;i<n;i++){
            total += (gas[i]-cost[i]);
            if(total<0){
                total = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};
