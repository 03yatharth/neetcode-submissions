class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int> mp;
        for(auto &i:hand)mp[i]++;
        for(auto &i:mp){
            int cur=i.first;
            int freq=i.second;
            for(int j=1;j<groupSize;j++){
                int next=cur+j;
                if(mp.count(next)==0 || mp[next]<freq)return false;
                mp[next]-=freq;
                if(mp[next]==0)mp.erase(next);
            }
            mp.erase(cur);
        }
        return true;
    }
};