class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>> freq(26,{1e9,-1});
        for(int i=0;i<s.length();i++){
            int ind = s[i]-'a';
            if(freq[ind].first==1e9){
                freq[ind].first = i;
                freq[ind].second = i;
            }
            else freq[ind].second = i;
        }
        sort(freq.begin(),freq.end());
        int l=0,r=freq[0].second;
        vector<int> ans;
        for(auto &i:freq){
            if(i.first==1e9)continue;
            if(i.first>r){
                ans.push_back(r-l+1);
                l=i.first;
            }
            r = max(r,i.second);
        }
        ans.push_back(r-l+1);
        return ans;
    }
};
