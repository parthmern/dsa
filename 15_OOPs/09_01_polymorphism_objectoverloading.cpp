#include <iostream>
using namespace std;

class Point {
    private:
        int x, y;

    public:
        // Constructor to initialize the point
        Point(int x = 0, int y = 0) : x(x), y(y) {
            
        }

        // Display function
        void display() {
            cout << "(" << x << ", " << y << ")" << endl;
        }

        // Overload the + operator
        Point operator+(const Point& other) {
            return Point(this->x + other.x, this->y + other.y);
        }

        
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2;  // Using overloaded + operator

    cout << "p1: ";
    p1.display();
    cout << "p2: ";
    p2.display();
    cout << "p3 (p1 + p2): ";
    p3.display();

    return 0;
}
