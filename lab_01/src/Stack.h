#pragma once
using namespace std;

class Stack
{
private:
	int count = 0;
	int size = 20;
	int* Stack;
	int* ptr = Stack;
public:
	void Buffer();
	void push(int t1);
	int pop();
	int peek();
	int countelement();
	void sort();
	void sortdiapazon(int start, int end);
};

void Stack::Buffer()
{
	Stack = new int[size];
};

void Stack::push(int t1)
{
	Stack[count] = t1;
	cout << Stack[count] << " ";
	count++;
};

int Stack::pop()
{
	if (size < 1)
		throw std::range_error("Выход за пределы массива");
	size--;
	count--;
	return Stack[count];
};

int Stack::peek()
{
	return Stack[count];
};

int Stack::countelement()
{
	return count;
};

void Stack::sort()
{
	for (int i = 0; i < count; i++)
	{
		if (Stack[i] < 0)
		{
			for (int j = i; j < count; j++)
				Stack[j] = Stack[j + 1];
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stack[i] << " ";
};

void Stack::sortdiapazon(int start, int end)
{
	for (int i = 0; i < count; i++)
	{
		if ((Stack[i] >= start) && (Stack[i] <= end))
		{
			for (int j = i; j < count; j++)
			{
				Stack[j] = Stack[j + 1];
			}
			count--;
			i--;
		}
	}

	for (int i = 0; i < count; i++)
		cout << Stack[i] << " ";
};