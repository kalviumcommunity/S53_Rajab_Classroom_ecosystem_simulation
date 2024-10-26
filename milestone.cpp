#include <iostream>
#include <string>
using namespace std;

// Base class
class Participant {
protected:
    string name;          // Protected, accessible by derived classes
    int energyLevel;      // Protected, accessible by derived classes

public:
    Participant(string name = "Unnamed", int energyLevel = 100) {
        this->name = name;
        this->energyLevel = energyLevel;
    }

    void rest() {
        this->energyLevel += 10;
        cout << this->name << " is resting. Energy level is now " << this->energyLevel << "." << endl;
    }

    // Public accessor and mutator for name
    string getName() const {
        return name;
    }
    void setName(const string& newName) {
        name = newName;
    }

    // Public accessor for energy level (no mutator to control modification)
    int getEnergyLevel() const {
        return energyLevel;
    }
};

// Derived class - Student
class Student : public Participant {
private:
    int knowledgeLevel;  // Private, encapsulating direct access to knowledge level

public:
    Student(string name = "Unnamed", int energyLevel = 100, int knowledgeLevel = 50)
        : Participant(name, energyLevel) {
        this->knowledgeLevel = knowledgeLevel;
    }

    // Public accessor and mutator for knowledge level
    int getKnowledgeLevel() const {
        return knowledgeLevel;
    }
    void setKnowledgeLevel(int newKnowledgeLevel) {
        if (newKnowledgeLevel >= 0) {  // Basic validation
            knowledgeLevel = newKnowledgeLevel;
        }
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
    string subject;  // Private, only accessible via get/set methods

public:
    Teacher(string name = "Unnamed", int energyLevel = 100, string subject = "Unknown")
        : Participant(name, energyLevel) {
        this->subject = subject;
    }

    // Public accessor and mutator for subject
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
    for (int i = 0; i < 3; i++) {
        students[i].study(2);
        students[i].rest();
    }

    for (int i = 0; i < 2; i++) {
        teachers[i].teach();
        teachers[i].rest();
    }

    // Deallocating dynamically allocated memory
    delete[] students;
    delete[] teachers;

    return 0;
}
