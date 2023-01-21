#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define STUDENTS_COUNT 10

const vector<string> NAMES = {"Adam", "Ewa", "Jan", "Katarzyna", "Marek", "Agata", "Piotr", "Anna", "Tomasz", "Joanna"};
const vector<string> SURNAME = {"Nowak", "Kowalski", "Wisniewski", "Dabrowski", "Lewandowski", "W?jcik", "Kaminski", "Kowalczyk", "Zielinski", "Szymanski"};

class Student {
public:
string studentNo;
string name;
string surname;
bool isActive;

void setStudentNo(string studentNo) {
this->studentNo = studentNo;
}

void setName(string name) {
this->name = name;
}

void setSurname(string surname) {
this->surname = surname;
}

void setIsActive(bool isActive) {
this->isActive = isActive;
}

string getStudentNo() {
return this->studentNo;
}

string getName() {
return this->name;
}

string getSurname() {
return this->surname;
}

bool getIsActive() {
return this->isActive;
}
};

string getRandomStudentNumber() {
ostringstream ss;
int randomNumber = rand() % 2000 + 37000;

ss << randomNumber;

return ss.str();
}

string getRandomName() {
return NAMES[rand() % NAMES.size()];
}

string getRandomSurname() {
return SURNAME[rand() % SURNAME.size()];
}

bool getRandomStatus() {
return rand() % 2;
}

int main() {
vector<Student> students;

for (int i = 0; i < STUDENTS_COUNT; i++) {
Student student;
student.setStudentNo(getRandomStudentNumber());
student.setName(getRandomName());
student.setSurname(getRandomSurname());
student.setIsActive(getRandomStatus());
students.push_back(student);
}

cout << "Students group have been filled." << endl << endl;

cout << "List of active students:" << endl;
for (int i = 0; i < students.size(); i++) {
Student student = students.at(i);
if (student.getIsActive()) {
cout << student.getStudentNo() << " " << student.getName() << " " << student.getSurname() << endl;
}
}

return 0;
}
