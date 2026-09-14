class Solution {
public:
    struct Trie{
        array<Trie *,26> nodes{};
        string word = "";
    };
    void DFS(int i,int j,Trie *cur,vector<vector<char>>& board,vector<string> &ans){
        int n=board.size(),m=board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='#')return ;
        char ch = board[i][j];
        if(!cur->nodes[ch-'a'])return ;
        board[i][j]='#';
        cur = cur->nodes[ch-'a'];
        if(cur->word.length()>0){
            ans.push_back(cur->word);
            cur->word = "";
        }
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for(int k=0;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];
            DFS(x,y,cur,board,ans);
        }
        board[i][j]=ch;
    }
    void insert(Trie *root,string &word){
        for(auto c:word){
            if(!root->nodes[c-'a'])root->nodes[c-'a'] = new Trie();
            root = root->nodes[c-'a'];
        }
        root->word=word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        vector<string> ans;
        Trie *root = new Trie();
        for(auto s:words){
            insert(root,s);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                DFS(i,j,root,board,ans);
            }
        }

        return ans;
    }
};