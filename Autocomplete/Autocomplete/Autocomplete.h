#pragma once
#include <iostream>
#include <string>
#include <vector>
#define ALPHABET_SIZE 26

using namespace std;

struct Vocabulary
{
	struct Vocabulary* children[ALPHABET_SIZE];
	bool isEndOfWord;
	int freq = 0;
};
Vocabulary* getNewNode();
void insert(Vocabulary* root, string key);
void autocompleteMoreRecursio(Vocabulary* root, char buf[], int ind, string word, vector<string>& correctWords);
void autocompleteRecursio(Vocabulary* root, char buf[], int ind, string word, vector<string>& correctWords);
void autocomplete(string arr[], int n, string word, vector<string>& correctWords);