#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void decToBin(int dec, int bin[]) {										//function to convert decimal value to binary
	int i;
	for (i = 0; dec > 0; i++) {
		bin[i] = dec % 2;												//getting remainder from decimal/2 as 0 or 1
		dec = dec / 2;
	}
	if (i < 4) {														//filling remainder bits with 0
		for (int j = i; j < 4; j++)
			bin[j] = 0;
	}
}

int findRow(int r1, int r2) {											//function to find row of s-box
	int row = 0;
	if (r1 == 1)
		row += 1;
	if (r2 == 1)
		row += 2;

	return row;
}

int findColumn(int c1, int c2, int c3, int c4) {						//function to find column of s-box
	int column = 0;
	if (c1 == 1)
		column += 1;
	if (c2 == 1)
		column += 2;
	if (c3 == 1)
		column += 4;
	if (c4 == 1)
		column += 8;

	return column;
}

void expand(char exp[], char input[]) {									//function to expand input string
	exp[0] = input[0];
	exp[1] = input[1];
	exp[2] = input[2];
	exp[3] = input[3];
	exp[4] = input[2];
	exp[5] = input[3];
	exp[6] = input[4];
	exp[7] = input[5];
	exp[8] = input[4];
	exp[9] = input[5];
	exp[10] = input[6];
	exp[11] = input[7];
}

void f(char input[], char key[], char binf[]) {											//function to execute f
	int s1[4][16] = { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,				//given s-boxes as 2-d array
					3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
					0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
					13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };
	int s2[4][16] = { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
					13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
					10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
					3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 };

	int xored[12], b1[6], b2[6], r1, r2, c1, c2, dec1, dec2, bin1[4], bin2[4];			//declaring variables
	char exp[12];
	expand(exp, input);																	//calling function to expand input

	for (int i = 0; i < 12; i++) {														//XORing expanded string with key
		if (exp[i] == key[i])
			xored[i] = 0;
		else
			xored[i] = 1;
	}
	for (int i = 0; i < 6; i++)															//splitting XORed into two bitstrings
		b1[i] = xored[i];
	for (int i = 6; i < 12; i++)
		b2[i - 6] = xored[i];

	r1 = findRow(b1[5], b1[0]);															//finding row and column of s-box for two bitstrings
	c1 = findColumn(b1[4], b1[3], b1[2], b1[1]);
	r2 = findRow(b2[5], b2[0]);
	c2 = findColumn(b2[4], b2[3], b2[2], b2[1]);

	dec1 = s1[r1][c1];
	dec2 = s2[r1][c1];

	decToBin(dec1, bin1);																//converting decimal value from s-box to binary
	decToBin(dec2, bin2);

	for (int i = 0; i < 4; i++) {														//converting int to char bitstring
		if (bin1[i] == 0)
			binf[i] = '0';
		else
			binf[i] = '1';
	}
	for (int i = 4; i < 8; i++) {
		if (bin2[i - 4] == 0)
			binf[i] = '0';
		else
			binf[i] = '1';
	}
}

int main() {
	char binf[8];
	string bitstring;
	char l[9], r[9], l1[9], r1[9];
	char k1[13], k2[13];
	string key;

	cout << "***This program decrypts only blocks of bitstrings.\nUse \'Q1.1\' to convert to binary.***\n\n";

	cout << "Enter a key: ";												//getting key from user
	getline(cin, key);

	for (int i = 0; i < 12; i++)
		k1[i] = key[i];
	for (int i = 12; i < 24; i++)
		k2[i - 12] = key[i];

	while (1) {
		cout << "Enter a bitstring block: ";								//getting bitstring block of size=16 one at a time from user
		getline(cin, bitstring);

		for (int i = 0; i < 8; i++)											//splitting input into 2
			l[i] = bitstring[i];
		for (int j = 8; j < 16; j++)
			r[j - 8] = bitstring[j];

		for (int k = 0; k < 8; k++)											//performing des decryption
			r1[k] = l[k];
		f(r1, k2, binf);
		for (int x = 0; x < 8; x++) {
			if (r[x] == binf[x])
				l1[x] = '0';
			else
				l1[x] = '1';
		}
		for (int i = 0; i < 8; i++)
			r[i] = l1[i];
		f(r, k1, binf);
		for (int x = 0; x < 8; x++) {
			if (r1[x] == binf[x])
				l[x] = '0';
			else
				l[x] = '1';
		}

		cout << "The plaintext bitstring: ";									//printing plaintext-bitstring
		for (int i = 0; i < 8; i++)
			cout << l[i];
		for (int j = 0; j < 8; j++)
			cout << r[j];
		cout << "\n\n";
	}
}