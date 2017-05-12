class BinaryTree {
  private:
    struct node {
      node* left;
      node* right;
      int data; // 
    };
    node* root;
  
  public:
    BinaryTree();
    ~BinaryTree();

    node getLeft();
    node getRight();
    node getRoot();

      
    void preorder_tree_walk();
    void inorder_tree_walk();
    void postorder_tree_walk();
    
    void insert(int d);
};

