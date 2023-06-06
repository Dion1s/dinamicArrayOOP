#include "Array.h"

int main() {
    Array array;
    Array otherArray;
    Array secondArray;

    int choice = 0;
    int newSize = 0;
    int constant = 0;

    Array mergedArray;
    Array diffArray;
    Array sumArray;
    Array divArray;
    do {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "\t\t-Menu" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "1. Fill array" << std::endl;
        std::cout << "2. Size" << std::endl;
        std::cout << "3. Display array" << std::endl;
        std::cout << "4. Resize array" << std::endl;
        std::cout << "5. Sort array" << std::endl;
        std::cout << "6. Get min value" << std::endl;
        std::cout << "7. Get max value" << std::endl;
        std::cout << "8. Randomly fill array" << std::endl;
        std::cout << "9. Assign array" << std::endl;
        std::cout << "10. Merge arrays" << std::endl;
        std::cout << "11. Add arrays" << std::endl;
        std::cout << "12. Subtract arrays" << std::endl;
        std::cout << "13. Divide arrays" << std::endl;
        std::cout << "14. Product arrays" << std::endl;
        std::cout << "15. Increase array by constant" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            array.fillArray();
            break;
        case 2:
            std::cout << "Enter size: ";
            std::cin >> newSize;
            array.setArraySize(newSize);
            break;
        case 3:
            array.displayArray();
            break;
        case 4:
            std::cout << "Enter new size: ";
            std::cin >> newSize;
            array.resizeArray(newSize);
            break;
        case 5:
            array.sortArray();
            break;
        case 6:
            std::cout << "Min value: " << array.getMinValue() << std::endl;
            break;
        case 7:
            std::cout << "Max value: " << array.getMaxValue() << std::endl;
            break;
        case 8:
            array.randomFill();
            break;
        case 9:
            array = otherArray;
            break;
        case 10:
            mergedArray = array.mergeArrays(otherArray);
            mergedArray.displayArray();
            break;
        case 11:
            std::cout << "Enter size: ";
            std::cin >> newSize;
            secondArray.setArraySize(newSize);
            secondArray.fillArray();
             sumArray = array + secondArray;
            sumArray.displayArray();
            secondArray = Array();
            break;
        case 12:
            std::cout << "Enter size: ";
            std::cin >> newSize;
            secondArray.setArraySize(newSize);
            secondArray.fillArray();
             diffArray = array - secondArray;
            diffArray.displayArray();
            secondArray = Array();
            break;
        case 13:
            std::cout << "Enter size: ";
            std::cin >> newSize;
            secondArray.setArraySize(newSize);
            secondArray.fillArray();
             divArray = array / secondArray;
            divArray.displayArray();
            secondArray = Array();
            break;
        case 14:
            std::cout << "Enter size: ";
            std::cin >> newSize;
            secondArray.setArraySize(newSize);
            secondArray.fillArray();
            divArray = array * secondArray;
            divArray.displayArray();
            secondArray = Array();
            break;
        case 15:
            std::cout << "Enter constant: ";
            std::cin >> constant;
            array.increaseBy(constant);
            break;
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }

        std::cout << std::endl;

    } while (choice != 0);

    return 0;
}
