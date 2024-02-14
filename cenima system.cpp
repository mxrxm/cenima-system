#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm> 
using namespace std;
int z;
int total = 0;
int employee_number = 1, item_code = 1, offers_number = 1;
void items_management();
void staff_management();
void offers_management();
void cenima_management();
void sale_item();
void sale_offer();
void management();
void workermanger();
void welcome();
void guest();
void other();
void menu2();
void check();
void exit();

class user {
private:
	string username;
	string password;
public:

	void set_username(string name) { username = name; }
	string get_username() { return username; }
	void set_password(string pass) { password = pass; }
	string get_password() { return password; }

	void create_account() {
		system("cls");
		cout << "-----------------------------------------------\n";
		string n, p;
		cout << "please enter your username:\n";
		cout << "-----------------------------------------------\n";
		cin >> n;
		cout << "-----------------------------------------------\n";
		set_username(n);
		cout << "please enter your password:\n";
		cin >> p;
		cout << "-----------------------------------------------\n";
		set_password(p);
		store_data();

	}
	bool sign_in() {

		system("cls");
		cout << "-----------------------------------------------\n";
		string n, p;
		cout << "please enter your username:\n";
		cout << "-----------------------------------------------\n";
		cin >> n;
		cout << "-----------------------------------------------\n";
		set_username(n);
		cout << "please enter your password:\n";
		cout << "-----------------------------------------------\n";
		cin >> p;
		set_password(p);
		check_data(n, p);
		if (check_data(n, p)) {
			cout << "You are successfully logged in!\n"; return true;
		}
		else {
			cout << "User not found!\n";
			return false;

		}
	}

	void store_data() {
		fstream EnterData;
		EnterData.open("userdata.txt", ios::app);
		EnterData << username << ' ' << password << endl;
		EnterData.close();
		cout << "Account Created Successfully!\n";
	}

	bool check_data(string x, string y) {
		int exist = 0;
		fstream CheckData;
		CheckData.open("userdata.txt", ios::in);
		CheckData.seekg(ios::beg);
		while (CheckData >> x >> y) {
			if (x == username && y == password) {
				exist = 1;
			}
		}
		CheckData.close();
		if (exist == 1) {
			return true;
		}
		else {
			return false;
		}
	}


	void delete_user() {
		system("cls");
		cout << "-----------------------------------------------\n";
		char s;
		string n, p;                                 //name and password
		fstream d, t;//d for the file that contains data to be deleted and t for an empty file
		cout << "Are you sure you want to delete your account? (enter y for yes, n for no)\n";
		cout << "-----------------------------------------------\n";
		cin >> s;
		cout << "-----------------------------------------------\n";
		if (s == 'y' || s == 'Y') {
			cout << "please enter your username:\n";
			cout << "-----------------------------------------------\n";
			cin >> n;
			cout << "-----------------------------------------------\n";
			set_username(n);
			cout << "please enter your password:\n";
			cout << "-----------------------------------------------\n";
			cin >> p;
			set_password(p);
			cout << "-----------------------------------------------\n";
			if (!check_data(n, p)) { cout << "User not found!\n"; }
			else {
				d.open("userdata.txt", ios::in);
				t.open("temp.txt", ios::out);
				t.seekg(ios::beg);
				while (!d.eof()) {
					d >> username >> password;
					if (n != get_username() && p != get_password()) { t << username << ' ' << password << endl; }

				}

				//copying the data from the original file to the empty one except for the account that will be deleted
				t.close();
				d.close();
				//now we have the data without the account to be deleted 
				//so we will delete the original file and rename the emporary file the same name as the orignial one was
				//because we want to be able to use it in other funcions
				remove("userdata.txt");
				rename("temp.txt", "userdata.txt");
				cout << "Account Deleted Successfully\n";
			}



		}
		else if (s == 'n' || s == 'N') cout << "We are delighted to still have your membership!\n";
	}
}customar;
class Movies {
private:
	struct details {
		string name, date, price;
		int movienum = 0;
	};
	int movien;
	int moviet;
	vector<details>v;
	int a[11][30] = { 0 };
	int halln = 1;
	int sc = 0;
	vector<pair<char, int>>seatsName;
public:
	void AddMovie() {//storage
		cout << "* Add Movie *" << endl;
		details x;
		system("cls");
		cout << "---------------------------------------" << endl;
		cout << "\nMovie's name to add :";
		std::cin >> std::ws;
		getline(cin, x.name);
		cout << "\nMovie's date to add :";
		std::cin >> std::ws;
		getline(cin, x.date);
		cout << "\nMovie's price to add :";
		cin >> x.price;
		cout << "---------------------------------------" << endl;

		z++;
		x.movienum = z;
		v.push_back(x);
		SaveData();
	}
	void ViewMovies() {//done
		system("cls");
		cout << "---------------------------------------" << endl;
		cout << "MOVIES AVALIBLE!!" << endl;
		string temp[3];
		details x;
		int i = 1;
		try {
			ifstream get;
			get.open("movieData.txt");
			while (!get.eof()) {
				get >> temp[0] >> temp[1] >> temp[2];

				x.name = temp[0];
				x.date = temp[1];
				x.price = temp[2];
				x.movienum = i;
				v.emplace_back(x);
				i++;

			}
			get.close();
		}
		catch (exception& e) {
			cout << "standard exeption" << e.what() << endl;
		}
		for (auto it : v)
			cout << it.movienum << "-" << it.name << "(" << it.date << ")" << "\t" << it.price << "LE\n\n\n";
		cout << "---------------------------------------" << endl;
	}
	void RemoveMovie() {
		ViewMovies();
		int n;
		auto i = v.begin();
		cout << " \nmovie number to remove :";
		cin >> n;
		v.erase(i + n - 1);
		v.shrink_to_fit();
		SaveData();

	}
	void SaveData() {
		fstream de;
		de.open("movieData.txt", ios::out);
		for (int i = 0; i < v.size(); i++)

			de << v[i].name << ' ' << v[i].date << ' ' << v[i].price << endl;;
		de.close();
	}
	void EditMovie() {
		ViewMovies();
		auto i = v.begin();
		int n;
		cout << " \nmovie number to edit :";
		cin >> n;
		system("cls");
		{
			int k = 0;
			cout << "---------------------------------------" << endl;
			cout << "to    change    the    name, press 1" << endl;
			cout << "to    change    the    Date, press 2" << endl;
			cout << "to    change    the   price, press 3" << endl;
			cout << "---------------------------------------" << endl;
			cout << "enter your choice: ";
			cin >> k;
			cout << "---------------------------------------" << endl;
			switch (k)
			{
			case 1:
				cout << "enter new name of movie : ";
				std::cin >> std::ws;
				getline(cin, v[n - 1].name);
				break;
			case 2:
				cout << "enter Date of movie : ";
				std::cin >> std::ws;
				getline(cin, v[n - 1].date);
				break;
			case 3:
				cout << "enter price of movie : ";
				cin >> v[n - 1].price;
				break;
			default:
				cout << "not found in the options,try again" << endl;
				EditMovie();
				break;
			}
			cout << "---------------------------------------" << endl;
			cout << "Do you want to modify something alse ?" << endl;
			string s;
			cout << "if you want, enter yes" << endl;
			cout << "if not Press any key" << endl;
			cin >> s;
			if (s == "yes")
				EditMovie();
			cout << endl;
		}
		SaveData();
	}
	void ChooseMovie() {
		ViewMovies();
		int n;
		cout << "choose movie number : ";
		cin >> n;
		movien = n;
	}

	void MovieTime() {
		int n;
		system("cls");
		cout << "*Times avalible*" << endl;

		cout << "---------------------------------------" << endl;

		cout << "1-[ 10:00 am ]\n\n\n";
		cout << "2-[ 3:00 pm  ]\n\n\n";
		cout << "3-[ 7:00 pm  ]\n\n\n";
		cout << "4-[ 12:00 am ]\n\n\n";
		cout << "---------------------------------------" << endl;

		cout << "choose time: ";
		cin >> n;
		//ad5l alhall? veiw hall
		if (n == 1)  moviet = 10;
		else if (n == 2)  moviet = 3;
		else if (n == 3)  moviet = 7;
		else moviet = 12;
	}
	void ChooseSeat() {
		ViewSeat();
		try {
		re:
			pair<char, int> seat;
			fstream book;
			book.open("data.txt", ios::out);/*fe mo4kla fl files*/
			cout << "seat choosen: ";

			cin >> seat.first >> seat.second;
			seatsName.emplace_back(seat);

			for (int i = 0; i < 11; i++) {
				for (int j = 0; j < 30; j++) {
					if (seat.first == char(97 + i) && seat.second == j + 1) a[i][j] = 1;

					book << a[i][j] << endl;
				}

			}book.close();
			sc++;
			char x;
			cout << "choose another enter 1 ,else press any key" << endl;
			cin >> x;
			if (x == '1') goto re;
		}

		catch (exception& e) { cout << "standard exeption" << e.what() << endl; }
	}
	void ViewSeat() {
		Getdata();
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\t\t-----------------" << endl;
		cout << "\t\t\t\t\t\t\t\t|    HALL " << movien << "     |" << endl;
		cout << "\t\t\t\t\t\t\t\t-----------------" << endl;
		cout << "\n";
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 30; j++) {
				if (a[i][j] == 0)	cout << setw(1) << "[" << char('a' + i) << j + 1 << "]";
				else {
					if (j + 1 > 10)cout << setw(1) << "[---]";
					else cout << setw(1) << "[--]";
				}
				if ((j + 1) % 10 == 0) cout << "\t";

			}
			cout << "\n\n";
		}
	}
	void Getdata() {

		string s;
		try {
			ifstream get;
			get.open("data.txt");
			for (int i = 0; i < 11; i++) {
				for (int j = 0; j < 30; j++) {

					get >> s;
					a[i][j] = stoi(s);//bt3ml error sa3at
				}

			}get.close();
		}
		catch (exception& e) { cout << "standard exeption" << e.what() << endl; }
	}
	void seats() {
		for (auto it : seatsName)
			cout << it.first << it.second << " ";
	}
	void Ticket() {
		system("cls");
		cout << "\n\n\n\n\t\t\t________________________________________________________________________\n";
		cout << "\t\t\t|                                                                       \n";
		cout << "\t\t\t|   Dear Customer, \n";
		cout << "\t\t\t|                      Congratulation!! Your tickets has been booked.\n";
		cout << "\t\t\t|                                                                       \n";
		cout << "\t\t\t|                  THE DETAILS:\n";
		cout << "\t\t\t|                            MOVIE HALL: " << movien << "\n";
		cout << "\t\t\t|                            MOVIE NAME: " << v[movien - 1].name << "\n";
		cout << "\t\t\t|                            SHOW STARTS:" << moviet << ":00\n";
		cout << "\t\t\t|                            NUMBER OF TICKETS BOOKED: " << sc << "\n";
		cout << "\t\t\t|                 THE SEAT NUMBERS ARE: ";  seats();
		cout << "\n\t\t\t|________________________________________________________________________\n";

		total += stoi(v[movien - 1].price) * sc;
	}

}movie;
class employee {
	string name;
	string id;
	string telephone_number;
	int days;
	int day_salary;
	float salary;
	bool enabled;
public:
	void set_name(string n) { name = n; }
	void set_id(string d) { id = d; }
	void set_telephone_number(string t) { telephone_number = t; }
	void set_days(int dy) { days = dy; }
	void set_day_salary(int ds) { day_salary = ds; }
	void set_salary(float s) { salary = s; }
	void set_enabled(bool e) { enabled = e; }
	string get_name() { return name; }
	string get_id() { return id; }
	string get_telephone_number() { return telephone_number; }
	int get_days() { return days; }
	int get_day_salary() { return day_salary; }
	float get_salary() { return salary; }
	bool get_enabled() { return enabled; }
	int code;
	void add_employee() {
		day_salary = 100;
		days = 0;
		salary = 0;
		enabled = true;
		code = employee_number;
		employee_number++;
		cout << "code : " << code << endl;
		cout << "enter employee`s name: ";
		std::cin >> std::ws;
		getline(cin, name);
		cout << "enter employee`s telephone number: ";
		std::cin >> std::ws;
		getline(cin, telephone_number);
		cout << "enter employee`s id: ";
		std::cin >> std::ws;
		getline(cin, id);

	}
	void attending() {      // out of management part
		int Code;
		do {
			cout << "enter your id (enter 0 to exit): ";
			cin >> Code;
			if (Code == 0)
				break;
		} while (code != code);
		if (Code == code) {
			days++;
			salary += day_salary;
		}
		cout << "day attended successfully" << endl;

	}
	void deduction_form_salary()
	{
		int deduction = 0;
		cout << "deduction value : ";
		cin >> deduction;
		salary -= deduction;
	}
	void bonus_to_salary()
	{
		int bonus = 0;
		cout << "bonus value : ";
		cin >> bonus;
		salary += bonus;
	}
	void modify()
	{
		int n = 0;
		cout << "---------------------------------------" << endl;
		cout << "to   change    the        name, press 1" << endl;
		cout << "to change the tetephone number, press 2" << endl;
		cout << "to  change     the          id, press 3" << endl;
		cout << "to  change     the  day salary, press 4" << endl;
		cout << "to  change     the      status, press 5" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << "---------------------------------------" << endl;
		switch (n)
		{
		case 1:
			cout << "enter new name : ";
			std::cin >> std::ws;
			getline(cin, name);
			break;
		case 2:
			cout << "enter the tetephone number of " << name << " : ";
			std::cin >> std::ws;
			getline(cin, telephone_number);
		case 3:
			cout << "enter id of " << name << " : ";
			std::cin >> std::ws;
			getline(cin, id);
			break;
		case 4:
			cout << "enter day salary of " << name << " : ";
			cin >> day_salary;
			break;
		case 5:
			cout << "enter status of " << name << " : ";
			cout << "1 (enable) or 0 (disable)" << endl;
			cin >> enabled;
			break;

		default:
			cout << "not found in the options,try again" << endl;
			modify();
			break;
		}
		cout << "---------------------------------------" << endl;
		cout << "Do you want to modify something alse ?" << endl;
		string s;
		cout << "if you want, enter yes" << endl;
		cout << "if not Press any key" << endl;
		cin >> s;
		if (s == "yes")
			modify();

		cout << endl;
	}

	void show()
	{
		cout << "employee`s name: " << name << endl;
		cout << "employee`s tetephone number: " << telephone_number << endl;
		cout << "employee`s id: " << id << endl;
		cout << "employee`s salary: " << day_salary * 26 << endl;
		cout << "current employee entitlements: " << salary << endl;
		cout << "employee attendance days: " << days << endl;
		cout << "employee`s status: " << enabled << endl;
	}

};
class item {
private:
	string name;
	string date;
	int quantity;
	string validity;
	float price;
	int sale_number = 0;
public:
	float get_price() { return price; }
	string get_name() { return name; }
	string get_date() { return date; }
	string get_validity() { return validity; }
	int get_quantity() { return quantity; }
	int get_sale_number() { return sale_number; }
	void set_name(string n) { name = n; }
	void set_price(float p) { price = p; }
	void set_date(string d) { date = d; }
	void set_validity(string v) { validity = v; }
	void set_quantity(int q) { quantity = q; }
	void set_sale_number(int s) { sale_number = s; }
	int code;
	void add_item()
	{
		cout << "enter name of item : ";
		std::cin >> std::ws;
		getline(cin, name);
		cout << "enter price of " << name << " : ";
		cin >> price;
		cout << "enter Production Date of " << name << " : ";
		std::cin >> std::ws;
		getline(cin, date);
		cout << "enter validity period of " << name << " : ";
		std::cin >> std::ws;
		getline(cin, validity);
		cout << "enter Quantity of " << name << " : ";
		cin >> quantity;
		code = item_code;
		item_code++;
		cout << "code : " << code << endl;
	}
	void show()
	{
		cout << "name            : " << name << endl;
		cout << "price           : " << price << endl;
		cout << "quantity        : " << quantity << endl;
		cout << "Production Date : " << date << endl;
		cout << "validity period : " << validity << endl;
		cout << "sale number     : " << sale_number << endl;
		cout << "profits         : " << profits() << endl;
	}
	float  sale()
	{
		if (quantity > 0) {
			int n;
			cout << "enter the Quantity : ";
			cin >> n;
			if (n > 0) {
				cout << " " << n << " | " << name << " | " << price << " | " << n * price << endl;
				quantity--;
				sale_number++;
				return n * price;
			}
			else return 0;
		}
		else
			cout << "Quantity is out :(" << endl;
		cout << endl;
		return 0;
	}
	void add_more()
	{
		int Add = 0;
		cout << "What is the quantity to be added? " << endl << " : ";
		cin >> Add;
		quantity += Add;
		cout << "An amount has been added : " << Add << endl;
		cout << "The quantity now of " << name << " is: " << quantity << endl;
		cout << endl;
	}
	void modify()
	{
		int n = 0;
		cout << "---------------------------------------" << endl;
		cout << "to   change      the     name, press 1" << endl;
		cout << "to change the Production Date, press 2" << endl;
		cout << "to change the validity period, press 3" << endl;
		cout << "to   change      the    price, press 4" << endl;
		cout << "to   change      the quantity, press 5" << endl;
		cout << "to   change   the sale number, press 6" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << "---------------------------------------" << endl;
		switch (n)
		{
		case 1:
			cout << "enter new name of item : ";
			std::cin >> std::ws;
			getline(cin, name);
			break;
		case 2:
			cout << "enter Production Date of " << name << " : ";
			std::cin >> std::ws;
			getline(cin, date);
		case 3:
			cout << "enter validity period of " << name << " : ";
			std::cin >> std::ws;
			getline(cin, validity);
			break;
		case 4:
			cout << "enter price of " << name << " : ";
			cin >> price;
			break;
		case 5:
			cout << "enter Quantity of " << name << " : ";
			cin >> quantity;
			break;
		case 6:
			cout << "enter the sale number of " << name << " : ";
			cin >> sale_number;
			break;
		default:
			cout << "not found in the options,try again" << endl;
			modify();
			break;
		}
		cout << "---------------------------------------" << endl;
		cout << "Do you want to modify something alse ?" << endl;
		string s;
		cout << "if you want, enter yes" << endl;
		cout << "if not Press any key" << endl;
		cin >> s;
		if (s == "yes")
			modify();

		cout << endl;
	}
	float profits() { return price * sale_number; }
};
class offer
{
private:
	string name;
	float price;
	string components;
	int sale_number = 0;
public:
	int code;
	void add_offer()
	{
		cout << "offer name : ";
		std::cin >> std::ws;
		getline(cin, name);
		cout << "offer price : ";
		cin >> price;
		cout << "offer conetnt : ";
		std::cin >> std::ws;
		getline(cin, components);
		code = offers_number;
		offers_number++;
		cout << "code : " << code << endl;
	}
	string get_name() { return name; }
	string get_components() { return components; }
	int get_sale_number() { return sale_number; }
	float get_price() { return price; }
	void set_name(string n) { name = n; }
	void set_price(int p) { price = p; }
	void set_sale_number(int s) { sale_number = s; }
	void set_components(string c) { components = c; }
	float  sale()
	{
		int n;
		cout << "enter the Quantity : ";
		cin >> n;
		if (n > 0) {
			cout << " " << n << " | " << name << " | " << price << " | " << n * price << endl;
			sale_number++;
			return n * price;
		}
		else return 0;
	}
	void show()
	{
		cout << "name        : " << name << endl;
		cout << "content     : " << components << endl;
		cout << "price       : " << price << endl;
		cout << "sale number : " << sale_number << endl;
		cout << "profits     : " << profits() << endl;
	}

	void modify()
	{
		int n = 0;
		cout << "---------------------------------------" << endl;
		cout << "to  change   the     name, press 1" << endl;
		cout << "to  change   the    price, press 2" << endl;
		cout << "to  change   the  content, press 3" << endl;
		cout << "to change the sale number, press 4" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter your choice: ";
		cin >> n;
		cout << "---------------------------------------" << endl;
		switch (n)
		{
		case 1:
			cout << "enter new name of movie : ";
			std::cin >> std::ws;
			getline(cin, name);
			break;
		case 2:
			cout << "enter price of offer : ";
			cin >> price;
			break;
		case 3:
			cout << "enter content of offer : ";
			std::cin >> std::ws;
			getline(cin, components);
			break;
		case 4:
			cout << "enter the sale number of " << name << " : ";
			cin >> sale_number;
			break;
		default:
			cout << "not found in the options,try again" << endl;
			modify();
			break;
		}
		cout << "---------------------------------------" << endl;
		cout << "Do you want to modify something alse ?" << endl;
		string s;
		cout << "if you want, enter yes" << endl;
		cout << "if not Press any key" << endl;
		cin >> s;
		if (s == "yes")
			modify();
		cout << endl;
	}
	float profits() { return price * sale_number; }
};
vector <employee> e(0);
vector <item> itemm(0);
vector <offer> offerr(0);
user CreateAccount();
user Login();
user DeleteAccount();

int main()
{




	string st1, st2, st3;
	int in1 = 0, in2 = 0;
	float fl1 = 0;
	bool b1 = 0;
	fstream employ("employee.txt");
	employ >> employee_number;
	e.resize(employee_number);
	for (int i = 0; i < employee_number; i++)
	{
		employ >> st1 >> st2 >> st3 >> in1 >> in2 >> fl1 >> b1 >> e[i].code;
		e[i].set_name(st1);
		e[i].set_id(st2);
		e[i].set_telephone_number(st3);
		e[i].set_days(in1);
		e[i].set_day_salary(in2);
		e[i].set_salary(fl1);
		e[i].set_enabled(b1);
	}
	employ.close();
	fstream Offer("offers.txt");
	Offer >> offers_number;
	offerr.resize(offers_number);
	for (int i = 0; i < offers_number; i++)
	{
		Offer >> st1 >> st2 >> in1 >> fl1 >> offerr[i].code;
		offerr[i].set_name(st1);
		offerr[i].set_components(st2);
		offerr[i].set_sale_number(in1);
		offerr[i].set_price(fl1);
	}
	Offer.close();

	fstream Item("items.txt");
	Item >> item_code;
	itemm.resize(item_code);
	for (int i = 0; i < item_code; i++) {

		Item >> st1 >> st2 >> st3 >> in1 >> in2 >> fl1 >> itemm[i].code;
		itemm[i].set_name(st1);
		itemm[i].set_date(st2);
		itemm[i].set_validity(st3);
		itemm[i].set_quantity(in1);
		itemm[i].set_sale_number(in2);
		itemm[i].set_price(fl1);
	}
	Item.close();
	welcome();

	employ.open("employee.txt");
	employ << employee_number << endl;
	for (int i = 0; i < e.size(); i++)
		employ << e[i].get_name() << " " << e[i].get_id() << " " << e[i].get_telephone_number() << " " << e[i].get_days() << " " << e[i].get_day_salary() << " " << e[i].get_salary() << " " << e[i].get_enabled() << " " << e[i].code << endl;
	employ.close();
	Offer.open("offers.txt");
	Offer << offers_number << endl;
	for (int i = 0; i < offerr.size(); i++)
		Offer << offerr[i].get_name() << " " << offerr[i].get_components() << " " << offerr[i].get_sale_number() << " " << offerr[i].get_price() << " " << offerr[i].code << endl;
	Offer.close();

	Item.open("items.txt");
	Item << item_code << endl;
	for (int i = 0; i < itemm.size(); i++)
		Item << itemm[i].get_name() << " " << itemm[i].get_date() << " " << itemm[i].get_validity() << " " << itemm[i].get_quantity() << " " << itemm[i].get_sale_number() << " " << itemm[i].get_price() << " " << itemm[i].code << endl;

	Item.close();
	system("cls");

}
void items_management()
{
	char s;
	int n = 0;
	bool t = 1;
	cout << endl;
	cout << "    items management" << endl;
	cout << "---------------------------------------" << endl;
	cout << " 1- add item" << endl;
	cout << " 2- delet item" << endl;
	cout << " 3- show data of item" << endl;
	cout << " 4- modify item" << endl;
	cout << " 5- add an extra quantity" << endl;
	cout << " 6- profits" << endl;
	cout << " 7- back" << endl;
	cout << "---------------------------------------" << endl;
	cout << "enter your choice: ";
	cin >> n;
	cout << "---------------------------------------" << endl;
	int ccc = 0;
	switch (n)
	{
	case 1:
		system("cls");
		cout << " add item" << endl;
		cout << "---------------------------------------" << endl;
		itemm.resize(item_code);
		itemm[item_code - 1].add_item();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();

		break;
	case 2:
		system("cls");
		cout << " delet an item" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the item code : ";
		cin >> ccc;
		for (int i = 0; i < itemm.size(); i++)
		{
			if (itemm[i].code == ccc)
			{
				itemm.erase(itemm.begin() + i);
				cout << "deleted" << endl;
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();

		break;
	case 3:
		system("cls");
		cout << " show data of item" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the item code : ";
		cin >> ccc;
		for (int i = 0; i < itemm.size(); i++)
		{
			if (itemm[i].code == ccc)
			{
				itemm[i].show();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();
		break;
	case 4:
		system("cls");
		cout << "  modify data of item" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the item code : ";
		cin >> ccc;
		for (int i = 0; i < itemm.size(); i++)
		{
			if (itemm[i].code == ccc)
			{
				itemm[i].modify();
				itemm[i].show();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();
		break;
	case 5:
		system("cls");
		cout << "  add an extra quantity" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the item code : ";
		cin >> ccc;
		for (int i = 0; i < itemm.size(); i++)
		{
			if (itemm[i].code == ccc)
			{
				itemm[i].add_more();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();

		break;
	case 6:
		system("cls");
		cout << "  profits" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the item code : ";
		cin >> ccc;
		for (int i = 0; i < itemm.size(); i++)
		{
			if (itemm[i].code == ccc)
			{
				itemm[i].profits();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		items_management();
		break;
	case 7:
		system("cls");
		management();

		break;
	default:
		system("cls");
		cout << "not found in the options,try again" << endl;
		items_management();
		break;
	}

	cout << endl;
}
void staff_management()
{
	char s;
	int n = 0;
	bool t = true;
	cout << endl;
	cout << "    Staff management" << endl;
	cout << "---------------------------------------" << endl;
	cout << " 1- add an employee" << endl;
	cout << " 2- delet an employee" << endl;
	cout << " 3- show data of employee" << endl;
	cout << " 4- modify an employee" << endl;
	cout << " 5- add bonus" << endl;
	cout << " 6- deduction from salary" << endl;
	cout << " 7- back" << endl;
	cout << "---------------------------------------" << endl;
	cout << "enter your choice: ";
	cin >> n;
	cout << "---------------------------------------" << endl;
	int ccc = 0;
	switch (n)
	{
	case 1:
		system("cls");
		cout << " add an employee" << endl;
		cout << "---------------------------------------" << endl;
		e.resize(employee_number);
		e[employee_number - 1].add_employee();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 2:
		system("cls");
		cout << " delet an employee" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{

				e.erase(e.begin() + i);
				cout << "deleted" << endl;
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 3:
		system("cls");
		cout << " show data of employee" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{
				e[i].show();
				t = 0;
				break;
			}
		}
		if (t) cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 4:
		system("cls");
		cout << " modify an employee" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{
				e[i].modify();
				e[i].show();
				t = 0;
				break;
			}
		}
		if (t) cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 5:
		system("cls");
		cout << " add bonus" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{
				e[i].bonus_to_salary();
				t = 0;
				break;
			}
		}
		if (t) cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 6:
		system("cls");
		cout << " deduction from salary" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{
				e[i].deduction_form_salary();
				t = 0;
				break;
			}
		}
		if (t) cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;
	case 7:
		system("cls");
		management();

		break;
	default:
		system("cls");
		cout << "not found in the options,try again" << endl;
		staff_management();
		break;
	}

	cout << endl;
}
void offers_management()
{
	char s;
	int n = 0;
	bool t = 1;
	cout << endl;
	cout << "    Offers management" << endl;
	cout << "---------------------------------------" << endl;
	cout << " 1- add an offer" << endl;
	cout << " 2- delet an offer" << endl;
	cout << " 3- show data of offer" << endl;
	cout << " 4- modify an offer" << endl;
	cout << " 5- back" << endl;
	cout << "---------------------------------------" << endl;
	cout << "enter your choice: ";
	cin >> n;
	cout << "---------------------------------------" << endl;
	int ccc = 0;
	switch (n)
	{
	case 1:
		system("cls");
		cout << " add an offer" << endl;
		cout << "---------------------------------------" << endl;

		offerr.resize(offers_number);
		offerr[offers_number - 1].add_offer();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		offers_management();
		break;
	case 2:
		system("cls");
		cout << " delet an offer" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the offer code : ";
		cin >> ccc;
		for (int i = 0; i < offerr.size(); i++)
		{
			if (offerr[i].code == ccc)
			{
				offerr.erase(offerr.begin() + i);
				cout << "deleted" << endl;
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		offers_management();

		break;
	case 3:
		system("cls");
		cout << "  show data of offer" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the offer code : ";
		cin >> ccc;
		for (int i = 0; i < offerr.size(); i++)
		{
			if (offerr[i].code == ccc)
			{
				offerr[i].show();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		offers_management();
		break;
	case 4:
		system("cls");
		cout << "  modify an offer" << endl;
		cout << "---------------------------------------" << endl;
		cout << "enter the offer code : ";
		cin >> ccc;
		for (int i = 0; i < offerr.size(); i++)
		{
			if (offerr[i].code == ccc)
			{
				offerr[i].modify();
				offerr[i].show();
				t = 0;
				break;
			}
		}
		if (t)	cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		offers_management();

		break;
	case 5:
		system("cls");
		management();

		break;
	default:
		system("cls");
		cout << "not found in the options,try again" << endl;
		offers_management();
		break;
	}

	cout << endl;
}
void management()
{
	system("cls");
	char s;
	int n = 0;
	cout << endl;
	cout << "    management" << endl;
	cout << "---------------------------------------" << endl;
	cout << " 1- Cinema management" << endl;
	cout << " 2- Staff management" << endl;
	cout << " 3- Offers management" << endl;
	cout << " 4- items management" << endl;
	cout << " 5- back" << endl;
	cout << "---------------------------------------" << endl;
	cout << "enter your choice: ";
	cin >> n;
	cout << "---------------------------------------" << endl;
	switch (n)
	{
	case 1:
		system("cls");
		cenima_management();

		break;
	case 2:
		system("cls");
		staff_management();
		break;
	case 3:
		system("cls");
		offers_management();

		break;
	case 4:
		system("cls");
		items_management();

		break;
	case 5:
		system("cls");
		welcome();

		break;
	default:
		system("cls");
		cout << "not found in the options,try again" << endl;
		management();
		break;
	}

	cout << endl;
}
void sale_item()
{
	system("cls");
	char s;
	int ch = 1;
	float tot = 0;
	cout << "num |   name   | price \n";
	for (int i = 0; i < itemm.size(); i++)
		cout << " " << i + 1 << "  | " << itemm[i].get_name() << " | " << itemm[i].get_price() << endl;
	do {
		cout << " enter 0 to go back \n";
		cout << " enter your choose (number) : ";
		cin >> ch;
		if (ch != 0)
		{
			cout << " num | name | price | tot\n";
			tot += itemm[ch - 1].sale();
			cout << " another ?press any key \n enter 0 to exit \n";
			cin >> ch;
		}
	} while (ch != 0);
	cout << " total price :" << tot << endl;
	cout << " enter any key to back \n";
	cin >> s;
	total += tot;

}
void sale_offer()
{
	system("cls");
	char s;
	int ch = 1;
	float tot = 0;
	cout << "num |   name  |  components  | price \n";
	for (int i = 0; i < offerr.size(); i++)
		cout << " " << i + 1 << " | " << offerr[i].get_name() << " | " << offerr[i].get_components() << " | " << offerr[i].get_price() << endl;
	do {
		cout << " enter 0 to back \n";
		cout << " enter your choose (number) : ";
		cin >> ch;
		if (ch != 0)
		{
			cout << " num | name | price | tot\n";
			tot += offerr[ch - 1].sale();
			cout << " another ?press any key \n enter 0 to exit \n";
			cin >> ch;
		}
	} while (ch != 0);
	cout << " total price :" << tot << endl;
	cout << " enter any key to back \n";
	cin >> s;
	//view()
}
void cenima_management() {

	char s;
	int n = 0;
	bool t = true;
	cout << endl;
	cout << "    cenima management" << endl;
	cout << "---------------------------------------" << endl;
	cout << " 1- add an movie" << endl;
	cout << " 2- delet an movie" << endl;
	cout << " 3- show movies" << endl;
	cout << " 4- modify movie" << endl;
	cout << " 5- back" << endl;
	cout << "---------------------------------------" << endl;
	cout << "enter your choice: ";
	cin >> n;
	cout << "---------------------------------------" << endl;
	int ccc = 0;
	switch (n)
	{
	case 1:
		movie.AddMovie();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		cenima_management();
		break;
	case 2:
		movie.RemoveMovie();

		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		cenima_management();
		break;
	case 3:
		system("cls");
		movie.ViewMovies();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		cenima_management();
		break;
	case 4:
		system("cls");
		movie.EditMovie();
		cout << " enter any key to back \n";
		cin >> s;
		system("cls");
		staff_management();
		break;

	case 5:
		system("cls");
		management();

		break;
	default:
		system("cls");
		cout << "not found in the options,try again" << endl;
		cenima_management();
		break;
	}

	cout << endl;
}
user CreateAccount() {
	user a;
	a.create_account();
	return a;
}
user Login() {
	user a;
	char s;
	if (a.sign_in()) menu2();
	else {
		cout << " enter any key to back \n";
		cin >> s;
		welcome();
	}
	return a;
}
user DeleteAccount() {
	user a;
	a.delete_user();
	return a;
}
void other() {
	system("cls");
	string x;
	int choice;
	cout << "-----------------------------------------------\n";
	cout << "Please choose a number:\n";
	cout << "1. Delete my account\n" << "2. Back\n" << "3. Other..\n";
	cout << "-----------------------------------------------\n";
	cout << "choice:";
A: cin >> choice;
	switch (choice) {
	case 1: DeleteAccount(); break;
	case 2: welcome(); break;
	case 3: 	cout << "-----------------------------------------------\n";
		cout << "please enter password: ";
		cin >> x;
		if (x == "smartcenimastaff") workermanger();
		else other(); break;
	default:
		welcome();
		cout << "wrong input!!\n"; goto A; break;
	}
}
void guest() {
	system("cls");
	int choice;
	cout << "Please choose a number:\n";
	cout << "1. Continue as a guest\n" << "2. Create an account\n" << "3. back\n";
	cout << "-----------------------------------------------\n";
A: cin >> choice;
	switch (choice) {
	case 1: menu2(); break;
	case 2: CreateAccount(); break;
	case 3: welcome(); break;
	default: cout << "wrong input\n"; goto A;
	}
}
void welcome() {
	system("cls");
	int choice;
	cout << "\t\t\t\t*****************************************" << endl
		<< "\t\t\t\t||              Welcome  to            ||" << endl
		<< "\t\t\t\t||         Smart Cinema System!        ||" << endl
		<< "\t\t\t\t*****************************************" << endl;
	cout << "Would you like to log in or continue as a guest:\n";
	cout << "1. Guest.\n" << "2. Log in\n" << "3. Other..\n";
	cout << "-----------------------------------------------\n";
	cout << "choice:";
A: cin >> choice;
	switch (choice) {
	case 1: guest(); break;
	case 2: Login();  break;
	case 3: other(); break;// alpass
	default: cout << "wrong input\n"; goto A;
	}
}
void menu2() {

	system("cls");
	int choice;
	cout << "-----------------------------------------------\n";
	cout << "Would you like to go to the cinema or go to the cafeteria first?\n";
	cout << "1. Go to the Cinema\n" << "2. Go to the cafeteria\n" << "3. Offers!!\n" << "4. Back\n";
	cout << "-----------------------------------------------\n";
A:cin >> choice;
	switch (choice) {
	case 1: movie.ChooseMovie();
		movie.MovieTime();
		movie.ChooseSeat();
		movie.Ticket();
		break;
	case 2: sale_item(); break;
	case 3: sale_offer(); break;
	case 4: welcome(); break;
	default: cout << "wrong input!!\n"; goto A; break;
	}
	exit();
}
void workermanger() {
	system("cls");
	bool t = true;
	int c;
	char s;
	string x;
	int ccc;
	cout << "-----------------------------------------------\n";
	cout << "1-Worker\n";
	cout << "2-Manager\n";
	cout << "3-Back\n";
	cout << "4-Save\n";
	cout << "-----------------------------------------------\n";
	cout << "choice: ";
	cin >> c;
	switch (c) {

	case 1:
		cout << "enter the employee code : ";
		cin >> ccc;
		for (int i = 0; i < e.size(); i++)
		{
			if (e[i].code == ccc)
			{
				e[i].attending();

				t = 0;
				break;
			}
		}
		if (t) cout << "not found " << endl;
		cout << " enter any key to back \n";
		cin >> s;
		workermanger();
		break;
	case 2:
		cout << "-----------------------------------------------\n";
		cout << "pass :";
		cin >> x;
		cout << "-----------------------------------------------\n";

		if (x == "manager")
			management();
		else workermanger();
		break;
	case 3: other(); break;
	case 4:break;
	default: workermanger();
	}
}
void exit() {
	char choice;
	cout << "\n-----------------------------------------------\n";
	cout << "to add another purchase enter 1,for your total enter any key\n";
	cin >> choice;
	if (choice == '1') { menu2(); }
	else {
		system("cls");
		cout << "-----------------------------------------------\n";
		cout << " your total is:" << total;
		cout << "\n-----------------------------------------------\n";
		cout << " THANK YOU FOR VISITING\n";
		cout << "-----------------------------------------------\n";
	}
	cout << "To sign out press any key ";
	cin >> choice;
	total = 0;
	welcome();
}


