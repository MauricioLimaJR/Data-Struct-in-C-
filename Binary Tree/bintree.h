class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int value);
	void see(int depth);
};

class Tree{
	public:
	  Node *root;
		Tree();
		bool exists(int value);
		void insert(int value);
		void remove(int value);
		void del(int value);
		void see(int depth);
};