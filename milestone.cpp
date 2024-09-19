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

public:
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50) : Participant(name, energyLevel)
    {
        this->knowledgeLevel = knowledgeLevel;
    }

    void study(int hours)
    {
        this->knowledgeLevel += hours * 2;
        this->energyLevel -= hours * 2;
        cout << this->name << " is studying for " << hours << " hours. Knowledge level is now " << this->knowledgeLevel << " and energy level is " << this->energyLevel << "." << endl;
    }
};

// Derived class - Teacher
class Teacher : public Participant
{
private:
    string subject;

public:
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown") : Participant(name, energyLevel)
    {
        this->subject = subject;
    }

    void teach()
    {
        this->energyLevel -= 10;
        cout << this->name << " is teaching " << this->subject << ". Energy level is now " << this->energyLevel << "." << endl;
    }
};

int main()
{
    // Creating an array of Student objects
    Student students[3] = {
        Student("Alice", 100, 50),
        Student("Bob", 100, 60),
        Student("Carol", 90, 70)};

    // Creating an array of Teacher objects
    Teacher teachers[2] = {
        Teacher("Mr. Johnson", 80, "Mathematics"),
        Teacher("Ms. Smith", 85, "English")};

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

    return 0;
}
