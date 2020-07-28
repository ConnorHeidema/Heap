#ifndef __HEAP_IMPL_HPP__
#define __HEAP_IMPL_HPP__

#include "Heap.hpp"

namespace Algorithm
{
	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	Heap<T, SIZE, HEAP_TYPE>::Heap()
	{

	}

	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	void Heap<T, SIZE, HEAP_TYPE>::Insert(T item)
	{
		if (m_currentSize + 1 == SIZE) throw std::out_of_range("Cannot insert element from heap of max size");

		m_heapArray.at(m_currentSize) = item;
		TrickleUp_(m_currentSize);
		m_currentSize++;
	}


	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	T Heap<T, SIZE, HEAP_TYPE>::Remove()
	{
		if (m_currentSize == 0) throw std::out_of_range("Cannot remove element from empty heap");

		T valueRemoved = std::move(m_heapArray.at(0));
		m_heapArray.at(0) = m_heapArray.at(m_currentSize - 1);
		TrickleDown_(0);
		m_currentSize--;
		return valueRemoved;
	}


	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	size_t Heap<T, SIZE, HEAP_TYPE>::GetMaxSize()
	{
		return SIZE;
	}


	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	size_t Heap<T, SIZE, HEAP_TYPE>::GetCurrentSize()
	{
		return m_currentSize;
	}

	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	void Heap<T, SIZE, HEAP_TYPE>::TrickleUp_(int const& currentIndex)
	{
		if (currentIndex == 0) return;

		if (m_heapArray.at((currentIndex - 1) / 2) < m_heapArray.at(currentIndex) &&
			HEAP_TYPE == HeapType_t::MAX ||
			m_heapArray.at((currentIndex - 1) / 2) > m_heapArray.at(currentIndex) &&
			HEAP_TYPE == HeapType_t::MIN)
		{
			Swap_(currentIndex, (currentIndex - 1) / 2);
			TrickleUp_((currentIndex - 1) / 2);
		}

		return;
	}

	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	void Heap<T, SIZE, HEAP_TYPE>::TrickleDown_(int const& currentIndex)
	{
		if (currentIndex >= m_currentSize) return;

		if (HEAP_TYPE == HeapType_t::MAX)
		{
			int largerChildNodeIndex = m_currentSize >= (currentIndex + 1) * 2 &&
				(m_heapArray.at((currentIndex * 2) + 1) > m_heapArray.at((currentIndex + 1) * 2)) ?
					(currentIndex * 2) + 1 :
					(currentIndex + 1) * 2;

			if (m_heapArray.at(currentIndex) < m_heapArray.at(largerChildNodeIndex))
			{
				Swap_(currentIndex, largerChildNodeIndex);
				TrickleDown_(largerChildNodeIndex);
			}
		}
		else if (HEAP_TYPE == HeapType_t::MIN)
		{
			int smallerChildNodeIndex = m_currentSize <= (currentIndex + 1) * 2 &&
				(m_heapArray.at((currentIndex * 2) + 1) < m_heapArray.at((currentIndex + 1) * 2)) ?
					(currentIndex * 2) + 1 :
					(currentIndex + 1) * 2;

			if (m_heapArray.at(currentIndex) > m_heapArray.at(smallerChildNodeIndex))
			{
				Swap_(currentIndex, smallerChildNodeIndex);
				TrickleDown_(smallerChildNodeIndex);
			}
		}

		return;
	}

	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE>
	void Heap<T, SIZE, HEAP_TYPE>::Swap_(int const& firstIndex, int const& secondIndex)
	{
		T temporaryNode = std::move(m_heapArray.at(firstIndex));
		m_heapArray.at(firstIndex) = m_heapArray.at(secondIndex);
		m_heapArray.at(secondIndex) = temporaryNode;
	}
} // namespace Algorithm

#endif