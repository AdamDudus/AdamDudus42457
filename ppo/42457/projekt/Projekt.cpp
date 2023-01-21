// Rados?aw Czapli?ski, Adam Dudu?, Marceli Filosek

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int x = 1;
long long int y = 1;

class Name {
	private:
		string name;
		string LastName;
	public:
		void getName() {
			cout << name << " " << LastName;
		}	
		void putName() {
			cin >> name >> LastName;
		}
	string nameVal() {
        return name, LastName;
    }
		
};

class Date {
	private:
		int day;
   	    int month;
 		int year;
 	public:
	 	void getDate() {
			 cout << day << ":" << month << ":" << year;
		 }	
		void putDate() {
			cin >> day >> month >> year;
		} 
		void setDate(int d, int m, int y) {
			day = d;
			month = m;
			year = y;
		}
};

class Room {
	protected:
		int bedsnumber;
		int roomnumber;
	public:
		string roomtype;
		float rent;
		int status;
		
		Room() {}
		
		Room(string roomtype, int bedsnumber, float rent, int roomnumber, int status) {
			this->roomtype = roomtype;
			this->bedsnumber = bedsnumber;
			this->rent = rent;
			this->roomnumber = roomnumber;
			this->status = status;
		}	
		
		int getRoomnumber() {
			return roomnumber;
		}
		void setRoom() {
			status = 1;
		}
		void vacateroom() {
        	status = 0;
    }
		
		void display_details(Room) {
			cout << "\nNumer pokoju : " << roomnumber;
	        cout << "\nTyp pokoju : " << roomtype;
	        cout << "\nLiczba lozek : " << bedsnumber;
	        cout << "\nCena : " << rent;
	        cout << "\nStatus : ";
	        if (status == 0) cout << "Wolny";
	        else cout << "Zajety";
		}		
};

class Person {
	protected:
	    Name person_name;
	    string person_addr;
	    long long int person_phone;
	    string person_mail;
	    Date person_dob;
	public:
    
	Person() {}

    Person(Name person_name, string person_addr, long int person_phone, string person_mail, Date person_dob) {
        this->person_name = person_name;
        this->person_addr = person_addr;
        this->person_mail = person_mail;
        this->person_phone = person_phone;
        this->person_dob = person_dob;
    }
    
    void setPerson() {
		cout << "\nImie i nazwisko : ";
        person_name.putName();
        cout << "\nData urodzenia : (dd mm yyyy) ";
        person_dob.putDate();
        cout << "\nNumer telefony : ";
        cin >> person_phone;
        cout << "\nAdres email : ";
        cin >> person_mail;
        cout << "\nAdres : ";
        cin >> person_addr;
	}
	
	long long int getPhone() {
        return person_phone;
    }
    Name getName() {
        return person_name;
    }
    
    string getMail() {
        return person_mail;
    }
	
    
    virtual void print_person() =0;
};		

class Customer : public Person {
	protected:
		string customer_id;
		string check_in_time;
	public:
		int status;
		
		Customer() {}
		
		void setData() {
			setPerson();
			cout << "\nPodaj godzine zameldowania: ";
			cin >> check_in_time;
			cout << "\n\nDostêpne pokoje: \n";
			status = 1;
			customer_id = to_string(x);
			x++;
		}	
		
		string getCustomer_id(){
			return customer_id;
		}
		
		virtual void checkOut() {}
};

class RoomCustomer : public Customer {
	protected:
		float room_bill;
		int book_status;
		Room room;
		int days_number;
	public:
		vector<pair<string, float>> services_used;
		
		void viewTotalBill() {
			float total = 0;
			cout << "\nDrukowanie paragonu dla klienta: \n";
			services_used.push_back(make_pair("Wynajêcie pokoju", days_number * room.rent));
			for(int i = 0; i < services_used.size(); i++) {
				cout << i + 1 << ":" << services_used[i].first << "----->" << services_used[i].second << "\n";
				total += services_used[i].second;
			}
			room_bill = total;
			cout << "Calkowity rachunek wynosi: " << total;
			cout << "\n\n\n Dziekujemy!\n\n";
			cout << "Zapraszamy ponownie!\n";
		}	
		
		void allocate_room(map<string, vector<int> > &vacant_room, map<string, vector<int> > &occupied_rooms, vector<Room> rooms) {
	        for (auto pow:vacant_room) {
	            cout << pow.first << " " << pow.second.size() << "\n";
	        }
	        string s;
	        cout << "\nPodaj typ pokoju : ";
	        cin>>s;
	        if (vacant_room[s].size() == 0) {
	            cout << "\nPodaj prawidlowa nazwe";
	            return;
	        }
	        int roomnumber = vacant_room[s][vacant_room[s].size() - 1];
	        roomnumber = vacant_room[s].back();
	        vacant_room[s].pop_back();
	        occupied_rooms[s].push_back(roomnumber);
	        room = rooms[roomnumber];
	        room.status = 1;
	        book_status = 1;
	        room_bill = 0;
	        days_number = 0;
	        cout << "\nTwoje id to :" << customer_id;
    }
    
        Room getRoom() {
			return room;
		}
    
      	void checkOut() {
       		if (book_status == 0) {
       	    	cout << "Nieaktywny";
       	    	return;
        	}else
       		cout << "\nWpisz liczbê dni pobytu: ";
        	cin >> days_number;
        	viewTotalBill();
        	room.status = 0;
        	book_status = 0;
    	}	
		
		virtual void print_person() {
	        cout << "\nImie i nazwisko : ";
	        person_name.getName();
	        cout << "\nData : ";
	        person_dob.getDate();
	        cout << "\nNumer telefonu : " << person_phone;
	        cout << "\nAdres email : " << person_mail;
	        cout << "\nAdres : " << person_addr;
	        cout << "\nID klienta : " << customer_id;
	        cout << "\nGodzina zameldowania : " << check_in_time;
	        cout << "\nAktualny status : ";
	        if (status == 0) cout << "Nieaktywny";
	        else cout << "Aktywny";
	        cout << "\nIle dni noclegowych : " << days_number;
	        cout << "\nCalkowity rachunek : " << room_bill;
	        room.display_details(room);
    	}
			
};

class Employee : public Person {
protected:
    long long int emp_id;
    string role;

public:
    Employee() {}

    Employee(Name name, string addr, long long int ph, string mail, Date d, long long int emp_id, string role) : Person(name, addr, ph, mail, d) {
        this->emp_id = emp_id;
        this->role = role;
    }

    void put_person() {}

    virtual void print_person() {
        cout << "\nId Pracownika : " << emp_id;
        cout << "\nPosada : " << role;
        cout << "\nImiê i Nazwisko : ";
        person_name.getName();
        cout << "\nData urodzenia : ";
        person_dob.getDate();
        cout << "\nNr telefonu : " << person_phone;
        cout << "\nAdres email : " << person_mail;
        cout << "\nAdres : " << person_addr;
    }
    
    long long int get_emp_id() {
        return emp_id;
    }
};


class Hotel {
	protected:
		string hotel_name;
		string hotel_address;
		vector<Room> rooms;
		map<string, vector<int>> vacantroom;
    	map<string, vector<int>> occupied_rooms;
    	vector<RoomCustomer> all_room_customers;
    	vector<RoomCustomer> all_room_customers_inactive;
    public:
		Hotel() {}
		
		void GenerateId() {}
		int i = 0;
		void setHotel(){
			hotel_name = "Collegium Hotel";
			hotel_address = "Legnica, Sejmowa, 5A, 59-220 Legnica";
			for (; i < 30; i++) {
	            Room r("Pojedynczy", 1, 1200, i, 0);
	            rooms.push_back(r);
	            vacantroom["Pojedynczy"].push_back(i);
	            
	        }
	        for (; i < 60; i++) {
	            Room r("Podwojny", 2, 1900, i, 0);
	            rooms.push_back(r);
	            vacantroom["Podwojny"].push_back(i);

	        }
	        for (; i < 90; i++) {
	            Room r("Potrojny", 3, 2700, i, 0);
	            rooms.push_back(r);
	            vacantroom["Potrojny"].push_back(i);

	        }
	        for (; i < 120; i++) {
	            Room r("Premium", 1, 3750, i, 0);
	            rooms.push_back(r);
	            vacantroom["Premium"].push_back(i);
	            
	        }
	    }
			
		void getRoom() {
			cout << "\nPodaj dane osoby : ";
			RoomCustomer tmp;
			tmp.setData();
			tmp.allocate_room(vacantroom, occupied_rooms, rooms);
			all_room_customers.push_back(tmp);
		}
			
		void roomCustomerCheckOut() {
        	cout << "Podaj nr id klienta : ";
        	string id;
        	Room temp;
        	cin >> id;
        	for (auto pow : all_room_customers) {
            	if (id == pow.getCustomer_id()) {
                	pow.checkOut();
                	temp = pow.getRoom();
                	break;
            	}
        	}	
        vacantroom[temp.roomtype].push_back(temp.getRoomnumber());
        auto pow1 = occupied_rooms[temp.roomtype].begin();
        auto pow2 = occupied_rooms[temp.roomtype].end();
        occupied_rooms[temp.roomtype].erase(find(pow1, pow2, temp.getRoomnumber()));
		}
		
        void vacateRoom(){
			roomCustomerCheckOut();
		}
		
		void add_employee() {
        	cout << "\nWpisz informacje o pracowniku : ";
        	Name name;
       		string addr;
        	long long int ph;
        	string mail;
        	long long int emp_id;
       	 	Date dob;
        	string role;
        	cout << "\nImiê i Nazwisko : ";
        	name.putName();
        	cout << "Adres : ";
        	cin>>addr;
        	cout << "Nr telefonu : ";
        	cin >> ph;
        	cout << "Adres Email : ";
        	cin>>mail;
        	emp_id = y++;
        	cout << "Data urodzenia : ";
        	dob.putDate();
        	cout << "\n---------------------------------------------------------------------------------------------";
       		cout << "\nDodano pracownika";
       	}
		
    
		bool display_menu_admin() {
        	cout << "\n\n";
       		cout << "\n1. ZnajdŸ klienta";
       		cout << "\n2. Dodaj Pracownika";
        	cout << "\nInna liczba spowoduje wyjœcie z menu";
        	cout << "\nWybór: ";
        	int choice;
        	cin >> choice;
			if (choice == 1) {
            	get_customer_data();
            	return true;
        	}
        	if (choice == 2) {
            add_employee();
            return true;
        }
			else return false;
		}
		
		bool display_menu() {
        	cout << "\n";
       		cout << "\n1. Zamelduj siê";
       		cout << "\n2. Wymelduj siê";
        	cout << "\nInna liczba spowoduje wyjœcie z menu";
        	cout << "\nWybór: ";
        	int choice;
        	cin >> choice;
        	if (choice == 1) {
            	getRoom();
            	return true;
        	}
        	else if (choice == 2) {
            	roomCustomerCheckOut();
            	return true;
        	}
      		else return false;
		}
		
		
		void get_customer_data() {
        cout << "\nWyszukaj klienta wedlug : ";
        cout << "\n1. id klienta";
        cout << "\n2. numer telefonu";
        cout << "\n3. adres email";
        cout << "\n4. imie i nazwisko \n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string id;
            cout << "\npodaj numer id : ";
            cin >> id;
            int flag = 0;
            for (auto pow : all_room_customers) {
                if (pow.getCustomer_id() == id) {
                    cout << "\nZnaleziono";
                    pow.print_person();
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) cout << "\nBrak klienta o takim numerze";
        } else if (choice == 2) {
            long long int ph;
            cout << "\nWpisz numer telefonu : ";
            cin >> ph;
            int flag = 0;
            for (auto pow:all_room_customers) {
                if (pow.getPhone() == ph) {
                    if (!flag)
                        cout << "\nZnaleziono";
                    pow.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nBrak klienta o takim numerze";
        } else if (choice == 3) {
            string m;
            cout << "\nPodaj email do wyszukania : ";
            cin >> m;
            int flag = 0;
            for (auto pow:all_room_customers) {
                if (pow.getMail() == m) {
                    if (!flag)
                        cout << "\nZnaleziono";
                    pow.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nNie znaleziono klienta o takim emailu";
        } else {
            string n;
            cout << "\nWpisz imie i nazwisko : ";
            cin >> n;
            int flag = 0;
            for (auto pow:all_room_customers) {
                if (pow.getName().nameVal() == n) {
                    if (!flag)
                        cout << "\nZnaleziono";
                    pow.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nNie znaleziono klienta o takim imieniu i nazwisku";
        }
    }

};

class invalid_password{};

void Codepage()
{
	system("chcp 65001");
	system("cls");
}


int main()
{
    Hotel H;      
	H.setHotel();
	
	Codepage();
	
    while (1) {
        int choice = 0;
        cout << "\n-----------------------------------------------------------------\n";
        cout << "\n--------------------------Hotel Menu-----------------------------\n";
        cout << "\n1.Wynajem pokoju";
        cout << "\n2.Logowanie do panelu";

        cout << "\nWybór: ";
        cin >> choice;
        if (choice == 1)
        {
        	H.display_menu();
		}
        if (choice == 2) {
            cout << "\nHas³o: ";
            string s;
            cin >> s;
            try {
                if (s == "password") {
                    while (H.display_menu_admin()) {}
                } else throw invalid_password();
            }
            catch (invalid_password a) {
                cout << "\nZ³e Has³o";
            }
        } 
    }
    return 0;
}
