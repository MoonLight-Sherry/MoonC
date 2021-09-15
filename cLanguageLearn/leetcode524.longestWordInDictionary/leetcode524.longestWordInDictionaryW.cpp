//fail to check for continueity


#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string longestWord(vector<string>& words) {
	string longestWord = " ";

	map<string, int> possibleWords;
	for (int i = 0; i < words.size(); i++)
	{
		possibleWords.insert({ words[i], 0 });
	}

	int cnt = 0;

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words.size(); j++)
		{
			if (j == i) continue;
			if (words[i].length() <= words[j].length()) continue;
			if (words[j] == words[i].substr(0, words[j].size()))
			{
				possibleWords[words[i]]++;
			}
		}
		//for(int k = 0; k < words.size(); k ++)
			//if (words.)
		if (possibleWords[words[i]] > cnt )
		{
			cnt = possibleWords[words[i]];
			longestWord = words[i];
		}
		else if(possibleWords[words[i]] == cnt && words[i] < longestWord)
		{
			cnt = possibleWords[words[i]];
			longestWord = words[i];
		}
	}
	return longestWord;
}

int main()
{
	vector<string> words = { "p","pe","pen","peng","pengu","pengui","penguin","e","el","ele","elep","eleph","elepha","elephan","elephant" };
	cout << longestWord(words);
}