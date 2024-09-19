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
    Participant(string n, int e) : name(n), energyLevel(e) {}

    void rest()
    {
        energyLevel += 10;
        cout << name << " is resting. Energy level is now " << energyLevel << "." << endl;
    }

    string getName()
    {
        return name;
    }
};

// Derived class - Student
class Student : public Participant
{
private:
    int knowledgeLevel;

public:
    Student(string n, int e, int k) : Participant(n, e), knowledgeLevel(k) {}

    void study()
    {
        knowledgeLevel += 5;
        energyLevel -= 5;
        cout << name << " is studying. Knowledge level is now " << knowledgeLevel << " and energy level is " << energyLevel << "." << endl;
    }

    void attendClass()
    {
        cout << name << " is attending class." << endl;
    }
};

// Derived class - Teacher
class Teacher : public Participant
{
private:
    string subject;

public:
    Teacher(string n, int e, string s) : Participant(n, e), subject(s) {}

    void teach()
    {
        energyLevel -= 10;
        cout << name << " is teaching " << subject << ". Energy level is now " << energyLevel << "." << endl;
    }

    void evaluateStudents()
    {
        cout << name << " is evaluating students." << endl;
    }
};

int main()
{
    // Creating objects of Student and Teacher
    Student alice("Alice", 100, 50);
    Teacher mrJohnson("Mr. Johnson", 80, "Mathematics");

    // Calling methods on objects
    alice.attendClass();
    alice.study(); //use of abstraction
    // The user doesn't need to know how knowledge or energy is being manipulated.
    alice.rest(); //use of polymorphism
//allows methods to have the same name but behave differently depending on the class in which they are defined. In this case, polymorphism is evident in the different names
    mrJohnson.teach();
    mrJohnson.evaluateStudents();
    mrJohnson.rest();

    return 0;
}
