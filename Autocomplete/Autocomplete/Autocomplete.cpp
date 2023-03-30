#include "Autocomplete.h"

using namespace std;

Vocabulary* getNewNode()
{
    struct Vocabulary* pNode = new Vocabulary;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        pNode->children[i] = nullptr;
    }

    return pNode;
}

void insert(Vocabulary* root, string key)
{
    Vocabulary* node = root;

    for (int i = 0; i < key.length(); ++i)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
        {
            node->children[index] = getNewNode();
        }
        node->children[index]->freq++;
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

void autocompleteMoreRecursio(Vocabulary* root, char buf[], int ind, string word, vector<string>& correctWords)
{
    if (root->isEndOfWord == true)
    {
        buf[ind] = '\0';
        correctWords.push_back(buf);
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            autocompleteMoreRecursio(root->children[i], buf, ind + 1, word, correctWords);
        }
    }
}

void autocompleteRecursio(Vocabulary* root, char buf[], int ind, string word, vector<string>& correctWords)
{
    if (root == nullptr)
    {
        return;
    }

    if ((root->freq == 3 || root->freq == 2 || root->freq == 1) && (word.size() == ind))
    {
        autocompleteMoreRecursio(root, buf, ind, word, correctWords);
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if ((i + 'a' == word[ind]) && (root->children[i] != nullptr))
        {
            buf[ind] = i + 'a';
            autocompleteRecursio(root->children[i], buf, ind + 1, word, correctWords);
        }
    }
}

void autocomplete(string arr[], int n, string word, vector<string>& correctWords)
{

    Vocabulary* root = new Vocabulary();
    for (int i = 0; i < n; ++i)
    {
        insert(root, arr[i]);
    }
    char buf[100];
    int ind = 0;

    autocompleteRecursio(root, buf, ind, word, correctWords);
}