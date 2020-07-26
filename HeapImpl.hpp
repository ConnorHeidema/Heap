#ifndef __HEAP_IMPL_HPP__
#define __HEAP_IMPL_HPP__

#include "Heap.hpp"

namespace Algorithm
{
	template <typename T, size_t SIZE>
	MaxHeap<T, SIZE>::MaxHeap()
	{

	}

	template <typename T, size_t SIZE>
	void MaxHeap<T, SIZE>::Insert(T item)
	{
		if (m_currentSize + 1 == SIZE) throw std::out_of_range("Cannot insert element from heap of max size");

		m_heapArray.at(m_currentSize) = item;
		TrickleUp_(m_currentSize);
		m_currentSize++;
	}


	template <typename T, size_t SIZE>
	T MaxHeap<T, SIZE>::Remove()
	{
		if (m_currentSize == 0) throw std::out_of_range("Cannot remove element from empty heap");

		T valueRemoved = std::move(m_heapArray.at(0));
		m_heapArray.at(0) = m_heapArray.at(m_currentSize - 1);
		TrickleDown_(0);
		m_currentSize--;
		return valueRemoved;
	}


	template <typename T, size_t SIZE>
	size_t MaxHeap<T, SIZE>::GetMaxSize()
	{
		return SIZE;
	}


	template <typename T, size_t SIZE>
	size_t MaxHeap<T, SIZE>::GetCurrentSize()
	{
		return m_currentSize;
	}

	// @todo DEBUG ONLY WHILE SOME FUNCTIONS ARE NOT COMPLETED! SHOULD REMOVE WHEN FINISHED DEBUGGING
	template <typename T, size_t SIZE>
	std::array<T, SIZE> MaxHeap<T, SIZE>::GetHeapArray()
	{
		return m_heapArray;
	}

	template <typename T, size_t SIZE>
	void MaxHeap<T, SIZE>::TrickleUp_(int const& currentIndex)
	{
		if (currentIndex == 0) return;

		if (m_heapArray.at((currentIndex - 1) / 2) < m_heapArray.at(currentIndex))
		{
			Swap_(currentIndex, (currentIndex - 1) / 2);
			TrickleUp_(currentIndex);
		}

		return;
	}

	template <typename T, size_t SIZE>
	void MaxHeap<T, SIZE>::TrickleDown_(int const& currentIndex)
	{
		if (currentIndex >= m_currentSize) return;

		int largerChildNodeIndex = m_currentSize >= (currentIndex + 1) * 2 &&
			(m_heapArray.at((currentIndex * 2) + 1) > m_heapArray.at((currentIndex + 1) * 2)) ?
				(currentIndex * 2) + 1 :
				(currentIndex + 1) * 2;

		if (m_heapArray.at(currentIndex) < m_heapArray.at(largerChildNodeIndex))
		{
			Swap_(currentIndex, largerChildNodeIndex);
			TrickleDown_(largerChildNodeIndex);
		}

		return;
	}

	template <typename T, size_t SIZE>
	void MaxHeap<T, SIZE>::Swap_(int const& firstIndex, int const& secondIndex)
	{
		T temporaryNode = std::move(m_heapArray.at(firstIndex));
		m_heapArray.at(firstIndex) = m_heapArray.at(secondIndex);
		m_heapArray.at(secondIndex) = temporaryNode;
	}
}

#endif