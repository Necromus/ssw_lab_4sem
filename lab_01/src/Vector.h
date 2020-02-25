#pragma once
using namespace std;
template <class T>

class Vector
{
private:
	int count = 0;
	int size = 20;
	T*Vector1;
	T* ptr = Vector1;
public:
	void Buffer();
	void push(T t1, int index);
	T pop();
	void sort();
	T at(int index);
	T countelement();
	T peek();
	void sortdiapazon(int start, int end);
};

template <typename T>
void Vector<T>::Buffer()
{
	Vector1 = new T [size];
};

template <typename T>
void Vector<T>::push(T t1, int index)
{
	count++;
	Vector1[index] = t1;
	cout << Vector1[index]<< " ";
};

template <typename T>
T Vector<T>::pop()
{
	if (size < 1)
		throw std::range_error("Выход за пределы массива");
	size--;
	count--;
	return Vector1[count];
};

template <typename T>
T Vector<T>::at(int index)
{
	if (index > size)
		throw std::range_error("Выход за пределы массива");
	cout << "Изменить значение " << index << " элемента: ";
	cin >> Vector1[index];
	return Vector1[index];
};

template <typename T>
T Vector<T>::peek()
{
	return Vector1[0];
};

template <typename T>
T Vector<T>::countelement()
{
	return count;
};

template <typename T>
void Vector<T>::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Vector1[i] < 0)
		{
			for (int j = i; j < count; j++)
				Vector1[j] = Vector1[j + 1];
			count--;
			i--;
		}
	}

	for(int i = 0; i < count; i++)
		cout << Vector1[i] << " ";
};

template <typename T>
void Vector<T>::sortdiapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Vector1[i] >= start) && (Vector1[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Vector1[j] = Vector1[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Vector1[i] << " ";
};