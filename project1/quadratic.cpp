#include <iostream>
#include <math.h>

using namespace std;

double quadraticFormula(double a, double b, double c, int oper);

int main() {

	double a;
	double b;
	double c;

	int n = 0;

	cout << "Please input A:\n" << endl;
	cin >> a;
	cout << "\n" << endl;

	cout << "Now, input B:\n" << endl;
	cin >> b;
	cout << "\n" << endl;

	cout << "Finally, input C:\n" << endl;
	cin >> c;
	cout << "\n" << endl;

	double x1 = quadraticFormula(a, b, c, n);

	n += 1;
	
	double x2 = quadraticFormula(a, b, c, n);

	if(x1 == x2) {
		cout << "There is only one solution, which is: " << x1 << endl;
	} else if (isnan(x1) && isnan(x2)) {
		cout << "There is no solution." << endl;
	} else { 
		cout << "The first solution is: " << x1 << "\n" << "and the second solution is: " << x2 << endl;
	}

	return 0;

}

double quadraticFormula(double a, double b, double c, int oper) {

	double x;
	
	if(oper == 1) {
		x = ((-b + (sqrt((pow(b, 2)) - (4 * a * c)))))/(2 * a);	
	} else {
		x = ((-b - (sqrt((pow(b, 2)) - (4 * a * c)))))/(2 * a);
	}	
	
	return x;
}

