// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <utility>
#include <string>
using namespace std;

class heap {
public:
    heap();
    heap(vector<struct huffman_node*> vec);
    ~heap();

    void insert(struct huffman_node*& x);
    struct huffman_node* findMin();
    int deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void compress();
    void encode(int n);

    vector<struct huffman_node*> Heap;
    vector<pair<string,string>> codes;

private:
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);

    void encodeTree(huffman_node* n, int arr[], int t);
};

struct huffman_node {
    int value;
    int frequency;
    huffman_node* left;
    huffman_node* right;
    huffman_node();
    huffman_node(int v, int f);
};

#endif
