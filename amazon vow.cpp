#include<bits/stdc++.h>
using namespace std;

int MAX_CHAR = 26;

	string encodeString(char str[], int m) {
		
		int hashEven[MAX_CHAR];
		int hashOdd[MAX_CHAR];

		
		for (int i = 0; i < m; i++) {
			char c = str[i];
			if ((i & 1) != 0) 
				hashOdd[c-'a']++;
			else
				hashEven[c-'a']++;

		}


		
		string encoding = "";
		for (int i = 0; i < MAX_CHAR; i++) {
			encoding += (hashEven[i]);
			encoding += ('-');
			encoding += (hashOdd[i]);
			encoding += ('-');
		}
		return encoding;
	}

	
	int Distinctpassword(int input1, string input2[]) {
		int countDist = 0; 

		
		set<string> s;
		for (int i = 0; i < input1; i++) {
            int len = sizeof(input2[i]) / sizeof(char);
			
			char char_array[len+1];
			strcpy(char_array, input2[i].c_str());
			if (s.find(encodeString(char_array, len+1)) == s.end()) {
				s.insert(encodeString(char_array,len+1));
				countDist++;
			}
		}

		return countDist;
	}


	int main() {
		string input[] = {"abcd", "acbd", "adcb", "cdba",
				"bcda", "badc"};
		int input1 = sizeof(input)/sizeof(input[0]);

		cout << Distinctpassword(input1, input) << "\n";
	}
