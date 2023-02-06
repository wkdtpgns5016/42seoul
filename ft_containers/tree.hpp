#ifndef TREE_HPP
#define TREE_HPP

#include "utility.hpp"
#include <memory>
#include <exception>
#include <algorithm>

enum rb_tree_color{
    RED,
    BLACK
};

namespace ft
{

template < class T >
struct rb_tree_node
{
    typedef T                           value_type;
    typedef rb_tree_node<value_type>    node_type;
    typedef node_type*                  node_ptr;
    typedef const node_type*            const_node_ptr;

    rb_tree_color   _color;
    node_ptr*       _parent;
    node_ptr*       _left;
    node_ptr*       _right;
    value_type      _data;

    rb_tree_node(rb_tree_color color, node_ptr parent, node_ptr left, node_ptr right, value_type data)
    : _color(color), _parent(parent), _left(left), _right(right), _data(data) {}
    ~rb_tree_node() {}
};

template < class Key,        
        class T,         
        class Compare = std::less<Key>,          
        class Allocator = std::allocator<T> > 
class rb_tree
{
    public:
    typedef Key                                         key_type;
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef Compare                                     key_compare;
    typedef rb_tree_node<value_type>                    node_type;
    typedef std::allocator<node_type>                   node_allocator_type;
    typedef typename node_type::node_ptr                node_ptr;
    typedef typename node_type::const_node_ptr          const_node_ptr;

    protected:
    node_allocator_type _node_alloc;
    node_ptr            _root;
    key_compare         _comp;
    size_t              _size;

    public:
    rb_tree() : _size(0) {}

    


};

}

#endif