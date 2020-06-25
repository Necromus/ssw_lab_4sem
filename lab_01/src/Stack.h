#ifndef STACK_H
#define STACK_H

using namespace std;
template<class T>

class Stack
{
private:
	unsigned int count { 0 };
	unsigned int size { 20 };
	T* Buffer;
public:
	Stack();
	~Stack();
	T pop();
	T peek();
	T scale();
	void vyvod(int index);
	void push(T t1);
	void out();
	void delete_minus_elements();
	void delete_elements_in_diapason(int start, int end);


	bool operator == (const Stack<T>& m2)
	{
		if (count == m2.count)
		{
			int i = count;
			do
			{
				if (Buffer[i] != m2.Buffer[i]) return false;
				i--;
			} while ((Buffer[i] == m2.Buffer[i]) && (i != 0));
			return true;
		}
		else return false;
	};

	bool operator !=(const Stack<T>& m2)
	{
		return !(*this == m2);
	};

	bool operator > (const Stack<T>& m2)
	{
		int i = count - 1;
		int j = m2.count - 1;
		if (count >= m2.count)
		{
			do
			{
				if (Buffer[i] < m2.Buffer[j]) return false;
				else if (Buffer[i] > m2.Buffer[j]) return true;
				i--;
				j--;
			} while ((Buffer[i] == m2.Buffer[j]) && (j != 0));
			if (count > m2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (Buffer[i] < m2.Buffer[j]) return false;
				else if (Buffer[i] > m2.Buffer[j]) return true;
				i--;
				j--;
			} while ((Buffer[i] == m2.Buffer[j]) && (i != 0));
			return false;
		}

	};

	bool operator < (const Stack<T>& struct2)
	{
		int i = count - 1;
		int j = struct2.count - 1;
		if (count >= struct2.count)
		{

			do
			{
				if (Buffer[i] < struct2.Buffer[j]) return true;
				else if (Buffer[i] > struct2.Buffer[i]) return false;
				i--;
				j--;
			} while ((Buffer[i] == struct2.Buffer[i]) && (i != 0));
			if (count > struct2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (Buffer[i] < struct2.Buffer[j]) return true;
				else if (Buffer[i] > struct2.Buffer[j]) return false;
				i--;
				j--;
			} while ((Buffer[i] == struct2.Buffer[j]) && (j != 0));
			return true;
		}

	};

	bool operator <= (const Stack<T>& m2)
	{
		return !(*this > m2);
	};

	bool operator >= (const Stack<T>& m2)
	{
		return !(*this < m2);
	};
};

template<typename T>
Stack<T>::Stack()
{
	Buffer = new T[size];
};

template<typename T>
Stack<T>::~Stack()
{
	delete[] Buffer;
};

template<typename T>
void Stack<T>::vyvod(int index)
{
	if (index > size)
		throw std::range_error("No this element");
	cout << Buffer[index] << " ";
}

template<typename T>
void Stack<T>::push(T t1)
{
	if (size == count)
		size++;
	T* Array;
	Array = new T[size];
	for (int i = 0; i < size; i++)
		Array[i] = Buffer[i];
	delete[] Buffer; 
	Array[count] = t1;
	Buffer = Array;
	count++;
};

template<typename T>
void Stack<T>::out()
{
	for (int i = 0; i < count; i++)
		cout << Buffer[i] << " ";
	cout << endl;
};

template<typename T>
T Stack<T>::pop()
{
	if (size > 0)
	{
		size--;
		T* Array;
		Array = new T[size];
		for (int i = 0; i < size; i++)
			Array[i] = Buffer[i];
		delete[] Buffer;
		Buffer = Array;
	}
	else throw std::out_of_range("vector: empty");
	count--;
	return Buffer[count];
};

template<typename T>
T Stack<T>::peek()
{
	if (count > 0)
	{
		return Buffer[count];
	}
	else throw std::out_of_range("stack: empty");
};

template<typename T>
T Stack<T>::scale()
{
	return count;
};

template<typename T>
void Stack<T>::delete_minus_elements()
{
	for (int i = 0; i < count; i++)
	{
		if (Buffer[i] < 0)
		{
			for (int j = i; j < count - 1; j++)
				Buffer[j] = Buffer[j + 1];
			count--;
			i--;
		}
	}
};

template<typename T>
void Stack<T>::delete_elements_in_diapason(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Buffer[i] >= start) && (Buffer[i] <= end))
		{
			for (int j = i; j < count - 1; j++)
			{
				Buffer[j] = Buffer[j + 1];
			}
			count--;
			i--;
		}
	}
};
#endif