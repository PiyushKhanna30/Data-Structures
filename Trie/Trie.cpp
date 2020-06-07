#include "TrieNode.h"
#include<iostream>
#include<string>
using namespace std;
class Trie
{
    TrieNode *root;
    void insertWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
    }
    bool searchWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return searchWord(child,word.substr(1));
    }
    void deleteWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return;
        }
        deleteWord(child,word.substr(1));
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL){
                    return;}
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    public:
    Trie()
    {
        root=new TrieNode('\0');
    }
    void ins(string word)
    {
        insertWord(root,word);
    }
    void sear(string word)
    {
        if(searchWord(root,word))
            cout<<"\nFound";
        else
            cout<<"\nNot found";
    }
    void del(string word)
    {
        deleteWord(root,word);
    }

};
int main()
{
    Trie obj;
    int x=1;
    while (x!=0)
    {
        int choice;
        string word;
        cout<<"\nEnter 1 to insert";
        cout<<"\nEnter 2 to search";
        cout<<"\nEnter 3 to delete";
        cout<<"\nEnter 0 to exit\n";
        cin>>choice;
        switch(choice)
        {

            case 1:
            {
                cout<<"\nEnter word : " ;
                cin>>word;
                obj.ins(word);
                break;
            }
            case 2:
            {
                cout<<"\nEnter word : " ;
                cin>>word;
                obj.sear(word);
                break;
            }
            case 3:
            {
                cout<<"\nEnter word : " ;
                cin>>word;
                obj.del(word);
                break;
            }
            case 0:
            {
                x=0;
                break;
            }
            default:
            {
                cout<<"\nUnexpected input...";
            }
        }
    }
}
