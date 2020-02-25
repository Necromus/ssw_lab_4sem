#pragma once
using namespace std;
class Queue
{
private:
	int size = 20;
	int count = 0;
	int* ptr = Queue;
	int* Queue;
public:
	void Buffer();
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void sort();
	void sortdiapazon(int start, int end);
};

void Queue::Buffer()
{
	Queue = new int[size];
}

void Queue::push(int t1)
{
	Queue[count] = t1;
	cout << Queue[count] << " ";
	count++;
};

int Queue::pop()
{
	if (size < 1)
		throw std::range_error("Выход за пределы массива");
	size--;
	count--;
	return Queue[0];
};

int Queue::peek()
{
	return Queue[count];
};

int Queue::countelement()
{
	return count;
}

void Queue::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Queue[i] < 0)
		{
			for (int j = i; j < count; j++)
				Queue[j] = Queue[j + 1];
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queue[i] << " ";
};

void Queue::sortdiapazon(int start, int end)
{
	for (int i = 0; i < size; i++)
	{
		if ((Queue[i] >= start) && (Queue[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Queue[j] = Queue[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Queue[i] << " ";
};