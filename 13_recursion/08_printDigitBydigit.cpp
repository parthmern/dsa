#include <iostream>

using namespace std;

void printDigit(int num){

    if( num == 0 ){
        return;
    }

    // int digit = num%10;
    // cout << digit << " ";       // that gives 5 4 6
    
    int newnum = num/10;    
    printDigit(newnum);

    int digit = num%10;
    cout << digit << " ";           // niche ghusa do ulata kar dega

}

int main(){

    printDigit(645);

    int number = 0647;  // Octal representation (bcz starting with 0 that's why)    // ignore by int num = 647;
    std::cout << "Decimal equivalent: " << number << std::endl; 


    return 0;
}