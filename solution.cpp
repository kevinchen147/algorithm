#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *_next) : val(x), next(_next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *_left, TreeNode *_right)
      : val(x), left(_left), right(_right) {}
};

class Solution {};

int main() {
  // Solution s;
  // vector<int> v{};
  // vector<vector<int>> vv{{}};
  // auto ans = s;
  // dbg(ans);

  return 0;
}
