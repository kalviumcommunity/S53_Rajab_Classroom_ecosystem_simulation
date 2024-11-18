#include <iostream>
#include <string>
using namespace std;

// Base class - Participant
class Participant {
protected:
    string name;
    int energyLevel;

public:
    // Default Constructor
    Participant(string name = "Unnamed", int energyLevel = 100) 
        : name(name), energyLevel(energyLevel) {
        cout << "Participant " << name << " created with energy level " << energyLevel << "." << endl;
    }

    // Copy Constructor
    Participant(const Participant& other) 
        : name(other.name), energyLevel(other.energyLevel) {
        cout << "Copy of participant " << name << " created." << endl;
    }

    // Destructor
    virtual ~Participant() {
        cout << "Participant " << name << " destroyed." << endl;
    }

    virtual void performAction() const { // Virtual function for polymorphism
        cout << name << " is taking a generic action." << endl;
    }

    void rest() {
        energyLevel += 10;
        cout << name << " is resting. Energy level is now " << energyLevel << "." << endl;
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

// Derived class - Student (Single Inheritance with virtual base)
class Student : virtual public Participant {
private:
    int knowledgeLevel;

public:
    // Default Constructor
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50)
        : Participant(name, energyLevel), knowledgeLevel(knowledgeLevel) {
        cout << "Student " << name << " created with knowledge level " << knowledgeLevel << "." << endl;
    }

    // Destructor
    ~Student() {
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

    void performAction() const override { // Overriding virtual function
        cout << name << " is studying to improve knowledge." << endl;
    }
};

// Derived class - Teacher (Single Inheritance with virtual base)
class Teacher : virtual public Participant {
private:
    string subject;

public:
    // Default Constructor
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown")
        : Participant(name, energyLevel), subject(subject) {
        cout << "Teacher " << name << " created with subject " << subject << "." << endl;
    }

    // Destructor
    ~Teacher() {
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

    void performAction() const override { // Overriding virtual function
        cout << name << " is teaching the subject: " << subject << "." << endl;
    }
};

// Derived class - AssistantTeacher (Multiple Inheritance)
class AssistantTeacher : public Student, public Teacher {
public:
    AssistantTeacher(string name = "Unnamed", int energyLevel = 90, int knowledgeLevel = 60, string subject = "Assistant")
        : Participant(name, energyLevel), Student(name, energyLevel, knowledgeLevel), Teacher(name, energyLevel, subject) {
        cout << "Assistant Teacher " << name << " created, who is both a student and a teacher." << endl;
    }

    // Destructor
    ~AssistantTeacher() {
        cout << "Assistant Teacher " << name << " destroyed." << endl;
    }

    void assist() {
        energyLevel -= 5;
        cout << name << " is assisting in " << getSubject() << ". Energy level is now " << energyLevel << "." << endl;
    }

    void performAction() const override {
         // Overriding virtual function
        cout << name << " is assisting and balancing teaching and learning." << endl;
    }
};

int main() {
    // Demonstrating Polymorphism with Participant pointers
    Participant* participants[3];

    participants[0] = new Student("Alice", 100, 50);
    participants[1] = new Teacher("Mr. Johnson", 80, "Mathematics");
    participants[2] = new AssistantTeacher("John Doe", 90, 60, "Science");

    cout << "\n--- Demonstrating Polymorphism ---\n";
    for (int i = 0; i < 3; i++) {
        participants[i]->performAction(); // Polymorphic behavior
    }

    cout << "\n--- Cleaning up resources ---\n";
    for (int i = 0; i < 3; i++) {
        delete participants[i]; // Clean up resources
    }

    return 0;
}
