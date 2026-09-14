class WordDictionary {
public:
    struct Trie{
        array<Trie *,26> nodes {};
        bool isEnd=false;
    };
    Trie *root = new Trie();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Trie *mover = root;
        for(auto c:word){
            if(!mover->nodes[c-'a']){
                mover->nodes[c-'a'] = new Trie();
            }
            mover=mover->nodes[c-'a'];
        }
        mover->isEnd = true;
    }
    
    bool search(string word) {
        return mySearch(root,0,word);
    }

    bool mySearch(Trie *par,int ind,string &word){
        Trie *mover = par;
        if(ind>=word.length())return mover->isEnd;
        char c = word[ind];
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(mover->nodes[i] && mySearch(mover->nodes[i],ind+1,word))return true;
            }
            return false;
        }
        else if(!mover->nodes[c-'a'])return false;
        return mySearch(mover->nodes[c-'a'],ind+1,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */