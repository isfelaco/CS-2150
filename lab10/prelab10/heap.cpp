// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <string>
#include "heap.h"
using namespace std;

heap::heap() : heap_size(0) {
    Heap.push_back(new huffman_node(0,0));
}

heap::heap(vector<huffman_node*> vec) : heap_size(vec.size()) {
    Heap = vec;
    Heap.push_back(Heap[0]);
    Heap.pop_back();
    Heap.push_back(new huffman_node(0,0));
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

heap::~heap() {
}

void heap::insert(huffman_node*& x) {
    Heap.push_back(x);
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    huffman_node* node = Heap[hole];
    int x = node->frequency;
    for ( ; (hole > 1) && (x < Heap[hole/2]->frequency); hole /= 2) {
        Heap[hole] = Heap[hole/2]; // move the parent down
    }
    Heap[hole] = node;
}

int heap::deleteMin() {
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }
    int ret = Heap[1]->frequency;
    Heap[1] = Heap[heap_size--];
    Heap.pop_back();
    if (!isEmpty()) {
        percolateDown(1);
    }
    return ret;
}

void heap::percolateDown(int hole) {
    huffman_node* node = Heap[hole];
    int x = node->frequency;
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        if ((child+1 <= heap_size) && (Heap[child+1]->frequency < Heap[child]->frequency)) {
            child++;
        }
        if (x > Heap[child]->frequency) {
            Heap[hole] = Heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    Heap[hole] = node;
}

void heap::compress() {
    huffman_node* parent = new huffman_node();
    parent->left = findMin();
    deleteMin();
    parent->right = findMin();
    deleteMin();
    parent->value = -1;
    parent->frequency = parent->left->frequency + parent->right->frequency;
    insert(parent);
}

huffman_node* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return Heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    Heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << Heap[0]->value << ", " << Heap[0]->frequency << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << "(" << Heap[i]->value << ", " << Heap[i]->frequency << ")" << "";
        if (Heap[i]->left != NULL) { cout << "*";       }
        if (Heap[i]->right != NULL) { cout << "*";        }
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

void heap::encode(int n) {
    int arr[n];
    encodeTree(Heap[1],arr,0);
}

void heap::encodeTree(huffman_node* n, int arr[], int t) {
    if (n->left) {
        arr[t] = 0;
        encodeTree(n->left, arr, t+1);
    }
    if (n->right) {
        arr[t] = 1;
        encodeTree(n->right, arr, t+1);
    }
    if (!n->left && !n->right) {
        string c = "";
        for (int i = 0; i < t; i++) {
            c += to_string(arr[i]);
        }
        string l = "";
        if (char(n->value) == ' ') { l += "space";}
        else {l += char(n->value);}
        codes.push_back(pair<string,string>(l,c));
    }
}

huffman_node::huffman_node() {
    value = -1;
    frequency = 0;
    left = NULL;
    right = NULL;
};

huffman_node::huffman_node(int v, int f) {
    value = v;
    frequency = f;
    left = NULL;
    right = NULL;
};