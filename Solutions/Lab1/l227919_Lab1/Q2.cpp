#include<iostream>
using namespace std;

class Student {
	string name;
	int studentid;
public:
	Student(string name, int studentId) :name(name), studentid(studentId){}

	string getName() const {
		return name;
	}

	int getStudentId() const {
		return studentid;
	}
};

class Course {
	string courseName;
	Student** students;
	int counter;

public:
	Course(string courseName): courseName(courseName),counter(0), students(nullptr) {}

	void addStudent(Student* student) {
		counter++;
		Student** newStudents = new Student * [counter];
		for (int i = 0; i < counter - 1; i++) {
			newStudents[i] = students[i];
		}
		newStudents[counter - 1] = student;
		delete[] students;
		students = newStudents;
	}

	void displayStudents() const {
		cout << "Students enrolled in " << courseName << "are:" << endl;

		for (int i = 0; i < counter; i++) {
			cout << "Name: " << students[i]->getName() << ", Student ID: " << students[i]->getStudentId() << endl;
		}
	}
};

int main()

{
	Student student1("John Smith", 12345);
	Student student2("Jane Doe", 54321);
	Course mathCourse("Mathematics");
	mathCourse.addStudent(&student1);
	mathCourse.addStudent(&student2);
	mathCourse.displayStudents();
	return 0;
}

