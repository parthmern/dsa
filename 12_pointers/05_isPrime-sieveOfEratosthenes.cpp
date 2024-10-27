#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    int count = 0;
    vector<bool> prime(n + 1, true); // Marking all as prime initially
    prime[0] = prime[1] = false;     // 0 and 1 are not prime numbers

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++;
            for (int j = 2 * i; j < n; j += i) {
                prime[j] = false; // Marking multiples of i as non-prime
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int primeCount = countPrimes(n);
    cout << "Number of prime numbers less than " << n << " is: " << primeCount << endl;

    return 0;
}
