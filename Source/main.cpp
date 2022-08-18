#include "MockStudentDataGenerator.h"

int main () {
    srand(time(NULL));
    RandomIntegerGenerator rig;
    int n = rig.next(5, 10);
    MockStudentDataGenerator msdg;
    msdg.getDataInFile("students.txt");
    msdg.addStudent(n);
    msdg.dataToFile("students.txt");
    msdg.printGPAGreaterThanAverageGPA();
    system("pause");
    return 0;
}