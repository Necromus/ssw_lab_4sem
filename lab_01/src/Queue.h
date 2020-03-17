#ifndef QUEUE_H
#define QUEUE_H

using namespace std;
template<class T>

class Queue
{
private:
	int sizes;
	int count = 0;
	T* Queue1;
public:
	Queue();
	~Queue();
	void push(T t1);
	T pop();
	T peek();
	T size();
	void delete_minus_elements();
	void delete_diapazon(int start, int end);
	void out();

	friend bool operator == (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		if (queue1.count == queue2.count)
		{
			int i = 0;
			do
			{
				if (queue1.Queue1[i] != queue2.Queue1[i])
					return false;
				i++;
			} while ((queue1.Queue1[i] == queue2.Queue1[i]) && (i < queue1.count));
			return true;
		}
		return false;
	};

	friend bool operator != (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		return !(queue1 == queue2);
	};

	friend bool operator > (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		int i = 0;
		if (queue1.count >= queue2.count)
		{
			do
			{
				if (queue1.Queue1[i] < queue2.Queue1[i])
					return false;
				else if (queue1.Queue1[i] > queue2.Queue1[i])
					return true;
				i++;
			} while ((queue1.Queue1[i] == queue2.Queue1[i]) && (i < queue2.count));
			if (queue1.count > queue2.count)
				return true;
		}
		i = 0;
		if (queue1.count < queue2.count)
		{
			do
			{
				if (queue1.Queue1[i] < queue2.Queue1[i])
					return false;
				else if (queue1.Queue1[i] > queue2.Queue1[i])
					return true;
				i++;
			} while ((queue1.Queue1[i] == queue2.Queue1[i]) && (i < queue1.count));
		}
		return false;
	};

	friend bool operator < (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		int i = 0;
		if (queue1.count >= queue2.count)
		{
			do
			{
				if (queue1.Queue1[i] < queue2.Queue1[i])
					return true;
				else if (queue1.Queue1[i] > queue2.Queue1[i])
					return false;
				i++;
			} while ((queue1.Queue1[i] == queue2.Queue1[i]) && (i < queue2.count));
		}
		i = 0;
		if (queue1.count <= queue2.count)
		{
			do
			{
				if (queue1.Queue1[i] < queue2.Queue1[i])
					return true;
				else if (queue1.Queue1[i] > queue2.Queue1[i])
					return false;
				i++;
			} while ((queue1.Queue1[i] == queue2.Queue1[i]) && (i < queue1.count));
			if (queue1.count < queue2.count)
				return true;
		}
		return false;
	};

	friend bool operator <= (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		return !(queue1 > queue2);
	};

	friend bool operator >= (const Queue<T>& queue1, const Queue<T>& queue2)
	{
		return !(queue1 < queue2);
	};
};

template <typename T>
Queue<T>::Queue()
{
	sizes = 0;
	Queue1 = new T[0];
};

template <typename T>
Queue<T>::~Queue()
{
	delete[] Queue1;
};

template<typename T>
void Queue<T>::out()
{
	for (int i = 0; i < count; i++)
		cout << Queue1[i] << " ";
	cout << endl;
};

template <typename T>
void Queue<T>::push(T t1)
{
	T* p1;
	p1 = new T [sizes + 1];
	for (int i = 0; i < sizes; i++)
		p1[i] = Queue1[i];
	p1[sizes] = 0;
	delete[] Queue1;
	Queue1 = p1;
	sizes++;
	Queue1[count] = t1;
	count++;
};

template <typename T>
T Queue<T>::pop()
{
	if (sizes > 0)
	{
		T* p2;
		p2 = new T[sizes - 1];
		for (int i = 0; i < sizes - 1; i++)
			p2[i] = Queue1[i + 1];
		delete[] Queue1;
		Queue1 = p2;
		sizes--;
	}
	else throw std::out_of_range("Queue: empty");
	count--;
};

template <typename T>
T Queue<T>::peek()
{
	if (count > 0)
	{
		return Queue1[0];
	}
	else std::out_of_range("Queue: empty");
};

template <typename T>
T Queue<T>::size()
{
	return count;
}

template <typename T>
void Queue<T>::delete_minus_elements()
{
	for (int i = 0; i < count; i++)
	{
		if (Queue1[i] < 0)
		{
			for (int j = i; j < count - 1; j++)
				Queue1[j] = Queue1[j + 1];
			count--;
			i--;
		}
	}
};

template <typename T>
void Queue<T>::delete_diapazon(int start, int end)
{
	for (int i = 0; i < sizes; i++)
	{
		if ((Queue1[i] >= start) && (Queue1[i] <= end))
		{
			for (int j = i; j < count - 1; j++)
			{
				Queue1[j] = Queue1[j + 1];
			}
			count--;
			i--;
		}
	}
};
#endif