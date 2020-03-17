#ifndef VECTOR_H
#define VECTOR_H

using namespace std;
template <class T>

class Vector
{
private:
	int count = 0;
	int sizes;
	T*Vector1;
public:
	Vector();
	~Vector();
	void push(T t1);
	T pop();
	void delete_minus_elements();
	T& at(int index);
	T size();
	T peek();
	void delete_diapazon(int start, int end);
	void out();
	

	friend bool operator == (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		if (vec1.count == vec2.count)
		{
			int i = 0;
			do
			{
				if (vec1.Vector1[i] != vec2.Vector1[i])
					return false;
				i++;
			} while ((vec1.Vector1[i] == vec2.Vector1[i]) && (i < vec1.count));
			return true;
		}
		return false;
	};

	friend bool operator != (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		return !(vec1 == vec2);
	};

	friend bool operator > (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		int i = 0;
		if (vec1.count >= vec2.count)
		{
			do
			{
				if (vec1.Vector1[i] < vec2.Vector1[i])
					return false;
				else if (vec1.Vector1[i] > vec2.Vector1[i])
					return true;
				i++;
			} while ((vec1.Vector1[i] == vec2.Vector1[i]) && (i < vec2.count));
			if (vec1.count > vec2.count)
				return true;
		}
		i = 0;
		if (vec1.count < vec2.count)
		{
			do
			{
				if (vec1.Vector1[i] < vec2.Vector1[i])
					return false;
				else if (vec1.Vector1[i] > vec2.Vector1[i])
					return true;
				i++;
			} while ((vec1.Vector1[i] == vec2.Vector1[i]) && (i < vec1.count));
		}
		return false;
	};

	friend bool operator < (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		int i = 0;
		if (vec1.count >= vec2.count)
		{
			do
			{
				if (vec1.Vector1[i] < vec2.Vector1[i])
					return true;
				else if (vec1.Vector1[i] > vec2.Vector1[i])
					return false;
				i++;
			} while ((vec1.Vector1[i] == vec2.Vector1[i]) && (i < vec2.count));
		}
		i = 0;
		if (vec1.count <= vec2.count)
		{
			do
			{
				if (vec1.Vector1[i] < vec2.Vector1[i])
					return true;
				else if (vec1.Vector1[i] > vec2.Vector1[i])
					return false;
				i++;
			} while ((vec1.Vector1[i] == vec2.Vector1[i]) && (i < vec1.count));//ошибка
			if (vec1.count < vec2.count)
				return true;
		}
		return false;
	};

	friend bool operator <= (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		return !(vec1 > vec2);
	};
	
	friend bool operator >= (const Vector<T>& vec1, const Vector<T>& vec2)
	{
		return !(vec1 < vec2);
	};
	
};

template <typename T>
Vector<T>::Vector()
{
	sizes = 0;
	Vector1 = new T [0];
};

template <typename T>
Vector<T>::~Vector()
{
	delete[] Vector1;
};

template <typename T>
void Vector<T>::push(T t1)
{
	T* p1;
	p1 = new T[sizes + 1];
	for (int i = 0; i < sizes; i++)
		p1[i] = Vector1[i];
	p1[sizes] = 0;
	delete[] Vector1;
	Vector1 = p1;
	sizes++;
	Vector1[count] = t1;
	count++;
};

template<typename T>
void Vector<T>::out()
{
	for (int i = 0; i < count; i++)
		cout << Vector1[i] << " ";
	cout << endl;
};

template <typename T>
T Vector<T>::pop()
{
	if (sizes > 0)
	{
		T* p2;
		p2 = new T[sizes - 1];
		for (int i = 0; i < sizes - 1; i++)
			p2[i] = Vector1[i];
		delete[] Vector1;
		Vector1 = p2;
		sizes--;
	}
	else throw std::out_of_range("vector: empty");
	count--;
};

template <typename T>
T& Vector<T>::at(int index)
{
	if ((index < count) && (index >= 0))
		return Vector1[index];
	else throw std::range_error("vector: out of range");	
};

template <typename T>
T Vector<T>::peek()
{
	if (count > 0)
	{
		return Vector1[count];
	}
	else throw std::out_of_range("vector: empty");
};

template <typename T>
T Vector<T>::size()
{
	return count;
};

template <typename T>
void Vector<T>::delete_minus_elements()
{
	for (int i = 0; i < count; i++)
	{
		if (Vector1[i] < 0)
		{
			for (int j = i; j < count - 1; j++)
				Vector1[j] = Vector1[j + 1];
			count--;
			i--;
		}
	}
};

template <typename T>
void Vector<T>::delete_diapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Vector1[i] >= start) && (Vector1[i] <= end))
		{
			for (int j = i; j < count - 1; j++)
			{
				Vector1[j] = Vector1[j + 1];
			}
			count--;
			i--;
		}
	}
};
#endif 