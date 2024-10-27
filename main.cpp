#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream File_main("Text4.in");
    if (!File_main.is_open()) {
        cout << "I can't open your file!" << endl;
        return 1;
    }

    ofstream File_neg("Negativ.out");
    if (!File_neg.is_open()) {
        cout << "I can't open your file!" << endl;
        File_main.close();
        return 1;
    }


    double i;
    int k_neg = 0;
    int pos = 0;
    while (File_main >> i) {
        if (i < 0) {
            File_neg << "Chislo: " << i <<" - Position: " << pos << endl;
            k_neg++;
        }
        pos++;
    }

    File_main.close();
    File_neg.close();

    cout << "Count of negative elements: " << k_neg << endl;
    
    return 0;
}