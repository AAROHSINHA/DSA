#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        // in the beginning the childrens will be null (until added)
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0'); // root node starts with null character
    }

    /////////////////////////////////////////////////////////////////////////
    // 1. INSERT ////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){ // word length is 0 means we have inserted most characters
            root->isTerminal = true;
            return;
        }

        // assumption - word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL){
            // means the letter is present
            child = root->children[index];
        }else{
            // means not present
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1)); // word ka first letter check ho gya h toh uske alawa wla word bhejo

    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    /////////////////////////////////////////////////////////////////////////
    // 2. SEARCH ////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            // means word is over. Now we need to check if the node we are at is terminal node
            // if yes then the string is present
            // if no means something other is present
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            // means character is present. 
            child = root->children[index];
        }else{
            // word not found
            return false;
        }

        // RECURSION
        return searchUtil(child, word.substr(1));
    }   
    
    bool search(string word){
        return searchUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("HELLO");
    cout << "Present or not - ";
    cout << t->search("HELL") << "\n";
    return 0;
}