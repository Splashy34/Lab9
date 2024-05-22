#include <iostream>
#include <string>
#include "Tree.h"

class HashTree 
{
private:
	static const int size = 503;
	Tree hashTable[size];
	int hashFunc(int key) const
	{
		unsigned long hash = 0;
		hash = (hash * 37 + key) % size;
		return hash % size;
	}
public:
	HashTree();
	~HashTree();
	void add(int data);
	void remove(int data);
	void clear();
	bool contains(int data);
	int count();
	int* ToArray();
};

HashTree::HashTree()
{
}

HashTree::~HashTree()
{
	clear();
}

void HashTree::add(int data)
{
	int index = hashFunc(data);
	hashTable[index].add(data);
}

void HashTree::remove(int data)
{
	int index = hashFunc(data);
	hashTable[index].remove(data);
}

void HashTree::clear()
{
	for (int i = 0; i < size; i++)
	{
		hashTable[i].clear();
	}
}

bool HashTree::contains(int data)
{
	int index = hashFunc(data);
	return hashTable[index].contains(data);
}


int HashTree::count()
{
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		total += hashTable[i].count();
	}
	return total;
}

int* HashTree::ToArray()
{
	int total = count();
	int* array = new int[total];
	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		hashTable[i].fillArray(array, index);
	}
	return array;
}

int main()
{
    HashTree hashTree;
    int choice;
    int value;
    do
    {
        cout << "1. Add an element." << endl;
        cout << "2. Remove an element." << endl;
        cout << "3. Check if an element is in the hash tree." << endl;
        cout << "4. Size of the hash tree." << endl;
        cout << "5. Clear the hash tree." << endl;
        cout << "6. Show all elements." << endl;
        cout << "0. Exit." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element you want to add: " << endl;
            cin >> value;
            hashTree.add(value);
            break;
        case 2:
            cout << "Enter the element to remove: " << endl;
            cin >> value;
            hashTree.remove(value);
            break;
        case 3:
            cout << "Enter the element to check: " << endl;
            cin >> value;
            if (hashTree.contains(value))
            {
                cout << "The element is in the hash tree." << endl;
            }
            else
            {
                cout << "The element is not in the hash tree." << endl;
            }
            break;
        case 4:
            cout << "The size of the hash tree is: " << hashTree.count() << endl;
            break;
        case 5:
            hashTree.clear();
            cout << "The hash tree is cleared." << endl;
            break;
        case 6:
        {
            int* elements = hashTree.ToArray();
            int count = hashTree.count();
            cout << "Elements in the hash tree: ";
            for (int i = 0; i < count; ++i)
            {
                cout << elements[i] << " ";
            }
            cout << endl;
            delete[] elements;
            break;
        }
        case 0:
            break;
        default:
            cout << "Unknown command. Try again." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}

