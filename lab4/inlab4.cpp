
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
void tableDump(string (*arr)[5], string (*arr1)[4]);

int main(){

	// Replace the empty strings below with
	// the values you found while experimenting.

  string nonPointers[6][5] = { 
		{"int", "4", "2,147,483,647", "0x00000000","0x00000001"},
		{"unsigned int", "4", "4,294,967,295", "0x00000000", "0x00000001"},
		{"float", "4", "2^128", "0x00000000", "0x3F800000"},
		{"double", "8", "2^1024", "0x0000000000000000", "0x3FF0000000000000"},
		{"char", "1", "127", "0x00", "0x01"},
		{"bool", "1", "1", "0x00", "0x01"},

	};

	string pointers[3][4] = {
		{"int*", "8", "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
		{"char*", "8", "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
		{"double*", "8", "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}
