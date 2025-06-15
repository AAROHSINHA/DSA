#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char val){
        this->data = val;
        this->isTerminal = false;
        for(int i = 0; i < 26; i+=1){
            children[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string word){
    TrieNode* currNode = root;
    for(char c : word){
        int index = c - 'a';
        if(currNode->children[index]!=NULL){
            currNode = currNode->children[index]; 
        }else{
            TrieNode* newNode = new TrieNode(c);
            currNode->children[index] = newNode;
            currNode = currNode->children[index];
        }
    }
    currNode->isTerminal = true;
}

bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode*  root = new TrieNode('\0');
    for(string word : wordDict){
        insert(root, word);
    }
    int ptr = 0;
    TrieNode* currNode = root;
    while(ptr < s.length()){
        if(currNode->isTerminal){
            currNode = root;
        }
        int index = s[ptr] - 'a';
        if(currNode->children[index]){
            currNode = currNode->children[index];
        }else{
            return false;
        }
        ptr++;
    }
    return currNode->isTerminal || currNode==root;
}

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << "\n";
    return 0;
}
