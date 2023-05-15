#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string toBinary(string text) {
	string key, invert, bitstring;										//function to convert text to binary
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == 'a' || text[i] == 'A')							//checking for each character to add particular bitstring block
			bitstring += "00000";
		else if (text[i] == 'b' || text[i] == 'B')
			bitstring += "00001";
		else if (text[i] == 'c' || text[i] == 'C')
			bitstring += "00010";
		else if (text[i] == 'd' || text[i] == 'D')
			bitstring += "00011";
		else if (text[i] == 'e' || text[i] == 'E')
			bitstring += "00100";
		else if (text[i] == 'f' || text[i] == 'F')
			bitstring += "00101";
		else if (text[i] == 'g' || text[i] == 'G')
			bitstring += "00110";
		else if (text[i] == 'h' || text[i] == 'H')
			bitstring += "00111";
		else if (text[i] == 'i' || text[i] == 'I')
			bitstring += "01000";
		else if (text[i] == 'j' || text[i] == 'J')
			bitstring += "01001";
		else if (text[i] == 'k' || text[i] == 'K')
			bitstring += "01010";
		else if (text[i] == 'l' || text[i] == 'L')
			bitstring += "01011";
		else if (text[i] == 'm' || text[i] == 'M')
			bitstring += "01100";
		else if (text[i] == 'n' || text[i] == 'N')
			bitstring += "01101";
		else if (text[i] == 'o' || text[i] == 'O')
			bitstring += "01110";
		else if (text[i] == 'p' || text[i] == 'P')
			bitstring += "01111";
		else if (text[i] == 'q' || text[i] == 'Q')
			bitstring += "10000";
		else if (text[i] == 'r' || text[i] == 'R')
			bitstring += "10001";
		else if (text[i] == 's' || text[i] == 'S')
			bitstring += "10010";
		else if (text[i] == 't' || text[i] == 'T')
			bitstring += "10011";
		else if (text[i] == 'u' || text[i] == 'U')
			bitstring += "10100";
		else if (text[i] == 'v' || text[i] == 'V')
			bitstring += "10101";
		else if (text[i] == 'w' || text[i] == 'W')
			bitstring += "10110";
		else if (text[i] == 'x' || text[i] == 'X')
			bitstring += "10111";
		else if (text[i] == 'y' || text[i] == 'Y')
			bitstring += "11000";
		else if (text[i] == 'z' || text[i] == 'Z')
			bitstring += "11001";
		else if (text[i] == ' ')
			bitstring += "11010";
		else if (text[i] == '.')
			bitstring += "11011";
		else if (text[i] == ',')
			bitstring += "11100";
		else if (text[i] == '?')
			bitstring += "11101";
		else if (text[i] == '(')
			bitstring += "11110";
		else if (text[i] == ')')
			bitstring += "11111";
	}
	return bitstring;													//returning corresponding bitstring
}
string toText(string text) {											//function to convert bitstring to text
	string plaintext;
	char chr[6];
	int block = 0;
	const char* c;
	int count = 0;
	block = text.length() / 5;											//dividing string into blocks of 5
	for (int i = 0; i < block; i++) {									//looping for each block to check which character the block corresponds to
		c = text.c_str();
		strncpy_s(chr, c + count, 5);
		count += 5;

		if (strcmp(chr, "00000") == 0)									//checking for each block
			plaintext += 'a';
		else if (strcmp(chr, "00001") == 0)
			plaintext += 'b';
		else if (strcmp(chr, "00010") == 0)
			plaintext += 'c';
		else if (strcmp(chr, "00011") == 0)
			plaintext += 'd';
		else if (strcmp(chr, "00100") == 0)
			plaintext += 'e';
		else if (strcmp(chr, "00101") == 0)
			plaintext += 'f';
		else if (strcmp(chr, "00110") == 0)
			plaintext += 'g';
		else if (strcmp(chr, "00111") == 0)
			plaintext += 'h';
		else if (strcmp(chr, "01000") == 0)
			plaintext += 'i';
		else if (strcmp(chr, "01001") == 0)
			plaintext += 'j';
		else if (strcmp(chr, "01010") == 0)
			plaintext += 'k';
		else if (strcmp(chr, "01011") == 0)
			plaintext += 'l';
		else if (strcmp(chr, "01100") == 0)
			plaintext += 'm';
		else if (strcmp(chr, "01101") == 0)
			plaintext += 'n';
		else if (strcmp(chr, "01110") == 0)
			plaintext += 'o';
		else if (strcmp(chr, "01111") == 0)
			plaintext += 'p';
		else if (strcmp(chr, "10000") == 0)
			plaintext += 'q';
		else if (strcmp(chr, "10001") == 0)
			plaintext += 'r';
		else if (strcmp(chr, "10010") == 0)
			plaintext += 's';
		else if (strcmp(chr, "10011") == 0)
			plaintext += 't';
		else if (strcmp(chr, "10100") == 0)
			plaintext += 'u';
		else if (strcmp(chr, "10101") == 0)
			plaintext += 'v';
		else if (strcmp(chr, "10110") == 0)
			plaintext += 'w';
		else if (strcmp(chr, "10111") == 0)
			plaintext += 'x';
		else if (strcmp(chr, "11000") == 0)
			plaintext += 'y';
		else if (strcmp(chr, "11001") == 0)
			plaintext += 'z';
		else if (strcmp(chr, "11010") == 0)
			plaintext += ' ';
		else if (strcmp(chr, "11011") == 0)
			plaintext += '.';
		else if (strcmp(chr, "11100") == 0)
			plaintext += ',';
		else if (strcmp(chr, "11101") == 0)
			plaintext += '?';
		else if (strcmp(chr, "11110") == 0)
			plaintext += '(';
		else if (strcmp(chr, "11111") == 0)
			plaintext += ')';
	}
	return plaintext;
}
int main() {
	cout << "***This program encrypts a string using CBC mode***\n\n";
	string str = "cryptography is an important tool for network security. but there are other issues for network security.";		//text to encrypt
	string bitstring = toBinary(str);										//converting string to binary
	char iv[] = "11011010100101000101101011";								//initial vector chosen
	string cipher, tblock;
	int count = 0, len;
	len = bitstring.length();
	cout << "The plaintext is: " << str << endl;
	for (int i = 0; i < (len / 26); i++) {									//choosing blocks of size 26
		for (int x = 0; x < 26; x++) {										//encrypting using cbc
			if (iv[x] == bitstring[count])									//xoring
				tblock += '0';
			else
				tblock += '1';
			count++;
		}
		cipher += tblock;
		for (int j = 0; j < 26; j++)										//adding previous cipherblock to IV
			iv[j] = tblock[j];
		tblock = "";
	}
	cout << "The cipher text is: " << toText(cipher) << endl;				//printing ciphertext by changing binary to text
	return 0;
}