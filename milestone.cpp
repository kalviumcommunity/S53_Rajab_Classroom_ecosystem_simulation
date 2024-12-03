#include <iostream>
#include <string>
using namespace std;

// Energy Manager
class EnergyManager {
private:
    int energyLevel;

public:
    EnergyManager(int energyLevel = 100) : energyLevel(energyLevel) {}

    int getEnergyLevel() const {
        return energyLevel;
    }

    void increaseEnergy(int amount) {
        energyLevel += amount;
        cout << "Energy increased by " << amount << ". Current energy: " << energyLevel << endl;
    }

    void decreaseEnergy(int amount) {
        energyLevel -= amount;
        cout << "Energy decreased by " << amount << ". Current energy: " << energyLevel << endl;
    }
};

// Knowledge Manager
class KnowledgeManager {
private:
    int knowledgeLevel;

public:
    KnowledgeManager(int knowledgeLevel = 50) : knowledgeLevel(knowledgeLevel) {}

    int getKnowledgeLevel() const {
        return knowledgeLevel;
    }

    void increaseKnowledge(int amount) {
        knowledgeLevel += amount;
        cout << "Knowledge increased by " << amount << ". Current knowledge: " << knowledgeLevel << endl;
    }
};

// Abstract Base Class - Participant
class Participant {
protected:
    string name;
    EnergyManager energyManager;

public:
    Participant(string name = "Unnamed", int energyLevel = 100)
        : name(name), energyManager(energyLevel) {
        cout << "Participant " << name << " created with energy level " << energyManager.getEnergyLevel() << "." << endl;
    }

    virtual ~Participant() {
        cout << "Participant " << name << " destroyed." << endl;
    }

    virtual void performAction() const = 0;

    void rest() {
        energyManager.increaseEnergy(10);
        cout << name << " is resting." << endl;
    }
};

// Derived class - Student
class Student : public Participant {
private:
    KnowledgeManager knowledgeManager;

public:
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50)
        : Participant(name, energyLevel), knowledgeManager(knowledgeLevel) {
        cout << "Student " << name << " created with knowledge level " << knowledgeManager.getKnowledgeLevel() << "." << endl;
    }

    void study(int hours) {
        knowledgeManager.increaseKnowledge(hours * 2);
        energyManager.decreaseEnergy(hours * 2);
        cout << name << " studied for " << hours << " hours." << endl;
    }

    void performAction() const  {
        cout << name << " is studying to improve knowledge." << endl;
    }
};

// Derived class - Teacher
class Teacher : public Participant {
private:
    string subject;

public:
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown")
        : Participant(name, energyLevel), subject(subject) {
        cout << "Teacher " << name << " created with subject " << subject << "." << endl;
    }

    string getSubject() const {
        return subject;
    }

    void teach() {
        energyManager.decreaseEnergy(10);
        cout << name << " is teaching " << subject << "." << endl;
    }

    void performAction() const  {
        cout << name << " is teaching the subject: " << subject << "." << endl;
    }
};

// Derived class - Researcher (New Class to Demonstrate Extension)
class Researcher : public Participant {
public:
    Researcher(string name, int energyLevel = 100) : Participant(name, energyLevel) {
        cout << "Researcher " << name << " created." << endl;
    }

    void performResearch() {
        energyManager.decreaseEnergy(15);
        cout << name << " is conducting research. Energy level is now " << energyManager.getEnergyLevel() << "." << endl;
    }

    void performAction() const  {
        cout << name << " is researching to find new knowledge." << endl;
    }
};

int main() {
    Participant* participants[3];

    participants[0] = new Student("Alice", 100, 50);
    participants[1] = new Teacher("Mr. Johnson", 80, "Mathematics");
    participants[2] = new Researcher("Dr. Smith", 90);

    cout << "\n--- Demonstrating Polymorphism ---\n";
    for (int i = 0; i < 3; i++) {
        participants[i]->performAction();
    }

    cout << "\n--- Cleaning up resources ---\n";
    for (int i = 0; i < 3; i++) {
        delete participants[i];
    }

    return 0;
}
