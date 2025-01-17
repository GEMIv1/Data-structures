#include <bits/stdc++.h>
#include "HUFFNODE.h"
using namespace std;
#define nl "\n"




class HUFFMAN{
private:
        priority_queue<HUFFNODE*, vector<HUFFNODE*>, Compare> pq;
        map<char,string> mp;
        map<char,int> freq;
        HUFFNODE* root = nullptr;

        void freeTree(HUFFNODE* node) {
            if (node == nullptr) return;
            freeTree(node->left);
            freeTree(node->right);
            delete node;
        }


    void generateCode(HUFFNODE* node, string code){
        if(node==nullptr)return;
        if(node->left==nullptr && node->right==nullptr){
            mp[node->ch]=code;
        }
        generateCode(node->left,code+"0");
        generateCode(node->right,code+"1");
    }

public:

    void decode(string s){

        for(int i=0;i<(int)s.size();i++)freq[s[i]]++;

        for(auto it=freq.begin();it!=freq.end();it++)pq.push(new HUFFNODE(it->first,it->second));


        while(pq.size()!=1){
            HUFFNODE* node1 = pq.top();
            pq.pop();
            HUFFNODE* node2 = pq.top();
            pq.pop();
            HUFFNODE* newNode = new HUFFNODE('_',node2->freq+node1->freq);
            newNode->left = node1;
            newNode->right = node2;
            pq.push(newNode);
        }
        root = pq.top();
    }


    void encode(string s){
        generateCode(root,"");
        for(auto it:mp){
            cout<<it.first<<": "<<it.second<<nl;
        }

        string encoded = "";
        for(char ch:s)encoded+=mp[ch];
        cout<<encoded<<nl;
    }

    ~HUFFMAN(){
        freeTree(root);
    }

};
