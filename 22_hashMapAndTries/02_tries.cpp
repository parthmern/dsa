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

int main(){

    TrieNode* root = new TrieNode('-');
    

    return 0;
}