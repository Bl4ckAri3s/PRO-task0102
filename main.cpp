#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void menu() {
    cout << "=========================" << endl;
    cout << "======== MENU: ==========" << endl;
    cout << "=========================" << endl;
    cout << "1 ... GENERATE GRADES" << endl;
    cout << "2 ... PRINT GRADES" << endl;
    cout << "3 ... PRINT AVERAGE GRADE" << endl;
    cout << "4 ... PRINT GRADES ABOVE AVERAGE" << endl;
    cout << "5 ... PRINT POSITIVE GRADES" << endl;
    cout << "6 ... PRINT NUMBER OF EACH GRADE" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "=========================" << endl;
    cout << "Select: ";
}

void fillArrayOfGrades(int *grades, int numberOfGrades) {
    srand(time(nullptr));

    for (int i = 0; i < numberOfGrades; i++) {
        grades[i] = 1 + (rand() % 10);
    }
}

void printArrayOfGrades(int *grades, int numerOfGrades) {
    cout << "Grades: ";
    for (int i = 0; i < numerOfGrades; i++) {
        cout << ((i > 0) ? ", " : "") << grades[i];
    }
    cout << "." << endl;
}

int getAverageGrade(int *grades, int numberOfGrades) {
    int sum = 0;
    for (int i = 0; i < numberOfGrades; i++) {
        sum += grades[i];
    }
    return (sum / numberOfGrades);
}

void printAboveAverageGrades(int *grades, int numberOfGrades) {
    int averageGrade = getAverageGrade(grades, numberOfGrades);

    cout << "Grades above average: ";
    for (int i = 0; i < numberOfGrades; i++) {
        if (grades[i] > averageGrade)
            cout << grades[i] << ", ";
    }
}

void printPositiveGrades(int *grades, int numberOfGrades) {
    cout << "Positive grades: ";

    for (int i = 0; i < numberOfGrades; i++) {
        if (grades[i] > 5)
            cout << grades[i] << ", ";
    }
}

void printNumberOfEachGrade(int *grades, int numberOfGrades) {
    int allGrades[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < numberOfGrades; i++) {
        allGrades[grades[i] - 1]++;
    }

    cout << "Number of each grade: \n";
    for (int i = 0; i < 10; i++) {
        cout << "Grade " << i + 1 << ": " <<  allGrades[i] << endl;
    }
}


int main() {
    int numberOfGrades = 30;
    int* grades = new int[numberOfGrades];

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArrayOfGrades(grades, numberOfGrades);
                break;
            case 2:
                printArrayOfGrades(grades, numberOfGrades);
                break;
            case 3:
                cout << "Average grade is: " << getAverageGrade(grades, numberOfGrades);
                break;
            case 4:
                printAboveAverageGrades(grades, numberOfGrades);
                break;
            case 5:
                printPositiveGrades(grades, numberOfGrades);
                break;
            case 6:
                printNumberOfEachGrade(grades, numberOfGrades);
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] grades;

    return 0;
}