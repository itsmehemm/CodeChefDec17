#include <iostream>
using namespace std;

int house[101][101];

int sumOfEven(int x) {
    int temp = x;
    int sum = 0;
    while (temp) {
        if ((temp % 10) % 2 == 0)
            sum += (temp % 10);
        temp /= 10;
    }
    return sum;
}

int sumOfOdd(int x) {
    int temp = x;
    int sum = 0;
    while (temp) {
        if ((temp % 10) % 2)
            sum += (temp % 10);
        temp /= 10;
    }
    return sum;
}

int diamond(int i, int j) {
    int houseNo = i + j;
    int diamonds = abs(sumOfEven(houseNo) - sumOfOdd(houseNo));
    return diamonds;
}

void preCompute() {

    for (int i = 1; i < 101; i++) 
        house[0][i] = house[i][0] = 0;
    
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (i == j)
                house[i][j] = diamond(i, j) + house[i - 1][j - 1] + house[i][j - 1] + house[i - 1][j];
            if (i < j)
                house[i][j] = diamond(i, j) + house[i - 1][j];
            else if (i > j)
                house[i][j] = diamond(i, j) + house[i][j - 1];
        }
    }
}

void print(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << house[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main() {
    preCompute();
    for (int i = 1; i <= 10; i++)
        cout << "\n" << house[i][i];
    return 0;
}