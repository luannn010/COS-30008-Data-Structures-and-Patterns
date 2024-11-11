
// COS30008, Tutorial 7, 2024

#pragma once

#include <iostream>
#include <functional>
#include <cassert>
#include <algorithm>

template<typename T>
using Cmp = std::function<bool(const T&, const T&)>;

template<typename T>
class BaseSorter
{
private:
    T* fCollection;
    size_t fSize;
    size_t fSwapCount;
    
public:
    BaseSorter( T* aCollection = nullptr, size_t aSize = 0 );
    virtual ~BaseSorter();
    
    size_t size() const noexcept;
    size_t getSwapCount() const noexcept;

    const T& operator[]( size_t aIndex ) const;
    void swap( size_t aLeftIndex, size_t aRightIndex );

    virtual void operator()( bool aPrintStage = true, Cmp<T> aIsOutOfOrder = std::greater{} ) noexcept
    {
        // intentionally empty
    }
    
    void printStage( size_t aIndent = 0 ) const noexcept;
};
