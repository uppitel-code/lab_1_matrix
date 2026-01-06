 
#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
int main() {
    const int MAX_SIZE = 7;
    const int MIN_VALUE = -10;
    const int MAX_VALUE = 10;
 
    int n;
 
    // Message before reading matrix size
    cout << "Введите размер матрицы (целое число от 1 до "
         << MAX_SIZE << "):" << endl;
 
    // Read matrix size with validation
    while (true) {
        if (!(cin >> n)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите целое число." << endl;
            cout << "Введите размер матрицы:" << endl;
        } else if (n < 1 || n > MAX_SIZE) {
            cout << "Ошибка: размер матрицы должен быть от 1 до "
                 << MAX_SIZE << "." << endl;
            cout << "Введите размер матрицы:" << endl;
        } else {
            break;
        }
    }
 
    vector<vector<int>> matrix(n, vector<int>(n));
 
    // Message before reading matrix elements
    cout << "Введите элементы матрицы." << endl;
    cout << "Допустимые значения: целые числа от "
         << MIN_VALUE << " до " << MAX_VALUE << "." << endl;
 
    // Read matrix elements with validation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            while (true) {
                if (!(cin >> matrix[i][j])) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ошибка: введите целое число для элемента ["
                         << i << "][" << j << "]." << endl;
                } else if (matrix[i][j] < MIN_VALUE || matrix[i][j] > MAX_VALUE) {
                    cout << "Ошибка: значение элемента ["
                         << i << "][" << j << "] должно быть в диапазоне от "
                         << MIN_VALUE << " до " << MAX_VALUE << "." << endl;
                } else {
                    break;
                }
            }
        }
    }
 
    // Process columns
    for (int j = 0; j < n; ++j) {
        int sum = 0;
        bool hasNegative = false;
 
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
            sum += matrix[i][j];
        }
 
        // Replace diagonal element if column has no negative values
        if (!hasNegative) {
            matrix[j][j] = sum;
        }
    }
 
    // Output resulting matrix
    cout << "Результирующая матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}
 