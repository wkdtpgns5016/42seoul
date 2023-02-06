#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        T1  _first_type;
        T2  _second_type;
        pair() : _first_type(0), _second_type(0) {}
        template<class U, class V> 
        pair (const pair<U,V>& pr) : _first_type(pr._first_type), _second_type(pr._second_type) {}
        pair (const _first_type& a, const _second_type& b) : _first_type(a), _second_type(b) {}
        pair& operator= (const pair& pr)
        {
            if (this == &pr) return (*this);
            _first_type = pr._first_type;
            _second_type = pr._second_type;
            return (*this);
        }

    };
    
    template <class T1, class T2>  
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        if (lhs._first_type == rhs._first_type && lhs._second_type == rhs._second_type) 
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
        if (lhs._first_type < rhs._first_type)
        {
            if (lhs._second_type < rhs._second_type)
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