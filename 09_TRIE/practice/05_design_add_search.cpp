#include <iostream>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char value){
        this->data = value;
        this->isTerminal = false;
        for(int i = 0; i < 26; i+=1){
            this->children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('\0');
    }
    
    void addWord(string word) {
        TrieNode* currNode = root;
        for(char c : word){
            int index = c - 'a';
            if(currNode->children[index]){
                currNode = currNode->children[index];
            }else{
                TrieNode* newNode = new TrieNode(c);
                currNode->children[index] = newNode;
                currNode = currNode->children[index];
            }
        }
        currNode->isTerminal = true;
    }
    
    bool isLeafNode(TrieNode* root){
        if(root->isTerminal) return true;
        return false;
    }

    void getWord(TrieNode* root, char str[20],string word, int level, bool& status){
        if(isLeafNode(root)){
            if(sizeof(str)/sizeof(char)!=level){
                return;
            }
            if(str == word){
                status = true;
                return;
            }
            for(int i = 0; i < word.length(); i+=1){
                if(word[i] == '.') continue;
                if(str[i] != word[i]) return;
            }
        }

        int i;
        for(i = 0; i < 26; i+=1){
            if(root->children[i]){
                str[level] = i + 'a';
                getWord(root->children[i], str, word, level + 1, status);
            }
        }
    }

    bool search(string word) {
        bool res =false;
        char str[20];
        int level = 0;
        getWord(root, str, word, level, res);
        return res; 
    }
};

int main(){

}