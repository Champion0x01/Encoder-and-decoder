#include <string>
using namespace std;

template <class T, class U>

class Map 
{
private:
		struct node {  	// node of the avl tree
		T element;		// key 
		U value[10];	// value
		int index;		// no of values for a key
		node* left;		// pointing to left node
		node* right;	// pointing to right node
		int height;		// height of the node
		node(const T &theelement,U val,int ind , node *a, node* b, int h) : // constructor to the node
		 element(theelement), left(a), right(b) , height(h) {
			value[ind] = val;
			index++;
		}
	};
	node* root; 	// to point to the root
public:
	Map();			// constructor to the map class
	void addValue(node *&t, U y); 	// add value to the given node
	int height(node *t) const;		// to find the height of the node
	int max(int a, int b);			// to find the maximum of two elements
	void insert(const T &x, const U &y);			// to insert new key value pair in user side
	void insert(const T &x, const U &y, node *&t);	// to insert new key value pair 
	void singlerotatewithleft(node *&k2);			// to rotate the tree to maintain the balance
	void singlerotatewithright(node *&k2);
	void doublerotatewithleft(node *&k3);
	void doublerotatewithright(node *&k3);
	node* findMin(node *t) const					// to find the node with min key
	{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
	}
	void remove(const T &x);						// to remove a key with its values in user side
	void remove(const T &x, node *&t);				// to remove a key with its values
	void balance(node *&t);							// to balance the tree 
	void display();									// to print the tree in inorder in user side
	void inorder(node *t);							// to print the key value pair in inorder fashion
	U s_values(const T &x, node *&t);				// to find the value for the given key
	U values(const T &x);							// to find the value for the given key in user side
	T findKey(U &s);								// to find the key for a given value in user side
	T findKey(U &s, node *t);						// to find the key for a given vlaue 
	void initilize();								// to initilize the map with key value pairs
};