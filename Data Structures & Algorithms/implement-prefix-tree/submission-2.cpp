class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    struct MyTri{
        array <MyTri *,26> nodes = {};
        bool isEnd=false;
    };

    MyTri *root = new MyTri(); 
    void insert(string word) {
        MyTri *mover = root;
        for(auto c:word){
            int ind = c-'a';
            if(!mover->nodes[ind])
                mover->nodes[ind] = new MyTri();
            mover = mover->nodes[ind];
        }
        mover->isEnd = true;
    }
    
    bool search(string word) {
        MyTri *mover = root;
        for(auto c:word){
            int ind = c-'a';
            if(!mover->nodes[ind])return false;
            mover = mover->nodes[ind];
        }
        return mover->isEnd;
    }
    
    bool startsWith(string prefix) {
        MyTri *mover = root;
        for(auto c:prefix){
            int ind = c-'a';
            if(!mover->nodes[ind])return false;
            mover = mover->nodes[ind];
        }
        return true;
    }
};
