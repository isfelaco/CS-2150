/**
 * Isabella Felaco, isf4rjk
 * 3-12-22
 * wordPuzzle.cpp
 **/
 
#include <iostream>
#include <string>
#include <fstream>
#include "HashTable.h"
#include "timer.h"
#include "primenumber.cpp"
using namespace std;

/**
 * take in a dictionary file and grid file using command line parameters
 * read in a dictionary and store its words in a hash table
 * read in a word search grid no longer than 500x500 and store it in an appropriate data structure
 * output every word of length three or greater and its location in the grid
 **/

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
string getDirection(int k);
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols);

int main(int argc, char *argv[]) {
    ifstream myfile;
    
    myfile.open(argv[1]); // open dictionary file
    string line;

    unsigned int x = 0;
    while(getline(myfile,line)) {
        x++; // counts the size of the dictionary
    } 
    myfile.close();
    
    x = getNextPrime(x*3); // sets the size of the hash table to the next prime number after 3*size of dictionary
    HashTable ht(x);

    myfile.open(argv[1]); // reopen dictionary file
    string word;
    while(getline(myfile, word)) {
        if (word.length() >= 3) // adds all words from dictionary with length >= 3
            ht.insertElement(word);
    }
    myfile.close();

    myfile.open(argv[2]); // open grid file
    int rows, cols;
    bool result = readInGrid(argv[2], rows, cols); // read in the grid
    if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    myfile.close();

    int count = 0;
    timer *t = new timer();
    t->start();
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            for (int k = 0; k < 8; k++) {
                string word = getWordInGrid(i,j,k,22,rows,cols); // gets the word once with maximum string length
                for (int l = word.length(); l >= 3; l--) {
                    if (word.substr(0,l) != "" && ht.find(word.substr(0,l))) { // iterates through substrings to length 3
                        count ++;                                               // faster than called getWordInGrid() 22 times
                        cout << getDirection(k) << "(" << i << ", " << j << "):   " << word.substr(0,l) <<endl;
                    }  
                }
                
            }
        }
    }
    t->stop();
    double time = t->getTime();
    cout << count << " words found" << endl;
    //cout << (time) << endl;
    return 0;
}

string getDirection(int k) {
    // gets the direction getWordInGrid() is going in by mapping integers to cardinal directions
    switch(k) {
        case 0: return "N ";        
        case 1: return "NE";                
        case 2: return "E ";
        case 3: return "SE";
        case 4: return "S ";
        case 5: return "SW";
        case 6: return "W ";
        case 7: return "NW";
        default: return "Direction not found!";
    }   
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            //output = "";
            break;
        }
        else {
            // set the next character in the output array to the next letter
            // in the grid
            output += grid[r][c];

            // move in the direction specified by the parameter
            switch (dir) { // assumes grid[0][0] is in the upper-left
                case 0:
                    r--;
                    break; // north
                case 1:
                    r--;
                    c++;
                    break; // north-east
                case 2:
                    c++;
                    break; // east
                case 3:
                    r++;
                    c++;
                    break; // south-east
                case 4:
                    r++;
                    break; // south
                case 5:
                    r++;
                    c--;
                    break; // south-west
                case 6:
                    c--;
                    break; // west
                case 7:
                    r--;
                    c--;
                    break; // north-west
            }
        }   
    }

    return output;
}