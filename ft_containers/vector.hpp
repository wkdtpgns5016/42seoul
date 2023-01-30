#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include "iterator.hpp"
#include <exception>

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
            // clear(); 원소 destory
            m_data_allocator.deallocate(m_start, capacity());
        }

        vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
        {
            if (this == x) return (*this);
            size_type n = x.capacity();
            m_data_allocator = x.get_allocator();

            m_start = m_data_allocator.allocate(n);
            m_end_of_storage = m_start + n;
            m_finish = std::uninitialized_copy(x.begin(), x.end(), m_start);
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
            size_type size = size();
            if (n > capacity())
            {
                pointer temp = allocate_capy(n, begin(), end());
                clear();
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
                size_type size = size();
                size_type new_capacity;
                if (capacity() < 3)
                    new_capacity = 1;
                else
                    new_capacity = capacity() + capacity() / 2;
                temp = allocate_capy(new_capacity, begin(), end());
                m_data_allocator.deallocate(m_start, capacity());
                clear();
                m_start = temp;
                m_finish = temp + size + 1;
                m_data_allocator.construct(end() - 1, x);
                m_end_of_storage = m_start + new_capacity;
            }
            else
            {
                m_data_allocator.construct(end(), x);
                m_finish++;
            }
        }

        void pop_back()
        {
            m_data_allocator.destory(end() - 1);
            m_finish--;
        }
        
        iterator insert(iterator position, const T& x)
        {
            if (capacity() < size() + 1)
            {
                pointer temp;
                pointer temp_finish;
                size_type size = size();
                size_type new_capacity = capacity() * 2;
                temp = allocate_capy(new_capacity, begin(), end());
                if (!temp)
                    return
                m_data_allocator.deallocate(m_start, capacity());
                clear();
                m_start = temp;
                m_finish = temp + size;
                m_end_of_storage = temp + new_capacity;
            }
            pointer back = end();
            while (--back != position - 1)
                back + 1 = *back;
            m_finish = std::uninitialized_fill_n(position, 1, x);
        }
        void insert(iterator position, size_type n, const T& x);
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void swap(vector<T,Allocator>&);
        void clear();

    protected:
        template <class InputIterator>
        pointer allocate_capy(size_type n, InputIterator first, InputIterator last)
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
};

template <class T, class Allocator>
bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y);

// specialized algorithms:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}

#endif