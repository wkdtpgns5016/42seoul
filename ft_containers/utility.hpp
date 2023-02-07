#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        T1  _first;
        T2  _second;
        pair() : _first(), _second() {}
        template<class U, class V> 
        pair (const pair<U,V>& pr) : _first(pr._first), _second(pr._second) {}
        pair (const T1& a, const T2& b) : _first(a), _second(b) {}
        pair& operator= (const pair& pr)
        {
            if (this == &pr) return (*this);
            _first = pr._first;
            _second = pr._second;
            return (*this);
        }

    };
    
    template <class T1, class T2>  
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        if (lhs._first == rhs._first && lhs._second == rhs._second) 
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
        if (lhs._first < rhs._first)
        {
            if (lhs._second < rhs._second)
                return (true);
            return (false);
        }
        return (false);
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
}

#endif