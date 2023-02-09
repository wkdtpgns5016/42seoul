#ifndef TREE_HPP
#define TREE_HPP

#include "utility.hpp"
#include "iterator.hpp"
#include <memory>
#include <exception>
#include <algorithm>
#include <iostream>
#include <cstddef>

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
    node_ptr        _parent;
    node_ptr        _left;
    node_ptr        _right;
    value_type      _data;

    rb_tree_node(rb_tree_color color, node_ptr parent, node_ptr left, node_ptr right, value_type data)
    : _color(color), _parent(parent), _left(left), _right(right), _data(data) {}
    ~rb_tree_node() {}
};

template < class T > 
class rb_tree_itterator
{
    typedef bidirectional_iterator_tag		         		iterator_category;
    typedef T			        					 		value_type;
    typedef ptrdiff_t			        			 		difference_type;
    typedef T*			        							pointer;
    typedef T&		        							    reference;

    typedef typename rb_tree_node<value_type>::node_ptr     node_ptr;

    public:
    node_ptr    _node;
    node_ptr    _NIL;

    rb_tree_itterator() : _node(), _NIL() {}
    rb_tree_itterator(node_ptr node, node_ptr nil) : _node(node), _NIL(nil) {}
    ~rb_tree_itterator() {}
    rb_tree_itterator(const rb_tree_itterator<value_type>& node) : _node(node.base()) {}

    value_type base() const { return (_node); }
    reference operator*() const { return *_node; }
    pointer operator->() const { return _node; }

    
    // rb_tree_itterator& operator++() 
    // { 
    //     ++_current; 
    //     return *this; 
    // }
    // rb_tree_itterator operator++(int) 
    // { 
    //     return rb_tree_itterator(_current++); 
    // }

    protected:
    void    increment()
    {
        if (_node->_right != _NIL) 
        {
            _node = _node->_right;
            while (_node->_left != _NIL)
                _node = _node->_left;
        }
        else 
        {
            
            node_ptr y = _node->_parent;
            while (_node == y->_right) 
            {
                _node = y;
                y = y->_parent;
            }
            // 추가
        }
    }

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
    node_ptr            _NIL;
    key_compare         _comp;
    size_t              _size;

    public:
    rb_tree() : _size(0) 
    {
        value_type p;
        _NIL = alloc_node(BLACK, p);
        _NIL->_left = _NIL;
        _NIL->_right = _NIL;
        _NIL->_parent = _NIL;
        _root = _NIL;
    }

    node_ptr make_node(value_type& data)
    {
        node_ptr new_node = alloc_node(RED, data);
        new_node->_left = _NIL;
        new_node->_right = _NIL;
        new_node->_parent = _NIL;
        return (new_node);
    }

    node_ptr minimum(node_ptr node)
    {
        node_ptr x = node;
        while (x != _NIL)
            x = x->_left;
        return (x->_parent);
    }

    node_ptr maximum(node_ptr node)
    {
        node_ptr x = node;
        while (x != _NIL)
            x = x->_right;
        return (x->_parent);
    }

    node_ptr successor(node_ptr node)
    {
        node_ptr x = node;
        node_ptr y = node->_parent;
        if (node->_right != _NIL)
            return (minimum(x->_right));
        while (y != _NIL && x == y->_right)
        {
            x = y;
            y = y->_parent;
        }
        return (y);
    }

    node_ptr predecessor(node_ptr node)
    {
        node_ptr x = node;
        node_ptr y = node->_parent;
        if (node->left != _NIL)
            return (maximum(x->left));
        while (y != _NIL && x == y->_left)
        {
            x = y;
            y = y->parent;
        }
        return (y);
    }

    bool is_empty()
    {
        if (_root == _NIL)
            return (true);
        return (false);
    }

    node_ptr get_root() const { return (_root); }
    size_t get_size() const { return (_size); }

    void inorder_print_tree(node_ptr t)
    {
        if (t != _NIL)
        {
            inorder_print_tree(t->_left);
            std::cout << "[" << t->_data._first << "]" << t->_data._second << " | ";
            inorder_print_tree(t->_right);
        }
    }

    void transplant(node_ptr t, node_ptr c)
    {
        if( t->_parent == _NIL)
        {
            _root = c;
        }
        else if( t == t->_parent->_left)
        {
            t->_parent->_left = c;
        }
        else
        {
            t->_parent->_right = c;
        }

        c->_parent = t->_parent; // link target's parent to child's parent.
    }

    void insert_node(value_type& data)
    {
        if (is_empty())
            insert_node_empty(make_node(data));
        else
            insert_node_not_empty(make_node(data));
        _size++;
    }

    void delete_node(node_ptr node)
    {
        node_ptr y; // 삭제할 노드
        node_ptr x; // 삭제할 노드의 자식 노드

        if (node->_left == _NIL)
        {
            x = node->_right;
            transplant(node, node->_right);
        }
        else if (node->_right == _NIL)
        {
            x = node->_left;
            transplant(node, node->_left);
        }
        else
        {
            y = successor(node);
            rb_tree_color color = y->_color;
            x = y->_right;

            transplant(y, y->_right);
            y->_right = node->_right;
            y->_right->_parent = y;

            transplant(node, y);
            y->_left = node->_left;
            y->_left->_parent = y;
            y->_color = node->_color;
            
            if (color == BLACK)
                delete_fixup(x);
        }
        _node_alloc.deallocate(y, 1);
        _node_alloc.destroy(y);
    }

    node_ptr find_node(const key_type & k)
    {
        node_ptr x = _root;
        while (x != _NIL)
        {
            if (k == x->_data._first)
                break ;
            if (_comp(k, x->_data._first))
                x = x->_left;
            else
                x = x->_right;
        }
        return (x);
    }

    protected:
    node_ptr alloc_node(rb_tree_color color, value_type data)
    {
        node_type node(color, NULL, NULL, NULL, data);
        node_ptr new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, node);
        return (new_node);
    }

    void left_rotate(node_ptr node)
    {
        node_ptr y = node->_right;
        node->_right = y->_left;
        y->_left->_parent = node;
        y->_parent = node->_parent;
        if (node->_parent == _NIL)
            _root = y;
        else if (node == node->_parent->_left)
            node->_parent->_left = y;
        else
            node->_parent->_right = y;
        y->_left = node;
        node->_parent = y;
    }

    void right_rotate(node_ptr node)
    {
        node_ptr y = node->_left;
        node->_left = y->_right;
        y->_right->_parent = node;
        y->_parent = node->_parent;
        if (node->_parent == _NIL)
            _root = y;
        else if (node == node->_parent->_right)
            node->_parent->_right = y;
        else
            node->_parent->_left = y;
        y->_right = node;
        node->_parent = y;
    }

    void insert_fixup_left(node_ptr* node)
    {
        node_ptr uncle = _NIL;

        uncle = (*node)->_parent->_parent->_right;
        if (uncle->_color == RED)                     // case 1 - Uncle의 Color가 RED인 경우
        {
            (*node)->_parent->_color = BLACK;
            uncle->_color = BLACK;
            (*node)->_parent->_parent->_color = RED;
            (*node) = (*node)->_parent->_parent;
        }
        else if ((*node) == (*node)->_parent->_right) // case 2 - node가 Right Child인 경우
        {
            (*node) = (*node)->_parent;
            left_rotate((*node));
        }
        else                                          // case 3 - node가 Left Child인 경우
        {
            (*node)->_parent->_color = BLACK;
            (*node)->_parent->_parent->_color = RED;
            right_rotate((*node)->_parent->_parent);
        }
    }

    void insert_fixup_right(node_ptr* node)
    {
        node_ptr uncle = _NIL;
        
        uncle = (*node)->_parent->_parent->_left;
        if (uncle->_color == RED) 
        {
            (*node)->_parent->_color = BLACK;
            uncle->_color = BLACK;
            (*node)->_parent->_parent->_color = RED;
            (*node) = (*node)->_parent->_parent;
        }
        else if ((*node) == (*node)->_parent->_left) 
        {
            (*node) = (*node)->_parent;
            right_rotate((*node));
        }
        else
        {
            (*node)->_parent->_color = BLACK;
            (*node)->_parent->_parent->_color = RED;
            left_rotate((*node)->_parent->_parent);
        }
    }

    void insert_fixup(node_ptr node)
    {
        while (node->_parent->_color == RED)
        {
            if (node->_parent == node->_parent->_parent->_left)
                insert_fixup_left(&node);
            else
                insert_fixup_right(&node);
        }
        _root->_color = BLACK;
    }
    
    void insert_node_empty(node_ptr node)
    {
        _root = node;
        _root->_color = BLACK;
        _root->_parent = _NIL;
    }

    void insert_node_not_empty(node_ptr node)
    {
        node_ptr y = _NIL;
        node_ptr x = _root;
        // key 값 비교하며 트리 이동
        while (x != _NIL)
        {
            y = x;
            if (_comp(node->_data._first, x->_data._first))
                x = x->_left;
            else
                x = x->_right;
        }

        // 트리에 노드 연결
        node->_parent = y;
        if (_comp(node->_data._first, y->_data._first))
            y->_left = node;
        else
            y->_right = node;

        // fixup 실행
        insert_fixup(node);
    }

    void delete_fixup_left(node_ptr* node)
    {
        node_ptr brother = (*node)->_parent->_right;
        // Case 1 : 형제노드가 Red
        if (brother->_color == RED) 
        {
            brother->_color = BLACK;
            (*node)->_parent->_color = RED;
            left_rotate((*node)->_parent);
            brother = (*node)->_parent->_right;
        }
        // Case 2 : 형제 자식노드가 둘다 Black
        if (brother->_left->_color == BLACK && brother->_right->_color == BLACK)
        {
            brother->_color = RED;
            (*node) = (*node)->_parent;
        }
        else if (brother->_right->_color == BLACK) // Case 3 : 형제 왼쪽 자식이 Red
        {
            brother->_left->_color = BLACK;
            brother->_color = RED;
            right_rotate(brother);
            brother = (*node)->_parent->_right;
        }
        if (brother->_right->_color == RED)       // Case 4 : 형제 오른쪽 자식이 Red
        {
            brother->_color = (*node)->_parent->_color;
            (*node)->_parent->_color = BLACK;
            brother->_right->_color = BLACK;
            left_rotate((*node)->_parent);
            (*node) = _root;
        }
    }

    void delete_fixup_right(node_ptr* node)
    {
        node_ptr brother = (*node)->_parent->_left;
        if (brother->_color == RED) 
        {
            brother->_color = BLACK;
            (*node)->_parent->_color = RED;
            right_rotate((*node)->_parent);
            brother = (*node)->_parent->_left;
        }
        if (brother->_left->_color == BLACK && brother->_right->_color == BLACK)
        {
            brother->_color = RED;
            (*node) = (*node)->_parent;
        }
        else if (brother->_left->_color == BLACK)
        {
            brother->_right->_color = BLACK;
            brother->_color = RED;
            left_rotate(brother);
            brother = (*node)->_parent->_left;
        }
        if (brother->_left->_color == RED)  
        {
            brother->_color = (*node)->_parent->_color;
            (*node)->_parent->_color = BLACK;
            brother->_left->_color = BLACK;
            right_rotate((*node)->_parent);
            (*node) = _root;
        }
    }

    void delete_fixup(node_ptr node)
    {
        while (node != _root && node->_color == BLACK)
        {
            if (node == node->_parent->_left)
                delete_fixup_left(&node);
            else
                delete_fixup_right(&node);
        }
        node->_color = BLACK;
    }
};

}

#endif