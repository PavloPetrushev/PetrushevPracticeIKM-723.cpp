// Практика Петрушев.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <unordered_set>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int myArray[] = { 10, 20, 30, 40, 50 };
    int size = 5;

    // 1. Знаходження суми всіх елементів у масиві
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += myArray[i];
    }
    cout << "Сума елементів масиву: " << sum << endl;

    // 2. Знаходження мінімального та максимального елементів у масиві
    int min = myArray[0];
    int max = myArray[0];
    for (int i = 1; i < size; i++) {
        if (myArray[i] < min) {
            min = myArray[i];
        }
        if (myArray[i] > max) {
            max = myArray[i];
        }
    }
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Максимальний елемент: " << max << endl;

    // 3. Знаходження середнього значення елементів у масиві
    double average = static_cast<double>(sum) / size;
    cout << "Середнє значення елементів масиву: " << average << endl;

    // 4. Перевірка, чи міститься певний елемент у масиві
    int target = 30;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (myArray[i] == target) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Елемент " << target << " міститься в масиві." << endl;
    }
    else {
        cout << "Елемент " << target << " не міститься в масиві." << endl;
    }

    // 5. Сортування елементів у масиві (в порядку зростання)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                int temp = myArray[j];
                myArray[j] = myArray[j + 1];
                myArray[j + 1] = temp;
            }
        }
    }
    cout << "Відсортований масив: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // 6. Підрахунок кількості парних та непарних чисел у масиві
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (myArray[i] % 2 == 0) {
            evenCount++;
        }
        else {
            oddCount++;
        }
    }
    cout << "Кількість парних чисел: " << evenCount << endl;
    cout << "Кількість непарних чисел: " << oddCount << endl;

    // 7. Знаходження всіх повторюваних елементів у масиві
    unordered_set<int> seen;
    unordered_set<int> duplicates;
    for (int i = 0; i < size; i++) {
        if (seen.find(myArray[i]) != seen.end()) {
            duplicates.insert(myArray[i]);
        }
        else {
            seen.insert(myArray[i]);
        }
    }
    cout << "Повторювані елементи: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    // 8. Знаходження всіх пар елементів у масиві, сума яких дорівнює заданому числу
    int targetSum = 70;
    seen.clear();
    cout << "Пари елементів, сума яких дорівнює " << targetSum << ": " << endl;
    for (int i = 0; i < size; i++) {
        int complement = targetSum - myArray[i];
        if (seen.find(complement) != seen.end()) {
            cout << myArray[i] << " + " << complement << " = " << targetSum << endl;
        }
        else {
            seen.insert(myArray[i]);
        }
    }

    return 0;
}