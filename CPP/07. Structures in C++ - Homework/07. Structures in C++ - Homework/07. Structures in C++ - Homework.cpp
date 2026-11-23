#include <iostream>
#include <Windows.h>

using namespace std;

const int MAX_N = 100;

struct Rect {
    double width;
    double height;
};

double getArea(const Rect& r) {
    return r.width * r.height;
}

void inputRectangles(Rect rects[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Правоъгълник " << i + 1 << ":" << endl;
        cout << "  Широчина: ";
        cin >> rects[i].width;
        cout << "  Височина: ";
        cin >> rects[i].height;
    }
}

void printAreas(const Rect rects[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Лице на правоъгълник " << i + 1 << ": "
            << getArea(rects[i]) << endl;
    }
}

double getTotalArea(const Rect rects[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += getArea(rects[i]);
    }
    return total;
}

int findLargest(const Rect rects[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (getArea(rects[i]) > getArea(rects[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Rect rects[MAX_N];
    int n;

    do {
        cout << "Брой правоъгълници (1 - " << MAX_N << "): ";
        cin >> n;
    } while (n < 1 || n > MAX_N);

    inputRectangles(rects, n);

    cout << endl;
    printAreas(rects, n);

    cout << "Общо лице: " << getTotalArea(rects, n) << endl;

    int idx = findLargest(rects, n);
    cout << "Правоъгълникът с най-голямо лице е номер " << idx + 1
        << " (широчина: " << rects[idx].width
        << ", височина: " << rects[idx].height
        << ", лице: " << getArea(rects[idx]) << ")" << endl;

    return 0;
}