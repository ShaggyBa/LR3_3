#include <iostream>
#include <cmath>

class ArrayProcessor {
private:
    int* arr;
    int size;

public:
    ArrayProcessor(int* array, int arraySize) {
        arr = new int[arraySize];
        size = arraySize;
        for (int i = 0; i < size; i++) {
            arr[i] = array[i];
        }
    }

    ~ArrayProcessor() {
        delete[] arr;
    }

    double calculateGeometricMean() {
        double product = 1.0;
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (arr[i] > 0) {
                product *= arr[i];
                count++;
            }
        }

        if (count == 0) {
            return 0.0; // Если все элементы нулевые, вернем 0
        }

        return pow(product, 1.0 / count);
    }
};

void runWhiteBoxTests() {
    // Тест 1: Проверка для массива, содержащего только ненулевые элементы
    int arr1[] = { 2, 4, 6, 8 };
    ArrayProcessor arrayProcessor1(arr1, 4);
    double result1 = arrayProcessor1.calculateGeometricMean();
    std::cout << "Тест 1: Ожидаемый результат = 4.42673, Фактический результат = " << result1 << std::endl;

    // Тест 2: Проверка для массива, содержащего только нулевые элементы
    int arr2[] = { 0, 0, 0, 0 };
    ArrayProcessor arrayProcessor2(arr2, 4);
    double result2 = arrayProcessor2.calculateGeometricMean();
    std::cout << "Тест 2: Ожидаемый результат = 0.0, Фактический результат = " << result2 << std::endl;

    // Тест 3: Проверка для массива, содержащего как ненулевые, так и нулевые элементы
    int arr3[] = { 1, 0, 3, 0, 5 };
    ArrayProcessor arrayProcessor3(arr3, 5);
    double result3 = arrayProcessor3.calculateGeometricMean();
    std::cout << "Тест 3: Ожидаемый результат = 2.46621, Фактический результат = " << result3 << std::endl;

    // Тест 4: Проверка для массива, содержащего отрицательные элементы
    int arr4[] = { -2, 4, -6, 8 };
    ArrayProcessor arrayProcessor4(arr4, 4);
    double result4 = arrayProcessor4.calculateGeometricMean();
    std::cout << "Тест 4: Ожидаемый результат = 5.65685, Фактический результат = " << result4 << std::endl;

    // Тест 5: Проверка для массива, содержащего один элемент
    int arr5[] = { 3 };
    ArrayProcessor arrayProcessor5(arr5, 1);
    double result5 = arrayProcessor5.calculateGeometricMean();
    std::cout << "Тест 5: Ожидаемый результат = 3.0, Фактический результат = " << result5 << std::endl;

    // Тест 6: Проверка для массива, содержащего только отрицательные элементы
    int arr6[] = { -1, -2, -3, -4 };
    ArrayProcessor arrayProcessor6(arr6, 4);
    double result6 = arrayProcessor6.calculateGeometricMean();
    std::cout << "Тест 6: Ожидаемый результат = 0, Фактический результат = " << result6 << std::endl;
}


int main() {
    int n;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;

    int* arr = new int[n];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    ArrayProcessor arrayProcessor(arr, n);
    double geometricMean = arrayProcessor.calculateGeometricMean();
    std::cout << "Среднее геометрическое ненулевых элементов: " << geometricMean << std::endl;

    delete[] arr;
    runWhiteBoxTests();
    return 0;
}

