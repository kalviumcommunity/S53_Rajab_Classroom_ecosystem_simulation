#include <iostream>
#include <string>
using namespace std;

// Base class
class Participant
{
protected:
    string name;
    int energyLevel;

public:
    Participant(string name = "Unnamed", int energyLevel = 100)
    {
        this->name = name;
        this->energyLevel = energyLevel;
    }

    void rest()
    {
        this->energyLevel += 10;
        cout << this->name << " is resting. Energy level is now " << this->energyLevel << "." << endl;
    }

    string getName()
    {
        return this->name;
    }
};

// Derived class - Student
class Student : public Participant
{
private:
    int knowledgeLevel;

    // Static variable to track the number of students
    static int studentCount;

public:
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50) : Participant(name, energyLevel)
    {
        this->knowledgeLevel = knowledgeLevel;
        studentCount++;  // Increment the static variable when a new student is created
    }

    ~Student()
    {
        studentCount--;  // Decrement when a student is destroyed
    }

    void study(int hours)
    {
        this->knowledgeLevel += hours * 2;
        this->energyLevel -= hours * 2;
        cout << this->name << " is studying for " << hours << " hours. Knowledge level is now " << this->knowledgeLevel << " and energy level is " << this->energyLevel << "." << endl;
    }

    // Static method to get the total number of students
    static int getStudentCount()
    {
        return studentCount;
    }

    // Static member function to display student information
    static void displayStudentCount()
    {
        cout << "There are currently " << studentCount << " students." << endl;
    }
};

// Initialize the static variable
int Student::studentCount = 0;

// Derived class - Teacher
class Teacher : public Participant
{
private:
    string subject;

    // Static variable to track the number of teachers
    static int teacherCount;

public:
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown") : Participant(name, energyLevel)
    {
        this->subject = subject;
        teacherCount++;  // Increment the static variable when a new teacher is created
    }

    ~Teacher()
    {
        teacherCount--;  // Decrement when a teacher is destroyed
    }

    void teach()
    {
        this->energyLevel -= 10;
        cout << this->name << " is teaching " << this->subject << ". Energy level is now " << this->energyLevel << "." << endl;
    }

    // Static method to get the total number of teachers
    static int getTeacherCount()
    {
        return teacherCount;
    }

    // Static member function to display teacher information
    static void displayTeacherCount()
    {
        cout << "There are currently " << teacherCount << " teachers." << endl;
    }
};

// Initialize the static variable
int Teacher::teacherCount = 0;

int main()
{
    // Dynamically creating an array of Student objects
    Student* students = new Student[3];
    students[0] = Student("Alice", 100, 50);
    students[1] = Student("Bob", 100, 60);
    students[2] = Student("Carol", 90, 70);

    // Dynamically creating an array of Teacher objects
    Teacher* teachers = new Teacher[2];
    teachers[0] = Teacher("Mr. Johnson", 80, "Mathematics");
    teachers[1] = Teacher("Ms. Smith", 85, "English");

    // Interacting with the students and teachers
    for (int i = 0; i < 3; i++)
    {
        students[i].study(2);
        students[i].rest();
    }

    for (int i = 0; i < 2; i++)
    {
        teachers[i].teach();
        teachers[i].rest();
    }

    // Display the total count of students and teachers using static member functions
    Student::displayStudentCount();
    Teacher::displayTeacherCount();

    // Deallocating dynamically allocated memory
    delete[] students;
    delete[] teachers;

    return 0;
}
