#include <string>

class TreeNode {
 public:
  TreeNode() : value(std::string()), count(1), left(nullptr), right(nullptr) {}
  TreeNode(TreeNode &n) {
    ++n.count;
    count = n.count;
    value = n.value;
    left = n.left;
    right = n.right;
  }

  TreeNode &operator=(TreeNode &n) {
    ++n.count;
    if (--count == 0) {
      delete left;
      delete right;
    }
    count = n.count;
    value = n.value;
    left = n.left;
    right = n.right;
    return *this;
  }

  ~TreeNode() {
    if (--count == 0) {
      delete left;
      delete right;
    }
  }

 private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
 public:
  BinStrTree() : root(nullptr) {}
  BinStrTree(const BinStrTree &rhs) { root = new TreeNode(*rhs.root); }
  BinStrTree &operator=(const BinStrTree &rhs) {
    auto new_root = new TreeNode(*rhs.root);
    delete root;
    root = new_root;
    return *this;
  }

  ~BinStrTree() { delete root; }

 private:
  TreeNode *root;
};
