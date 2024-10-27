#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream File_main("Text2.in");
    if (!File_main.is_open()) {
        cout<<"I can't open your file!"<<endl;
        return 1;
    }

    ofstream File_neg("Negativ.out");
    if (!File_neg.is_open()) {
        cout<<"I can't open your file!"<<endl;
        return 1;
    }

    ofstream File_pos("Positiv.out");
    if (!File_pos.is_open()) {
        cout << "I can't open your file!" << endl;
        return 1;
    }

    double i;
    int k_neg = 0;
    int k_pos = 0;
    while (File_main >> i) {
        if (i < 0) {
            File_neg << i << endl;
            k_neg++;
        }
        else if (i > 0) {
            File_pos << i << endl;
            k_pos++;
        }
    }

    File_main.close();
    File_neg.close();
    File_pos.close();

    cout << "Count of negative elements: " << k_neg << endl;
    cout << "Count of positive elements: " << k_pos << endl;

    return 0;
}