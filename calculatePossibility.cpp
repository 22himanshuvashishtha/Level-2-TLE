#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
int targetPos = 0;
int correctOutcomes = 0;
int totalOutcomes = 0;
 
void calculateProbability(int pos, int index, const string& s1, const string& s2) {
    if (index == s2.length()) {
        if (pos == targetPos) {
            correctOutcomes++;
        }
        totalOutcomes++;
        return;
    }
    
    if (s2[index] == '+') {
        calculateProbability(pos + 1, index + 1, s1, s2);
    } else if (s2[index] == '-') {
        calculateProbability(pos - 1, index + 1, s1, s2);
    } else {
        calculateProbability(pos + 1, index + 1, s1, s2);
        calculateProbability(pos - 1, index + 1, s1, s2);
    }
}
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    for (char c : s1) {
        if (c == '+') {
            targetPos++;
        } else {
            targetPos--;
        }
    }
    calculateProbability(0, 0, s1, s2);
    
    double probability = static_cast<double>(correctOutcomes) / totalOutcomes;
    cout << fixed << setprecision(12) << probability << endl;
    
    return 0;
}
