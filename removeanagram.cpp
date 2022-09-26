// C++ implementation to remove
// all the anagram strings
#include <bits/stdc++.h>
using namespace std;

// Function to remove the anagram string
vector<string> removeAnagrams(vector<string> textlist)
{
	
	vector<string> res;
    int len = textlist.size();

	
	unordered_set<string> searched;

	for (int i = 0; i < len; i++) {

		string word = textlist[i];

		
		sort(word.begin(), word.end());

		
		if (searched.find(word) == searched.end()) {

			res.push_back(textlist[i]);
			searched.insert(word);
		}
	}

	
	sort(res.begin(), res.end());

    return res;


	
	
}

int res=0;
int t=0;

for(int i=0;i<N;i++)
{
    if(A[i])
}

// Driver code
int main()
{
	string textlist[]
		= { "geeks", "keegs",
			"code", "doce" };
	int N = 4;

	

	return 0;
}
