/*
 * Caesar.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: Alan
 */
#include <iostream>
#include <vector>
using namespace std;
string reverse(string wtr) {	//function to reverse strings, inputs and outputs strings
	string rs;
	for (int i = wtr.length() - 1; i >=0; --i) {		// reverse order by scanning from end
		rs += wtr[i];
	}
	return rs;
}

int main() {
	vector<string> hold; 	//holds the words
	string word;

  while(true) {
	cout << "Enter text, empty text will quit the input..." << endl;
	cout << "> ";

	while(getline(cin,word)) {
		string encrypt;
		if (word == "") break;
		cout << "> ";

		for(int i = 0, len = word.length(); i < len; ++i) {
			if ((word[i] == ' ' || word[i] == '\t') && (word[i-1] != ' ' || word[i-1] != '\t' )) {
				encrypt += ' ';
				while ((word[i] == ' ') || (word[i] == '\t'))
					{
						i++;
					}
				}
			encrypt += word[i];
		}
		//ROT13, rotate letters 13 letters
		for (int i = 0, len = encrypt.length(); i < len; ++i) {

				if (encrypt[i] >= 64 && encrypt[i] <= 90) {
					encrypt[i] = (((encrypt[i] - 65) + 13) % 26) + 65;
		    	}

		    	if (encrypt[i] >= 97 && encrypt[i] <= 122) {
		    		encrypt[i] = (((encrypt[i]-97) + 13) % 26) +97;
		    	}
			//}
		}
		hold.insert(hold.begin(),reverse(encrypt));//reverse letters and lines
		hold.insert(hold.begin(), "\n");				//Separate lines

	}
	//outputs encryption
	cout << "[ ENCRYPTED IMAGE FOLLOWS ]" << endl;
	for (int i = 1, end = hold.size(); i < end; ++i) {
		cout << hold[i];

	}
	hold.clear();
	cout << "\n \n";
  }
	return 0;
}



