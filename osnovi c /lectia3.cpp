#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Функция для чтения чисел из файла
vector<int> readNumbersFromFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return numbers;
    }

    int number;
    while (file >> number) {
        numbers.push_back(number);
    }

    file.close();
    return numbers;
}

// Функция для записи чисел в файл
void writeNumbersToFile(const vector<int>& numbers, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка создания файла!" << endl;
        return;
    }

    for (int num : numbers) {
        file << num << " ";
    }

    file.close();
    cout << "Числа успешно записаны в файл " << filename << endl;
}

int main() {
    // 1. Чтение чисел из файла
    const string inputFile = "numbers.txt";
    vector<int> numbers = readNumbersFromFile(inputFile);

    if (numbers.empty()) {
        cerr << "Файл пуст или не найден!" << endl;
        return 1;
    }

    cout << "Прочитанные числа: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl << endl;

    // 2. Задача 1: Подсчет заданного числа
    int target;
    cout << "Введите число для поиска: ";
    cin >> target;

    int countTarget = count(numbers.begin(), numbers.end(), target);
    cout << "Число " << target << " встречается " << countTarget << " раз(а)" << endl << endl;

    // 3. Задача 2: Числа с заданным квадратным корнем
    int sqrtValue;
    cout << "Введите значение квадратного корня для поиска: ";
    cin >> sqrtValue;

    int countSqrt = 0;
    for (int num : numbers) {
        if (sqrt(num) == sqrtValue) {
            countSqrt++;
        }
    }
    cout << "Чисел с квадратным корнем " << sqrtValue << " найдено: " << countSqrt << endl << endl;

    // 4. Задача 3: Поиск пар чисел
    cout << "Пары одинаковых соседних чисел: ";
    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        if (numbers[i] == numbers[i + 1]) {
            cout << "(" << numbers[i] << "," << numbers[i + 1] << ") ";
        }
    }
    cout << endl;

    cout << "Пары чисел, отличающиеся в 3 раза: ";
    for (size_t i = 0; i < numbers.size() - 1; ++i) {
        if (numbers[i] == 3 * numbers[i + 1] || numbers[i + 1] == 3 * numbers[i]) {
            cout << "(" << numbers[i] << "," << numbers[i + 1] << ") ";
        }
    }
    cout << endl << endl;

    // 5. Задача 4: Возведение в квадрат и запись в файл
    vector<int> squaredNumbers;
    for (int num : numbers) {
        squaredNumbers.push_back(num * num);
    }

    const string outputFile = "squared_numbers.txt";
    writeNumbersToFile(squaredNumbers, outputFile);
    cout << endl;

    // 6. Задача 5: Поиск подпоследовательности
    vector<int> subsequence;
    cout << "Введите подпоследовательность (завершите ввод любым нечислом): ";

    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int subNum;
    while (cin >> subNum) {
        subsequence.push_back(subNum);
    }

    if (!subsequence.empty()) {
        auto it = search(numbers.begin(), numbers.end(), subsequence.begin(), subsequence.end());

        if (it != numbers.end()) {
            cout << "Подпоследовательность найдена, начиная с позиции "
                << distance(numbers.begin(), it) << endl;
        }
        else {
            cout << "Подпоследовательность не найдена" << endl;
        }
    }
    else {
        cout << "Подпоследовательность не введена" << endl;
    }

    return 0;
}
