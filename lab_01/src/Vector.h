#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

template <class T>
class Vector
{
private:
	unsigned int count { 0 };
	unsigned int size { 20 };
	T*Buffer;
public:
	Vector();
	~Vector();
	T pop();
	T& at(unsigned int index);
	T scale();
	T peek();
	void vyvod(int index);
	void push(T t1);
	void out();
	void delete_minus_elements();
	void delete_elements_in_diapason(int start, int end);
	
	bool operator == (const Vector<T>& m2)
	{
		if (count == m2.count)
		{
			int i = 0;
			do
			{
				if (Buffer[i] != m2.Buffer[i]) return false;
				i++;
			} while ((Buffer[i] == m2.Buffer[i]) && (i < count));
			return true;
		};
		return false;
	};

	bool operator !=(const Vector<T>& m2)
	{
		return !(*this == m2);
	};

	bool operator > (const Vector<T>& m2)
	{
		int i = 0;
		if (count >= m2.count)
		{
			do
			{
				if (Buffer[i] < m2.Buffer[i]) return false;
				else if (Buffer[i] > m2.Buffer[i]) return true;
				i++;
			} while ((Buffer[i] == m2.Buffer[i]) && (i < (m2.count - 1)));
			if (count > m2.count) return true;
			else return false;
		}
		else
		{
			do
			{
				if (Buffer[i] < m2.Buffer[i]) return false;
				else if (Buffer[i] > m2.Buffer[i]) return true;
				i++;
			} while ((Buffer[i] == m2.Buffer[i]) && (i < m2.count));
		}
		return false;
	};

	bool operator < (const Vector<T>& m2)
	{

		int i = 0;
		if (count >= m2.count)
		{
			do
			{
				if (Buffer[i] < m2.Buffer[i]) return true;
				else if (Buffer[i] > m2.Buffer[i]) return false;
				i++;
			} while ((Buffer[i] == m2.Buffer[i]) && (i < m2.count));
			if (count > m2.count) return false;
			else return true;
		}
		else
		{
			do
			{
				if (Buffer[i] < m2.Buffer[i]) return true;
				else if (Buffer[i] > m2.Buffer[i]) return false;
				i++;
			} while ((Buffer[i] == m2.Buffer[i]) && (i < count));
		}
		return true;
	};

	bool operator <= (const Vector<T>& m2)
	{
		return !(*this > m2);
	};

	bool operator >= (const Vector<T>& m2)
	{
		return !(*this < m2);
	};

};

template <typename T>
Vector<T>::Vector()
{
	Buffer = new T[size];
};

template <typename T>
Vector<T>::~Vector()
{
	delete[] Buffer;
};

template<typename T>
void Vector<T>::vyvod(int index)
{
	if (index > size)
		throw std::range_error("No this element");
	cout << Buffer[index] << " ";
}
template <typename T>
void Vector<T>::push(T t1)
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
void Vector<T>::out()
{
	for (int i = 0; i < count; i++)
		cout << Buffer[i] << " ";
	cout << endl;
};

template <typename T>
T Vector<T>::pop()
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

template <typename T>
T& Vector<T>::at(unsigned int index)
{
	if ((index < count) && (index >= 0))
		return Buffer[index];
	else throw std::range_error("vector: out of range");	
};

template <typename T>
T Vector<T>::peek()
{
	if (count > 0)
	{
		return Buffer[count];
	}
	else throw std::out_of_range("vector: empty");
};

template <typename T>
T Vector<T>::scale()
{
	return count;
};

template <typename T>
void Vector<T>::delete_minus_elements()
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

template <typename T>
void Vector<T>::delete_elements_in_diapason(int start, int end)
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