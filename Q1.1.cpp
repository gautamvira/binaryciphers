#include <iostream>
#include <string>

using namespace std;

void toText(string text) {							//function to convert binary to text
	string plaintext;
	char chr[6];									//initializing variables
	int block = 0;
	const char* c;
	int count = 0;
	block = text.length() / 5;
	for (int i = 0; i < block; i++) {				// comparing binary blocks one by one
		c = text.c_str();							// to check which character they represent
		strncpy_s(chr, c+count, 5);
		count += 5;
		
		if (strcmp(chr, "00000") == 0)
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
	cout << "The plaintext is: " << plaintext << endl;					//print the text
}

void toBinary(string text) {											//function to convert text to binary
	string key, invert, bitstring;
	for (int i = 0; i < text.length(); i++) {							//looping for length of string
		if (text[i] == 'a' || text[i] == 'A')							//checking for character to convert to the particular binary block
			bitstring += "00000";
		else if (text[i] == 'b' || text[i] == 'B')
			bitstring += "00001";
		else if (text[i] == 'c' || text[i] == 'C')
			bitstring += "00010";
		else if (text[i] == 'd' || text[i] == 'D')
			bitstring +="00011";
		else if (text[i] == 'e' || text[i] == 'E')
			bitstring+= "00100";
		else if (text[i] == 'f' || text[i] == 'F')
			bitstring+= "00101";
		else if (text[i] == 'g' || text[i] == 'G')
			bitstring+= "00110";
		else if (text[i] == 'h' || text[i] == 'H')
			bitstring+= "00111";
		else if (text[i] == 'i' || text[i] == 'I')
			bitstring += "01000";
		else if (text[i] == 'j' || text[i] == 'J')
			bitstring+= "01001";
		else if (text[i] == 'k' || text[i] == 'K')
			bitstring+= "01010";
		else if (text[i] == 'l' || text[i] == 'L')
			bitstring+="01011";
		else if (text[i] == 'm' || text[i] == 'M')
			bitstring+= "01100";
		else if (text[i] == 'n' || text[i] == 'N')
			bitstring+= "01101";
		else if (text[i] == 'o' || text[i] == 'O')
			bitstring+= "01110";
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

	cout << "The bitstring is: " << bitstring << endl;					// printing bitstring
}

int main() {
	cout << "***This program only converts between text and binary***\n\n";					//this program only converts to and from binary
	string text;
	int ch = 0;
	while (1) {																				//menu
		cout << "1. Convert to Binary\n2. Convert to text\nEnter a choice: ";
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Enter a string: ";
			cin.ignore();
			getline(cin, text);																//getting user input for text string
			toBinary(text);																	//calling function to convert to binary
			break;

		case 2:
			cout << "Enter a binary string: ";
			cin.ignore();
			getline(cin, text);																//getting user input for bitstring
			if (text.length() % 5 != 0) {													//if bitstring cannot be divided into blocks of 5, it is invalid
				cout << "Invalid bitstring." << endl;
				break;
			}
			toText(text);																	//calling function to convert to text
			break;
			
		default:																			//if invalid input
			cout << "Invalid input.";
			break;
		}
	}
	return 0;
}