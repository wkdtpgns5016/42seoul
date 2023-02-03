#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>
#include "type_traits.hpp"
namespace ft
{

/* Iterator */
template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&> 
struct iterator 
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};

/* Iterator category */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/* Iterator_Traits */
template <class Iterator> 
struct iterator_traits 
{
    typedef typename Iterator::iterator_category    iterator_category;
    typedef typename Iterator::value_type           value_type;
    typedef typename Iterator::difference_type      difference_type;
    typedef difference_type                         distance_type;
    typedef typename Iterator::pointer              pointer;
    typedef typename Iterator::reference            reference;
};

template <class T>
struct iterator_traits<T*> 
{
    typedef random_access_iterator_tag				iterator_category;
    typedef T										value_type;
    typedef ptrdiff_t								difference_type;
    typedef T*										pointer;
    typedef T&										reference;
};

template <class T>
struct iterator_traits<const T*> 
{
    typedef random_access_iterator_tag				iterator_category;
    typedef T										value_type;
    typedef ptrdiff_t								difference_type;
    typedef const T*								pointer;
    typedef const T&								reference;
};

// /* iterator operation */
// template <class InputIterator, class Distance>
// void advance(InputIterator& i, Distance n);

// template <class InputIterator>
// typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last);

/* reverse_iterator */
template <class Iterator>
class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category, 
                                        typename iterator_traits<Iterator>::value_type, 
                                        typename iterator_traits<Iterator>::difference_type, 
                                        typename iterator_traits<Iterator>::pointer,
                                        typename iterator_traits<Iterator>::reference> 
{
    protected:
    Iterator current;

    public:
    typedef Iterator iterator_type;
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::reference reference;
    typedef typename iterator_traits<Iterator>::pointer pointer;

    reverse_iterator() { }
    reverse_iterator (iterator_type it) : current(it) { }
    template <class Iter>
    reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) { }
    ~reverse_iterator() { }
   
    Iterator base() const 
    { 
        return (current);
    }

    reference operator*() const
    {
        Iterator tmp = current; 
        return (*--tmp);
    }

    pointer operator->()const 
    { 
        return &(operator*());
    }
    
    reverse_iterator& operator++()
    {
        --current;
        return (*this);
    }

    reverse_iterator operator++(int)
    {
        reverse_iterator tmp = *this; 
        --current;
        return (tmp);
    }

    reverse_iterator& operator--()
    {
        ++current;
        return (*this);
    }
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp = *this; 
        ++current;
        return (tmp);
    }
    reverse_iterator operator+ (difference_type n) const
    {
        return (reverse_iterator(current - n));
    }
    reverse_iterator& operator+=(difference_type n)
    {
        current -= n;
        return (*this);
    }
    reverse_iterator operator- (difference_type n) const
    {
        return (reverse_iterator(current + n));
    }
    reverse_iterator& operator-=(difference_type n)
    {
        current += n;
        return (*this);
    }
    reference operator[](difference_type n) const
    {
        return (current[-n - 1]);
    }
};

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() == y.base());
}

template <class Iterator1, class Iterator2>
bool operator< (const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() > y.base());
}

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() != y.base());
}

template <class Iterator1, class Iterator2>
bool operator> (const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() < y.base());
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() <= y.base());
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& x, 
                const reverse_iterator<Iterator2>& y)
{
    return (x.base() >= y.base());
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& x, 
    const reverse_iterator<Iterator2>& y)
{
    return (y.base() - x.base());
} 

template <class Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n, 
    const reverse_iterator<Iterator>& x)
{
    return (reverse_iterator<Iterator> (x.base() - n));
}

template<class Iterator>
class random_access_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                            typename iterator_traits<Iterator>::value_type,
                                            typename iterator_traits<Iterator>::difference_type,
                                            typename iterator_traits<Iterator>::pointer,
                                            typename iterator_traits<Iterator>::reference>
{
    protected:
    Iterator current;

    public:
    typedef typename iterator_traits<Iterator>::difference_type    difference_type;
    typedef typename iterator_traits<Iterator>::reference          reference;
    typedef typename iterator_traits<Iterator>::pointer            pointer;

    random_access_iterator() : current(Iterator()) { }
    random_access_iterator(const Iterator& i) : current(i) { }
    template<typename Iter>
    random_access_iterator(const random_access_iterator<Iter>& i) : current(i.base()) { }
    ~random_access_iterator() { }

    Iterator base() const { return (current); }
    reference operator*() const { return *current; }
    pointer operator->() const { return current; }

    random_access_iterator& operator++() { ++current; return *this; }
    random_access_iterator operator++(int) { return random_access_iterator(current++); }
    random_access_iterator& operator--() { --current; return *this; }
    random_access_iterator operator--(int) { return random_access_iterator(current--); }

    random_access_iterator operator+ (difference_type n) const
    {
        return (random_access_iterator(current + n));
    }
    random_access_iterator& operator+=(difference_type n)
    {
        current += n;
        return (*this);
    }
    random_access_iterator operator- (difference_type n) const
    {
        return (random_access_iterator(current - n));
    }
    random_access_iterator& operator-=(difference_type n)
    {
        current -= n;
        return (*this);
    }
    reference operator[](difference_type n) const
    {
        return (current[n]);
    }

};

template<class Iterator1, class Iterator2>
bool operator==(const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() == y.base());
}

template<class Iterator1, class Iterator2>
bool operator> (const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() > y.base());
}

template<class Iterator1, class Iterator2>
bool operator!=(const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() != y.base());
}

template<class Iterator1, class Iterator2>
bool operator< (const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() < y.base());
}

template<class Iterator1, class Iterator2>
bool operator<=(const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() <= y.base());
}

template<class Iterator1, class Iterator2>
bool operator>=(const random_access_iterator<Iterator1>& x, 
                const random_access_iterator<Iterator2>& y)
{
    return (x.base() >= y.base());
}

template<class Iterator1, class Iterator2>
typename random_access_iterator<Iterator1>::difference_type operator-(
    const random_access_iterator<Iterator1>& x, 
    const random_access_iterator<Iterator2>& y)
{
    return (x.base() - y.base());
}

template<class Iterator>
random_access_iterator<Iterator> operator+(
    typename random_access_iterator<Iterator>::difference_type n, 
    const random_access_iterator<Iterator>& x)
{
    return (random_access_iterator<Iterator> (x.base() + n));
}

template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type _distance(
    InputIterator first, InputIterator last, input_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;
    while (first != last)
    {
        n++;
        first++;
    }
    return (n);
}

template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type _distance(
    InputIterator first, InputIterator last, std::bidirectional_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;
    while (first != last)
    {
        n++;
        first++;
    }
    return (n);
}

template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type _distance(
    InputIterator first, InputIterator last, std::forward_iterator_tag)
{
    typename iterator_traits<InputIterator>::difference_type n = 0;
    while (first != last)
    {
        n++;
        first++;
    }
    return (n);
}

template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type _distance(
    InputIterator first, InputIterator last, std::random_access_iterator_tag)
{
    return (last - first);
}


template<class InputIterator>  
typename iterator_traits<InputIterator>::difference_type distance(
    InputIterator first, InputIterator last)
{
    return (_distance(first, 
                      last, 
                      typename iterator_traits<InputIterator>::iterator_category()));        
}



}
#endif
