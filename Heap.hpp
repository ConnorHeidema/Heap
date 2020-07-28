#ifndef __HEAP_HPP__
#define __HEAP_HPP__

#include <array>

namespace Algorithm
{
	enum class HeapType_t
	{
		MAX,
		MIN
	};

	/**
	 * This heap needs to know how big it will be at instantiation with a template argument
	 *
	 */
	template <typename T, size_t SIZE, HeapType_t HEAP_TYPE = HeapType_t::MAX>
	class Heap
	{
	public:
		Heap();

		void Insert(T item);

		T Remove();

		size_t GetMaxSize();

		size_t GetCurrentSize();

	private:
		void TrickleUp_(int const& currentIndex);

		void TrickleDown_(int const& currentIndex);

		void Swap_(int const& firstIndex, int const& secondIndex);

		std::array<T, SIZE> m_heapArray;
		size_t m_currentSize = 0;
	};

}

#include "HeapImpl.hpp"
#endif