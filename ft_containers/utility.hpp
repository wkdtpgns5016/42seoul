#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        T1  first;
        T2  second;
        pair() : first(), second() {}
        template<class U, class V> 
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
        pair (const T1& a, const T2& b) : first(a), second(b) {}
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
        if (lhs.first < rhs.first)
        {
            if (lhs.second < rhs.second)
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