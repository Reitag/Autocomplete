#include "Autocomplete.h"

using namespace std;

string vocabulary[] = 
{ 
	"apple", "atmosphere", "atom", "appetite", "appearance",
	"clever", "can", "cat", "car", "clown",
	"brave", "bravo", "battle", "bar", 
	"drinks", "discord", "drive", "dan", "dark", "dart",
};
int n = sizeof(vocabulary) / sizeof(vocabulary[0]);

vector<string> words, correctWords;
string word;
string msg;
int choice;

int main()
{
	cout << "Welcome to autocomplete program. Input your text below or type \"exit\" to exit the program" << endl;

	while (msg != "exit")
	{
		getline(cin, msg);
		for (int i = 0; i < msg.length(); ++i)
		{
			if (msg[i] == ' ')
			{
				words.push_back(word);
				word.clear();
				++i;
			}
			word += msg[i];
		}
		words.push_back(word);

		autocomplete(vocabulary, n, words[words.size() - 1], correctWords);

		if (!correctWords.empty())
		{
			for (int i = 0; i < correctWords.size(); ++i)
			{
				cout << i + 1 << '-' << correctWords[i] << endl;
			}

			(cin >> choice).get();

			msg.clear();

			for (int i = 0; i < words.size() - 1; ++i)
			{
				msg = msg + words[i] + ' ';
			}
			msg += correctWords[choice - 1];

			cout << msg << '\n' << endl;

			correctWords.clear();
		}

		words.clear();
		word.clear();
	}

	return 0;
}