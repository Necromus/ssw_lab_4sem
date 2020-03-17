#include <iostream>
#include "generator.h"
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include <chrono>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) 
{
    
    try 
    {
        setlocale(LC_ALL, "RUS");
        int n;
        Vector <int> vector1;
        Vector <float> vector2;
        Stack <int> stack1;
        Stack <float> stack2;
        Queue <int> queue1;
        Queue <float> queue2;
        vector <int> stl_vector;
        stack <int> stl_stack;
        queue <int> stl_queue;
        Vector <int> vec1;
        Vector <int> vec2;

        cout << "Massive size(check time): ";
        cin >> n;

        auto t1 = generate<int>(n); // t1 is std::vector
        cout << "<TEST>" << endl;
        cout << "\t" << t1[0] << " | " << t1.size() << endl;
        cout << "";
        
        /*
        auto t2 = generate<string>(20);
        cout << "<TEST>" << endl;
        cout << "\t" << t2[0] << " | " << t2.size() << endl;
        */
        
        auto t3 = generate<float>(n);
        cout << "<TEST>" << endl;
        cout << "\t" << t3[0] << " | " << t3.size() << endl;
        
        cout << "Compare vector - push\n";
        auto start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            vector1.push(11);
        auto end1 = chrono::high_resolution_clock::now();
        auto res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_vector.push_back(11);
        auto end = chrono::high_resolution_clock::now();
        auto res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "vector = " << res_time1 << endl;
        cout << "stl_vector = " << res_time << endl;
        cout << endl;

        cout << "Compare vector - pop\n";
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            vector1.pop();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_vector.pop_back();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "vector = " << res_time1 << endl;
        cout << "stl_vector = " << res_time << endl;
        cout << endl;

        cout << "Compare stack - push\n";
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stack1.push(11);
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_stack.push(11);
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "stack = " << res_time1 << endl;
        cout << "stl_stack = " << res_time << endl;
        cout << endl;

        cout << "Compare stack - pop\n";
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stack1.pop();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_stack.pop();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "stack = " << res_time1 << endl;
        cout << "stl_stack = " << res_time << endl;
        cout << endl;

        cout << "Compare queue - push\n";
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            queue1.push(11);
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_queue.push(11);
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "queue = " << res_time1 << endl;
        cout << "stl_queue = " << res_time << endl;
        cout << endl;

        cout << "Compare queue - pop\n";
        start1 = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            queue1.pop();
        end1 = chrono::high_resolution_clock::now();
        res_time1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            stl_queue.pop();
        end = chrono::high_resolution_clock::now();
        res_time = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "queue = " << res_time1 << endl;
        cout << "stl_queue = " << res_time << endl;
        cout << endl;
    }
    catch (const std::exception & exp) 
    {
        cout << exp.what() << endl;
    }

    return 0;
}