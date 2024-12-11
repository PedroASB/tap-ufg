#include <bits/stdc++.h>

using namespace std;

const int N = 5*1e5 + 10; // Número de palavras
const int K = 10; // Tamanho máximo de cada palavra
const int SIGMA = 26; // Quantidade de letras no alfabeto

typedef struct {
	bool end = false;
	int next[SIGMA];
} node;

node trie[N * K];
int size = 0;

void add_trie(string& str){
	int node = 0;
	for (char ch: str) {
		int pos = ch - 'a';
		if (trie[node].next[pos] == 0) {
			size++;
			trie[node].next[pos] = size;
		}
		node = trie[node].next[pos];
	}
	trie[node].end = true;
}

void dfs(int u, string& str, string prefix){
	if (trie[u].end && str != prefix)
		cout << str << '\n';

	for (int i = 0; i < 26; i++) {
		if (trie[u].next[i] != 0) {
			str.push_back((char) ('a' + i));
			dfs(trie[u].next[i], str, prefix);
			str.pop_back();
		}
	}

}

int main(){
	int n, k;
	string word;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		add_trie(word);
	}

    cin >> k;
    for (int i = 1; i <= k; i++) {
        cout << "Case #" << i << ":\n";
        cin >> word;

        int node = 0;
        bool match = true;
        for (char ch: word) {
            int pos = ch - 'a';
            if (trie[node].next[pos] == 0) {
                cout << "No match.\n";
                match = false;
                break;
            }
            node = trie[node].next[pos];
        }
	    if (match) dfs(node, word, word);
    }

	return 0;
}