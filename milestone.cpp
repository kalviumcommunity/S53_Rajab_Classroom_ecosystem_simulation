#include <iostream>
#include <string>
using namespace std;

// Base class
class Participant {
protected:
    string name;
    int energyLevel;

public:
    Participant(string name, int energyLevel) {
        // Using 'this' to distinguish between the member variable and the constructor parameter
        this->name = name;
        this->energyLevel = energyLevel;
    }

    // Method to simulate resting
    Participant* rest() {
        this->energyLevel += 10; // Using 'this' to refer to the instance's energyLevel
        cout << this->name << " is resting. Energy level is now " << this->energyLevel << "." << endl;
        return this; // Returning 'this' to allow method chaining
    }

    string getName() {
        return this->name; // Using 'this' to return the object's name
    }
};

// Derived class - Student
class Student : public Participant {
private:
    int knowledgeLevel;

public:
    Student(string name, int energyLevel, int knowledgeLevel) : Participant(name, energyLevel) {
        // Using 'this' to distinguish between the member variable and the constructor parameter
        this->knowledgeLevel = knowledgeLevel;
    }

    void study(int hours) {
        this->knowledgeLevel += hours * 2; // Using 'this' to modify the object's knowledgeLevel
        this->energyLevel -= hours * 2;
        cout << this->name << " is studying for " << hours << " hours. Knowledge level is now " << this->knowledgeLevel << " and energy level is " << this->energyLevel << "." << endl;
    }
};

// Derived class - Teacher
class Teacher : public Participant {
private:
    string subject;

public:
    Teacher(string name, int energyLevel, string subject) : Participant(name, energyLevel) {
        this->subject = subject; // Using 'this' to distinguish between the member variable and the constructor parameter
    }

    void teach() {
        this->energyLevel -= 10;
        cout << this->name << " is teaching " << this->subject << ". Energy level is now " << this->energyLevel << "." << endl;
    }
};

int main() {
    // Creating objects of Student and Teacher
    Student alice("Alice", 100, 50);
    Teacher mrJohnson("Mr. Johnson", 80, "Mathematics");

    // Calling methods on objects
    alice.study(3);
    alice.rest()->rest(); // Method chaining using 'this' pointer

    mrJohnson.teach();
    mrJohnson.rest();

    return 0;
}
