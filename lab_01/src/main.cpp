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
        Stack <int> stack1;
        Queue <int> queue1;
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

        Vector<float> vector2;
        Queue<float> queue2;
        Stack<float> stack2;
        Vector<float> vector3;
        Queue<float> queue3;
        Stack<float> stack3;
        cout << "Vector2: \n";
        for (int i = 0; i < 20; i++)
        {
            vector2.push(t1[i]);
            vector2.vyvod(i);
        }
        cout << endl;
        cout << "Queue2: \n";
        for (int i = 0; i < 20; i++)
        {
            queue2.push(t3[i]);
            queue2.vyvod(i);
        }
        cout << endl;
        cout << "Stack2: \n";
        for (int i = 0; i < 20; i++)
        {
            stack2.push(t3[i]);
            stack2.vyvod(i);
        }
        cout << endl;
        cout << "Vector3: \n";
        for (int i = 0; i < 25; i++)
        {
            vector3.push(t3[i]);
            vector3.vyvod(i);
        }
        cout << endl;
        cout << "Queue3: \n";
        for (int i = 0; i < 25; i++)
        {
            queue3.push(t3[i]);
            queue3.vyvod(i);
        }
        cout << endl;
        cout << "Stack3: \n";
        for (int i = 0; i < 25; i++)
        {
            stack3.push(t3[i]);
            stack3.vyvod(i);
        }
        cout << endl;

        if (vector2 == vector3)
            cout << "Vector2 is equally to vector3\n";
        else cout << "Vector2 is not equally to vector3\n";

        if (vector2 <= vector3)
            cout << "Vector2 is equal to or less than to vector3\n";
        else cout << "Vector2 is not equal to or not less than vector3\n";

        if (vector2 >= vector3)
            cout << "Vector2 is equal or greater than to vector3\n";
        else cout << "Vector2 is not equal to or not greater than vector3\n";

        if (vector2 != vector3)
            cout << "Vector2 is not equally to vector3\n";
        else cout << "Vector2 is equally to vector3\n";

        if (vector2 > vector3)
            cout << "Vector2 is greater than to vector3\n";
        else cout << "Vector2 is not greater than to vector3\n";

        if (vector2 < vector3)
            cout << "Vector2 is less than to vector3\n";
        else cout << "Vector2 is not less than to vector3\n";

        if (queue2 == queue3)
            cout << "Queue2 is equally to queue3\n";
        else cout << "Queue2 is not equally to queue3\n";

        if (queue2 <= queue3)
            cout << "Queue2 is equal to or less than to queue3\n";
        else cout << "Queue2 is not equal to or not less than queue3\n";

        if (queue2 >= queue3)
            cout << "Queue2 is equal or greater than to queue3\n";
        else cout << "Queue2 is not equal to or not greater than queue3\n";

        if (queue2 != queue3)
            cout << "Queue2 is not equally to queue3\n";
        else cout << "Queue2 is equally to queue3\n";

        if (queue2 > queue3)
            cout << "Queue2 is greater than to queue3\n";
        else cout << "Queue2 is not greater than to queue3\n";

        if (queue2 < queue3)
            cout << "Queue2 is less than to queue3\n";
        else cout << "Queue2 is not less than to queue3\n";

        if (stack2 == stack3)
            cout << "Stack2 is equally to stack3\n";
        else cout << "Stack2 is not equally to stack3\n";

        if (stack2 <= stack3)
            cout << "Stack2 is equal to or less than to stack3\n";
        else cout << "Stack2 is not equal to or not less than stack3\n";

        if (stack2 >= stack3)
            cout << "Stack2 is equal or greater than to stack3\n";
        else cout << "Stack2 is not equal to or not greater than stack3\n";

        if (stack2 != stack3)
            cout << "Stack2 is not equally to stack3\n";
        else cout << "Stack2 is equally to stack3\n";

        if (stack2 > stack3)
            cout << "Stack2 is greater than to stack3\n";
        else cout << "Stack2 is not greater than to stack3\n";

        if (stack2 < stack3)
            cout << "Stack2 is less than to stack3\n";
        else cout << "Stack2 is not less than to stack3\n";

        vector<float> stl_vector1;
        queue <float> stl_queue1;
        stack <float> stl_stack1;
        vector<float> stl_vector2;
        queue <float> stl_queue2;
        stack <float> stl_stack2;

        for (int i = 0; i < 20; i++)
        {
            stl_vector1.push_back(t3[i]);
        }
        for (int i = 0; i < 20; i++)
        {
            stl_queue1.push(t3[i]);
        }
        for (int i = 0; i < 20; i++)
        {
            stl_stack1.push(t3[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_vector2.push_back(t3[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_queue2.push(t3[i]);
        }
        for (int i = 0; i < 25; i++)
        {
            stl_stack2.push(t3[i]);
        }
        cout << "STL container:\n";
     
        if (stl_vector1 == stl_vector2)
            cout << "Vector2 is equally to vector3\n";
        else cout << "Vector2 is not equally to vector3\n";

        if (stl_vector1 <= stl_vector2)
            cout << "Vector2 is equal to or less than to vector3\n";
        else cout << "Vector2 is not equal to or not less than vector3\n";

        if (stl_vector1 >= stl_vector2)
            cout << "Vector2 is equal or greater than to vector3\n";
        else cout << "Vector2 is not equal to or not greater than vector3\n";

        if (stl_vector1 != stl_vector2)
            cout << "Vector2 is not equally to vector3\n";
        else cout << "Vector2 is equally to vector3\n";

        if (stl_vector1 > stl_vector2)
            cout << "Vector2 is greater than to vector3\n";
        else cout << "Vector2 is not greater than to vector3\n";

        if (stl_vector1 < stl_vector2)
            cout << "Vector2 is less than to vector3\n";
        else cout << "Vector2 is not less than to vector3\n";
        ///////////////////////////////////////////////////////////////
        if (stl_queue1 == stl_queue2)
            cout << "Queue2 is equally to queue3\n";
        else cout << "Queue2 is not equally to queue3\n";

        if (stl_queue1 <= stl_queue2)
            cout << "Queue2 is equal to or less than to queue3\n";
        else cout << "Queue2 is not equal to or not less than queue3\n";

        if (stl_queue1 >= stl_queue2)
            cout << "Queue2 is equal or greater than to queue3\n";
        else cout << "Queue2 is not equal to or not greater than queue3\n";

        if (stl_queue1 != stl_queue2)
            cout << "Queue2 is not equally to queue3\n";
        else cout << "Queue2 is equally to queue3\n";

        if (stl_queue1 > stl_queue2)
            cout << "Queue2 is greater than to queue3\n";
        else cout << "Queue2 is not greater than to queue3\n";

        if (stl_queue1 < stl_queue2)
            cout << "Queue2 is less than to queue3\n";
        else cout << "Queue2 is not less than to queue3\n";
        //////////////////////////////////////////////////////////////////
        if (stl_stack1 == stl_stack2)
            cout << "Stack2 is equally to stack3\n";
        else cout << "Stack2 is not equally to stack3\n";

        if (stl_stack1 <= stl_stack2)
            cout << "Stack2 is equal to or less than to stack3\n";
        else cout << "Stack2 is not equal to or not less than stack3\n";

        if (stl_stack1 >= stl_stack2)
            cout << "Stack2 is equal or greater than to stack3\n";
        else cout << "Stack2 is not equal to or not greater than stack3\n";

        if (stl_stack1 != stl_stack2)
            cout << "Stack2 is not equally to stack3\n";
        else cout << "Stack2 is equally to stack3\n";

        if (stl_stack1 > stl_stack2)
            cout << "Stack2 is greater than to stack3\n";
        else cout << "Stack2 is not greater than to stack3\n";

        if (stl_stack1 < stl_stack2)
            cout << "Stack2 is less than to stack3\n";
        else cout << "Stack2 is not less than to stack3\n";
    }

    catch (const std::exception & exp) 
    {
        cout << exp.what() << endl;
    }

    return 0;
}