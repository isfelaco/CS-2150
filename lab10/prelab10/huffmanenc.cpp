/**
 * Isabella Felaco, isf4rjk
 * Prelab 10
 * huffamnenc.cpp
 * 4-18-22
 * 
 * 
 * sources:
 * 
 * heap.h originally taken from binary_heap.h by Aaron Bloomfield,
 * then extensively edited to include operations to create a Huffman Tree
 * 
 * heap::encode() and heap::encodeTree() based off of code from:
 *      https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
 *      (edited to save data to array rather than print)
**/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "heap.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v;

    ifstream myfile;
    myfile.open(argv[1]);
    string input;
    while(getline(myfile, input)) {
        for (int i = 0; i < input.length(); i++)
            v.insert(v.begin(),input[i]);
    }
    myfile.close();

    sort(v.begin(), v.end());

    int size = v.size();

    heap h;

    while (!v.empty()) {
        bool found = false;
        int temp = v[0];
        v.erase(v.begin());
        for (int i = 1; i < h.Heap.size(); i++) {
            if (h.Heap[i]->value == temp) {
                h.Heap[i]->frequency += 1;
                found = true;
            }
        }
        if (found == false) {
            huffman_node* node = new huffman_node(temp,1);
            h.insert(node);
        }
    }

    int distinct = h.size();

    while(h.size() > 1) {
        h.compress();
    }
    h.encode(size);

    for (int i = 0; i < h.codes.size(); i++) {
        cout << h.codes[i].first << " " << h.codes[i].second << endl;
    }

    myfile.open(argv[1]);
    string input2;
    string output;
    int bits = 0;
    while(getline(myfile,input2)) {
        for (int i = 0; i < input2.length(); i++) {
            string letter2 = "";
            if (input2[i] == ' ') { letter2 = "space";}
            else { letter2 += input2[i]; }
            for (int j = 0; j < h.codes.size(); j++) {
                if (letter2 == h.codes[j].first) {
                    output += h.codes[j].second + " ";
                    bits += h.codes[j].second.length();
                }
            }
        }
    }
    myfile.close();

    double comp_ratio = ((double)size*8)/(double)bits;
    double cost = (double)bits/(double)size;

    cout << "----------------------------------------" << endl;
    cout << output;
    cout << "\n----------------------------------------" << endl;
    cout << "There are a total of " << size << " symbols encoded." << endl;
    cout << "There are " << distinct << " distinct symbols used." << endl;
    cout << "There were " << size*8 << " bits in the original file." << endl;
    cout << "There were " << bits << " bits in the compressed file." << endl;
    cout << "This gives us a compression ratio of " << setprecision(6) << comp_ratio << "." << endl;
    cout << "The cost of the Huffman tree is " << setprecision(6) << cost << " bits per character." << endl;

    return 0;
}

