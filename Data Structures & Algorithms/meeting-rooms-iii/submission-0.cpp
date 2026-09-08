class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> rooms(n,0);
        vector<int> cnt(n,0);
        sort(meetings.begin(),meetings.end());
        for(auto &i:meetings){
            int st = i[0];
            int end = i[1];
            int ind = 0;
            bool flag = false;
            for(int j=0;j<n;j++){
                if(rooms[j]<=st){
                    flag = true;
                    cnt[j]++;
                    if(rooms[j]<st)rooms[j]=st;
                    rooms[j] += ((long long)end - st);
                    break;
                }
                if(rooms[ind]>rooms[j]){
                    ind = j;
                }
            }
            if(flag)continue;
            if(rooms[ind]<st)rooms[ind]=st;
            rooms[ind] += ((long long)end - st);
            cnt[ind]++;
        }
        int ind = 0;
        for(int i=0;i<n;i++){
            if(cnt[ind]<cnt[i])ind=i;
        }
        return ind;
    }
};