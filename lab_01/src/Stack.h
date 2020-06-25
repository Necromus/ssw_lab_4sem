#ifndef STACK_H
#define STACK_H

using namespace std;
template<class T>

class Stack
{
private:
	int count = 0;
	int sizes;
	T* Stack1;
public:
	Stack();
	~Stack();
	void push(T t1);
	T pop();
	T peek();
	T size();
	void delete_minus_elements();
	void delete_diapazon(int start, int end);
	void out();

	friend bool operator == (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		if (stack1.count == stack2.count)
		{
			int i = 0;
			do
			{
				if (stack1.Stack1[i] != stack2.Stack1[i])
					return false;
				i++;
			} while ((stack1.Stack1[i] == stack2.Stack1[i]) && (i < stack1.count));
			return true;
		}
		return false;
	};

	friend bool operator != (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		return !(stack1 == stack2);
	};

	friend bool operator > (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		int i = 0;
		if (stack1.count >= stack2.count)
		{
			do
			{
				if (stack1.Stack1[i] < stack2.Stack1[i])
					return false;
				else if (stack1.Stack1[i] > stack2.Stack1[i])
					return true;
				i++;
			} while ((stack1.Stack1[i] == stack2.Stack1[i]) && (i < stack2.count));
			if (stack1.count > stack2.count)
				return true;
		}
		i = 0;
		if (stack1.count < stack2.count)
		{
			do
			{
				if (stack1.Stack1[i] < stack2.Stack1[i])
					return false;
				else if (stack1.Stack1[i] > stack2.Stack1[i])
					return true;
				i++;
			} while ((stack1.Stack1[i] == stack2.Stack1[i]) && (i < stack1.count));
		}
		return false;
	};

	friend bool operator < (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		int i = 0;
		if (stack1.count >= stack2.count)
		{
			do
			{
				if (stack1.Stack1[i] < stack2.Stack1[i])
					return true;
				else if (stack1.Stack1[i] > stack2.Stack1[i])
					return false;
				i++;
			} while ((stack1.Stack1[i] == stack2.Stack1[i]) && (i < stack2.count));
		}
		i = 0;
		if (stack1.count <= stack2.count)
		{
			do
			{
				if (stack1.Stack1[i] < stack2.Stack1[i])
					return true;
				else if (stack1.Stack1[i] > stack2.Stack1[i])
					return false;
				i++;
			} while ((stack1.Stack1[i] == stack2.Stack1[i]) && (i < stack1.count));
			if (stack1.count < stack2.count)
				return true;
		}
		return false;
	};

	friend bool operator <= (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		return !(stack1 > stack2);
	};

	friend bool operator >= (const Stack<T>& stack1, const Stack<T>& stack2)
	{
		return !(stack1 < stack2);
	};
};

template<typename T>
Stack<T>::Stack()
{
	sizes = 0;
	Stack1 = new T[0];
};

template<typename T>
Stack<T>::~Stack()
{
	delete[] Stack1;
};

template<typename T>
void Stack<T>::push(T t1)
{
	T* p1;
	p1 = new T[sizes + 1];
	for (int i = 0; i < sizes; i++)
		p1[i] = Stack1[i];
	p1[sizes] = 0;
	delete[] Stack1;
	Stack1 = p1;
	sizes++;
	Stack1[count] = t1;
	count++;
};

template<typename T>
void Stack<T>::out()
{
	for (int i = 0; i < count; i++)
		cout << Stack1[i] << " ";
	cout << endl;
};

template<typename T>
T Stack<T>::pop()
{
	if (sizes > 0)
	{
		T* p2;
		p2 = new T[sizes - 1];
		for (int i = 0; i < sizes - 1; i++)
			p2[i] = Stack1[i];
		delete[] Stack1;
		Stack1 = p2;
		sizes--;
	}
	else throw std::out_of_range("vector: empty");
	count--;
};

template<typename T>
T Stack<T>::peek()
{
	if (count > 0)
	{
		return Stack1[count - 1];
	}
	else throw std::out_of_range("stack: empty");
};

template<typename T>
T Stack<T>::size()
{
	return count;
};

template<typename T>
void Stack<T>::delete_minus_elements()
{
	for (int i = 0; i < count; i++)
	{
		if (Stack1[i] < 0)
		{
			for (int j = i; j < count - 1; j++)
				Stack1[j] = Stack1[j + 1];
			count--;
			i--;
		}
	}
};

template<typename T>
void Stack<T>::delete_diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Stack1[i] >= start) && (Stack1[i] <= end))
		{
			for (int j = i; j < count - 1; j++)
			{
				Stack1[j] = Stack1[j + 1];
			}
			count--;
			i--;
		}
	}
};
#endif