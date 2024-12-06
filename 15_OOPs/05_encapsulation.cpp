#include <iostream>

class Animal {
private:
    int age;
    double weight;

public:
    Animal(int a, double w) : age(a), weight(w) {}

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        } else {
            std::cout << "Age cannot be negative.\n";
        }
    }
};

int main() {
    Animal myAnimal(5, 20.5);

    std::cout << "Initial Age: " << myAnimal.getAge() << " years\n";

    myAnimal.setAge(7);
    std::cout << "Updated Age: " << myAnimal.getAge() << " years\n";

    myAnimal.setAge(-3);

    return 0;
}
