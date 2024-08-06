#include <iostream>
using namespace std;

class Course {
public:
    string courseName;
    int credits;
    double grade;

    Course() : courseName(""), credits(0), grade(0.0) {}
};

class Student {
public:
    string studentName;
    Course* courses;
    int numCourses;

    Student(string name, int numCourses) : studentName(name), numCourses(numCourses) {
        courses = new Course[numCourses];
    }

    ~Student() {
        delete[] courses;
    }

    void addCourse(int index, string name, int credits, double grade) {
        if (index >= 0 && index < numCourses) {
            courses[index].courseName = name;
            courses[index].credits = credits;
            courses[index].grade = grade;
        }
    }

    double calculateCGPA() {
        double totalGradePoints = 0.0;
        int totalCredits = 0;

        for (int i = 0; i < numCourses; ++i) {
            totalGradePoints += courses[i].grade * courses[i].credits;
            totalCredits += courses[i].credits;
        }

        if (totalCredits == 0) return 0.0; // Avoid division by zero

        return totalGradePoints / totalCredits;
    }

    void displayResults() {
        cout << "Student: " << studentName << endl;
        cout << "Course Grades: " << endl;

        for (int i = 0; i < numCourses; ++i) {
            cout << "Course: " << courses[i].courseName 
                 << ", Credits: " << courses[i].credits 
                 << ", Grade: " << courses[i].grade << endl;
        }

        cout << "CGPA: " << calculateCGPA() << endl;
    }
};

int main() {
    string studentName;
    cout << "Enter student name: ";
    getline(cin, studentName);

    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;
    cin.ignore(); // to clear the newline character from the input buffer

    Student student(studentName, numCourses);

    for (int i = 0; i < numCourses; ++i) {
        string courseName;
        int credits;
        double grade;

        cout << "Enter course name: ";
        getline(cin, courseName);
        cout << "Enter course credits: ";
        cin >> credits;
        cout << "Enter course grade: ";
        cin >> grade;
        cin.ignore(); // to clear the newline character from the input buffer

        student.addCourse(i, courseName, credits, grade);
    }

    student.displayResults();

    return 0;
}
