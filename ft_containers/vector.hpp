#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include <algorithm>
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector 
{
    
    public:
    // define types
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef typename Allocator::reference               reference;
    typedef typename Allocator::const_reference         const_reference;
    typedef typename Allocator::pointer                 pointer;
    typedef typename Allocator::const_pointer           const_pointer;
    typedef ft::random_access_iterator<pointer>         iterator;
    typedef ft::random_access_iterator<const_pointer>   const_iterator;
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    typedef typename allocator_type::difference_type    difference_type;
    typedef typename allocator_type::size_type          size_type;

    protected:
    // member val 
    T*              _m_start;
    T*              _m_finish;
    T*              _m_end_of_storage;
    allocator_type  _m_data_allocator;  

    public:
    // Constructs and Destroys
    vector (const allocator_type& alloc = allocator_type())
            : _m_start(0), _m_finish(0), _m_end_of_storage(0), _m_data_allocator(alloc) { }

    vector (size_type n, 
            const value_type& val = value_type(), 
            const allocator_type& alloc = allocator_type())
            : _m_start(0), _m_finish(0), _m_end_of_storage(0), _m_data_allocator(alloc)
    {
        _m_start = _m_data_allocator.allocate(n);
        _m_end_of_storage = _m_start + n;
        _m_finish = std::uninitialized_fill_n(_m_start, n, val);
    }

    template <typename InputIterator>
    vector (InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!(ft::is_integral<InputIterator>::value)>::type* = 0)
            : _m_start(0), _m_finish(0), _m_end_of_storage(0), _m_data_allocator(alloc)
    {
        size_type n = ft::distance(first, last);
        _m_start = _m_data_allocator.allocate(n);
        _m_end_of_storage = _m_start + n;
        _m_finish = std::uninitialized_copy(first, last, _m_start);
    }

    vector(const vector<T,Allocator>& x)
    {
        size_type n = x.size();
        _m_data_allocator = x.get_allocator();
        _m_start = _m_data_allocator.allocate(n);
        _m_end_of_storage = _m_start + n;
        _m_finish = std::uninitialized_copy(x.begin(), x.end(), _m_start);
    }

    ~vector()
    {
        destroy_element(_m_start, _m_finish);
        _m_data_allocator.deallocate(_m_start, capacity());
    }

    vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
    {
        if (this == &x) return (*this);
        size_type n = x.size();
        if (n > capacity())
        {
            pointer temp = allocate_copy(n, x.begin(), x.end());
            destroy_element(_m_start, _m_finish);
            _m_data_allocator.deallocate(_m_start, _m_end_of_storage - _m_start);
            _m_start = temp;
            _m_end_of_storage = _m_start + n;
        }
        else if (n <= capacity() && n > size())
        {
            relocate(x.begin(), x.end(), begin());
        }
        else
        {
            iterator iter(relocate(x.begin(), x.end(), begin()));
            destroy_element(iter, end());
        }
        _m_finish = _m_start + n;
        return (*this);
    }
    
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
        clear();
        insert(begin(), first, last);
    }

    void assign(size_type n, const T& u)
    {
        clear();
        insert(begin(), n, u);
    }

    allocator_type get_allocator() const
    {
        return (_m_data_allocator);
    }

    // iterators
    iterator begin()
    {
        return (iterator(_m_start));
    }

    const_iterator begin() const
    {
        return (const_iterator(_m_start));
    }

    iterator end()
    {
        return (iterator(_m_finish));
    }

    const_iterator end() const
    {
        return (const_iterator(_m_finish));
    }

    reverse_iterator rbegin()
    {
        return (reverse_iterator(_m_finish));
    }

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(_m_finish));
    }

    reverse_iterator rend()
    {
        return (reverse_iterator(_m_start));
    }

    const_reverse_iterator rend() const
    {
        return (reverse_iterator(_m_start));
    }

    // capacity
    size_type size() const
    {
        return (ft::distance(begin(), end()));
    }

    size_type max_size() const
    {
        return ((SIZE_MAX) / sizeof(value_type));
    }

    void resize (size_type n, value_type val = value_type())
    {
        if (n > capacity())
        {
            pointer temp;
            size_type size = this->size();
            temp = allocate_copy(n, begin(), end());
            std::uninitialized_fill_n(temp + size, n - size, val);
            _m_data_allocator.deallocate(_m_start, capacity());
            destroy_element(_m_start, _m_finish);
            _m_start = temp;
            _m_end_of_storage = _m_start + n;
        }
        else if (n <= capacity() && n > size())
            std::uninitialized_fill_n(_m_finish, n, val);
        else
            destroy_element(begin() + n, end());
        _m_finish = _m_start + n;
    }

    size_type capacity() const
    {
        return (_m_end_of_storage - _m_start);
    }

    bool empty() const
    {
        return (_m_start == _m_finish);
    }

    void reserve(size_type n)
    {
        size_type size = this->size();
        if (n > capacity())
        {
            pointer temp = allocate_copy(n, begin(), end());
            destroy_element(_m_start, _m_finish);
            _m_data_allocator.deallocate(_m_start, capacity());
            _m_start = temp;
            _m_finish = temp + size;
            _m_end_of_storage = _m_start + n;
        }
    }

    // element access
    reference operator[](size_type n)
    {
        return (*(begin() + n));
    }

    const_reference operator[](size_type n) const
    {
        return (*(begin() + n));
    }

    reference at(size_type n)
    {
        if (n < 0 || n > size())
            throw std::out_of_range("Out of Range!\n");
        return (*(begin() + n));
    }

    const_reference at(size_type n) const
    {
        if (n < 0 || n > size())
            throw std::out_of_range("Out of Range!\n");
        return (*(_m_start + n));
    }

    reference front()
    {
        return (*begin());
    }

    const_reference front() const
    {
        return (*begin());
    }

    reference back()
    {
        return (*(end() - 1));
    }

    const_reference back() const
    {
        return (*(end() - 1));
    }

    // element modify
    void push_back(const T& x)
    {
        if (size() == capacity())
        {
            pointer temp;
            size_type size = this->size();
            size_type new_capacity;
            if (capacity() < 3)
                new_capacity = 1;
            else
                new_capacity = capacity() + capacity() / 2;
            temp = allocate_copy(new_capacity, begin(), end());
            _m_data_allocator.deallocate(_m_start, capacity());
            destroy_element(_m_start, _m_finish);
            _m_start = temp;
            _m_finish = temp + size + 1;
            _m_data_allocator.construct(_m_finish - 1, x);
            _m_end_of_storage = _m_start + new_capacity;
        }
        else
        {
            _m_data_allocator.construct(_m_finish, x);
            _m_finish++;
        }
    }

    void pop_back()
    {
        _m_data_allocator.destroy(_m_finish - 1);
        _m_finish--;
    }
    
    iterator insert(iterator position, const T& x)
    {
        size_type add_size = ft::distance(begin(), position);
        if (size() + 1 <= capacity())
        {
            relocate_insert(position, end(), position + 1);
            _m_data_allocator.construct(_m_start + add_size, x);
            _m_finish++;
            return (position);
        }
        pointer temp;
        size_type size = this->size();
        size_type new_capacity = capacity() * 2;
        if (new_capacity == 0)
            new_capacity++;
        temp = allocate_copy(new_capacity, begin(), end());
        _m_data_allocator.deallocate(_m_start, capacity());
        destroy_element(_m_start, _m_finish);
        _m_start = temp;
        _m_finish = _m_start + size;
        _m_end_of_storage = _m_start + new_capacity;
        relocate_insert(begin() + add_size, end(), begin() + add_size + 1);
        _m_data_allocator.construct(_m_start + add_size, x);
        _m_finish++;
        return (_m_start + add_size);
    }

    void insert(iterator position, size_type n, const T& x)
    {
        size_type add_size = ft::distance(begin(), position);
        if (size() + n <= capacity())
        {
            relocate_insert(position, end(), position + n);
            std::uninitialized_fill_n(_m_start + add_size, n, x);
            _m_finish += n;
            return ;
        }
        pointer temp;
        size_type size = this->size();
        size_type new_capacity = capacity() * 2;
        if (size + n > new_capacity)
            new_capacity = capacity() + n;
        temp = allocate_copy(new_capacity, begin(), end());
        _m_data_allocator.deallocate(_m_start, capacity());
        destroy_element(_m_start, _m_finish);
        _m_start = temp;
        _m_finish = _m_start + size;
        _m_end_of_storage = _m_start + new_capacity;
        relocate_insert(begin() + add_size, end(), begin() + add_size + n);
        std::uninitialized_fill_n(_m_start + add_size, n, x);
        _m_finish += n;
        return ;
    }

    template <class InputIterator>
    void insert(iterator position, 
                InputIterator first, InputIterator last,
                typename ft::enable_if<!(ft::is_integral<InputIterator>::value)>::type* = 0)
    {
        size_type add_size = ft::distance(begin(), position);
        size_type n = ft::distance(first, last);
        if (size() + n <= capacity())
        {
            relocate_insert(position, end(), position + n);
            std::uninitialized_copy(first, last, _m_start + add_size);
            _m_finish += n;
            return ;
        }
        pointer temp;
        size_type size = this->size();
        size_type new_capacity = capacity() * 2;
        if (size + n > new_capacity)
            new_capacity = capacity() + n;
        temp = allocate_copy(new_capacity, begin(), end());
        _m_data_allocator.deallocate(_m_start, capacity());
        destroy_element(_m_start, _m_finish);
        _m_start = temp;
        _m_finish = _m_start + size;
        _m_end_of_storage = _m_start + new_capacity;
        relocate_insert(begin() + add_size, end(), begin() + add_size + n);
        std::uninitialized_copy(first, last, _m_start + add_size);
        _m_finish += n;
        return ;
    }

    iterator erase(iterator position)
    {
        if (position + 1 != end())
        {
            relocate(position + 1, end(), position);
        }
        _m_finish--;
        _m_data_allocator.destroy(_m_finish);
        return (position);
    }

    iterator erase(iterator first, iterator last)
    {
        iterator iter(relocate(last, end(), first));
        size_type n = ft::distance(first, last);
        destroy_element(iter, end());
        _m_finish = _m_finish - n;
        return (first);
    }

    void swap(vector<T,Allocator>& x)
    {
        std::swap(_m_start, x._m_start);
        std::swap(_m_finish, x._m_finish);
        std::swap(_m_end_of_storage, x._m_end_of_storage);
    }
    
    void clear()
    {
        erase(begin(), end());
    }

    protected:
    template <class Iter1, class Iter>
    Iter relocate(Iter1 first, Iter1 last, Iter position)
    {
        Iter temp = position;
        size_type n = ft::distance(first, last);
        Iter1 swap = first;
        while (swap != last)
        {
            swap = first;
            *temp = *swap;
            temp++;
            first++;
        }
        return (position + n);
    }

    template <class Iter>
    Iter relocate_insert(Iter first, Iter last, Iter position)
    {
        Iter temp = last;
        size_type n = ft::distance(first, position);
        while (first != last)
        {
            *(last + n) = *last;
            last--;
        }
        *(last + n) = *last;
        return (position);
    }

    template <class InputIterator>
    pointer allocate_copy(size_type n, InputIterator first, InputIterator last)
    {
        pointer result = _m_data_allocator.allocate(n); 
        try
        {
            std::uninitialized_copy(first, last, result);
        }
        catch(const std::bad_alloc& e)
        {
            _m_data_allocator.deallocate(result, n);
            throw ;
        }
        return (result);
    }
    
    template <class InputIterator>
    void destroy_element(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            _m_data_allocator.destroy(&(*first));
            first++;
        }
    }
};

template <class T, class Allocator>
bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    if (x.size() == y.size())
        return (ft::equal(x.begin(), x.end(), y.begin()));
    return (false);
}

template <class T, class Allocator>
bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
}
template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    return (!(x == y));
}
template <class T, class Allocator>
bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    return (y < x);
}
template <class T, class Allocator>
bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    return (!(x < y));
}
template <class T, class Allocator>
bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
{
    return (!(y < x));
}

// specialized algorithms:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
{
    x.swap(y);
}
}

#endif
