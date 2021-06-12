#include <iostream>
#include "project.h"
#include <string>
using namespace std;

// constructor to the map class 
template <class T, class U>
Map<T,U>::Map()
{
	root = NULL;
}

// to find the height of the node
template <class T, class U>
int Map<T,U>::height(node *t) const
{
	return (t == NULL) ? -1 : t->height ;
}

// to find the maximum of two elements
template <class T , class U>
int Map<T,U>::max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

// add value to the given node
template <class T, class U>
void Map<T,U>::addValue(node *&t, U y){
	t->value[t->index] = y;
	t->index++;
}

// to insert new key value pair
template <class T , class U>
void Map<T,U>::insert(const T &x,const U &y, node *&t)
{
	if( t == NULL)
	{
		t = new node(x,y,0,NULL,NULL,0); // if node is null , create a node
	}
	else if( x < t->element)		// if node value is greater than node see left subtree
	{
		insert(x,y,t->left);
		if(height(t->left) - height(t->right) == 2){
			if (x < (t->left)->element)
				singlerotatewithleft(t);
			else
				doublerotatewithleft(t);
		}
	}
	else if( x > t->element){		// if node value is less than node see right subtree
		insert(x,y,t->right);
		if (height(t->right) - height(t->left) == 2){
			if (x > (t->right)->element)
				singlerotatewithright(t);
			else
				doublerotatewithright(t);
		}
	}
	else
	{
		addValue(t,y);
	} ; // element already present;
	t->height = max(height(t->left) , height(t->right))+1 ;	// update the height in the insert path
}

// to insert new key value pair in user side
template <class T , class U>
void Map<T,U>::insert(const T &x,const U &y)
{
	insert(x,y,root);
}

// to rotate the tree to maintain the balance
template <class T , class U>
void Map<T,U>::singlerotatewithleft(node *&k2)
{
	node *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left),height(k2)) + 1;
	k2 = k1;
}

// to rotate the tree to maintain the balance
template <class T , class U>
void Map<T,U>::singlerotatewithright(node *&k2)
{
	node *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k2), height(k1->right)) + 1;
	k2 = k1;
}

// to rotate the tree to maintain the balance
template <class T , class U>
void Map<T,U>::doublerotatewithleft(node *&k3)
{
	singlerotatewithright(k3->left);
	singlerotatewithleft(k3);
}

// to rotate the tree to maintain the balance
template <class T , class U>
void Map<T,U>::doublerotatewithright(node *&k3)
{
	singlerotatewithleft(k3->right);
	singlerotatewithright(k3);
}

// to remove a key with its values
template <class T , class U>
void Map<T,U>::remove(const T &x, node *&t)
{
	if ( t == NULL){
		return; // element not found
	}
	else if (x < t->element)
		remove(x,t->left);		// search left subtree
	else if (x > t->element)
		remove(x, t->right);	// search right subtree
	else if (t->left != NULL && t->right != NULL){ 	// if the node has 2 children 
		t->element = (findMin(t->right))->element;	// replace it with the min node of its right child
		t->index =  (findMin(t->right))->index;
		for (int q = 0; q < (findMin(t->right))->index ; q++ ){  
			t->value[q] = (findMin(t->right))->value[q];
		}
		remove(t->element,t->right);
	}
	else{
		t = (t->left != NULL) ? t->left : t->right; // if a node has only one child replace the node with that child
	}
	balance(t);		// balance the tree
}

// to remove a key with its values in user side
template <class T , class U>
void Map<T,U>::remove(const T &x)
{
	remove(x,root);
}

// to balance the tree 
template <class T , class U>
void Map<T,U>::balance(node *&t)
{
	if(t == NULL)
		return ;
	else if (height(t->left) - height(t->right) == 2){		// checking the balance of left subtree
		if ( height((t->left)->left) >= height((t->left)->right)){
			singlerotatewithleft(t);
		}
		else
			doublerotatewithleft(t);
	}
	else {													// checking the balance of right subtree
		if (height(t->right) - height(t->left) == 2)
		{
			if (height((t->right)->right) >= height((t->right)->left)){
				singlerotatewithright(t);
			}
			else
				doublerotatewithright(t);
		}
		t->height = max(height(t->left) , height(t->right)) + 1 ;
	}
}

// to print the tree in inorder in user side
template <class T , class U>
void Map<T,U>::display()
{
	if (root != NULL){
		cout << "\nKEY\tVALUES\n";
		inorder(root);
	}
	else 
		cout << "Map is Empty";
	cout << endl;
}

// to print the key value pair in inorder fashion
template <class T , class U>
void Map<T,U>::inorder(node *t)
{
	if( t != NULL){
		inorder(t->left);						// go to left subtree
		cout << t->element << "\t";
		for ( int q = 0 ; q < t->index ; q++){	// print root
			cout << t->value[q] << " ";
		}
		cout << endl;
		inorder(t->right);						// go to right subtree
	}
}

// to find the value for the given key in user side
template<class T,class U>
U Map<T,U>::values(const T &x)
{
	return s_values(x,root);
}

// to find the value for the given key
template <class T, class U>
U Map<T,U>::s_values(const T &x, node *&t){
	U temp ;
	if (t->element == x){
		temp = (t->value[0]);			//  return the value of the given tree
	}
	else
	{
		if (x < t->element)
			temp = s_values(x,t->left);	// search in left subtree
		else if (x > t->element)
			temp = s_values(x,t->right); // search in right subtree
	}
	return temp;
}

// to find the key for a given value in user side
template <class T,class U>
T Map<T,U>::findKey(U &s )
{
	return findKey(s,root);
}

// to find the key for a given vlaue 
template <class T,class U>
T Map<T,U>::findKey(U &s , node *t)
{
	if (t == NULL )
		return '\0' ;
	T temp = '\0';
	if (t->value[0] == s){	
		temp = t->element;	// to return the key for the given value
	}
	else {
		temp = findKey(s,t->left); 		// search in left subtree
		if ( temp == '\0'){				// if not found in left subtree
			temp = findKey(s,t->right);	// search in right subtree
		}
	}
	return temp;
}

// to initilize the map with key value pairs
template <class T, class U>
void Map<T,U>::initilize()
{
	for (T i = ' ' ; i <= '~' ; i++){
		U e;
		T d = ((int)(i + 2*i - 0.3*i) % 123);
		d = (d < 60) ? d + 64 : d ;
		e += d;
		d = ((int)(i + 1.6*i - 0.47*i) % 123);
		d = (d < 64) ? d + 64 : d ;
		e += d;
		d = ((int)(i + 0.698*i - 0.097*i) % 123);
		d = (d < 64) ? d + 64 : d ;
		e += d;
		d = ((int)(i + 1.6*i - 0.47*i) % 58);
		d = (d < 48) ? d + 48 : d ;
		e += d;
		d = ((int)(i + 2.698*i - 1.797*i) % 123);
		d = (d < 58) ? (d + 64) : d ;
		e += d;
		T k = i;
		this->insert(k,e);
	}
	T i = '\n';
	U e;
	T d = ((int)(i + 2*i - 0.3*i) % 123);
	d = (d < 60) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 1.6*i - 0.47*i) % 123);
	d = (d < 64) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 0.698*i - 0.097*i) % 123);
	d = (d < 64) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 1.6*i - 0.47*i) % 58);
	d = (d < 48) ? d + 48 : d ;
	e += d;
	d = ((int)(i + 2.698*i - 1.797*i) % 123);
	d = (d < 58) ? (d + 64) : d ;
	e += d;
	T k = i;
	this->insert(k,e);
	if (1)
	{
		T i = '\t';
	U e;
	T d = ((int)(i + 2*i - 0.3*i) % 123);
	d = (d < 60) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 1.6*i - 0.47*i) % 123);
	d = (d < 64) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 0.698*i - 0.097*i) % 123);
	d = (d < 64) ? d + 64 : d ;
	e += d;
	d = ((int)(i + 1.6*i - 0.47*i) % 58);
	d = (d < 48) ? d + 48 : d ;
	e += d;
	d = ((int)(i + 2.698*i - 1.797*i) % 123);
	d = (d < 58) ? (d + 64) : d ;
	e += d;
	T k = i;
	this->insert(k,e);
	}
	
}

template class Map<char,string>;
