#include "ChainNode.h"
#include "Polynomial.h"
#include "av_list.h"

int debug =0;
int N ;
void system_init(ifstream&);
int main() {
	int cont = 1;
	char ch;
	LOGO();
	while (cont) {
		ifstream inFile("polynomial.txt", ios::in); //"equiv.in" is th input file
		if (!inFile) { cerr << "Cannot open input file" << endl; return 0; }
		system_init(inFile);
		debug = 1;
		Polynomial a, b, c, d;   
 		inFile >> a; // input polynomial a data
		inFile >> b; // input polynomial b data

		c = (a + b);
		cout << "a = "<<a<<"\nb = "<<b<<"\nc = a + b =\n"
		<< a << " + " << b << " =\n " << c << "\n";
		
		d = a * b;
		d = c + d;
		cout <<"\n(a+b) + (a*b) =\n"<< c <<'+'<<a<<" * "<<b<<" =\n"<<d<< "\n";
		cont = 0;	
		cout << "Press any key to trigger polynomial destructor\n";
		cin.get();
	}  // this right brace trigger polynomial destructor to free all allcated space 
	cout << "\nPress any key to terminate the program\n";
	cin.ignore(); cin.get();
	return 0; 
};

void system_init(ifstream& is) {
	is >> debug;	is.clear();  is.ignore(100, '\n');
	is >> N;		is.clear();  is.ignore(100, '\n');
}