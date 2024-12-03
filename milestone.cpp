#include <iostream>
#include <string>
#include <vector>
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
public:
    Student(string name = "Unnamed", int energyLevel = 100)
        : Participant(name, energyLevel) {
        cout << "Student " << name << " created." << endl;
    }

    void study(int hours) {
        energyManager.decreaseEnergy(hours * 2);
        cout << name << " studied for " << hours << " hours." << endl;
    }

    void performAction() const override {
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

    void teach() {
        energyManager.decreaseEnergy(10);
        cout << name << " is teaching " << subject << "." << endl;
    }

    void performAction() const override {
        cout << name << " is teaching the subject: " << subject << "." << endl;
    }
};

// Derived class - Researcher
class Researcher : public Participant {
public:
    Researcher(string name, int energyLevel = 100) : Participant(name, energyLevel) {
        cout << "Researcher " << name << " created." << endl;
    }

    void performResearch() {
        energyManager.decreaseEnergy(15);
        cout << name << " is conducting research." << endl;
    }

    void performAction() const override {
        cout << name << " is researching to find new knowledge." << endl;
    }
};

// Function to test Liskov Substitution Principle
void performParticipantActions(const vector<Participant*>& participants) {
    for (const auto& participant : participants) {
        participant->performAction();
    }
}

int main() {
    // Creating a vector of participants (polymorphism)
    vector<Participant*> participants;

    participants.push_back(new Student("Alice", 100));
    participants.push_back(new Teacher("Mr. Johnson", 80, "Mathematics"));
    participants.push_back(new Researcher("Dr. Smith", 90));

    cout << "\n--- Demonstrating Liskov Substitution Principle ---\n";
    performParticipantActions(participants);

    cout << "\n--- Cleaning up resources ---\n";
    for (auto participant : participants) {
        delete participant;
    }

    return 0;
}
