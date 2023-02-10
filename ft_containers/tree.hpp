#ifndef TREE_HPP
#define TREE_HPP

#include "utility.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"
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

    rb_tree_node<T>* minimum(rb_tree_node<T>* node, rb_tree_node<T>* _NIL)
    {
        rb_tree_node<T>* x = node;
        while (x->_left != _NIL)
            x = x->_left;
        return (x);
    }

    rb_tree_node<T>* maximum(rb_tree_node<T>* node, rb_tree_node<T>* _NIL)
    {
        rb_tree_node<T>* x = node;
        while (x->_right != _NIL)
            x = x->_right;
        return (x);
    }
};

template < class T > 
class rb_tree_itterator
{
    public:
    typedef bidirectional_iterator_tag		            iterator_category;
    typedef T			        						value_type;
    typedef ptrdiff_t                                   difference_type;
    typedef T*			        					    pointer;
    typedef T&		        							reference;

    typedef rb_tree_node<value_type>                    node_type;
    typedef node_type*                                  node_ptr;

    private:
    node_ptr    _node;
    node_ptr    _root;
    node_ptr    _NIL;

    public:

    rb_tree_itterator() : _node(), _NIL() {}
    rb_tree_itterator(node_ptr node, node_ptr root, node_ptr nil)
     : _node(node), _root(root), _NIL(nil) {}
    rb_tree_itterator(const rb_tree_itterator<value_type>& node) 
     : _node(node._node), _root(node._root), _NIL(node._NIL) {}

    reference operator*() const { return (_node->_data); }
    pointer operator->() const { return (&(operator*())); }
    
    rb_tree_itterator& operator++() 
    { 
        increment();
        return *this; 
    }
    rb_tree_itterator operator++(int) 
    {
        rb_tree_itterator temp(*this);
        temp.increment();
        return (temp);
    }

    rb_tree_itterator& operator--() 
    { 
        decrement();
        return *this; 
    }
    rb_tree_itterator operator--(int) 
    {
        rb_tree_itterator temp(*this);
        temp.decrement();
        return (temp);
    }

    template<class Iterator1, class Iterator2>
    bool operator==(const rb_tree_itterator<Iterator1>& x, 
                    const rb_tree_itterator<Iterator2>& y)
    {
        return (x._root == y._root);
    }

    template<class Iterator1, class Iterator2>
    bool operator!=(const rb_tree_itterator<Iterator1>& x, 
                    const rb_tree_itterator<Iterator2>& y)
    {
        return (!(x == y));
    }

    private:
    void    increment()
    {
        if (_node == _NIL)
            _node = _root->minimum(_root, _NIL);
        if (_node->_right != _NIL) 
        {
            _node = _node->_right;
            while (_node->_left != _NIL)
                _node = _node->_left;
        }
        else
        {
            node_ptr y = _node->_parent;
            while (_node == y->_right && y != _NIL) 
            {
                _node = y;
                y = y->_parent;
            }
            _node = y;
        }
    }

    void    decrement()
    {
        if (_node == _NIL)
            _node = _root->maximum(_root, _NIL);
        else
        {
            if (_node->_left != _NIL)
            {
                _node = _node->_left;
                while (_node->_right != _NIL)
                    _node = _node->_right;
            }
            else
            {
                node_ptr y = _node->_parent;
                while (_node == y->_left && y != _NIL) 
                {
                    _node = y;
                    y = y->_parent;
                }
                _node = y;
            }
        }
    }
    
};


template < class Key, class T, class Compare, class Allocator > 
class rb_tree
{
    public:
    typedef Key                                         key_type;
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef Compare                                     key_compare;
    typedef ft::rb_tree_node<value_type>                node_type;
    typedef std::allocator<node_type>                   node_allocator_type;
    typedef typename node_type::node_ptr                node_ptr;
    typedef typename node_type::const_node_ptr          const_node_ptr;

    typedef ft::rb_tree_itterator<T>                    iterator;
    typedef ft::rb_tree_itterator<const T>              const_iterator;
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;

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

    rb_tree(const key_compare& comp, const allocator_type& alloc) : _node_alloc(alloc), _comp(comp), _size(0)
    {
        rb_tree();
    }

    template <class InputIterator>  
    rb_tree(InputIterator first, InputIterator last, const key_compare& comp , const allocator_type& alloc) : _node_alloc(alloc), _comp(comp), _size(0)
    {
        rb_tree();
        insert_node(first, last);
    }

    rb_tree(const rb_tree& tree) : _size(0)
    {
        if (this == &tree)
            return ;
        rb_tree(tree.begin(), tree.end(), tree.get_comp(), tree.get_allocator());
    }

    node_ptr make_node(value_type& data)
    {
        node_ptr new_node = alloc_node(RED, data);
        new_node->_left = _NIL;
        new_node->_right = _NIL;
        new_node->_parent = _NIL;
        return (new_node);
    }

    node_ptr successor(node_ptr node)
    {
        node_ptr x = node;
        node_ptr y = node->_parent;
        if (node->_right != _NIL)
            return (_root->minimum(x->_right, _NIL));
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
            return (_root->maximum(x->left, _NIL));
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

    bool is_exist(const key_type& k)
    {
        if (find_node(k) != _NIL)
            return (true);
        return (false);
    }

    bool is_hint(iterator hint, const key_type& k)
    {
        if (hint == _NIL)
        {
            node_ptr max = _root->maximum(_root, _NIL);
            if (_comp(max->_data.first < k))
                return (true);
            return (false);
        }


    }

    node_ptr get_root() const { return (_root); }
    node_ptr get_nil() const { return (_NIL); }
    size_t get_size() const { return (_size); }
    allocator_type get_allocator() const { return (_node_alloc); }
    key_compare get_comp() const { return (_comp); }

    void inorder_print_tree(node_ptr t)
    {
        if (t != _NIL)
        {
            inorder_print_tree(t->_left);
            std::cout << "[" << t->_data.first << "]" << t->_data.second << " | ";
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

    template <class InputIterator> 
    void insert_node(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            insert_node(*first);
            first++;
        }
    }

    template <class InputIterator> 
    iterator insert_node(InputIterator hint, value_type& data)
    {
        node_ptr node = make_node(data);
        if (is_empty())
            insert_node_empty(node);
        else
            insert_node_with_hint(hint, node);
        _size++;
        return (iterator(node, _root, _NIL));
    }

    iterator insert_node(node_ptr node)
    {
        if (is_empty())
            insert_node_empty(node);
        else
            insert_node_not_empty(node);
        _size++;
        return (iterator(node, _root, _NIL));
    }

    iterator insert_node(value_type& data)
    {
        return (insert_node(make_node(data)));
    }

    void delete_node(node_ptr node)
    {
        node_ptr y; // 삭제할 노드
        node_ptr x; // 삭제할 노드의 자식 노드

        if (!is_exist(node))
            return ;

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
            if (k == x->_data.first)
                break ;
            if (_comp(k, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }
        return (x);
    }

    iterator begin()
    {
        return (iterator(_root->minimum(_root, _NIL), _root, _NIL));
    }

    const_iterator begin() const
    {
        return (const_iterator(_root->minimum(_root, _NIL), _root, _NIL));
    }

    iterator end()
    {
        return (iterator(_NIL, _root, _NIL));
    }

    const_iterator end() const
    {
        return (const_iterator(_NIL, _root, _NIL));
    }

    reverse_iterator rbegin()
    {
        return (reverse_iterator(begin()));
    }

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(begin()));
    }

    reverse_iterator rend()
    {
        return (reverse_iterator(end()));
    }

    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(end()));
    }

    iterator lower_bound(const key_type& k)
    {
        if (is_exist(k))
            return (iterator(find_node(k), _root, _NIL));

        node_ptr x = _root;
        node_ptr y = _NIL;
        node_ptr bound = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }
        bound = successor(y);
        return (iterator(y, _root, _NIL));
    }

    const_iterator lower_bound(const key_type& k) const
    {
        if (is_exist(k))
            return (const_iterator(find_node(k), _root, _NIL));

        node_ptr x = _root;
        node_ptr y = _NIL;
        node_ptr bound = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }
        bound = successor(y);
        return (const_iterator(y, _root, _NIL));
        
    }

    iterator upper_bound (const key_type& k)
    {
        node_ptr x = _root;
        node_ptr y = _NIL;
        node_ptr bound = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }
        bound = predecessor(y);
        return (iterator(y, _root, _NIL));
    }
    
    const_iterator upper_bound (const key_type& k) const
    {
        node_ptr x = _root;
        node_ptr y = _NIL;
        node_ptr bound = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }
        bound = predecessor(y);
        return (const_iterator(y, _root, _NIL));
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

    void insert_node_with_hint(iterator hint, node_ptr node)
    {
        node_ptr y = hint._node;

        // 트리에 노드 연결
        node->_parent = y;
        if (_comp(node->_data.first, y->_data.first))
            y->_left = node;
        else
            y->_right = node;

        // fixup 실행
        insert_fixup(node);
    }

    void insert_node_not_empty(node_ptr node)
    {
        node_ptr y = _NIL;
        node_ptr x = _root;
        // key 값 비교하며 트리 이동
        while (x != _NIL)
        {
            y = x;
            if (_comp(node->_data.first, x->_data.first))
                x = x->_left;
            else
                x = x->_right;
        }

        // 트리에 노드 연결
        node->_parent = y;
        if (_comp(node->_data.first, y->_data.first))
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