//#ifndef POLYNOMIAL_H
//#define POLYNOMIAL_H
#pragma once
#include "ChainIterator.h"
#include "Chain.h"
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

extern int debug;
using namespace std;

struct Term {  // all members of Term are public by default
	int coef;	//coefficient
	int exp;	// exponential lorder
	Term Set(int c, int e) { 
		coef = c; exp = e;  return *this; };
	Term Set(ChainNode <Term> temp) {	
		Term data = temp.GetData();  
		coef = data.coef; exp = data.exp; 
		return *this;
	};
};
class Polynomial {
	friend ostream &operator<<(ostream &, Polynomial &);
	friend istream &operator>>(istream &, Polynomial &);
	friend Polynomial operator+(const Polynomial&, const Polynomial&);

public:	
	// Polynomial(Chain <Term>ll) :poly(ll) { label = '0' + counter++;  };
	Polynomial(){ label = 'A' + counter;  num = counter++; message(); };
	Polynomial(char c) { label = c;  num = counter++;  message(); };
	Polynomial(const Polynomial&); // copy constructor 
	~Polynomial();
	void operator=(const Polynomial&);
	Polynomial operator*(const Polynomial&) const;
public:
	Chain <Term> poly;
	void free();
	char label;
private:
	void message();
	static int counter;
	int num;
};
// ======================================
//   COPY CONSTRUCTOR of polynomial
// ======================================
Polynomial::Polynomial(const Polynomial &p){
	ChainNode <Term> *current = p.poly.first;
	this->num = counter++;
	this->label = '?';

	while (current) {
		poly.InsertBack(current->data);
		current = current->link;
	}
	message();
};

//====================================== 
// print out poly object message 
//======================================
void Polynomial::message() {
	if(debug) cout << "\nConstruct Poly(num=" << this->num << ", op=" << this->label << ")";
};

int Polynomial::counter = 0; // initialize static variables 
//====================================== 
// COPY 'ASSIGNMENT' of Polynomial 
//======================================
void Polynomial::operator= (const Polynomial& p)  {
	/* do it by yourself */
	Term* t1 = new Term; t1->Set(9, 9);
	Term* t2 = new Term; t2->coef = 8; t2->exp = 8;
	this->poly.Create2(*t1, *t2);
};
// Destructor: executed automatically after the corresponding '}"
Polynomial::~Polynomial() {
	// The ~Chain() will be triggered to clear the linked list poly
	if(debug) cout << "\nDestruct Poly(num="<< this->num <<", op=" << setw(2) << (char)this->label << "): ";
};
// The destructor automatically delete a linkted list data but 
// it conflicts with an operator overloading function p3 = p1 + p2;
void Polynomial::free() { // Free all nodes in the chain
	cout << "Free Polynomial " << setw(4) << (char)this->label << endl;
	poly.free();
};

// polynomial multiplication function 
Polynomial Polynomial::operator*(const Polynomial& b) const {
	// ChainIterator <Term> ai(poly);
	Polynomial c('*');
	Term* t1 = new Term; t1->Set(9, 9);
	Term* t2 = new Term; t2->coef = 8; t2->exp = 8;
	c.poly.Create2(*t1, *t2);
   /*    Do it by yourself  */
	return c;
};


Polynomial operator+(const Polynomial& a, const Polynomial& b) {   
	Term temp;
	// ChainIterator <Term> ai(a.poly), bi(b.poly);
	Polynomial c('+');
	Term* t1 = new Term; t1->Set(9, 9);
	Term* t2 = new Term; t2->coef = 8; t2->exp = 8;
	c.poly.Create2(*t1, *t2);
	/*     	Do it by yourself  	*/ 
	return c;
};

ostream & operator<<(ostream &out, Polynomial &p) {
	// ChainIterator <Term> ct(p.poly);
	char sign; int first = 1;
	out <<"(";
	/*
	while (ct.NotNull())
	{
		sign = ct->coef > 0 ? '+' : '-' ;
		if (first && sign == '+') {
			out << fabs(ct->coef) << "x^" << ct->exp;
			first = 0;
		}
		else out << ' '<< sign <<' '<< fabs(ct->coef) << "x^" << ct->exp ;
		ct++;
	}*/
	Term t = p.poly.FirstNode()->GetData();
	out << t.coef << "x^" << t.exp;
    out << ")";
	
	return out;
};

istream& operator>>(istream& is, Polynomial& p)
// read in a polynomial  and set up its linked representation.
{
	int i, nterm;
	Term s;
	is >> nterm;
	is.clear(); 
	is.ignore(100, '\n');
	
	for (i = 0; i < nterm; i++) {
		is >> s.coef >> s.exp; // matrix dimensions
	//	p.poly.InsertBack(s);
	}
	Term* t1 = new Term; t1->Set(9, 9);  
	Term* t2 = new Term; t2->coef = 8; t2->exp = 8;
	p.poly.Create2(*t1, *t2);
	return is;
};

void LOGO() {
	cout << "===============================================================\n"
		<< "       Linked Polynomial Lecture 4 Part I: p44-p47 \n"
		<< "      Designed and verified by Jiann-Jone Chen 2025\n"
		<< "================================================================\n\n";
}


//#endif
