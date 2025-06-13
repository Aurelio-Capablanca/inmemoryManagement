//
// Created by aurel on 5/29/2025.
//

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

struct Street {
    std::string name;

    explicit Street(const std::string &name_): name(std::move(name)) {}
};


struct Locality {
    std::string name;
    std::vector<std::unique_ptr<Street> > streets;

    explicit Locality(std::string name_): name(std::move(name_)) {
    }

    void addStreet(const std::string &name) {
        streets.push_back(std::make_unique<Street>(name));
    }
};

struct City {
    std::string name;
    std::vector<std::unique_ptr<Locality> > localities;

    explicit City(std::string name_): name(std::move(name_)) {
    }

    void addLocality(const std::string &name) {
        localities.push_back(std::make_unique<Locality>(name));
    }

    Locality *getLocality(const std::string &name) {
        for (auto &l: localities) {
            if (l->name == name) return l.get();
        }
        return nullptr;
    }
};

struct Country {
    std::string name;
    std::vector<std::unique_ptr<City> > cities;

    explicit Country(std::string name_): name(std::move(name_)) {
    }

    void addCity(const std::string &name) {
        cities.push_back(std::make_unique<City>(name));
    }

    City *getCity(const std::string &name) {
        for (auto &c: cities) if (c->name == name) return c.get();
        return nullptr;
    }
};

using WorldMap = std::map<std::string, Country>;

int main() {
    auto const country = std::make_unique<Country>("The Empire of the Asturians");
    country->addCity("Oportia");

    City *city = country->getCity("Oportia");
    city->addLocality("Villas Vedras");

    Locality *locality = city->getLocality("Villas Vedras");
    locality->addStreet("Caminos Imperiales 9");

    std::cout << "Country :  " << country->name << "\n";
    for (const auto &city: country->cities) {
        std::cout << " City :  " << city->name << "\n";
        for (const auto &local: city->localities) {
            std::cout << " Locality : " << locality->name << "\n";
            for (const auto &street: locality->streets) {
                std::cout << " Street : " << street->name << "\n";
            }
        }
    }
    return 0;
}
