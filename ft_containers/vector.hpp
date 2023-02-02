#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <exception>
#include <algorithm>
#include "iterator.hpp"
#include "utils.hpp"

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
        allocator_type  m_data_allocator;   
        T*              m_start;
        T*              m_finish;
        T*              m_end_of_storage;

    public:
        // Constructs and Destroys
        vector (const allocator_type& alloc = allocator_type())
                : m_start(0), m_finish(0), m_end_of_storage(0), m_data_allocator(alloc) { }

        vector (size_type n, 
                const value_type& val = value_type(), 
                const allocator_type& alloc = allocator_type())
                : m_start(0), m_finish(0), m_end_of_storage(0), m_data_allocator(alloc)
        {
            m_start = m_data_allocator.allocate(n);
            m_end_of_storage = m_start + n;
            m_finish = std::uninitialized_fill_n(m_start, n, val);
        }

        template <class InputIterator>
        vector (InputIterator first,
                InputIterator last,
                const allocator_type& alloc = allocator_type())
                : m_start(0), m_finish(0), m_end_of_storage(0), m_data_allocator(alloc)
        {
            size_type n = ft::distance(first, last);
            m_start = m_data_allocator.allocate(n);
            m_end_of_storage = m_start + n;
            m_finish = std::uninitialized_copy(first, last, m_start);
        }

        vector(const vector<T,Allocator>& x)
        {
            size_type n = x.size();
            m_data_allocator = x.get_allocator();
            m_start = m_data_allocator.allocate(n);
            m_end_of_storage = m_start + n;
            m_finish = std::uninitialized_copy(x.begin(), x.end(), m_start);
        }

        ~vector()
        {
            destroy_element(m_start, m_finish);
            m_data_allocator.deallocate(m_start, capacity());
        }

        vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
        {
            if (this == x) return (*this);
            size_type n = x.size();
            if (n > capacity())
            {
                pointer temp = allocate_copy(n, x.begin(), x.end());
                destroy_element(m_start, m_finish);
                m_data_allocator.deallocate(m_start, m_end_of_storage - m_start);
                m_start = temp;
                m_end_of_storage = m_start + n;
            }
            else if (n < = capacity() && n > size())
            {
                relocate(x.begin(), x.begin() + size(), m_start);
                std::uninitialized_copy(x.begin() + size(), x.end(), m_finish);
            }
            else
            {
                iterator iter(relocate(x.begin(), x.end(), begin()));
                destroy_element(iter, end());
            }
            m_finish = m_start + n;
            return (*this);
        }
        
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const T& u);

        allocator_type get_allocator() const
        {
            return (m_data_allocator);
        }

        // iterators
        iterator begin()
        {
            return (iterator(m_start));
        }

        const_iterator begin() const
        {
            return (const_iterator(m_start));
        }

        iterator end()
        {
            return (iterator(m_finish));
        }

        const_iterator end() const
        {
            return (const_iterator(m_finish));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(m_finish));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(m_finish));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(m_start));
        }

        const_reverse_iterator rend() const
        {
            return (reverse_iterator(m_start));
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

        void resize (size_type n, value_type val = value_type());
    
        size_type capacity() const
        {
            return (m_end_of_storage - m_start);
        }

        bool empty() const
        {
            return (m_start == m_finish);
        }

        void reserve(size_type n)
        {
            size_type size = this->size();
            if (n > capacity())
            {
                pointer temp = allocate_copy(n, begin(), end());
                destroy_element(m_start, m_finish);
                m_data_allocator.deallocate(m_start, capacity());
                m_start = temp;
                m_finish = temp + size;
                m_end_of_storage = m_start + n;
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
            return (*(m_start + n));
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
                m_data_allocator.deallocate(m_start, capacity());
                destroy_element(m_start, m_finish);
                m_start = temp;
                m_finish = temp + size + 1;
                m_data_allocator.construct(m_finish - 1, x);
                m_end_of_storage = m_start + new_capacity;
            }
            else
            {
                m_data_allocator.construct(m_finish, x);
                m_finish++;
            }
        }

        void pop_back()
        {
            m_data_allocator.destory(end() - 1);
            m_finish--;
        }
        
        iterator insert(iterator position, const T& x);
        void insert(iterator position, size_type n, const T& x);
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last);

        iterator erase(iterator position)
        {
            if (position + 1 != end())
            {
                relocate(position + 1, end(), position);
            }
            m_finish--;
            m_data_allocator.destroy(m_finish);
            return (position);
        }

        iterator erase(iterator first, iterator last)
        {
            iterator iter(relocate(last, end(), first));
            size_type n = ft::distance(first, last);
            destroy_element(iter, end());
            m_finish = m_finish - n;
            return (first);
        }

        void swap(vector<T,Allocator>& x)
        {
            std::swap(m_start, x.m_start);
            std::swap(m_finish, x.m_finish);
            std::swap(m_end_of_storage, x.m_end_of_storage);
        }
        
        void clear()
        {
            erase(begin(), end());
        }

    protected:
        template <class InputIterator>
        InputIterator relocate(InputIterator first, InputIterator last, InputIterator position)
        {
            InputIterator temp = position;
            size_type n = ft::distance(first, last);
            while (first != last)
            {
                *temp = *first;
                temp++;
                first++;
            }
            return (position + n);
        }

        template <class InputIterator>
        pointer allocate_copy(size_type n, InputIterator first, InputIterator last)
        {
            pointer result = m_data_allocator.allocate(n); 
            try
            {
                std::uninitialized_copy(first, last, result);
            }
            catch(const std::bad_alloc& e)
            {
                m_data_allocator.deallocate(result, n);
                throw ;
            }
            return (result);
        }
        
        template <class InputIterator>
        void destroy_element(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                m_data_allocator.destroy(&(*first));
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
    return (!x == y);
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