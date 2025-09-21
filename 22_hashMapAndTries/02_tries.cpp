#include <iostream>
using namespace std;

class TrieNode{
    public:

        char data;
        TrieNode* children[26]; // array of pointer
        bool isTerminal;

        TrieNode(char d){
            this->data = d;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word){
    if(word.length()==0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'A';

    TrieNode* child;
    if(root->children[index]==NULL){
        // if present nhi he then
        child = new TrieNode(ch);
        root->children[index] = child;
    }else{ 
        child = root->children[index];
    }
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word){
    if(word.length()==0){
        return root->isTerminal; 
    }
    
    char ch = word[0];
    int index = ch - 'A';

    TrieNode* child;
    if(root->children[index] == NULL){
        return false;
    }else{
        child = root->children[index];
    }
    return searchWord(child, word.substr(1));
 
}

bool deleteWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        if (root->isTerminal) {
            root->isTerminal = false;  // only unmark
            return true;
        }
        return false;
    }

    char ch = toupper(word[0]);
    int index = ch - 'A';

    TrieNode* child = root->children[index];
    if (child == NULL) {
        return false;
    }

    return deleteWord(child, word.substr(1));
}

int main() {
    TrieNode* root = new TrieNode('-');

    insertWord(root, "CAT");
    insertWord(root, "CAP");
    insertWord(root, "DOG");

    cout << (searchWord(root, "CAT") ? "Found" : "Not Found") << endl; // ✅ Found
    cout << (searchWord(root, "CAP") ? "Found" : "Not Found") << endl; // ✅ Found
    cout << (searchWord(root, "DOG") ? "Found" : "Not Found") << endl; // ✅ Found
    cout << (searchWord(root, "COW") ? "Found" : "Not Found") << endl; // ❌ Not Found

    deleteWord(root, "CAT");
    cout << (searchWord(root, "CAT") ? "Found" : "Not Found") << endl; // Not Found
    cout << (searchWord(root, "CAP") ? "Found" : "Not Found") << endl; // Still Found


    return 0;
}
