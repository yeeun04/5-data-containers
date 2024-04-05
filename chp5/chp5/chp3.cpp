//chp3.cpp

#include <iostream>
#include <vector>
#include <unordered_map> //word:count

using namespace std;

int main()
{

	vector<string> words;
	unordered_map<string, int>wordCount;
	cout << "Enter words (XTRL+Z to stop): " << endl;

	string word;
	while (cin >> word)
	{
		words.push_back(word);
	}

	//2. Countwords (for)
	for (auto& w : words)
	{
		wordCount[w]++;
	}

	//3. Print results
	cout << "Word count: " << endl;
	for (auto& pair : wordCount)
	{
		cout << pair.first << ": " << pair.second << endl;
	}

	return 0;
}
