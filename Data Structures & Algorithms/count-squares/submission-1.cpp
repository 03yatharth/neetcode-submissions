class CountSquares {
public:
    CountSquares() {
        
    }
    map<pair<int,int>,int> mp;
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0],y1 = point[1],ans=0;
        for(auto [pt,count] : mp){
            int x3=pt.first ,y3=pt.second;
            if(!(x1!=x3 && abs(x1-x3)==abs(y3-y1)))continue;
            if(mp.count({x1,y3}) && mp.count({x3,y1})){
                ans += count*mp[{x1,y3}]*mp[{x3,y1}];
            }
        }
        return ans;
    }
};
