#include <iostream>
#include "bird.h"

void birdDoesSomething(Bird* bird) {
    bird->eat();
    bird->fly();
    bird->eat();
}

int main() {
    Bird* bird = new Sparrow();
    birdDoesSomething(bird);
    delete bird;
    return 0;
}
