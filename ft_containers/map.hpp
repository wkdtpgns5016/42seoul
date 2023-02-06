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
           class Allocator = std::allocator<pair<const Key,T>> > 
class map
{
    public:
        // define types
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<const key_type, mapped_type>           value_type;
        typedef Compare                                     key_compare;

        template <class Key, class T, class Compare, class Alloc>
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

        typedef Allocator                                   allocator_type;
        typedef typename Allocator::reference               reference;
        typedef typename Allocator::const_reference         const_reference;
        typedef typename Allocator::pointer                 pointer;
        typedef typename Allocator::const_pointer           const_pointer;

        typedef ft::tree_iterator<pointer>                  iterator;
        typedef ft::tree_iterator<const_pointer>            const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        
        typedef typename allocator_type::difference_type    difference_type;
        typedef typename allocator_type::size_type          size_type;


};


}

#endif