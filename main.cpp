#include "tasks.h"

using namespace std;

int main() {
    int task;
    cout << "Выберите номер задания: ";
    cin >> task;
    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            cout << "3.1 или 3.2? ";
            cin >> task;
            switch(task) {
                case 1:
                    task_3_1();
                    break;
                case 2:
                    task_3_2();
                    break;
                default:
                    cout << "Шалость удалась!";
            }
            break;
        case 4:
            task_4();
            break;
        default:
            cout << "Шалость удалась!";
    }
    return 0;
}
