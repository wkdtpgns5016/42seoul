#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator>
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
template <class Iterator> struct iterator_traits 
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

/* iterator operation */
template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n);

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last);

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

    reverse_iterator();
    explicit reverse_iterator(Iterator x);
    template <class U> reverse_iterator(const reverse_iterator<U>& u);
   
    Iterator base() const 
    { 
        return (this->current) 
    }
    reference operator*() const
    {
        Iterator tmp = current; 
        return (*--tmp);
    }
    pointer operator->()const 
    { 
        return &(operator*()) 
    }
    
    reverse_iterator& operator++()
    {
        --this->current;
        return (*this);
    }

    reverse_iterator operator++(int)
    {
        reverse_iterator tmp = *this; 
        --this->current;
        return (tmp);
    }

    reverse_iterator& operator--()
    {
        ++this->current;
        return (*this);
    }
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp = *this; 
        ++this->current;
        return (tmp);
    }
    reverse_iterator operator+ (difference_type n) const
    {
        return (reverse_iterator(this->current - n));
    }
    reverse_iterator& operator+=(difference_type n)
    {
        this->current -= n;
        return (*this);
    }
    reverse_iterator operator- (difference_type n) const
    {
        return (reverse_iterator(this->current + n));
    }
    reverse_iterator& operator-=(difference_type n)
    {
        this->current += n;
        return (*this);
    }
    reference operator[](difference_type n) const
    {
        return (this->current[-n - 1]);
    }
};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current == y.current);
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current > y.current);
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current != y.current);
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current < y.current);
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current <= y.current);
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (x.current >= y.current);
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
{
    return (y.current - x.current);
} 

template <class Iterator>
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
{
    return (reverse_iterator<Iterator> (x.current - n));
}

}
#endif