#include<cstdio>
#include<iostream>
using namespace std;
unsigned long long int next(unsigned long long int x , unsigned long long int y, unsigned long long int p=295075153) {
	x = (2*x + 5)%p;
	y = (3*y + 7)%p;	
	return x ^ y;
}
unsigned long long int cnx(unsigned long long int x , unsigned long long int p=295075153) {
	return (2*x + 5)%p;
}
unsigned long long int cny(unsigned long long int y , unsigned long long int p=295075153) {
	return (3*y + 7)%p;	
}
unsigned long long int getny(unsigned long long int nx, unsigned long long int pi=210205973) {
	return nx ^ pi;
}

void printit(unsigned long long int nx, unsigned long long int ny) {
unsigned long long int x;
unsigned long long int y;
	for (int k=0; k<10; k++) {
		x = nx;
		y = ny;
		nx = cnx(x);
		ny = cny(y);
		cout << next(nx,ny) << endl;	
	}
}
int main ( void ) { 
	unsigned long long int i = 0;
	unsigned long long int j = 0;
	unsigned long long int x = 0;
	unsigned long long int y = 0;
	unsigned long long int nx = 0;
	unsigned long long int ny = 0;
	unsigned long long int p = 295075153;
	unsigned long long int v[] = {210205973L,22795300L,58776750,121262470,264731963,140842553,242590528,195244728,86752752};
	for ( i = 0; i<=295075153; i++) {
		x = i;
		nx =cnx(x);
		ny = getny(nx);
		if (next(nx,ny) == v[1]){
			x = nx;
			y = ny;
			nx = cnx(x);
			ny = cny(y);
			if (next(nx,ny) == v[2]){
				printit(nx,ny);
			}			
		}		
	}	
	return 0;
}

