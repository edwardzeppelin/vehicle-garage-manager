#include "keeper.h"
#include "car.h"
#include "moto.h"
#include "bus.h"
#include <string>

int main() {

	int choice;
	int index;

	string cbrand;
	string cmodel;
	float cengv;
	string ccolour;
	string ctrans;
	int chorsepwr;
	string cterrain;

	Keeper keeper1;

	keeper1.add(new Car("Toyota", "Mark II", 3.000, "White", "Mechanical"));
	keeper1.add(new Car("Ferrari", "488 Pista", 4.400, "51 Livery", "Robot"));
	keeper1.add(new Motorcycle("Kawasaki", "500", 1.9, 220, "Road"));
	keeper1.add(new Bus("LIAZ", "677", 45, 70, "Boksitogorsk"));

	while (true) {

		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Menu:" << endl;
		cout << "1 - Show all vehicles" << endl;
		cout << "2 - Add car" << endl;
		cout << "3 - Edit car" << endl;
		cout << "4 - Delete car" << endl;
		cout << "5 - Add motorcycle" << endl;
		cout << "6 - Edit motorcycle" << endl;
		cout << "7 - Delete motorcycle" << endl;
		cout << "8 - Add bus" << endl;
		cout << "9 - Edit bus" << endl;
		cout << "10 - Delete bus" << endl;
		cout << "11 - Save in file" << endl;
		cout << "12 - Read from file" << endl;
		cout << "13 - Exit" << endl;
		cout << "Choose an action: ";

		cin >> choice;

		try {
			switch (choice) {
			case 1:
				keeper1.printall();
				break;
			case 2:
				cout << "Enter brand: ";
				cin >> cbrand;
				cout << "Enter model: ";
				cin >> cmodel;
				cout << "Enter engine volume: ";
				cin >> cengv;
				if (cengv < 1)
					throw invalid_argument("Cant be negative");
				cout << "Enter colour: ";
				cin >> ccolour;
				cout << "Enter type of transmission: ";
				cin >> ctrans;

				keeper1.add(new Car(cbrand, cmodel, cengv, ccolour, ctrans));
				break;
			case 3:
				cout << "Enter index of changable vehicle: ";
				cin >> index;
				index = index - 1;
				if (index < 0)
					throw invalid_argument("Cant be less 1");

				if ((keeper1[index]->gettype()) == "Car") {
					cout << "Editing the car" << endl;
				}
				else {
					throw invalid_argument("Wrong vehicle");
				}
				cout << "Enter new brand: ";
				cin >> cbrand;
				cout << "Enter new model: ";
				cin >> cmodel;
				cout << "Enter new engine volume: ";
				cin >> cengv;
				if (cengv < 0)
					throw invalid_argument("Cant be negative");
				cout << "Enter new colour: ";
				cin >> ccolour;
				cout << "Enter new type of transmission: ";
				cin >> ctrans;

				keeper1[index]->setbrand(cbrand);
				keeper1[index]->setmodel(cmodel);
				keeper1[index]->setenginev(cengv);
				keeper1[index]->setcolour(ccolour);
				keeper1[index]->setgearbox(ctrans);

				cout << "Done" << endl;

				break;
			case 4:

				break;
			case 5:
				cout << "Enter brand: ";
				getline(cin, cbrand);
				cin >> cbrand;
				cout << "Enter model: ";
				cin >> cmodel;
				cout << "Enter engine volume: ";
				cin >> cengv;
				if (cengv < 1)
					throw invalid_argument("Cant be negative");
				cout << "Enter power (in hp): ";
				cin >> chorsepwr;
				cout << "Enter type of terrain: ";
				cin >> cterrain;

				keeper1.add(new Motorcycle(cbrand, cmodel, cengv, chorsepwr, cterrain));

				break;

			case 6:

				cout << "Enter index of changable vehicle: ";
				cin >> index;
				index = index - 1;
				if (index < 0)
					throw invalid_argument("Cant be less 1");

				if ((keeper1[index]->gettype()) == "Moto") {
					cout << "Editing the motorcycle" << endl;
				}
				else {
					throw invalid_argument("Wrong vehicle");
				}
				cout << "Enter new brand: ";
				cin >> cbrand;
				cout << "Enter new model: ";
				cin >> cmodel;
				cout << "Enter new engine volume: ";
				cin >> cengv;
				if (cengv < 0)
					throw invalid_argument("Cant be negative");
				cout << "Enter new power (in hp): ";
				cin >> chorsepwr;
				cout << "Enter new type of terrain: ";
				cin >> cterrain;

				keeper1[index]->setbrand(cbrand);
				keeper1[index]->setmodel(cmodel);
				keeper1[index]->setenginev(cengv);
				keeper1[index]->sethorsepwr(chorsepwr);
				keeper1[index]->setterrain(cterrain);

				cout << "Done" << endl;

				break;
			case 7:

				break;
			case 8:
				cout << "Exiting..." << endl;
				return 0;
			default:
				cout << "Try again" << endl;
				break;
			}
		}
		catch (const runtime_error& e) {
			cout << "Runtime error: " << e.what() << endl;
		}
		catch (const invalid_argument& e) {
			cout << "Invalid argument: " << e.what() << endl;
		}
		catch (const exception& e) {
			cout << "Exception: " << e.what() << endl;
		}
		catch (...) {
			cout << "Unknown error occurred." << endl;
		}
	}
}

/*

	keeper1.printall();

	try {
		keeper1[0]->print();
		keeper1[1]->print();
		(keeper1[1])->setgearbox("Auto");
		keeper1[1]->setbrand("Lexus");
		keeper1[1]->print();
		//keeper1[2]->print();
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
	}

	return 0;
}*/