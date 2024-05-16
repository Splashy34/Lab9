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
    return 0;
}

