#include <iostream>
using namespace std;

int min(int a, int b){ return a > b ? b : a; }
int max(int a, int b){ return a > b ? a : b; }
void printWinner(int a, int b, int s){
    cout << ((a > b) ? "TEAM-A " : "TEAM-B ") << s << endl;
}
int main() {
    string record;
    while (cin >> record) {
        int scoreA = 0;
        int scoreB = 0;
        int shots = 0;
        bool advantage = false;
        bool tie = true;
        for (int i = 0; i < 5; i++) {
            if (record[2 * i] == '1')
                scoreA += 1;
            if (scoreA != scoreB) {
                int remainA = 5 - i - 1;
                int remainB = 5 - i;
                if ((scoreA < scoreB && scoreA + remainA < scoreB) || (scoreB < scoreA && scoreB + remainB < scoreA)) {
                    advantage = true;
                    shots = 2 * i + 1;
                    break;
                }
            }
            if (record[2 * i + 1] == '1')
                scoreB += 1;
            if (scoreA != scoreB) {
                int remainA = 5 - i - 1;
                int remainB = 5 - i - 1;
                if ((scoreA < scoreB && scoreA + remainA < scoreB) || (scoreB < scoreA && scoreB + remainB < scoreA)) {
                    advantage = true;
                    shots = 2 * i + 2;
                    break;
                }
            }   
        }
        if (advantage) {
            printWinner(scoreA, scoreB, shots);
            continue;
        }
        if (scoreA == scoreB) {
            for (int i = 0; i < 5; i++) {
                if (record[2 * i + 10] == '1')
                    scoreA += 1;
                if (record[2 * i + 11] == '1')
                    scoreB += 1;
                if (scoreA != scoreB) {
                    printWinner(scoreA, scoreB, 2 * i + 12 );
                    tie = false;
                    break;
                }
            }
        }
        if (tie)
            cout << "TIE\n";
    }
    return 0;
}