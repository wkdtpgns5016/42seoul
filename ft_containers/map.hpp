#ifndef MAP_HPP
#define MAP_HPP

#include "iterator.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
#include "tree.hpp"
#include <memory>
#include <exception>
#include <algorithm>
#include <map>


namespace ft
{

template < class Key, 
           class T, 
           class Compare = std::less<Key>, 
           class Allocator = std::allocator<pair<const Key, T> > > 
class map
{
    public:
    // define types
    typedef Key                                         key_type;
    typedef T                                           mapped_type;
    typedef pair<const key_type, mapped_type>           value_type;
    typedef Compare                                     key_compare;

    class value_compare
    {
        friend class map;
        protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

        public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first_type, y.first_type);
        }
    };

    typedef Allocator                                                       allocator_type;
    typedef typename Allocator::reference                                   reference;
    typedef typename Allocator::const_reference                             const_reference;
    typedef typename Allocator::pointer                                     pointer;
    typedef typename Allocator::const_pointer                               const_pointer;

    typedef ft::rb_tree<key_type, value_type, key_compare, allocator_type>  tree_type;

    typedef typename tree_type::iterator                                    iterator;
    typedef typename tree_type::const_iterator                              const_iterator;
    typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;
    
    typedef typename allocator_type::difference_type                        difference_type;
    typedef typename allocator_type::size_type                              size_type;

    protected:
    tree_type _m_tree;

    public:
    // constructor && destructor && operator
    map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : _m_tree(tree_type(comp, alloc)) {}

    template <class InputIterator>  
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : _m_tree(tree_type(first, last, comp, alloc)) {}

    map (const map& x)
    {
        if (this == &x)
            return (*this);
        _m_tree = tree_type(x.begin(), x.end());
    }

    ~map ()
    {
        clear();
    }

    map& operator= (const map& x)
    {
        if (this == &x)
            return (*this);
        _m_tree = tree_type(x.begin(), x.end());
    }

    mapped_type& operator[] (const key_type& k)
    {
        if (count(k))
            return ((*(this->find(k))).first);
        else
            return ((*((this->insert(make_pair(k,mapped_type()))).first)));
    }

    // iterator
    iterator begin()
    {
        return (_m_tree.begin());
    }
    
    const_iterator begin() const
    {
        return (_m_tree.begin());
    }

    iterator end()
    {
        return (_m_tree.end());
    }
    
    const_iterator end() const
    {
        return (_m_tree.end());
    }

    iterator rbegin()
    {
        return (_m_tree.rbegin());
    }
    
    const_iterator rbegin() const
    {
        return (_m_tree.rbegin());
    }

    iterator rend()
    {
        return (_m_tree.rend());
    }
    
    const_iterator rend() const
    {
        return (_m_tree.rend());
    }


    // 
    size_type count (const key_type& k) const
    {
        return (_m_tree.is_exist(k));
    }

    bool empty() const
    {
        return (_m_tree.is_empty());
    }

    iterator lower_bound(const key_type& k)
    {
        return (_m_tree.lower_bound(k));
    }

    const_iterator lower_bound(const key_type& k) const
    {
        return (_m_tree.lower_bound(k));
    }

    iterator upper_bound (const key_type& k)
    {
        return (_m_tree.upper_bound(k));
    }

    const_iterator upper_bound (const key_type& k) const
    {
        return (_m_tree.upper_bound(k));
    }

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const
    {
        return (make_pair(lower_bound(k), upper_bound(k)));
    }

    pair<iterator,iterator> equal_range (const key_type& k)
    {
        return (make_pair(lower_bound(k), upper_bound(k)));
    }

    iterator find (const key_type& k)
    {
        return (iterator(_m_tree.find_node(k), _m_tree.get_root(), _m_tree.get_nil()));
    }

    const_iterator find (const key_type& k) const
    {
        return (const_iterator(_m_tree.find_node(k), _m_tree.get_root(), _m_tree.get_nil()));
    }

    // getter
    allocator_type get_allocator() const { return (_m_tree.get_allocator()); }

    value_compare value_comp() const { return (value_compare()); }

    key_compare key_comp() const { return (_m_tree.get_comp()); }

    size_type size() const { return (_m_tree.get_size()); }

    size_type max_size() const { return ((SIZE_MAX) / sizeof(value_type)); }

    // element modify
    pair<iterator,bool> insert (const value_type& val)
    {
        if (count(val.first))
            return (make_pair(find(val.first), false));
        return (make_pair(_m_tree.insert_node(val), true));
    }

    iterator insert (iterator position, const value_type& val)
    {
        iterator iter;

        if (count(val.first))
            return (find(val.first));
        if (_m_tree.is_hint(position, val.first))
            iter = _m_tree.insert_node(position, val);
        else
            iter = _m_tree.insert_node(val);
        return (iter);
    }

    template <class InputIterator>  
    void insert (InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert(first._node->_data);
            first++;
        }
    }

    void erase (iterator position)
    {
        key_type k = position._node->_data.first;
        if (count(k))
         _m_tree.delete_node(_m_tree.find(k));

    }

    size_type erase (const key_type& k)
    {
        if (count(k))
        {
            _m_tree.delete_node(_m_tree.find(k));
            return (1);
        }
        return (0);
    }

    void erase (iterator first, iterator last)
    {
        key_type k;
        while (first != last)
        {
            k = first._node->_data.first;
            _m_tree.delete_node(_m_tree.find(k));
            first++;
        }
    }

    void clear()
    {
        erase(begin(), end());
    }

    void swap (map& x)
    {
        std::swap(_m_tree, x._m_tree);
    }
};

template <class Key, class T, class Compare, class Alloc>  
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, 
                const map<Key,T,Compare,Alloc>& rhs )
{
    if (lhs.size() == rhs.size())
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    return (false);

}

template <class Key, class T, class Compare, class Alloc>  
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, 
                  const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>  
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, 
                  const map<Key,T,Compare,Alloc>& rhs )
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>  
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, 
                  const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>  
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, 
                  const map<Key,T,Compare,Alloc>& rhs )
{
    return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>  
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, 
                  const map<Key,T,Compare,Alloc>& rhs )
{
    return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>  
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
    return (x.swap(y));
}

}

#endif