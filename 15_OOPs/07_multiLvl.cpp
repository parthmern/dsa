#include <iostream>
using namespace std;

class Fruit{
    public:
        string name;
};

class Mango : public Fruit{
    public:
        int weight;
};

class Alphanso : public Mango{
    public:
        int sugarlvl;
};

int main(){

    Alphanso a;

    cout << a.name << a.weight << a.sugarlvl ;  // all accessible

    return 0;
}