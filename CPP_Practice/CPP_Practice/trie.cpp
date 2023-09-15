#include <iostream>
#include <string>

using namespace std;

class Trie
{
public:
	Trie() : finish(false)
	{
		memset(next, 0, sizeof(next));
	}

	void Insert(const char* key)
	{
		if (*key == '\0')
		{
			finish = true;
		}
		else
		{
			int current = *key - 'a';
			if (next[current] == NULL)
			{
				next[current] = new Trie();
			}
			next[current]->Insert(key + 1);
		}
	}

	bool FindString(const char* key)
	{
		if (finish == true)
		{
			return true;
		}

		if (*key == '\0')
		{
			return false;
		}

		int current = *key - 'a';
		if (next[current] == NULL)
		{
			return NULL;
		}

		return next[current]->FindString(key + 1);
	}

private:
	Trie* next[26];
	bool finish;
};

int main()
{
	Trie trie;
	trie.Insert("test");
	trie.Insert("asdf");
	trie.Insert("tteeqqssff");
	trie.Insert("fghgfh");
	trie.Insert("tyjtyj");
	trie.Insert("temp");

	string str;
	cin >> str;

	if (trie.FindString(str.c_str()) == true)
	{
		cout << "Found in trie : " << str << endl;
	}
	else
	{
		cout << "Not found in trie : " << str << endl;
	}

	return 0;
}