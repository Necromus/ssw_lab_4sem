#include <iostream>
#include "generator.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    
    try 
    {
        setlocale(LC_ALL, "RUS");
        int mas;
        int str;
        int type;
        int operation;
        int close = 1;
        int elementint;
        float elementfloat;
        int arint;
        float arfloat;
        int start, end;
        Vector <int> vector1;
        Vector <float> vector2;
        Stack stack1;
        Queue queue1;

        cout << "С чем вы хотите работать?" << endl;
        cout << "1-Вектор\n2-Стек\n3-Очередь\n";
        cin >> str;
        cout << endl;

        cout << "какой тип данных использовать? 1-int 2-float(реализовано только в векторе в качестве примера): ";
        cin >> type;
        cout << endl;

        cout << "Введите количество элементво в массиве: ";
        cin >> mas;
        cout << endl;
        
        auto t1 = generate<int>(mas); // t1 is std::vector
        cout << "<TEST>" << endl;
        cout << "\t" << t1[0] << " | " << t1.size() << endl;
        cout << "";
        
        /*
        auto t2 = generate<string>(20);
        cout << "<TEST>" << endl;
        cout << "\t" << t2[0] << " | " << t2.size() << endl;
        */
        
        auto t3 = generate<float>(mas);
        cout << "<TEST>" << endl;
        cout << "\t" << t3[0] << " | " << t3.size() << endl;
        
        vector1.Buffer();
        vector2.Buffer();
        stack1.Buffer();
        queue1.Buffer();

        switch (str)
        {
        case 1:
            cout << "Элементы вектора:";
            if (type == 1)
            {
                for (int i = 0; i < mas; i++)
                    vector1.push(t1[i], i);
                cout << endl;
            }
            if (type == 2)
            {
                for (int i = 0; i < mas; i++)
                    vector2.push(t3[i], i);
                cout << endl;
            }
            
            while (close == 1)
            {
                cout << "Список операций:\n";
                cout << "1-push->Вставка элемента в структуру\n2-pop->Выталкивание элемента из структуры\n3-peek->Возврат вершины структуры(верхнего элемента)\n";
                cout << "4-at->Метод произвольного\n5-count->Возврат количества элементов в структуре\n6-Исключение из структуры всех элементов с отрицательными значениями\n";
                cout << "7-Исключение из структуры всех элементов подпадающих в заданный диапазонон\n8-Выход из структуры\n";
                cin >> operation;
                switch (operation)
                {
                case 1:
                    if (type == 1)
                    {
                        cout << "Введите элемент:";
                        cin >> elementint;
                        cout << endl;
                        vector1.push(elementint, mas + 1);
                        mas++;
                        cout << endl;
                    }
                    if (type == 2)
                    {
                        cout << "Введите элемент:";
                        cin >> elementfloat;
                        cout << endl;
                        vector2.push(elementfloat, mas + 1);
                        mas++;
                        cout << endl;
                    }
                    break;
                case 2:
                    if (type == 1)
                    {
                        arint = vector1.pop();
                        cout << arint << endl;
                        mas--;
                    }
                    if (type == 2)
                    {
                        arfloat = vector2.pop();
                        cout << arfloat << endl;
                        mas--;
                    }
                    break;
                case 3:
                    if (type == 1)
                    {
                        arint = vector1.peek();
                        cout << arint << endl;
                    }
                    if (type == 2)
                    {
                        arfloat = vector2.peek();
                        cout << arfloat << endl;
                    }
                    break;
                case 4:
                    if (type == 1)
                    {
                        cout << "Какой элемент вы хотите получить: ";
                        cin >> arint;
                        vector1.at(arint);
                    }
                    if (type == 2)
                    {
                        cout << "Какой элемент вы хотите получить: ";
                        cin >> arfloat;
                        vector2.at(arfloat);
                    }
                    break;
                case 5:
                    if (type == 1)
                    {
                        arint = vector1.countelement();
                        cout << arint << endl;
                    }
                    if (type == 2)
                    {
                        arfloat = vector2.countelement();
                        cout << arfloat << endl;
                    }
                    break;
                case 6:
                    if (type == 1)
                    {
                        vector1.sort();
                    }
                    if (type == 2)
                    {
                        vector2.sort();
                    }
                    break;
                case 7:
                    cout << "Введите начало диапазона: ";
                    cin >> start;
                    cout << endl;
                    cout << "Введите конец диапазона: ";
                    cin >> end;
                    cout << endl;
                    if (type == 1)
                    {
                        vector1.sortdiapazon(start, end);
                    }
                    if (type == 2)
                    {
                        vector2.sortdiapazon(start, end);
                    }
                    break;
                case 8:
                    close = 0;
                    break;
                }
            }
                break;

        case 2:
            cout << "Элементы стека:";
            for (int i = 0; i < mas; i++)
                stack1.push(t3[i]);
            cout << endl;
            while (close == 1)
            {
                cout << "Список операций:\n";
                cout << "1-push->Вставка элемента в структуру\n2-pop->Выталкивание элемента из структуры\n3-peek->Возврат вершины структуры(верхнего элемента)\n";
                cout << "4-count->Возврат количества элементов в структуре\n5-Исключение из структуры всех элементов с отрицательными значениями\n";
                cout << "6 - Исключение из структуры всех элементов подпадающих в заданный диапазонон\n7 - Выход из структуры\n";
                cin >> operation;
                switch (operation)
                {
                case 1:
                    cout << "Введите элемент:";
                    cin >> elementint;
                    cout << endl;
                    stack1.push(elementint);
                    cout << endl;
                    break;
                case 2:
                    arint = stack1.pop();
                    cout << arint << endl;
                    break;
                case 3:
                    arint = stack1.peek();
                    cout << arint << endl;
                    break;
                case 4:
                    arint = stack1.countelement();
                    cout << arint << endl;
                    break;
                case 5:
                    stack1.sort();
                    break;
                case 6:
                    cout << "Введите начало диапазона: ";
                    cin >> start;
                    cout << endl;
                    cout << "Введите конец диапазона: ";
                    cin >> end;
                    cout << endl;
                    stack1.sortdiapazon(start, end);
                    break;
                case 7:
                    close = 0;
                    break;
                }
            }
            break;

        case 3:
            cout << "Элементы очереди:";
            for (int i = 0; i < mas; i++)
                queue1.push(t3[i]);
            cout << endl;
            while (close == 1)
            {
                cout << "Список операций:\n";
                cout << "1-push->Вставка элемента в структуру\n2-pop->Выталкивание элемента из структуры\n3-peek->Возврат вершины структуры(верхнего элемента)\n";
                cout << "4-count->Возврат количества элементов в структуре\n5-Исключение из структуры всех элементов с отрицательными значениями\n";
                cout << "6 - Исключение из структуры всех элементов подпадающих в заданный диапазонон\n7 - Выход из структуры\n";
                cin >> operation;
                switch (operation)
                {
                case 1:
                    cout << "Введите элемент:";
                    cin >> elementint;
                    cout << endl;
                    queue1.push(elementint);
                    cout << endl;
                    break;
                case 2:
                    arint = queue1.pop();
                    cout << arint << endl;
                    break;
                case 3:
                    arint = queue1.peek();
                    cout << arint << endl;
                    break;
                case 4:
                    arint = queue1.countelement();
                    cout << arint << endl;
                    break;
                case 5:
                    queue1.sort();
                    break;
                case 6:
                    cout << "Введите начало диапазона: ";
                    cin >> start;
                    cout << endl;
                    cout << "Введите конец диапазона: ";
                    cin >> end;
                    cout << endl;
                    queue1.sortdiapazon(start, end);
                    break;
                case 7:
                    close = 0;
                    break;
                }
            }
            break;
        }
        
        
    }
    catch (const std::exception & exp) 
    {
        cout << exp.what() << endl;
    }

    return 0;
}