#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;
struct Aeroflot {
	int flightNumber;
	string nameOfDeparturePoint;
	string nameOfDestinationPoint;
	string typeOfPlane;
	double travelTimeInMinutes;
	double ticketPrice;
};

void getFlightInfo(int n, Aeroflot* inf) {
	for (int i = 0; i < n; i++) {
		Aeroflot info;
		cout << "Enter the flight number please: "; cin >> info.flightNumber;
		cout << "Enter the name of departure point please: "; getline(cin >> ws, info.nameOfDeparturePoint);
		cout << "Enter the name of destination point please: "; getline(cin >> ws, info.nameOfDestinationPoint);
		cout << "Enter the type of plane please: "; getline(cin >> ws, info.typeOfPlane);
		cout << "Enter the travel time please: "; cin >> info.travelTimeInMinutes;
		cout << "Enter the ticket price please: "; cin >> info.ticketPrice;
		inf[i] = info;
	}

}

void outputFlightInfo(int n, Aeroflot* inf) {
	cout << setw(10) << "Flight number: ";
	cout << setw(20) << "Name of departure point: ";
	cout << setw(30) << "Name of destination point: ";
	cout << setw(40) << "Type of plane: ";
	cout << setw(50) << "Travel time: ";
	cout << setw(60) << "Ticket price: " << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(10) << inf[i].flightNumber << setw(20) << inf[i].nameOfDeparturePoint << setw(30) << inf[i].nameOfDestinationPoint << setw(40) << inf[i].typeOfPlane << setw(50) << inf[i].travelTimeInMinutes << setw(60) << inf[i].ticketPrice << endl;
	}
}

void searchByNameOfDestinationPoint(Aeroflot* inf, int n, string name) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (inf[i].nameOfDestinationPoint == name) {
			sum = sum + 1;
			cout << setw(10) << "Flight number: ";
			cout << setw(20) << "Name of departure point: ";
			cout << setw(30) << "Name of destination point: ";
			cout << setw(40) << "Type of plane: ";
			cout << setw(50) << "Travel time: ";
			cout << setw(60) << "Ticket price: ";
			cout << endl;
			cout << setw(10) << inf[i].flightNumber << setw(20) << inf[i].nameOfDeparturePoint << setw(30) << inf[i].nameOfDestinationPoint << setw(40) << inf[i].typeOfPlane << setw(50) << inf[i].travelTimeInMinutes << setw(60) << inf[i].ticketPrice << endl;
		}
	}
	if (sum == 0) {
		cout << "There are no suitable flights! ";
	}
}


void sortByNameOfDestinationInAlphabeticalOrder(Aeroflot* inf, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (inf[j].nameOfDestinationPoint > inf[j + 1].nameOfDestinationPoint) {
				swap(inf[j].nameOfDestinationPoint, inf[j + 1].nameOfDestinationPoint);
			}
		}
	}
}
void sortByTicketPrice(Aeroflot* inf, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (inf[j].ticketPrice > inf[j + 1].ticketPrice) {
				swap(inf[j].ticketPrice, inf[j + 1].ticketPrice);
			}
		}
	}
}

void editByNumberOfFlight(Aeroflot* inf, int n) {
	cout << "Please enter flight number to edit information: ";
	int FlightNumberToEdit;
	cin >> FlightNumberToEdit;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (inf[i].flightNumber == FlightNumberToEdit) {
			cout << "Please enter a new number of flight:";
			cin >> inf[i].flightNumber;
			cout << "Please enter a new name of departure point:";
			cin >> inf[i].nameOfDeparturePoint;
			cout << "Please enter a new name of destination point:";
			cin >> inf[i].nameOfDestinationPoint;
			cout << "Please enter a new type of plane:";
			cin >> inf[i].typeOfPlane;
			cout << "Please enter a new travel time:";
			cin >> inf[i].travelTimeInMinutes;
			cout << "Please enter a new ticket price: ";
			cin >> inf[i].ticketPrice;
			sum = sum + 1;
		}
	}
	if (sum == 0) {
		cout << "There are no flights with a suitable number! Try once again! " << endl;
		cout << "Press any key to continue or enter 0 to exit: " << endl;
		int a;
		cin >> a;
		if (a != 0) {
			editByNumberOfFlight(inf, n);
		}
		else {
			cout << "Information has not been changed! " << endl;
		}
	}
	else {
		cout << "Information has been changed! " << endl;
	}
}
int menu(Aeroflot* inf, int n, bool isInputCorrect) {
	int switchHelper;
	bool input = isInputCorrect;
	cout << "Select an action please: " << endl << "To display information as a table - 1 " << endl << "To search flight by name of destination - 2" << endl << "To sort flights by ticket price - 3" << endl << "To sort flights by name of destination point in alphabetical order - 4" << endl << "To edit information about flight - 5" << endl << "To enter flight information - 6" << endl << "To exit - 0" << endl;
 cin >> switchHelper;
	switch (switchHelper)
	{
	case 1:
		if (!input) {
			cout << "You need to fill the information about flight first! " << endl;
		}
		else {
			outputFlightInfo(n, inf);
		}
		break;
	case 4:if (!input) {
		cout << "You need to fill the information about flight first! " << endl;
	}
		  else {
		sortByNameOfDestinationInAlphabeticalOrder(inf, n);
		outputFlightInfo(n, inf);
	}
		  break;
	case 2:
		if (!input) {
			cout << "You need to fill the information about flight first! " << endl;
		}
		else {
			string name;
			cout << "Please enter a destination point to search: ";
			cin >> name;
			searchByNameOfDestinationPoint(inf, n, name);
		}
		break;
	case 3:
		if (!input) {
			cout << "You need to fill the information about flight first! " << endl;
		}
		else {
			sortByTicketPrice(inf, n);
			outputFlightInfo(n, inf);
		}
		break;
	case 5:
		if (!input) {
			cout << "You need to fill the information about flight first! " << endl;
		}
		else {
			editByNumberOfFlight(inf, n);
			outputFlightInfo(n, inf);
		}
		break;
	case 0:return 0;
	case 6: getFlightInfo(n, inf);
		input = true;
	}
	return menu(inf, n, input);
}

int main() {
	int n;
	cout << "Enter a number of flights please: ";
	cin >> n;
	while (n <= 0) {
		cout << "You can not do it! Try once again! "; cin >> n;
	}
	
	Aeroflot* info = new Aeroflot[n];
	bool isInputCorrect = false;
	menu(info, n, isInputCorrect);
	return 0;
	
}


