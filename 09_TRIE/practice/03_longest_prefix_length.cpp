#include <iostream>
#include <vector>
#include <string>
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
        int index = c - '0';
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

int getPrefixLength(TrieNode* root, string word){
    int length = 0;
    TrieNode* currNode = root;
    for(char c : word){
        int index = c - '0';
        if(currNode->children[index]){
            length++;
            currNode = currNode->children[index];
        }else{
            break;
        }
    }
    return length;
}

int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    TrieNode* trie = new TrieNode('\0');
    for(int num : arr2){
        insert(trie, to_string(num));
    }
    
    int maxLength = 0;
    for(int num : arr1){
        string prefix = to_string(num);
        int prefixLength = getPrefixLength(trie, prefix);
        maxLength = (maxLength < prefixLength) ? prefixLength : maxLength;
    }
    return maxLength;
}


int main(){
    vector<int> num1 = {1, 10, 100};
    vector<int> num2 = {1000};
    cout << longestCommonPrefix(num1, num2) << "\n";
    return 0;
}