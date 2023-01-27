#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector 
{
    
    public:
        // types:
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
        allocator_type  m_data_allocator;   
        T*              m_start;
        T*              m_finish;
        T*              m_end_of_storage;

    public:
        vector (const allocator_type& alloc = allocator_type())
                : m_start(0), m_finish(0), m_end_of_storage(0) { }
        vector (size_type n, 
                const value_type& val = value_type(), 
                const allocator_type& alloc = allocator_type())
        {
            this->m_start = m_data_allocator.allocate(n);
            this->m_finish = m_start;
            this->m_end_of_storage = m_start + n;
        }
        template <class InputIterator>
        vector (InputIterator first,
                InputIterator last,
                const allocator_type& alloc = allocator_type());

        vector(const vector<T,Allocator>& x);
        ~vector();
        vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
        
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const T& u);
        allocator_type get_allocator() const;

        // iterators:
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // 23.2.4.2 capacity:
        size_type size() const;
        size_type max_size() const;
        void resize(size_type sz, T c = T());
        size_type capacity() const;
        bool empty() const;
        void reserve(size_type n);

        // element access:
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;
        const_reference at(size_type n) const;
        reference at(size_type n);
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        // 23.2.4.3 modifiers:
        void push_back(const T& x);
        void pop_back();
        iterator insert(iterator position, const T& x);
        void insert(iterator position, size_type n, const T& x);
        template <class InputIterator>
        void insert(iterator position,
        InputIterator first, InputIterator last);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void swap(vector<T,Allocator>&);
        void clear();
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