
#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;

    void resize(int newCapacity)
    {
        int *newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 4)
    {
        data = new int[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void append(int value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
        if (size > 0 && size <= capacity / 4)
        {
            resize(capacity / 2);
        }
    }

    int get(int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    DynamicArray arr;

    arr.append(5);
    arr.append(10);
    arr.append(15);
    arr.append(20);
    arr.append(25);

    cout << "Array after appending elements: ";
    arr.print();

    arr.removeAt(1);
    cout << "After removing index 2 :: ";
    arr.print();

    cout << "Element at index 1 :: " << arr.get(1) << endl;

    arr.append(40);
    cout << "After appending 40 :: ";
    arr.print();


    cout<<endl<<"24CE027_yash Desai"<<endl;
    return 0;
}
