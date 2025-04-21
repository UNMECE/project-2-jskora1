#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Student {

protected:
	string first, last, GradSemester, EnrollSemester;
	double GPA;
	int GradYear;
	int EnrollYear;
	

public: 
	Student(string first, string last) : first(first), last(last), GPA(),
	GradYear(2029), EnrollYear(2025), GradSemester("Spring"),
	EnrollSemester("Fall") {}

void setGPA(double grade_point_avg) { GPA = grade_point_avg; }
void setGradYear (int year) { GradYear = year; } 
void setEnrollYear (int year) { EnrollYear = year; }
void setGradSemester(string semester) { GradSemester = semester; }
void setEnrollSemester(string semester) { EnrollSemester = semester; }

virtual void print() { print(cout); } 

virtual void print(ostream& out) { 
	out << "Student: " << first << " " << last << endl
		<< "GPA: " << GPA << endl
		<< "Enrollment Semester: " << EnrollSemester << endl
		<< "Enrollment Year: " << EnrollYear << endl
		<< "Graduation Semester: " << GradSemester << endl	
		<< "Graduation Year: " << GradYear << endl;		
 }

virtual ~Student() {
}
};

class Art_Student : public Student {

protected: 
	string emphasis;

public:
	Art_Student(string first, string last, string emphasis) :
	Student(first, last), emphasis(emphasis) {}

void setEmphasis(string emphasis) { this->emphasis = emphasis; }
string getEmphasis() { return emphasis; } 

void print () { print(cout); } 
void print (ostream& out)  { 
	Student::print(out);
	out << "Art Emphasis: " << emphasis << endl << endl;
}

};

class Physics_Student : public Student {

protected:
	string concentration;

public:
	Physics_Student(string first, string last, string concentration) : 
	Student(first, last), concentration(concentration) {}

void setConcentration (string concentration) {this->concentration = concentration;  }

string getConcentration () { return concentration; } 

void print () { print(cout); }
void print (ostream& out)  { 
	Student::print(out);
	out << "Physics Concentration: " << concentration << endl << endl;
}

};

int main() {
  vector<Art_Student *> art_students;
	cout << "\n Art Students" << endl;

  art_students.push_back(new Art_Student ("Alex", "Johnson", "Modern Art"));
		art_students[0]->setGPA(2.5);
		art_students[0]->setEnrollSemester("Fall");
		art_students[0]->setEnrollYear(2020);
		art_students[0]->setGradSemester("Spring");
		art_students[0]->setGradYear(2025);
  art_students.push_back(new Art_Student ("Taylor", "Barnes", "Western Art"));
		art_students[1]->setGPA(3.3);
		art_students[1]->setEnrollYear(2023);
		art_students[1]->setGradSemester("Spring");
		art_students[1]->setGradYear(2027);
		art_students[1]->setEnrollSemester("Spring");
	art_students.push_back(new Art_Student ("Future", "Student", "TBD"));


for (int i = 0; i < art_students.size(); i++) { 
	art_students[i]->print();
}


  vector<Physics_Student *> physics_students;
		cout << "\n Physics Students" << endl;	

physics_students.push_back(new Physics_Student("Erin", "Hanks", "BioPhysics"));
		physics_students[0]->setGPA(3.7);
		physics_students[0]->setEnrollSemester("Spring");
		physics_students[0]->setEnrollYear(2024);
		physics_students[0]->setGradYear(2028);
		physics_students[0]->setGradSemester("Fall");

physics_students.push_back(new Physics_Student("Riley", "Stone", "AstroPhysics"));
		physics_students[1]->setGPA(1.7);
		physics_students[1]->setEnrollSemester("Fall");
		physics_students[1]->setGradSemester("Fall");
		physics_students[1]->setGradYear(2025);
		physics_students[1]->setEnrollYear(2021);

physics_students.push_back(new Physics_Student ("Future", "Student", "TBD"));

for (int i = 0; i < physics_students.size(); i++) { 
	physics_students[i]->print();
}


ofstream outfile("student_info.dat", std::ios::out);
for(int i = 0; i < art_students.size(); i++)  {
	outfile << "Art Students " << i + 1 << ":" << endl;
	art_students[i]->print(outfile);
}

for (int i = 0; i < physics_students.size(); i++) {
	outfile << "Physics Student " << i + 1 << ":" << endl;
	physics_students[i]->print(outfile);
}
outfile.close();

return 0;
}
