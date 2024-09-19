#include <iostream>
#include <string>
using namespace std;

// Base class
class Participant {
protected:
    string name;
    int energyLevel;

public:
    Participant(string name = "Unnamed", int energyLevel = 100) {
        this->name = name;
        this->energyLevel = energyLevel;
    }

    void rest() {
        energyLevel += 10;
        cout << name << " is resting. Energy level is now " << energyLevel << "." << endl;
    }

    string getName() const {
        return name;
    }
};

// Derived class - Student
class Student : public Participant {
private:
    int knowledgeLevel;

public:
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50)
        : Participant(name, energyLevel) {
        this->knowledgeLevel = knowledgeLevel;
    }

    void study(int hours) {
        knowledgeLevel += hours * 2;
        energyLevel -= hours * 2;
        cout << name << " is studying for " << hours << " hours. Knowledge level is now " << knowledgeLevel << " and energy level is " << energyLevel << "." << endl;
    }
};

// Main function
int main() {
    // Creating an array of Student objects
    Student students[3] = {
        Student("Alice", 100, 50),
        Student("Bob", 90, 40),
        Student("Carol", 80, 60)
    };

    // Interacting with the students
    for (int i = 0; i < 3; i++) {
        students[i].study(2);
        students[i].rest();
    }

    return 0;
}
