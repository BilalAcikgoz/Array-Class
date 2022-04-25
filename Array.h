#include <iostream>
using namespace std;

class Array
{
	private:
		int* data, size, capacity;
		int FindIndex(int number, int b = 0);
    public:
		Array(int user_capacity = 5);
		~Array();
		Array(const Array& copyArray);
		int GetSize() { return size; }
		int GetCapacity() { return capacity; }
		void AddItem(int number);
		void PrintItems();
		void RemoveIndexItem(int index);
		void RemoveItem(int number);
		void FindElement(int number, int b = 0);
};

Array::Array(int user_capacity)
{
	capacity = user_capacity;
	size = 0;
	data = new int[capacity];
	// cout << "Constructer created with capacity " << capacity << endl;
}

Array::~Array()
{
	delete[] data;
	// cout << "Array destroyed" << endl;
}

Array::Array(const Array& copyArray)
{
	capacity = copyArray.capacity;
	size = copyArray.size;
	data = new int[capacity];

	for (int i = 0; i < copyArray.size; i++)
		data[i] = copyArray.data[i];

	// cout << "Array copied to target." << endl;
}

void Array::AddItem(int number)
{
	if (size == capacity)
	{
		capacity = capacity * 2;
		int* temp_data = new int[capacity];

		for (int i = 0; i < size; i++)
			temp_data[i] = data[i];

		delete[] data;
		data = temp_data;
	}

	data[size] = number;
	size++;
}

void Array::PrintItems()
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";

	cout << endl;
}

void Array::RemoveIndexItem(int index)
{
	if (index < 0 || index >= size)
		cout << "ERROR!No item at the index" << endl;

	int removeItem = data[index];

	for (int i = index; i < size; i++)
		data[i] = data[i + 1];

	size--;
	cout << "Item " << removeItem << " is deleted" << endl;
}

void Array::RemoveItem(int number)
{
	int counter = 0;
	for (int i = 0; i <= size; i++)
	{
		if (data[i] == number)
		{
			int removeItem = data[i];
			for (int j = i; j < size; j++)
				data[j] = data[j + 1];
			
			counter += 1;
			i -= 1;
		}
	}

	cout << counter << " items (" << number << ") " << "are deleted from the array" << endl;
	size -= counter;
}

int Array::FindIndex(int number, int index) {
	for (int i = index; i < size; i++) {
		if (data[i] == number) {
			return i;
		}
	}
	return -1;
}


void Array::FindElement(int number, int index) {
	int result = FindIndex(number, index);
	if (result != -1) {
		cout << number << "found at index" << result << endl;
	}
	else {
		cout << number << "not found in the array" << endl;
	}
}