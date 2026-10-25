class TrieNode{
    public:
    int data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;

    TrieNode(int val){
        data=val;
        isTerminal=false;
    }
};

void insertWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }
    char ch=word[0];

    if(root->children.find(ch)!=root->children.end()){
        root=root->children[ch];
    }
    else{
        TrieNode* temp=new TrieNode(ch);
        root->children[ch]=temp;
        root=root->children[ch];
    }

    insertWord(root,word.substr(1));
}

bool findWord(TrieNode* root,string word){
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch=word[0];
    if(root->children.find(ch)!=root->children.end()){
        root=root->children[ch];
        return findWord(root,word.substr(1));
    }
    else return false;
}

bool findPrefix(TrieNode* root,string prefix){
    if(prefix.length()==0){
        return true;   // reached the end of the prefix, so the path exists
    }
    char ch=prefix[0];
    if(root->children.find(ch)!=root->children.end()){
        root=root->children[ch];
        return findPrefix(root,prefix.substr(1));
    }
    else return false;
}

class Trie {

public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('-');
    }

    void insert(string word) {
        insertWord(root,word);
    }

    bool search(string word) {
        return findWord(root,word);
    }

    bool startsWith(string prefix) {
        return findPrefix(root,prefix);
    }
};