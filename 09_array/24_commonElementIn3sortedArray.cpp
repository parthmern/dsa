#include <iostream>
#include <set>
using namespace std;

void findCommon(int A[], int B[], int C[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;

    set<int> ans;

    while (i < n1 && j < n2 && k < n3) {

        // Check if A[i], B[j], and C[k] are the same
        if (A[i] == B[j] && B[j] == C[k]) {
            cout << "Same element is => " << A[i] << endl;
            ans.insert(A[i]);
            i++;
            j++;
            k++;
        }
        // Move i if A[i] is smaller
        else if (A[i] < B[j]) {
            i++;
        }
        // Move j if B[j] is smaller
        else if (B[j] < C[k]) {
            j++;
        }
        // Move k if C[k] is smaller
        else {
            k++;
        }
    }

    // print set
    for (auto& x : ans) {
        cout << x << ' ';
    }
}

int main() {
    int A[] = {1, 5, 10, 20, 40, 80}; 
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    findCommon(A, B, C, n1, n2, n3);

    return 0;
}
