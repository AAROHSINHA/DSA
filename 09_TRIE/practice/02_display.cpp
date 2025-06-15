#include <iostream>
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
        int index = c - 'A';
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

// print all words
bool isLeafNode(TrieNode* root){
    for(int i = 0; i < 26; i+=1){
        if(root->children[i]!=NULL) return false;
    }
    return true;
}
void displayTree(TrieNode* root, char word[], int level ){
    if(isLeafNode(root)){
        word[level] = '\0';
        cout << word << "\n";
    }

    int i;
    for(i = 0; i < 26; i++){
        if(root->children[i]){
            word[level] = i + 'a';
            displayTree(root->children[i], word, level + 1);
        }
    }
}

// AUTOCOMPLETE
/*
For example if the Trie store {"abc", "abcd", "aa", "abbbaba"} and the User types in "ab" then he must be shown {"abc", "abcd", "abbbaba"}.

-> to ab ke b tak jao. consider it as root. Aur uske baad se saare children ke pehle ab laga ke print kro.
for eg, b ko root maanke ek string milega bbbaba, print ab + bbbaba = abbbbaba
*/
void displayAfterRoot(TrieNode* root, char str[], int level, string search){
    if(isLeafNode(root)){
        str[level] = '\0';
        cout << search << str << "\n";
    }

    int i;
    for(i = 0; i < 26; i+=1){
        if(root->children[i]!=NULL){
            str[level] = i + 'A';
            displayAfterRoot(root->children[i], str, level + 1, search);
        }
    }
}

void autoComplete(TrieNode* root, string search){
    TrieNode* currNode = root;
    for(char c : search){
        int index = c - 'A';
        if(currNode->children[index]){
            currNode = currNode->children[index];
        }else{
            cout << "WORD NOT PRESENT" << "\n";
            return;
        }
    }
    char str[26];
    int level = 0;
    displayAfterRoot(currNode, str, level, search);
}

int main(){
    TrieNode* trie = new TrieNode('\0');
    string arr[7] = {
        "ARM", "ARTICLE", " ART", "ARCHIVE", "BALL", "BACK", "BLACKLIST"
    };
    for(int i = 0; i < 7; i+=1){
        insert(trie, arr[i]);
    }

    cout << "Tree Autocomplete - " << "\n";
    autoComplete(trie, "B");
    return 0;
}
