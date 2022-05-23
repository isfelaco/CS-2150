/**
 * Isabella Felaco, isf4rjk
 * Inlab 10
 * huffmandec.cpp
 * 4-20-22
 * 
 * sources:
 * 
 * inlab-skeleton.cpp
**/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <vector>
using namespace std;

struct node {
    string value;
    int frequency;
    node* left;
    node* right;
    node();
    node(string v);
};

node::node() {
    value = "-";
    frequency = 0;
    left = NULL;
    right = NULL;
};

node::node(string v) {
    value = v;
    left = NULL;
    right = NULL;
};

bool insert(node* n, string value, string prefix) {
    if (prefix[0] == '0') {
        if (prefix.length() == 1) {
            if (n->left == NULL){n->left = new node();}
            n->left->value = value;
            return true;
        }
        else {
            if (n->left == NULL) {n->left = new node("-");}
            prefix = prefix.substr(1,prefix.length()-1);
            insert(n->left, value, prefix);
        }          
    }
    else if (prefix[0] == '1') {
        if (prefix.length() == 1) {
            if (n->right == NULL){n->right = new node();}
            n->right->value = value;
            return true;
        }
        else {
            if (n->right == NULL) {n->right = new node("-");}
            prefix = prefix.substr(1,prefix.length()-1);
            insert(n->right, value, prefix);
        }          
    }
    return false;
}

string traverse(node* n, string prefix) {
    if (n->left == NULL && n->right == NULL) {
        cout << n->value;
        return prefix;
    }
    if (prefix[0] == '0') {
        if (n->left == NULL) {
            return "Prefix not in tree!";
        }
        else if (prefix.length() == 1) {
            cout << n->left->value;
        }
        else {
            prefix = prefix.substr(1,prefix.length()-1);
            return traverse(n->left, prefix);
        }          
    }
    else if (prefix[0] == '1') {
        if (n->right == NULL) {
            return "Prefix not in tree!";
        }
        else if (prefix.length() == 1) {
            cout << n->right->value;
        }
        else {
            prefix = prefix.substr(1,prefix.length()-1);
            return traverse(n->right, prefix);
        }           
    }
    return "-";
}

int main (int argc, char** argv) {

    vector<pair<string,string>> v;

    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    while (true) {
        string character, prefix;
        file >> character;
        if (character[0] == '-' && character.length() > 1) {break;}
        if (character == "space") {character = " ";}
        file >> prefix;

        v.push_back(pair<string,string>(character,prefix));

        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    node* root = new node();
    for (int i = 0; i < v.size(); i++) {insert(root, v[i].first, v[i].second);}

    stringstream sstm;
    while (true) {
        string bits;
        file >> bits;
        if (bits[0] == '-') {
            break;
        }
        sstm << bits;
    }

    string allbits = sstm.str();
    // cout << "All the bits: " << allbits << endl;
    file.close();

    while (allbits.length() > 1) {
        allbits = traverse(root, allbits);
    }
    cout << endl;
    return 0;
}