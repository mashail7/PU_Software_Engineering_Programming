#include <iostream>
#include <cmath>
#include <string>
#include <Windows.h>
using namespace std;

struct Student
{
    string name;
    int facultyNumber;
    double averageGrade;
};

Student s1;
Student s2, s3;

// Структура като тип параметър на функция
// Структурите могат да се предават на функции по стойност или по адрес/референция &
void printStudent(const Student& st) {
    cout << st.name << " (" << st.facultyNumber << ") - " << st.averageGrade << endl;
}

// Масив от структури
Student group[3]; // масив от 3 студента

// Зад.1
struct Person {
    string firstName;
    string lastName;
    int age;
};

// Зад.2
struct Trapec {
    double side1;
    double side2;
    double height;
};

void inputTrapecData(Trapec& trapec) {
    cout << "Въведете първата основа: " << endl;
    cin >> trapec.side1;
    cout << "Въведете втората основа: " << endl;
    cin >> trapec.side2;
    cout << "Въведете височината: " << endl;
    cin >> trapec.height;
}

double calculateArea(const Trapec& trapec) {
    return (((trapec.side1 + trapec.side2) * trapec.height) / 2);
}

// Задача 3
struct Person1 {
    string name;
    int age;
};

// Линейно търсене в статичен масив с елементи от тип структура по име
bool linearSearchByName(const Person1 arr[], int size, const string& nameToFind) {
    for (int i = 0; i < size; i++) {
        if (arr[i].name == nameToFind) {
            return true;
        }
    } return false;
}

// Задача 4
void  bubbleSort(Person1 arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                Person1 temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);



    // Достъп до членовете на структурата
    s1.name = "Анна Петрова";
    s1.facultyNumber = 10001;
    s1.averageGrade = 5.50;

    // Въвеждане и извеждане на структура
    Student st;
    cout << "Въведете име: ";
    getline(cin, st.name);
    cout << "Факултетен номер: ";
    cin >> st.facultyNumber;
    cout << "Средна оценка: ";
    cin >> st.averageGrade;

    cout << "\nВъведеният студент: ";
    printStudent(st);

    // Въвеждане на инфирмация в масива от структури
    group[0].name = "Ivan";
    group[0].facultyNumber = 1342;
    group[0].averageGrade = 4.6;

    /* Задача 1. Декларирайте структура с име 'Person', която да представлява информация за двама човека.
    Структурата трябва да съдържа следните член-променливи:
    - firstName (string)
    - lastName (string)
    - age (int)
    */

	Person p1, p2;
	p1.firstName = "Иван";
	p1.lastName = "Иванов";
	p1.age = 25;

    p2.firstName = "Мария";
    p2.lastName = "Петрова";
    p2.age = 30;

    // Извеждане на информацията за двама души
    cout << "Първи човек: " << p1.firstName << " " << p1.lastName << ", възраст: " << p1.age << endl;
    cout << "Втори човек: " << p2.firstName << " " << p2.lastName << ", възраст: " << p2.age << endl;

    /* Задача 2. Създайте структура, която описва трапец ABCD с член-променливи дължините на двете основи
    (AB - CD) и височината на трапеца. При въведени от потребителя входни данни за член-променливите,
    намерете лицето на успоредника.*/

    Trapec trapec; // Създаване на променлива trapec ot тип Trapec

    // Извикване на подпрограмата за въвеждане на данните за трапеца
    inputTrapecData(trapec);

    // Извикване на подпрограмата за изчисляване на площта на трапеца
    double area = calculateArea(trapec);

    cout << "Площ на трашеца: " << area << endl;

    // Статичен масив с елементи от тип структура
    
    // Декларираме структура Point за представяне на точка с поординати x и  y
    struct Point {
        int x;
        int y;
    };

    // Дефинираме и инициализираме статичен масив от тип Point с 3 елемента
    Point points[3];

    // Въвеждаме координатите на точките от потребителя
    for (int i = 0; i < 3; i++) {
        cout << "Въведете координати на точка: " << i + 1 << endl;
        cin >> points[i].x;
        cin >> points[i].y;
    }

    // Извеждаме въведените точки на екрана
    cout << "Въведените точки са: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Точка " << i + 1 << ": x = " << points[i].x << ", y = " << points[i].y << endl;
    }

    // Задача 3
    const int SIZE = 5;
    Person1 people[SIZE]{
        {"Иван", 25},
        {"Драган", 31},
        {"Петкан", 42},
        {"Хайван", 73},
        {"Айрян", 51},
    };
    
    // Търсене на име в статичния масив
    string nameToFind = "Хайван";
    bool found = linearSearchByName(people, SIZE, nameToFind);
    if (found) {
        cout << "Името " << nameToFind << " е намерено в статичен масив" << endl;
    }
    else {
        cout << "Името " << nameToFind << " не е намерено в статичен масив" << endl;
    }

    // Задача 4
    bubbleSort(people, SIZE);

    cout << "Сортиран масив по възраст: " << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << people[i].name << ", " << people[i].age << " години" << endl;
    }


    return 0;
}