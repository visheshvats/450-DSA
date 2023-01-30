#include <bits/stdc++.h>
using namespace std;
int findMinimumCharacter(string &searchWord,string &resultWord){
  map<char,set<int>>mp;
  for(int i = 0;i < searchWord.length();i++)
  mp[searchWord[i]].insert(i);
  int j = 0,i = 0;
  while(j < resultWord.length()){
    if(mp.find(resultWord[j]) == mp.end())
    break;
    auto it = mp[resultWord[j]].lower_bound(i);
    if(it == mp[resultWord[j]].end())
    break;
    i = *it;
    j++;
  }
  return resultWord.size()-j;
}
int main() 
{
    string s,t;
    cin >> s >> t;
    cout << findMinimumCharacter(s,t);
    return 0;
}