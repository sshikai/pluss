#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

// Обобщенная функция для вывода list<T> в файл
template <typename T>
void printListToFile(const list<T>& lst, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& item : lst) {
            outFile << item << " ";
        }
        outFile.close();
        cout << "List successfully written to " << filename << endl;
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int main() {
    // 1. Заполнить vector<int> из файла, найти сколько раз в нем встречается значение 1
    vector<int> vec;
    ifstream inFile("input.txt");
    
    if (inFile.is_open()) {
        int num;
        while (inFile >> num) {
            vec.push_back(num);
        }
        inFile.close();
        
        
        int countOnes = count(vec.begin(), vec.end(), 1);
        cout << "Number of 1's in vector: " << countOnes << endl;
    }
    else {
        cerr << "Unable to open input.txt file" << endl;
        return 1;
    }

    // 2. Скопировать vector<int> в list<int>, исключая значения равные 1
    list<int> lst;
    for (int num : vec) {
        if (num != 1) {
            lst.push_back(num);
        }
    }
    
    cout << "List after copying from vector (without 1's): ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;

    // 3. Заполнить list<int> из файла, скопировать в vector<int> в обратном порядке
    list<int> lstFromFile;
    ifstream inFile2("input.txt"); 
    
    if (inFile2.is_open()) {
        int num;
        while (inFile2 >> num) {
            lstFromFile.push_back(num);
        }
        inFile2.close();
        
        vector<int> reversedVec;
        
        copy(lstFromFile.rbegin(), lstFromFile.rend(), back_inserter(reversedVec));
        
        cout << "Vector in reverse order: ";
        for (int num : reversedVec) {
            cout << num << " ";
        }
        cout << endl;
    }

    // 4. Заполнить вектор из list<int>, считанного из файла и данных введенных в консоль
    vector<int> combinedVec;
    
   
    copy(lstFromFile.begin(), lstFromFile.end(), back_inserter(combinedVec));
    
    
    cout << "Enter integers (enter 'q' to stop): ";
    int input;
    while (cin >> input) {
        combinedVec.push_back(input);
    }
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Combined vector: ";
    for (int num : combinedVec) {
        cout << num << " ";
    }
    cout << endl;

    // 5. Использование обобщенной функции вывода list<T> в файл
    printListToFile(lst, "output.txt");

    return 0;
}
