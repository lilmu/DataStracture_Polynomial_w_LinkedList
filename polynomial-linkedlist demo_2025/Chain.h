#pragma once
#include "ChainIterator.h"
#include "ChainNode.h"

// *********Chain Template Class *********************
template<class T>
class Chain {
	template <class T> friend ostream& operator<<(ostream&, Chain<T>&);
	friend class ChainIterator<T>; // New Added for Iterator
	friend class Polynomial;
	friend class ChainNode<T>;
	friend istream& operator >> (istream&, Polynomial&);   // for reading in a matrix	
public:
	Chain() { current = first = last = NULL; num = 0; }; // constructor initializing first to 0
	~Chain();// destructor to free all allocated memory space, got some trouble
	void Create2(T, T);
	void Insert(ChainNode<T>*, T);
	ChainNode<T>* Pop();
	void Delete(ChainNode<T>*, ChainNode<T>*);
	void InsertBack(const T& e);

	void InsertBack(ChainNode<T>*);
	void InsertInorder(const T& e);
	ChainNode<T>* FirstNode() { return first; };
	void free();
	void operator=(const Chain<T>& t);
private:
	ChainNode <T>* first, * last;
	ChainNode <T>* current;
	int num;
};
// ================================================================================
// COPY Assignment, it needs to delete available data first, 
// i.e., this->~Chain() 
// ================================================================================
template<class T>
void Chain<T>::operator=(const Chain<T>& t) {
// Do it by yourself
}

// =============================================================
// free memory space by destructor may lead to unexpected semantic error.
// So we design another free() function to deleted allocated mem. space of the linked list nodes
// =============================================================
template<class T>
Chain<T>::~Chain() { // Free all nodes in the chain
    /* Do it by yourself */
	first = NULL; first->avv->num = 10;
		num = 10;
	if (debug) cout << "\nrecycle " << num << " nodes->total AV nodes = " << first->avv->num <<endl;
};

/*  Free the memory space allocated for linked list nodes
	See lecture notes linked list I page 51 for details  */
template<class T>
void Chain<T>::free() {
	ChainNode <T>* next;
	for (; first; first = next) {
		next = first->link;
		if (debug) cout << "Term(" << first->data.coef << ',' << first->data.exp << ") being freed\n";
		delete first;
	}
};
// ***************************************************************************
template<class T>
void Chain<T>::Create2(T x1, T x2)
{
	first = new ChainNode<T>(x1); // create & initialize first node
	// create & initialize 2nd node & place its address in first->link   
	last = first->link = new ChainNode<T>(x2);
};

/****************************************************************************
  create a node with data value and insert after the node pointed by x
***************************************************************************  */
template< class T>
void Chain<T>::Insert(ChainNode<T>* x, T value)
{ // Do it by yourself
};


/******************************************************************
  delete the node x, in which the original list is y-->x-->
********************************************************************/
template <class T>
void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T>* y){  
	// Do it by yourself 
};

/******************************************************************
  delete the node x, in which the original list is y-->x-->
 ********************************************************************/
template <class T>
ChainNode<T>* Chain<T>::Pop(){
    // Do it by yourslef
	return NULL;
};
//=============================================================
// Insert the template term 'e' to the rear of the chain
//=============================================================
template <class T>
void Chain<T>::InsertBack(const T& e) {
	 // Do it by yourself
	num++;
};

// Insert a node pointed by t after the last node
template <class T>
void Chain<T>::InsertBack(ChainNode<T>* t)
{  // Do it by yourself
	num++;
};
/*******************************************************
 Insert one node into a list in an increasing order
********************************************************/
template <class T>
void Chain<T>::InsertInorder(const T& e)
{   // Do it by yourself
};
//***************************************



//****************************************
//  Finished in 2022
//****************************************
template<class T>
ostream& operator<<(ostream& out, Chain<T>& Chain) {
	// Do it by yourself
	return out;
};