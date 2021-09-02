#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main()
{
	vector<vector<string>> passage;

	string word;

	for (;;)
	{
		vector<string> words;

		if (scanf("%s", &word) == 1 && word != "\n")
			words.push_back(word);
		else if (word == "\n") 
		{ 
			passage.push_back(words); 
			continue;
		}
		else break;
	}



}









