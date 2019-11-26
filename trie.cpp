/*

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.

*/

#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

struct Node{
    char val;
    map<char, Node*> children;
    bool isEnd;

    Node(char v, bool end = false){
        val = v;
        isEnd = end;
    }    
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node('$');
        }

        void addWord(string word){
            Node* curr = root;
            for(int i = 0; i < word.size(); i++){
                Node* next = new Node(word[i]);
                if(curr->children.count(word[i]) <= 0){
                    curr->children[word[i]] = next;
                }
                curr = curr->children[word[i]];
            }
            curr->isEnd = true;
        }

        bool containsWord(string word){
            Node* curr = root;
            for(int i = 0; i < word.size(); ++i){
                if(curr->children.count(word[i]) <= 0){
                    return false;
                }
                curr = curr->children[word[i]];
            }
            return curr->isEnd;
        }

        vector<string> getAllWithPrefix(string prefix){
            vector<string> words;

            Node* curr = root;
            for(int i = 0; i < prefix.size(); ++i){
                if(curr->children.count(prefix[i]) <= 0){
                    return words;
                }
                curr = curr->children[prefix[i]];
            }

            string word = prefix;

            traverse(words, word, curr);

            return words;
        }

        void traverse(vector<string>& words, string word, Node* curr){

            if(curr == nullptr){
                return;
            }

            if(curr->isEnd){
                words.push_back(word);
            }

            for(const auto& child : curr->children){
                traverse(words, word + child.first, child.second);
            }
        }
};

int main(){

    Trie trie;

    trie.addWord("dear");
    trie.addWord("deal");
    trie.addWord("dogs");

    vector<string> words = trie.getAllWithPrefix("de");

    for(int i = 0; i < words.size(); i++){
        cout<<words[i]<<endl;
    }
}
