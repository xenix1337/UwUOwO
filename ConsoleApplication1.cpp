#include <iostream>
#include <string>
#include <fstream>
#include <array>

using namespace std;

char getChar(int x, int y) {
    char l[3] = { 'U', 'w' };
    return l[(x + y) % 2];
}

char getChar2(int x, int y) {
    char l[3] = { 'O', 'w' };
    return l[(x + y) % 2];
}

int main()
{
    ofstream file("OWO.UWU");

    string linie[25];
    for (int i = 0; i < 25; i++) {
        for (int x = 0; x < 150; x++) {
            linie[i] += ' ';
        }
    }

    for (int y = 0; y < 25; y ++) {
        for (int x = 0; x < 150; x++) {
            int cy = y * 2;
            float dist = (x - 25) * (x - 25) + (cy - 29) * (cy - 29);
            dist = sqrt(dist);
            if (dist < 20 && dist > 10) linie[y][x] = getChar(x, y);

            dist = (x - 125) * (x - 125) + (cy - 29) * (cy - 29);
            dist = sqrt(dist);
            if (dist < 20 && dist > 10) linie[y][x] = getChar(x, y);

            if (x > 50 && x < 100) {
                if (cy >= 0 && cy <= 50) {
            float cx = (x - 75) * 1.5;
                    float xx = abs( abs(cx) - 15);
                    dist = abs(cy - xx);
                    if (dist < 4) linie[24 - y][x] = getChar(x, y);
                }
            }
        }
    }

    for (int i = 0; i < 25; i++) {
        cout << linie[i] << '\n';
        file << linie[i] << '\n';
    }

    //UwU

    for (int i = 0; i < 25; i++) {
        linie[i] = "";
        for (int x = 0; x < 150; x++) {
            linie[i] += ' ';
        }
    }

    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 150; x++) {
            int cy = y * 2;
            if (cy > 33) {
                float dist = (x - 25) * (x - 25) + (cy - 29) * (cy - 29);
                dist = sqrt(dist);
               
                if (dist < 20 && dist > 10) linie[y][x] = getChar2(x, y);
            }
            else {
                if (cy > 4 && cy < 34) {
                    float dist = abs(x - 25);
                    if (dist < 20 && dist > 10) linie[y][x] = getChar2(x, y);
                }
            }

            if (cy > 33) {
                float dist = (x - 125) * (x - 125) + (cy - 29) * (cy - 29);
                dist = sqrt(dist);
                if (dist < 20 && dist > 10) linie[y][x] = getChar2(x, y);
            } else {
                if (cy > 4 && cy < 34) {
                    float dist = abs(x - 125);
                    if (dist < 20 && dist > 10) linie[y][x] = getChar2(x, y);
                }
            }

            if (x > 50 && x < 100) {
                if (cy >= 0 && cy <= 50) {
                    float cx = (x - 75) * 1.5;
                    float xx = abs(abs(cx) - 15);
                    float dist = abs(cy - xx);
                    if (dist < 4) linie[24 - y][x] = getChar2(x, y);
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < 25; i++) {
        cout << linie[i] << '\n';
        file << linie[i] << '\n';
    }
}