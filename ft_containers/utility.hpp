#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;
        first_type  first;
        second_type  second;
        pair() : first(), second() {}
        template<class U, class V> 
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}
        pair& operator= (const pair& pr)
        {
            if (this == &pr) return (*this);
            first = pr.first;
            second = pr.second;
            return (*this);
        }

    };
    
    template <class T1, class T2>  
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        if (lhs.first == rhs.first && lhs.second == rhs.second) 
            return (true);
        return (false);
    }
    template <class T1, class T2>  
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T1, class T2>  
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>  
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>  
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs > rhs));
    }
    template <class T1, class T2>  
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }

    template <class T>
    void swap (T& a, T& b)
    {
        T c = a;
        a = b;
        b = c;
    }

    template <class Pair>
    struct key_with_pair
    {
        typename Pair::first_type &operator()(Pair & pair) const { return (pair.first); }
        typename Pair::first_type &operator()(const Pair & pair) const { return (pair.first); }
    };

    template <class Value>
    struct key_with_value
    {
        Value &operator()(Value & val) const { return (val); }
        Value &operator()(const Value & val) const { return (val); }
    };
}

#endif