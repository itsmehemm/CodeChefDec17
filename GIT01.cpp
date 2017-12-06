#include <iostream>
using namespace std;

int findOptimalPlacement(string* cake, int n, int m) {
    int optimal = 0;
    int red_m1 = 0;
    int red_m2 = 0;
    int gre_m1 = 0;
    int gre_m2 = 0;
    int m1 = 0;
    int m2 = 0;
    char start = 'R';

    for (int i = 0; i < n; i++) {
        start = (i % 2 == 0) ? 'R' : 'G';
        for (int j = 0; j < m; j++) {
            if (start != cake[i][j])
                if (cake[i][j] == 'R')
                    red_m1 += 1;
                else
                    gre_m1 += 1;
            else
                if (cake[i][j] == 'R')
                    red_m2 += 1;
                else
                    gre_m2 += 1;
            start = (start == 'R') ? 'G' : 'R';
        }
    }
    m1 = red_m1 * 5 + gre_m1 * 3;
    m2 = red_m2 * 5 + gre_m2 * 3;
    optimal = (m1 > m2) ? m2 : m1;
    return optimal;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int m;
        scanf("%d%d", &n, &m);
        string* cake = new string[n + 1];
        for (int i = 0; i < n; i++) 
            cin >> cake[i];
        int optimal = findOptimalPlacement(cake, n, m);
        printf("%d\n", optimal);
    }
    return 0;
}