#include "keeper.h"
#include "car.h"
#include "moto.h"
#include "bus.h"

int main() {

	int choice;

	do {

		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Menu:" << endl;
		cout << "1 - Show all vehicles" << endl;
		cout << "2 - Add car" << endl;
		cout << "3 - Delete car" << endl;
		cout << "4 - Add motorcycle" << endl;
		cout << "5 - Delete" << endl;
		cout << "6 - Read the file" << endl;
		cout << "7 - Exit" << endl;
		cout << "Choose an action: ";

		cin >> choice;

		switch (choice) {
		case 1: {

			break;
		}
		case 2: {

			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			
			break;
		}
		case 5: {

			break;
		}
		case 6: {

			break;
		}
		case 7: {
			break;
		}
		default:
			cout << "Try again" << endl;
		}
	} while (choice != 7);


	Keeper keeper1;

	keeper1.add(new Car("Toyota", "Mark II", 3.000, "White", "Mechanical"));
	keeper1.add(new Car("Ferrari", "488 Pista", 4.400, "51 Livery", "Robot"));
	keeper1.add(new Bus("LIAZ", "677", 45, 70, "Boksitogorsk"));

	keeper1.printall();

	try {
		keeper1[0]->print();
		keeper1[1]->print();
		dynamic_cast<Car*>(keeper1[1])->setgearbox("Auto");
		keeper1[1]->print();
		keeper1[2]->print();
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}

	return 0;
}