#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person(const std::string& fname, const std::string& sname)
        : firstname(fname), secondname(sname) {}

    virtual void printName() const {
        std::cout << firstname << " " << secondname << std::endl;
    }

protected:
    std::string firstname;
    std::string secondname;
};

class Parent : public Person {
public:
    Parent(const std::string& fname, const std::string& sname)
        : Person(fname, sname) {}

    void printName() const override {
        std::cout << "Parent: " << firstname << " " << secondname << std::endl;
    }
};

class Student : public Person {
public:
    Student(const std::string& fname, const std::string& sname)
        : Person(fname, sname) {}

    void printName() const override {
        std::cout << "Student: " << firstname << " " << secondname << std::endl;
    }
};

int main() {
    std::vector<Person*> people;
    people.push_back(new Parent("John", "Doe"));
    people.push_back(new Student("Mary", "Doe"));

    for (const auto& person : people) {
        person->printName();
    }

    // Clean up allocated memory
    for (auto& person : people) {
        delete person;
    }

    return 0;
}
