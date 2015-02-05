#include <iostream>

using namespace std;

double isNotDone(double grade) {

	if(grade == -1) {
		grade = 100.00;	
	}
	return grade;
}

int main() {

	double projects = 0;
	double midterms = 0;
	double quizzes = 0;
	double fproject = 0;
	double fexam =  0;
	
	double temp  = 0;

	for(int x = 0; x<6; x++) {
		cout << "Enter project[" << x << "] grade:\n" << endl;
		cin >> temp;
		temp = isNotDone(temp);
		projects += temp;
		temp = 0;
	}
	
	for(int x = 1; x<3; x++) {
		cout << "Enter midterm grade number " << x << endl;
		cin >> temp;
		temp = isNotDone(temp);
		midterms += temp;
		temp = 0;
	}
	
	for(int x = 1; x<6; x++) {
		cout << "Enter quiz grade number " << x << endl;
		cin >> temp;
		temp = isNotDone(temp);
		quizzes += temp;
		temp = 0;
	}

	cout << "Enter final project grade:\n" << endl;
	cin >> temp;
	temp = isNotDone(temp);
	fproject += temp;
	temp = 0;

	cout << "Enter final exam grade :\n" << endl;
	cin >> temp;
	temp = isNotDone(temp);
	fexam += temp;
	temp = 0;

	//Calculate percentages and display results
	projects /= 6;
	cout << "Average projects grade: " << projects << "\n" << endl;
	projects *= .4;

	midterms /= 2;
	midterms *= .2;

	quizzes /= 5;
	cout << "Average quizzes grade: " << quizzes << "\n" << endl;
	quizzes *= .1;

	fproject /= 1;
	fproject *= .1;

	fexam /= 1;
	fexam *= .2;
	
	temp = projects + midterms + quizzes + fproject + fexam;

	cout << "Final Grade: " << temp << "\n" << endl;

	return 0;	
}
