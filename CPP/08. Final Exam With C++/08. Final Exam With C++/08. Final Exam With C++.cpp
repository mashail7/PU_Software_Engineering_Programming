#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Зад.1

const int TEXTS_COUNT = 3;

struct TextEntry {
    string text;
};

void inputEntries(TextEntry entries[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Въведете низ " << i + 1 << ": ";
        getline(cin, entries[i].text);
    }
}

void printReverse(const TextEntry entries[], int n) {
    cout << endl << "Низовете в обратен ред:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << entries[i].text << endl;
    }
}

// Зад.2

const int TRIANGLES_COUNT = 2;

struct Triangle {
    double a;
    double b;
    double c;
};

double getPerimeter(const Triangle& t) {
    return t.a + t.b + t.c;
}

void inputTriangles(Triangle triangles[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Триъгълник " << i + 1 << ":" << endl;
        cout << "  Страна a: ";
        cin >> triangles[i].a;
        cout << "  Страна b: ";
        cin >> triangles[i].b;
        cout << "  Страна c: ";
        cin >> triangles[i].c;
    }
}

void comparePerimeters(const Triangle triangles[]) {
    double p1 = getPerimeter(triangles[0]);
    double p2 = getPerimeter(triangles[1]);

    cout << endl;
    if (p1 > p2) {
        cout << "По-големият периметър е на триъгълник 1: " << p1 << endl;
    }
    else if (p2 > p1) {
        cout << "По-големият периметър е на триъгълник 2: " << p2 << endl;
    }
    else {
        cout << "Двата триъгълника имат равни периметри: " << p1 << endl;
    }
}

// Зад.3

const int MAX_N = 100;

struct Student {
    string name;
    double grade;
};

// Задача 3 - Подусловие 1: Въвеждане
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "Ученик " << i + 1 << ":" << endl;
        cout << "  Име: ";
        getline(cin, students[i].name);
        cout << "  Оценка: ";
        cin >> students[i].grade;
    }
}

// Задача 3 - Подусловие 2: Извеждане
void printStudents(const Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << students[i].name
            << " - оценка: " << students[i].grade << endl;
    }
}

// Задача 3 - Подусловие 3: Среден успех
double getAverageGrade(const Student students[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += students[i].grade;
    }
    return total / n;
}

// Задача 3 - Подусловие 4: Най-висок успех
int findTopStudent(const Student students[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].grade > students[maxIndex].grade) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Задача 3 - Подусловие 5: Bubble Sort в низходящ ред
void sortStudentsByGradeDesc(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Зад.1
    TextEntry entries[TEXTS_COUNT];
    inputEntries(entries, TEXTS_COUNT);
    printReverse(entries, TEXTS_COUNT);

    // Зад.2
    Triangle triangles[TRIANGLES_COUNT];
    inputTriangles(triangles, TRIANGLES_COUNT);
    comparePerimeters(triangles);

    // Зад.3
    Student students[MAX_N];
    int n;

    do {
        cout << "Брой ученици (1 - " << MAX_N << "): ";
        cin >> n;
    } while (n < 1 || n > MAX_N);

    // Подусловие 1
    inputStudents(students, n);

    // Подусловие 2
    cout << endl << "--- Списък на учениците ---" << endl;
    printStudents(students, n);

    // Подусловие 3
    cout << endl << "Среден успех: " << getAverageGrade(students, n) << endl;

    // Подусловие 4
    int topIdx = findTopStudent(students, n);
    cout << "Ученик с най-висока оценка: " << students[topIdx].name
        << " (оценка: " << students[topIdx].grade << ")" << endl;

    // Подусловие 5
    sortStudentsByGradeDesc(students, n);
    cout << endl << "--- Сортиран списък (низходящ ред по оценка) ---" << endl;
    printStudents(students, n);

    return 0;
}