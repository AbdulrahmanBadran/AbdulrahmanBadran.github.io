#include <cstdio>
#include <iomanip>
#include <string>
#include <fstream>
#include "myLib.h"
using namespace std;


int clientPos;
bool isAdd = false;
const string fileName = "myFile.txt";

struct stClientData {

	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;

};

enum enOption {

	enShowAllClients = 1, enAddClients = 2,
	enDeleteClients = 3, enUpdateClients = 4,
	enFindClient = 5, enTransaction = 6,
	enExit = 7

};

stClientData readClientData() {
	
	stClientData data;

	 cout<<"enter account number : ";
	 getline(cin >> ws, data.accountNumber);
	data.pinCode = myLib::readString("enter the pin code:");

	data.name = myLib::readString("enter your name:");

	data.phone= myLib::readString("enter your phoneNumber:");

	data.accountBalance = myLib::readDoubleNum("enter your balance:");

	return data;
}

stClientData readClientData(string accountNumber ) {

	stClientData data;
	
	data.accountNumber = accountNumber;

	data.pinCode = myLib::readString("enter the pin code:");

	data.name = myLib::readString("enter your name:");

	data.phone = myLib::readString("enter your phoneNumber:");

	data.accountBalance = myLib::readDoubleNum("enter your balance:");

	return data;
}

vector<stClientData> depositPerforme(vector<stClientData>& clients,double amount) {
	

	 clients[clientPos - 1].accountBalance+= amount;

	 return clients;



}

vector<string> splitString(string join, string delim = "#//#") {
	vector<string>v;
	string record;
	short pos;
	while ((pos = join.find(delim)) != string::npos) {

		record = join.substr(0, pos);
		v.push_back(record);
		join.erase(0, pos + delim.length());

	}

	if (join != "")
		v.push_back(join);


	return v;

}

stClientData convertLineToRecord(vector<string>v) {

	stClientData client;

	client.accountNumber = v[0];
	client.pinCode = v[1];
	client.name = v[2];
	client.phone = v[3];
	client.accountBalance = stod(v[4]);

	return client;

}

string convertRecordToLine(stClientData data) {

	string delim = "#//#";

	string join;

	join += data.accountNumber + delim + data.pinCode + delim + data.name + delim + data.phone + delim + to_string(data.accountBalance);


	return join;
}

void saveLineToFile(string line) {

	fstream myFile;

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open()) {

		myFile << line << endl;

		myFile.close();


	}

}

void saveAllVectorToFile(vector<stClientData>clients) {

	for (stClientData& i : clients) {

		saveLineToFile(convertRecordToLine(i));

	}


}

vector<stClientData> saveAllClientsInVectorExept(string accountNumber) {

	fstream myFile;
	myFile.open(fileName, ios::in);

	vector<string>v;
	vector<stClientData>clients;
	if (myFile.is_open()) {

		string line;
		while (getline(myFile, line)) {
			v = splitString(line);
			if (v[0] != accountNumber)
				clients.push_back(convertLineToRecord(v));
		}
		myFile.close();
	}

	return clients;
}

vector<stClientData> saveAllClientsInVector() {

	fstream myFile;
	myFile.open(fileName, ios::in);

	vector<string>v;

	vector<stClientData>clients;

	if (myFile.is_open()) {

		string line;
		while (getline(myFile, line)) {
			v = splitString(line);

			clients.push_back(convertLineToRecord(v));
		}
		myFile.close();
	}

	return clients;
}

bool findClientByAccountNumber(string AccountNumber, vector<stClientData>clients) {

	fstream myFile;



	myFile.open(fileName, ios::in);

	if (myFile.is_open()) {
		int i = 0;
		for (stClientData& client : clients) {
			i++;
			if (client.accountNumber == AccountNumber) {

				cout << endl;
				clientPos = i;
				myFile.close();

				return 1;
			}
		}
		if(!isAdd)
		cout << "Account with number(" << AccountNumber << ") is not exist!\n";

		myFile.close();

	}
	return 0;

}

bool isTheClientexist(string line, string AccountNumber) {

	return line.find(AccountNumber) != string::npos;
}

void PrintClientRecord(stClientData Client ) {
	cout << "\n\nThe following are the client data:\n";
	cout << "\nAccout Number: " << Client.accountNumber;
	cout << "\nPin Code     : " << Client.pinCode;

	cout << "\nName         : " << Client.name;
	cout << "\nPhone        : " << Client.phone;
	cout << "\nAccount Balance: " << Client.accountBalance;

}

void addClientScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tAdd Client Screen\n";
	cout << "--------------------------------------------------------\n";


}

void addNewClient(vector<stClientData>& clients) {
	stClientData data;


	

	string accountNumber;
	cout << "enter Account Number:";
	cin >> accountNumber;

	while (findClientByAccountNumber(accountNumber, clients)) {

		cout << "\nclient with account number (" << accountNumber << ") is already exist,try another acoount number:";
		cin >> accountNumber;


	}


	data=readClientData(accountNumber);
	saveLineToFile(convertRecordToLine(data));

	
}

void addClients(vector<stClientData>& clients) {

	char addMore='y';

	while (toupper(addMore) != 'Y' && toupper(addMore)!= 'N') {

		cout << "enter (y OR n -_-):";
		cin >> addMore;

	}
	while (toupper(addMore) =='Y') {
		system("cls");
		addClientScreen();
		cout << "Adding new client:\n\n";

		addNewClient(clients);
		cout << "Client added succefully do you want to add more (y/n):";
		cin >> addMore;
		
	} 

	
}

void printHeader(short number) {

	cout << "\t\t\tClient List (" << number << ") Client(s)\n";
	cout << "_____________________________________________________________________________________________________________\n";
	cout << "\n| Account Number  | Pin Code  | Client Name" << setw(30) << " | phone" << setw(20) << "| Balance";
	cout << "\n_____________________________________________________________________________________________________________\n";
}

void printClientData(vector<string>& v) {

	cout << "| " << setw(16) << left << v[0];
	cout << "| " << setw(10) << v[1];
	cout << "| " << setw(34) << v[2];
	cout << "| " << setw(15) << v[3];
	cout << "| " << setw(15) << left << v[4] << "\n";
}

void printAllBalances(vector<string>& v) {

	cout << "| " << setw(27) << left << v[0];
	cout << "| " << setw(30) << v[2];
	cout << "| " << setw(27) << left << v[4] << "\n";
}

void showAllClients( vector<stClientData>clients) {
	system("cls");

	

	fstream myFile;

	string line;

	vector<string>v;

	printHeader(clients.size());

	myFile.open(fileName, ios::in);

	if (myFile.is_open()) {

		while (getline(myFile, line)) {

			v = splitString(line,"#//#");
			printClientData(v);
			
		}
	}


}

void clearTheFile() {

	fstream myFile;

	myFile.open(fileName, ios::out);

	if (myFile.is_open()) {

		myFile << "";
		myFile.close();

	}

}

void deleteAccountScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tDelete Account Screen\n";
	cout << "--------------------------------------------------------\n";


}

void deleteClientByAccountNumber( vector<stClientData>&c) {

	system("cls");
	deleteAccountScreen();
	string AccountNumber= myLib::readString("Please enter account number: ") ;

	fstream myFile;

	vector<stClientData>clients;

	myFile.open(fileName, ios::out | ios::app);

	char insurance='n';

	if (myFile.is_open()) {
		

		if(findClientByAccountNumber(AccountNumber,c)) {
			PrintClientRecord(c[clientPos-1]);

		cout << "\n\nAre you sure you want to delete this client (y/n):";
		cin >> insurance;

		while (toupper(insurance) != 'Y' && toupper(insurance) != 'N') {

			cout << "enter (y OR n -_-):";
			cin >> insurance;

		}

		if (toupper(insurance) == 'Y') {

			clients = saveAllClientsInVectorExept(AccountNumber);

			clearTheFile();

			cout << "client deleted successfully"<<endl;

			for (stClientData& client : clients) {

				saveLineToFile(convertRecordToLine(client));
			}
		}

		}

		myFile.close();
		
	}



}

void deleteClientToUpdateIt(string AccountNumber, vector<stClientData>& clients, stClientData newData) {

	fstream myFile;

	

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{

		clients = saveAllClientsInVectorExept(AccountNumber);

		clearTheFile();

		saveLineToFile(convertRecordToLine(newData));

		for (stClientData& client : clients) {

			saveLineToFile(convertRecordToLine(client));
		}



	}
}

void updateClienScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tUpdate Clien Screen\n";
	cout << "--------------------------------------------------------\n";


}

void updateClientDataByAccountNumber( vector<stClientData>& c) {

	system("cls");

	updateClienScreen();

	fstream myFile;

	stClientData data;

	string AccountNumber = myLib::readString("Please enter account number: ");

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{

		if (findClientByAccountNumber(AccountNumber, c)) {

			PrintClientRecord(c[clientPos-1]);

			char insurance = 'y';

			cout << "\nAre you sure you want to update this client(y/n):";

			cin >> insurance;

			while (toupper(insurance) != 'Y' && toupper(insurance) != 'N') {

				cout << "enter (y OR n -_-):";
				cin >> insurance;

			}


			if (toupper(insurance) == 'Y') {
				cout << endl << endl;
				data = readClientData(AccountNumber);
				
				c[clientPos - 1] = data;
				
				clearTheFile();

				saveAllVectorToFile(c);
				cout << "Client Updated Successfully\n";
			}
		}

	}

	

}

void findClientScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tFind Client Screen\n";
	cout << "--------------------------------------------------------\n";


}

void findClient(vector<stClientData>&clients) {

	system("cls");
	findClientScreen();
	string AccountNumber = myLib::readString("Please enter account number: ");
	if (findClientByAccountNumber(AccountNumber, clients)) {

		PrintClientRecord(clients[clientPos - 1]);


	}


}

void exit() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tProgram Ends -_-\n";
	cout << "--------------------------------------------------------\n";

}

void updateClientBalanceByDeposit(vector<stClientData>& c) {

	

	fstream myFile;

	stClientData data;

	string AccountNumber = myLib::readString("Please enter account number: ");

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{

		if (findClientByAccountNumber(AccountNumber, c)) {

			PrintClientRecord(c[clientPos - 1]);

			char insurance = 'y';

			cout << "\nAre you sure you want to deposit to this client(y/n):";

			cin >> insurance;

			while (toupper(insurance) != 'Y' && toupper(insurance) != 'N') {

				cout << "enter (y OR n -_-):";
				cin >> insurance;

			}


			if (toupper(insurance) == 'Y') {
				cout << endl << endl;

				double deposit;

				cout << "how much do you want to deposit:";

				cin >> deposit;

				depositPerforme(c,deposit);

				clearTheFile();

				saveAllVectorToFile(c);
				cout << "The deposit has done Successfully\n";
			}
		}

	}



}

void updateClientBalanceByWithDraw(vector<stClientData>& c) {

	
	fstream myFile;

	stClientData data;

	string AccountNumber = myLib::readString("Please enter account number: ");

	myFile.open(fileName, ios::out | ios::app);

	if (myFile.is_open())
	{

		if (findClientByAccountNumber(AccountNumber, c)) {

			PrintClientRecord(c[clientPos - 1]);

			char insurance = 'y';

			cout << "\nAre you sure you want to withdraw from this client(y/n):";

			cin >> insurance;

			while (toupper(insurance) != 'Y' && toupper(insurance) != 'N') {

				cout << "enter (y OR n -_-):";
				cin >> insurance;

			}


			if (toupper(insurance) == 'Y') {
				cout << endl << endl;

				double withdraw;

				cout << "how much do you want to withdraw:";

				cin >> withdraw;

				if (withdraw > c[clientPos - 1].accountBalance)
				{
					cout << "The amount you are trying to withdraw is greater than the amount in your account";
					return;

				}

				depositPerforme(c, withdraw * -1);

				clearTheFile();

				saveAllVectorToFile(c);
				cout << "The withdraw has done Successfully\n";
			}
		}

	}



}

void depositScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tDeposit Screen\n";
	cout << "--------------------------------------------------------\n";



}

void deposit(vector<stClientData>& clients) {

	depositScreen();

	updateClientBalanceByDeposit(clients);

}

void withDrawScreen() {

	system("cls");
	cout << "--------------------------------------------------------\n";
	cout << "\t\tWithdraw Screen\n";
	cout << "--------------------------------------------------------\n";


}

void withDraw(vector<stClientData>& clients) {

	withDrawScreen();

	updateClientBalanceByWithDraw(clients);


}

string balancesTotal(vector<stClientData>& clients) {

	double total = 0;

	for (stClientData& i : clients) {

		total += i.accountBalance;
	}


	return to_string(total);

}

void showAllBalances(vector<stClientData>& clients) {

	cout << setw(50)<<" Balances List ("<< clients.size()<<") clients";

	cout << "_________________________________________________________________________________________________\n\n";
		cout << "| Account Number "<<setw(25)<<" | Client Name" << setw(30) << " | Balances\n";
	cout << "_________________________________________________________________________________________________\n";

	vector<string>data;
	for (stClientData& i : clients) {

		data=splitString((convertRecordToLine(i)));

		printAllBalances(data);
		cout << endl;
	}
	cout << "_________________________________________________________________________________________________\n";


	cout << setw(69) <<right <<"| Total=" << balancesTotal(clients)<<endl;



}

void transActions(vector<stClientData>& clients) {

	short operation;

	while (true) {
		system("cls");
		cout << "===============================================\n";
		cout << "press [1] Deposit\n";
		cout << "press [2] Withdraw\n";
		cout << "press [3] Total Balances\n";
		cout << "press [4] Main Menu\n";
		cout << "===============================================\n";

		operation = myLib::readShortNumber("enter what do you want to do [1 to 4]:");

		switch (operation)
		{
			{case 1:deposit(clients);
				   system("pause");
				   continue; }

			{case 2:withDraw(clients);
				   system("pause");
				   continue; }

			{case 3:showAllBalances(clients);
				   system("pause");
				   continue; }

			{case 4: return;}

			{default:cout << "enter a valid operation -_-\n";
					system("pause");
					continue; }
		}
	}



}



void mainMenu() {

	vector<stClientData>clients = saveAllClientsInVector();

	enOption option;
	
	string accountNumber;

	while (true) {
		system("cls");
		cout << "===============================================\n";
		cout << "press [1] to show all clients\n";
		cout << "press [2] to add client\n";
		cout << "press [3] to delete client\n";
		cout << "press [4] to update client\n";
		cout << "press [5] to find client\n";
		cout << "press [6] to Transactions\n";
		cout << "press [7] to exit the program\n";
		cout << "===============================================\n";

		option = (enOption)myLib::readShortNumber("enter what do you want to do [1 to 7]:");

		switch (option)
		{
			

			{case enOption::enShowAllClients:showAllClients(clients);
			system("pause");
			continue;}

            {case enOption::enAddClients:addClients(clients);
			system("pause");
			continue;}

			{case enOption::enDeleteClients:deleteClientByAccountNumber( clients);
				system("pause");
				   continue;}

			{case enOption::enUpdateClients:updateClientDataByAccountNumber(clients);
				   system("pause");
				   continue; }

			{case enOption::enFindClient:findClient(clients);
				   system("pause");
				   continue; }

			{case enOption::enTransaction:transActions(clients);
				   continue; }

			{case enOption::enExit: exit();
				return;}
			{default:cout << "enter a valid operation -_-\n";
					system("pause");
					continue;}
		}
	}
	


}



int main()
{

	vector<stClientData>clients = saveAllClientsInVector();
	
	mainMenu();
	
	

	system("pause>0");
}
