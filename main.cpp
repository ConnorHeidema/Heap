#include "Heap.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	Algorithm::MaxHeap<int, 10> heap;
	heap.Insert(55);
	heap.Insert(45);
	heap.Insert(37);
	heap.Insert(70);
	heap.Insert(7);

	auto heapArray = heap.GetHeapArray();
	for (int i = 0; i < heap.GetCurrentSize(); i++)
	{
		std::cout << heapArray[i] << ",";
	}
	std::cout << std::endl << heap.Remove() << std::endl;
	auto heapArray5 = heap.GetHeapArray();
	for (int i = 0; i < heap.GetCurrentSize(); i++)
	{
		std::cout << heapArray5[i] << ",";
	}
	std::cout << std::endl << heap.Remove() << std::endl;
	auto heapArray2 = heap.GetHeapArray();
	for (int i = 0; i < heap.GetCurrentSize(); i++)
	{
		std::cout << heapArray2[i] << ",";
	}
	std::cout << std::endl << heap.Remove() << std::endl;
	auto heapArray3 = heap.GetHeapArray();
	for (int i = 0; i < heap.GetCurrentSize(); i++)
	{
		std::cout << heapArray3[i] << ",";
	}
	std::cout << std::endl << heap.Remove() << std::endl;

	auto heapArray4 = heap.GetHeapArray();
	for (int i = 0; i < heap.GetCurrentSize(); i++)
	{
		std::cout << heapArray4[i] << ",";
	}
	std::cout << std::endl << heap.Remove() << std::endl;
}