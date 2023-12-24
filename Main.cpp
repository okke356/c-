#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
using namespace std;
int LineCount = 0;
// bang chu cai va so
const char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzquot";
const char char_set2[] = "0123456789";

// ham lay gia tri trong mang
int Getid(const int i) {
	return char_set[i];
}
int Getid1(const int i) {
	return char_set2[i];

}// ham ramdom id
string RandomAmuont() {
	char arr[11];

	// lay ramdom ki tu bat ki trong 2 mang ki tu
	for (int i = 0; i < 10; i++) {
		int temp = rand() % 2;
		int temp1 = rand() % (sizeof(char_set) - 1);
		int temp2 = rand() % (sizeof(char_set2) - 1);
		if (temp == 0) {
			arr[i] = Getid(temp1);
		}
		if (temp == 1) {
			arr[i] = Getid1(temp2);
		}
	}
	arr[10] = '\0';


	return  arr;


}


class ATM {
private:
	int AccountBalance = 100;
	int PinNumber;
	string UserId="";
	int tranfer=0;
	vector<string> UsersID;
public:


	void Displaymenu1() {
		cout << "--------------------------ATM-----------------------------" << endl;
		cout << "\t" << "1.  LOGIN" << "\t" << endl;
		cout << "\t" << "2.  CREATE NEW ACCOUNT" << "\t" << endl;
		cout << "\t" << "3.  EXIT" << "\t" << endl;
	}
	void Displaymenu2() {
		cout << "---------------------SUCCESSFULYY LOGGED IN---------------------------" << endl;
		cout << "\t" << "1.  ACCOUNT INFORMATION" << "\t" << endl;
		cout << "\t" << "2.  WITHDRAW MONEY" << "\t" << endl;
		cout << "\t" << "3.  DEPOSIT MONEY" << "\t" << endl;
		cout << "\t" << "4.  TRANSFER MONEY" << "\t" << endl;
		cout << "\t" << "5.  LOGOUT" << "\t" << endl;

	}
	void Displaymenu21() {
		
		cout << "----------- CHOOSE YOUR AMUONT OF MONEY -------------" << "\t" << endl;
		cout << "\t" << "1.  10" << "\t" << endl;
		cout << "\t" << "2.  20" << "\t" << endl;
		cout << "\t" << "3.  50" << "\t" << endl;
		cout << "\t" << "4.  100" << "\t" << endl;
		cout << "\t" << "5.  OTHER" << "\t" << endl;
		cout << "\t" << "CHOOSE YOUR OPTION: " << "\t";
		
	}
	void Displaymenu11() {
		cout << "===========================================" << endl;
		cout << "USER ID: ";
	}
	int Displaymenu12() {
		cout << "PIN NUMBER: ";
		cin >> PinNumber;
		int option = 1;
		string PinString;
		PinString = to_string(PinNumber);

		if (PinString.length() == 6 && PinNumber > 0 && CheckPin(PinString)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			option = 0;

		}
		else {
			cout << "Error! Please enter a valid 6-digit PIN." << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		return PinNumber;
	}
	//ham check xem pin co phai la so k
	bool CheckPin(const string& Pin) {
		//ham for each vs duyet qua moi bien check voi pin
		for (char check : Pin) {
			if (!isdigit(check)) {
				return false;
			}
		}
		return true;
	}


	// dang ki
	string Resgister() {
		UserId = RandomAmuont();
		cout << "YOUR ACCOUNT NUMBER: " << UserId << endl;
		
		string line;

		int option = 1;

		// tao file de gi thong tin
		while (option == 1) {
			cout << "Please enter a valid 6 - digit PIN. " << endl;
			cout << "PIN NUMBER: ";
			cin >> PinNumber;
			string PinString;
			PinString = to_string(PinNumber);

			if (PinString.length() == 6 && PinNumber > 0 && CheckPin(PinString)) { 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				ofstream WriteFile(UserId + ".txt", ios::app);
				WriteFile << PinNumber << " " << AccountBalance << endl;
				WriteFile.close();
				option = 0;

			}
			else {
				cout << "Error! Please enter a valid 6-digit PIN." << "\n";
				// xoa nhung ki tu da nhap vao cin de 
				cin.clear();
				// tinh ca ki tu xuong dong
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}

		}
		return UserId;
	}
	// tao ham de luu id check login
	// chay moi ham nay thoi vi trong ham nay chua resgistor
	int  MasterSaveId() {
		ofstream WriteFile1("ListUserId.txt", ios::app);
		WriteFile1 << UserId<<endl;
		WriteFile1.close();
		
	
		return LineCount;
	}
	
	string Login() {
		string temp11;
		string line;
		Displaymenu11();
		cin >> UserId;
		ifstream ReadFile("ListUserId.txt", ios::app);
		while (getline(ReadFile, line)) {
			UsersID.push_back(line);
		}
		

		ReadFile.close();
		
		for(int i = 0; i < UsersID.size(); i++){
			if (UsersID[i] == UserId) {
				Displaymenu12();
				ifstream File(UsersID[i]+".txt", ios::app);
				char charracters[7];
				// lau 6 ki tu + ki tu null cua dong dau tien cua file 
				File.get(charracters, 7);
				string temp = to_string(PinNumber);	
				if (charracters == temp) {
					cout << "======================WELLCOME USER NO. " << UsersID[i] << "====================" << endl;
						
				}
				else
				{
					cout << "falied"<< endl;
				}
				File.close();

				
			}
			
			if (UsersID[i] == " ") {
				break;
			}
			
			
		}
		
		
		return temp11;
	}
	void WithdrawMoney() {
		string line;
		vector<string>Information;
		ifstream ReadFile1(UserId + ".txt", ios::app);
		while(getline(ReadFile1, line)) {
			
			Information.push_back(line);
		}
		ReadFile1.close();


		
		
		int temp =0;
		
			Displaymenu21();
			cin >> temp;
	
			if (AccountBalance > 0) {
			switch (temp){
		case 1:
			cout << "WITHDRAW: " << 10 << endl;
			AccountBalance = AccountBalance - 10;
			cout << "ACCOUNT BALANCE: " << AccountBalance << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		case 2:
			cout << "WITHDRAW: " << 20 << endl;
			AccountBalance = AccountBalance - 20;
			cout << "ACCOUNT BALANCE: " << AccountBalance << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		case 3:
			cout << "WITHDRAW: " << 50 << endl;
			AccountBalance = AccountBalance - 50;
			cout << "ACCOUNT BALANCE: " << AccountBalance << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		case 4:
			cout << "WITHDRAW: " << 100 << endl;
			AccountBalance = AccountBalance - 100;
			cout << "ACCOUNT BALANCE: " << AccountBalance << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		case 5:
			int Money;
			cin >> Money;
			cout << "WITHDRAW: " << Money << endl;
			AccountBalance = AccountBalance - Money;
			cout << "ACCOUNT BALANCE: " << AccountBalance << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;

		default:
			cout << "Wrong option" << endl;;
			// lam moi cin
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		}
			else
		{
			cout << "dflkashuikadfghkud";

		}
		
		
			string temp1 = to_string(PinNumber);
			string temp2 = to_string(AccountBalance);
			string temp3 = temp1 + " " + temp2;
			Information[0] =  temp3 ;
		// ghi tat ca cac dong trong vector vao file
		ofstream WriteFile2(UserId + ".txt", ios::app);
		for (int i = 0; i < Information.size(); i++) {
			if (Information[i] != "") {
				WriteFile2 << Information[i];
			}
		}
		WriteFile2.close();
		
	}
	int stringtoint(string str) {
		int temp1 = 0;
		for (int i = 0; i < str.length(); i++) {
			int temp = str[i] - 48;
			temp1 = temp1 * 10 + temp;
		}
		return temp1;
	}
	void DepositMoney() {
		cout << "THE AMOUNT OF CASH YOU WANT TO DEPOSIT: ";
		int Deposit = 0;
		string StringDeposit = to_string(Deposit);
		string line;
		string line1;

		vector<string>Information;
		ifstream ReadFile2(UserId + ".txt", ios::app);
		while (getline(ReadFile2, line)) {

			Information.push_back(line);
		}
		ReadFile2.close();
		//dong mo file 2 lan de con tro cua file chay tu dau file
		ifstream ReadFile3(UserId + ".txt", ios::app);
		ReadFile3.seekg(7, ios::beg);
		getline(ReadFile3, line1);
		int amount = stringtoint(line1);
		ReadFile3.close();
		string temp1 = to_string(PinNumber);
		int temp2 = 0;
		int option = 1;
		while (option == 1) {

			cin >> Deposit;
			if (Deposit > 0 && CheckPin(StringDeposit)) {
				temp2 = amount + Deposit;
				string temp3 = to_string(temp2);
				cout << "YOUR ACCOUNT BALANCE: "<< temp3 << endl;
				Information[0] = temp1 + " " + temp3;
				option = 0;

			}
			else {
				cout << "WRONG TYPE NUMBER TRY AGAIN" << endl;
			}
		}
	
		// kiem tra co phai so duong k
		
		
		ofstream WriteFile3(UserId + ".txt");
		// ghi tat ca cac dong trong vector vao file
		for (int i = 0; i < Information.size(); i++){
			if (Information[i] != "") {
				WriteFile3 << Information[i];
				
			}

		}
		
		WriteFile3.close();
		
	}
	void TransferMoney() {
		cout << "THE AMOUNT OF ID YOU WANT TO TRANFER: ";
		
		string userTranfer;
		
		string StringTranfer = to_string(tranfer);
		string line;
		string line1;
		vector<string>Information;
		// mo file de luu ra vector
		ifstream ReadFile4(UserId + ".txt", ios::app);
		for (int i = 0; i < sizeof(ReadFile4); i++) {
			getline(ReadFile4, line);
			Information.push_back(line);
		}
		ReadFile4.close();
		// dem so dong
		ifstream ReadFile6(UserId + ".txt", ios::app);
		while (getline(ReadFile6, line))
		{
			LineCount++;
		}
		ReadFile6.close();
		// kiem tra xem co friendly account k va in ra danh asch firendly account
		ifstream ReadFile5(UserId + ".txt", ios::app);

		if (LineCount <= 1) {

				cout<<"NONE ACCOUNT FRIENDLY" << endl;
		}
		else
		{
			while (getline(ReadFile5, line))
			{
				cout << line << endl;

			}
		}
		ReadFile5.close();
		// kiem tra xem da co nguoi dung nay trong account friendly chua
		cout << "TRANFER ID: ";
		cin >> userTranfer;
		for (int i = 0; i < Information.size(); i++){
			if (Information[i] != "" && Information[i]!=userTranfer) {
				cout << "----------------DO YOU WANT ADD FRIEND THIS ACCOUNT (Y/N)-----------------"<<endl;
				string temp ;
				cout << "INPUT YOUR OPTION: ";
				cin >> temp;
					if (temp == "Y" || temp == "y") {
						Information.push_back(userTranfer);
						cout << "SUCCESSFULLY" << endl;
						break;

					}
					if (temp == "n" || temp == "N") {
						break;

					}
					else
					{
						cout << "WRONG TYPE OF OPTION" << endl;
					}
					
					
			}
		}
		//dong mo file 2 lan de con tro cua file chay tu dau file
		// chi lay amuont bat dau tinh tu ki tu thu 7
		ifstream ReadFile7(UserId + ".txt", ios::app);
		ReadFile7.seekg(7, ios::beg);
		getline(ReadFile7, line1);
		int amount= stringtoint(line1);
		ReadFile7.close();

		// kiem tra co phai so duong k
		int option = 1;
		while (option == 1) {

			cin >> tranfer;
			if (tranfer > 0 && CheckPin(StringTranfer)) {
				if (tranfer < amount) {
					cout << "NOT ENGOUGH MONEY" << endl;
				}
				else
				{
					amount = amount - tranfer;
					option = 2;
				}
			}
		}
		//=================
		Information[0] = Displaymenu12() + " " + amount;
		ofstream WriteFile4(UserId + ".txt", ios::app);
		// ghi tat ca cac dong trong vector vao file
		for (int i = 0; i < Information.size(); i++) {
			if (Information[i] != "") {
				WriteFile4 << Information[i];
			}

		}

		WriteFile4.close();
		
	}
	void Check() {
		cout << "Number of users: " << UsersID[0] << endl;
	}
};
class User : public ATM {
private:
	string AccountID;
	unsigned int PinNumber = 0;
	int AccountBalance = 0; 
public:
	// lay thong tin
	string GetAccountID() {
		return AccountID;
	}
	int GetPinNumber() {
		return PinNumber;
	}
	int GetAcoutBalance() {
		return AccountBalance;
	}

	void AccountInformation() {
		string Line;
		AccountID = Login();
		ifstream ReadFile8(AccountID+".txt", ios::app);
		while (getline(ReadFile8,Line))
		{
			cout << Line;
		}
		ReadFile8.close();
	}
};

int main() {
	
	User User;
	ATM ATM;
	int Option =0;
	ATM.Login();
	ATM.TransferMoney();
	return 0;
}
