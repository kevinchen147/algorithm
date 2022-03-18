#include <bits/stdc++.h>
using namespace std;

class TrieNode {
 public:
  unordered_map<char, TrieNode *> dict;
  int childCnt, endCnt;
  string str;
  TrieNode() : childCnt(0), endCnt(0) {}
  void add(const char &c) {
    childCnt += 1;
    if (dict.find(c) == dict.end()) dict[c] = new TrieNode();
  }
  void remove() { childCnt -= 1; }
  bool has(const char &c) {
    return dict.find(c) != dict.end() and childCnt > 0;
  }
};

class TrieTree {
 public:
  TrieNode *root;
  TrieTree() { root = new TrieNode(); }
  void add(const string &s) {
    auto curr = root;
    for (auto &&c : s) {
      curr->add(c);
      curr = curr->dict[c];
    }
    curr->endCnt += 1;
    curr->str = s;
  }
  // should guarantee by yourself
  void remove(const string &s) {
    auto curr = root;
    for (size_t i = 0; i < s.size(); ++i) {
      curr->remove();
      curr = curr->dict[s[i]];
    }
    curr->endCnt -= 1;
  }
  bool has(const string &s) {
    auto curr = root;
    for (auto &&c : s) {
      if (!curr->has(c)) return false;
      curr = curr->dict[c];
    }
    return curr->endCnt > 0;
  }
  bool start(const string &s) {
    auto curr = root;
    for (auto &&c : s) {
      if (!curr->has(c)) return false;
      curr = curr->dict[c];
    }
    return true;
  }
};