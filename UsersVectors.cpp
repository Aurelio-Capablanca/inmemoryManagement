//
// Created by aurel on 6/12/2025.
//
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>


class Persons {
private:
    std::string *name;
    std::string *lastname;
    std::string *email;

public:
    Persons() {
        name = new std::string();
        lastname = new std::string();
        email = new std::string();
        std::cout << "started Persons !";
    }

    ~Persons() {
        delete name;
        delete lastname;
        delete email;
    }

    void setName(const std::string &n) {
        *name = n;
    }

    void setLastname(const std::string &l) {
        *lastname = l;
    }

    void setEmail(const std::string &e) {
        *email = e;
    }

    const std::string &getName() {
        return *name;
    }

    const std::string &getLastname() {
        return *lastname;
    }

    const std::string &getEmail() {
        return *email;
    }
};


struct repositoryPeople {
    std::vector<Persons *> persons;

    ~repositoryPeople() {
        for (const auto &person: persons) {
            delete person;
        }
    }
};


int main() {
    printf("test\n");
    std::string name;
    std::string lastname;
    std::string email;

    Persons* persons = new Persons();
    repositoryPeople repository;

    std::cout << "Enter Your Name !\n";
    std::cin >> name;
    persons->setName(name);
    std::cout << "Enter your Lastname !\n";
    std::cin >> lastname;
    persons->setLastname(lastname);
    std::cout << "Enter an Email !\n";
    std::cin >> email;
    persons->setEmail(email);

    repository.persons.push_back(persons);

    for (const auto person: repository.persons) {
        std::cout << " Name : " << person->getName()
        << " Last Name : " << persons->getLastname()
        << " Email : "<< person->getEmail();
    }


    delete persons;
}
