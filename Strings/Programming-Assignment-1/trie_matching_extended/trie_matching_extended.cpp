#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node
{
	int next [Letters];
	bool patternEnd;

	Node ()
	{
		fill (next, next + Letters, NA);
		patternEnd = false;
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector<Node> buildTrie(const vector <string>& patterns)
{
    vector<Node> t;
    Node root;
    t.push_back(root);
    int nodeCount = 0;
    for(auto pattern : patterns)
    {
        int currentNode = 0;
        for(int i=0;i<pattern.length();i++)
        {
            int currentLetterIndex = letterToIndex(pattern[i]);
            if(t[currentNode].next[currentLetterIndex] != NA)
            {
                currentNode = t[currentNode].next[currentLetterIndex];
            }
            else
            {
                t[currentNode].next[currentLetterIndex] = ++nodeCount;
                Node node;
                t.push_back(node);
                currentNode = nodeCount;
            }
        }
        t[currentNode].patternEnd = true;
    }
    return t;
}



bool trieMatching(const string& text, int pos, const vector<Node>& trie)
{
    int trieIndex = 0;
    for(int i=pos;i<text.size();i++)
    {
        if(trie[trieIndex].next[letterToIndex(text[i])] != -1 && trie[trie[trieIndex].next[letterToIndex(text[i])]].patternEnd)
        {
            return true;
        }
        else if (trie[trieIndex].next[letterToIndex(text[i])] == -1) return false;
        trieIndex = trie[trieIndex].next[letterToIndex(text[i])];
    }
    return false;
}


vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
    vector <int> result;

    vector<Node> trie = buildTrie(patterns);

    for(int i=0;i<text.size();i++)
    {
        if(trieMatching(text, i, trie)) result.push_back(i);
    }

    return result;
}

int main (void)
{
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
