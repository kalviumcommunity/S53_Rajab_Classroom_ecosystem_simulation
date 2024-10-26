#include <iostream>
#include <string>
using namespace std;

// Base class
class Participant {
protected:
    string name;          
    int energyLevel;      

public:
    // Default Constructor
    Participant(string name = "Unnamed", int energyLevel = 100) : name(name), energyLevel(energyLevel) {
        cout << "Participant " << name << " created with energy level " << energyLevel << "." << endl;
    }

    // Copy Constructor
    Participant(const Participant& other) : name(other.name), energyLevel(other.energyLevel) {
        cout << "Copy of participant " << name << " created." << endl;
    }

    // Destructor
    virtual ~Participant() {
        cout << "Participant " << name << " destroyed." << endl;
    }

    void rest() {
        this->energyLevel += 10;
        cout << this->name << " is resting. Energy level is now " << this->energyLevel << "." << endl;
    }

    string getName() const {
        return name;
    }
    void setName(const string& newName) {
        name = newName;
    }

    int getEnergyLevel() const {
        return energyLevel;
    }
};

// Derived class - Student
class Student : public Participant {
private:
    int knowledgeLevel;

public:
    // Default Constructor
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50)
        : Participant(name, energyLevel), knowledgeLevel(knowledgeLevel) {
        cout << "Student " << name << " created with knowledge level " << knowledgeLevel << "." << endl;
    }

    // Destructor
    ~Student() override {
        cout << "Student " << name << " destroyed." << endl;
    }

    int getKnowledgeLevel() const {
        return knowledgeLevel;
    }
    void setKnowledgeLevel(int newKnowledgeLevel) {
        knowledgeLevel = newKnowledgeLevel;
    }

    void study(int hours) {
        knowledgeLevel += hours * 2;
        energyLevel -= hours * 2;
        cout << name << " is studying for " << hours << " hours. Knowledge level is now "
             << knowledgeLevel << " and energy level is " << energyLevel << "." << endl;
    }
};

// Derived class - Teacher
class Teacher : public Participant {
private:
    string subject;

public:
    // Default Constructor
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown")
        : Participant(name, energyLevel), subject(subject) {
        cout << "Teacher " << name << " created with subject " << subject << "." << endl;
    }

    // Destructor
    ~Teacher() override {
        cout << "Teacher " << name << " destroyed." << endl;
    }

    string getSubject() const {
        return subject;
    }
    void setSubject(const string& newSubject) {
        subject = newSubject;
    }

    void teach() {
        energyLevel -= 10;
        cout << name << " is teaching " << subject << ". Energy level is now " << energyLevel << "." << endl;
    }
};

int main() {
    Student* students = new Student[3]{
        Student("Alice", 100, 50),
        Student("Bob", 100, 60),
        Student("Carol", 90, 70)
    };

    Teacher* teachers = new Teacher[2]{
        Teacher("Mr. Johnson", 80, "Mathematics"),
        Teacher("Ms. Smith", 85, "English")
    };

    for (int i = 0; i < 3; i++) {
        students[i].study(2);
        students[i].rest();
    }

    for (int i = 0; i < 2; i++) {
        teachers[i].teach();
        teachers[i].rest();
    }
// Deallocation
    delete[] students;
    delete[] teachers;

    return 0;
}
