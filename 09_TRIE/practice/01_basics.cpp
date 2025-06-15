#include <iostream>
using namespace std;

// Making the TrieNode
class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char value){
        this->data = value;
        this->isTerminal = false;
        for(int i = 0; i < 26; i+=1){
            this->children[i] = NULL;
        }
    }
};

// Trie Class
class Trie{
public:
    TrieNode* root;
    // initializing the root to a null character
    Trie(){
        root = new TrieNode('\0');
    }


    // 1. INSERT FUNCTION
    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            cout << "WORD ADDED!" << "\n";
            return;
        }

        // insertion logic
        // if word characters in the root iterate else add
        TrieNode* child;
        int index = word[0] - 'A';
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
    }


    // 2. SEARCH FUNCTION
    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        // search logic
        TrieNode* child;
        int index = word[0] - 'A';
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }

};

// OUT OF CLASS INSERT FUNCTION
void insert(TrieNode* root, const string& word) {
    TrieNode* currNode = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (currNode->children[index] == NULL) {
            currNode->children[index] = new TrieNode(ch);
        }
        currNode = currNode->children[index];
    }
    currNode->isTerminal = true;
}


// OUT OF CLASS SEARCH FUNCTION
bool search(TrieNode* root, const string& word){
    TrieNode* currNode = root;
    for (char ch : word) {
        int index = ch - 'A';
        if (currNode->children[index] == NULL) {
            return false;
        }
        currNode = currNode->children[index];
    }
    return currNode->isTerminal; // <- This is critical!
}

// // OUT OF CLASS DELETE -  THIS BELOW HAS LOTS OF ERRORS
// void deleteWord(TrieNode* root, string word){
//     // 1. word not present
//     if(!search(root, word)){
//         cout << "WORD IS NOT PRESENT!" << "\n";
//         return;
//     }

//     // Word has not other branches (we can directly remove the word)
//     if(!hasBranches(root, word)){
//         int index = word[0] - 'A';
//         root->children[index] = NULL; 
//         /*
//         PROBLEM HERE - Suppose the word to delete was ARMY and it is in the trie
//         we remove A from root so now trie wont have ARMY. But the characters and TrieNodes
//         of A R M Y Stay floating in the memory! Look into it
//         */
//         return;
//     }

//     // means word has other branches.
//     // get till the last branch where word splits.
//     /*
//     eg - for army and article, splits at r. If we need to delete army, delete the m
//     */
//     TrieNode* currNode = root;
//     TrieNode* lastSplitNode;
//     int splitIndex = -1;
//     int i = 0;
//     for(char c : word){
//         int index = c - 'A';
//         for(int i = 0; i < 26; i+=1){
//             for(int i = 0; i < 26; i+=1){
//                 if(i == index) continue;
//                 if(currNode->children[i]!=NULL){
//                     lastSplitNode = currNode;
//                     splitIndex = i;
//                 }
//         }
//         i++;
//         }
//     }
//     int delIndex = word[splitIndex + 1] - 'A';
//     lastSplitNode->children[delIndex] = NULL;
//     // this has the same floating problem as above.
//     // plus this is not optimal by any means

// }

// bool hasBranches(TrieNode* root, string word){
//     TrieNode* currNode = root;
//     for(char c : word){
//         int index = c - 'A';
//         // look in children apart from index for other non nulls
//         // if null found means multiple words/branches return true
//         for(int i = 0; i < 26; i+=1){
//             if(i == index) continue;
//             if(currNode->children[i]!=NULL) return true;
//         }
//     }
//     return false;
// }

// Recursive function
bool deleteWordHelper(TrieNode* node, const string& word, int depth = 0) {
    if (!node) return false;

    if (depth == word.length()) {
        if (!node->isTerminal) return false; // word not present

        node->isTerminal = false;

        // Check if node has any children — if not, we can delete this node
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) return false; // can't delete node
        }
        return true; // delete this node
    }

    int index = word[depth] - 'A';
    if (!node->children[index]) return false;

    bool shouldDeleteChild = deleteWordHelper(node->children[index], word, depth + 1);

    if (shouldDeleteChild) {
        delete node->children[index];
        node->children[index] = nullptr;

        // If current node is not terminal and has no children, it can also be deleted
        if (!node->isTerminal) {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) return false;
            }
            return true;
        }
    }

    return false;
}

// OUT OF CLASS DELETE FUNCTION
void deleteWord(TrieNode* root, const string& word) {
    if (!search(root, word)) {
        cout << "WORD IS NOT PRESENT!" << "\n";
        return;
    }
    deleteWordHelper(root, word);
}


int main() {
    // Initialize the root node with '\0' (empty root)
    TrieNode* root = new TrieNode('\0');

    // Insert words
    insert(root, "ARM");
    insert(root, "ARTICULATE");
    insert(root, "ROBOT");
    insert(root, "SOCCER");
    insert(root, "SOFT");

    // Search words
    cout << "Search ARM: " << search(root, "ARM") << endl;         // Expected: 1 (true)
    cout << "Search ARTICULATE: " << search(root, "ARTICULATE") << endl; // Expected: 1 (true)
    cout << "Search ART: " << search(root, "ART") << endl;         // Expected: 0 (false, not inserted)
    cout << "Search SOFTER: " << search(root, "SOFTER") << endl;   // Expected: 0 (false)

    return 0;
}