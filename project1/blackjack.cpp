#include <iostream>

using namespace std;

int main() {

	int x = 0;	
	int x1;
	int x2;
	int y1 = 0;

	cout << "Input your first drawn card: " << endl;
	cin >> x1;
	cout << "\n" << endl;

	cout << "Input your second drawn card " << endl;
	cin >> x2;
	cout << "\n" << endl;

	x1 += x2;

	while(x<4) {
		x1 += y1;

		if(x1 > 21) {
			cout << "You die" << endl;
			return 0;
		} else if(x1 == 21) {
			cout << "You win!" <<endl;
			return 0;		
		} else if(x1 >= 17 && x <= 21) {
			cout << "I got " << x1 << endl;
			return 0;
		} else if(x == 3) {
			cout << "I win with 5 cards!" << endl;
			return 0;
		} else {
			cout << "Your hand is less than 17, draw another and input card: " << endl;
			cin >> y1;
			cout << "\n" << endl;
		}
		x++;
	}
	return 0;
}
