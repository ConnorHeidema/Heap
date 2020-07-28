#include "Heap.hpp"

#include <iostream>

int main(int argc, char** argv)
{
	Algorithm::Heap<int, 10, Algorithm::HeapType_t::MIN> heap;
	heap.Insert(55);
	heap.Insert(45);
	heap.Insert(37);
	heap.Insert(70);
	heap.Insert(7);
	std::cout << std::endl << heap.Remove() << std::endl;
}