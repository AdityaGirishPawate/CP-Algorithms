// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

TrieNode* delete_trie(TrieNode *root, string &key,int i);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n],del[3];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        cin>>del[0]>>del[1]>>del[2];
        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc,def;

        cin >> abc>>def;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";

        for(auto & i : del)
            delete_trie(root,i,0);

        if (search(root, def))
            cout << "1\n";
        else
            cout << "0\n";

        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++



//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    int n=key.size();
    TrieNode* curr=root;
    for(int i=0;i<n;i++){
        int index = key[i]-'a';
        if(curr->children[index]==NULL){
            curr->children[index] = getNode();
        }
        curr = curr->children[index];
    }
    curr->isLeaf=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    int n=key.size();
    TrieNode* curr=root;
    for(int i=0;i<n;i++){
        int index = key[i]-'a';
        if(curr->children[index]==NULL){
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isLeaf;
}

bool isEmpty(TrieNode* root){
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            return true;
        }
    }
    return false;
}
TrieNode* delete_trie(TrieNode *root, string &key,int i){
    if(root==NULL){
        return NULL;
    }
    if(key.size()==i){
        root->isLeaf=false;
        if(isEmpty(root)){
            delete(root);
            root=NULL;
        }
        return root;
    }
    int index = key[i]-'a';
    root->children[index] = delete_trie(root->children[index], key,i+1);
    if(isEmpty(root) && root->isLeaf==false){
        delete(root);
        root=NULL;
    }
    return root;
}











