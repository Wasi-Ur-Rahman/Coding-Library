// problem link: https://leetcode.com/problems/longest-word-in-dictionary/description/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

struct Trie {

	// creating a structure of node
	struct node {
    bool end; // used to indicate that an string is successfully placed in the nodes
    int cnt; // used for counting the prefix
    node* nxt[26];
    node() {
    	cnt = 0;
    	end = false;
    	for (int i = 0;i < 26;i++)
    		nxt[i] = NULL;
    }
  }*root;
  

  Trie() {
    root = new node(); // creating a fresh node of size 26
  }

  void add(string s) {
  	
  	node* cur = root; // starting from root to traverse whole Trie
  	for (int i = 0;i < s.size();i++) {
  		int x = s[i] - 'a';
  		if (cur->nxt[x] == NULL) cur->nxt[x] = new node(); // if current character doesn't exist than we must add it to a new node and connect it with the previous node
  		cur = cur->nxt[x]; // otherwise jump to the next terminal node
  		cur->cnt++; // count the prefix for each string
  	}
  	cur->end = true;
  }

  void dfs(node *cur,string so_far,string& ans) { // finding the longest string that is possible to build in lexicographically smaller manner
  	// update the current answer
  	if (so_far.size() == ans.size()) {
  		ans = min(ans,so_far);
  	}
  	if (so_far.size() > ans.size()) {
  		ans = so_far;
  	}

  	// traverse from lexicographically lower character to the upper
  	for (int i = 0;i < 26;i++) {

  		// checking if that character exist on the trie or not
  		if (cur->nxt[i] != NULL) {
  			// if it does than run dfs and go to the next node
  			if (cur->nxt[i]->end == true) {
	  			string k = so_far;
	  			k += (i + 'a');
	  			dfs(cur->nxt[i],k,ans); // call dfs for newly built string
	  		}
  		}
  	}
  }
  // finding the longest word that can be built
  string Find() {
  	string ans = "";
  	node* cur = root;
  	dfs(cur,"",ans);
  	return ans;
  }

  // searching a word exist or not
  int search(string s) {
  	node* cur = root;
  	for (int i = 0;i < s.size();i++) {
  		int x = s[i] - 'a';
  		if (cur->nxt[x] == NULL) return 0;
  		cur = cur->nxt[x];
  	}
  	return cur->cnt;
  }
};

int32_t main() {
	ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;

	Trie t;
	bool ok = 0;
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		t.add(s);
	}

	cout << t.Find() << '\n';
	return 0;
}
