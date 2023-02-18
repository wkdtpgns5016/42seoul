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
    typedef T*                          value_ptr;
    typedef rb_tree_node<value_type>    node_type;
    typedef node_type*                  node_ptr;
    typedef const node_type*            const_node_ptr;

    rb_tree_color   _color;
    node_ptr        _parent;
    node_ptr        _left;
    node_ptr        _right;
    value_type      _data;

    rb_tree_node() {}
    rb_tree_node(rb_tree_color color, node_ptr parent, node_ptr left, node_ptr right, value_type data)
    : _color(color), _parent(parent), _left(left), _right(right), _data(data) {}
    ~rb_tree_node() {}

};

template < class T, class Ref, class Point> 
class rb_tree_itterator
{
    public:
    typedef bidirectional_iterator_tag		            iterator_category;
    typedef T			        						value_type;
    typedef ptrdiff_t                                   difference_type;
    typedef Point			        					pointer;
    typedef Ref		        							reference;

    // typedef rb_tree_itterator<value_type, value_type&, value_type*>             iterator;
    // typedef rb_tree_itterator<value_type, const value_type&, const value_type*> const_iterator;

    typedef rb_tree_node<value_type>                    node_type;
    typedef rb_tree_node<value_type>*                   node_ptr;

    protected:
    node_ptr    _node;
    node_ptr    _root;
    node_ptr    _NIL;

    public:
    rb_tree_itterator() : _node(), _NIL() {}
    rb_tree_itterator(node_ptr node, node_ptr root, node_ptr NIL)
    { 
        _node = node;
        _root = root;
        _NIL = NIL;
    }
    rb_tree_itterator(const rb_tree_itterator<value_type, value_type&, value_type*>& node) 
     : _node(node.base()), _root(node.get_root()), _NIL(node.get_nil()) {}


    reference operator*() const { return ((_node->_data)); }
    pointer operator->() const { return (&(operator*())); }
    
    rb_tree_itterator& operator++() 
    { 
        increment();
        return *this; 
    }

    rb_tree_itterator operator++(int) 
    {
        rb_tree_itterator temp = *this;
        increment();
        return (temp);
    }

    rb_tree_itterator& operator--() 
    { 
        decrement();
        return *this; 
    }

    rb_tree_itterator operator--(int) 
    {
        rb_tree_itterator temp = *this;
        decrement();
        return (temp);
    }

    node_ptr base() const { return (_node); }
    node_ptr get_root() const { return (_root); }
    node_ptr get_nil() const { return (_NIL); }

    private:
    void    increment()
    {
        if (_node == _NIL)
            _node = minimum(_root, _NIL);
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
            _node = maximum(_root, _NIL);
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

    node_ptr minimum(node_ptr node, node_ptr _NIL)
    {
        node_ptr x = node;
        while (x->_left != _NIL)
            x = x->_left;
        return (x);
    }

    node_ptr maximum(node_ptr node, node_ptr _NIL)
    {
        node_ptr x = node;
        while (x->_right != _NIL)
            x = x->_right;
        return (x);
    }
    
};

template<class Iterator1, class Iterator2>
bool operator==(const rb_tree_itterator<Iterator1, Iterator1&, Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, Iterator2&, Iterator2*>& y)
{
    return (x.base() == y.base());
}

template<class Iterator1, class Iterator2>
bool operator==(const rb_tree_itterator<Iterator1, const Iterator1&, const Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, Iterator2&, Iterator2*>& y)
{
    return (x.base() == y.base());
}

template<class Iterator1, class Iterator2>
bool operator==(const rb_tree_itterator<Iterator1, Iterator1&, Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, const Iterator2&, const Iterator2*>& y)
{
    return (x.base() == y.base());
}

template<class Iterator1, class Iterator2>
bool operator==(const rb_tree_itterator<Iterator1, const Iterator1&, const Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, const Iterator2&, const Iterator2*>& y)
{
    return (x.base() == y.base());
}

template<class Iterator1, class Iterator2>
bool operator!=(const rb_tree_itterator<Iterator1, Iterator1&, Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, Iterator2&, Iterator2*>& y)
{
    return (x.base() != y.base());
}

template<class Iterator1, class Iterator2>
bool operator!=(const rb_tree_itterator<Iterator1, const Iterator1&, const Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, Iterator2&, Iterator2*>& y)
{
    return (x.base() != y.base());
}

template<class Iterator1, class Iterator2>
bool operator!=(const rb_tree_itterator<Iterator1, Iterator1&, Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, const Iterator2&, const Iterator2*>& y)
{
    return (x.base() != y.base());
}

template<class Iterator1, class Iterator2>
bool operator!=(const rb_tree_itterator<Iterator1, const Iterator1&, const Iterator1*>& x, 
                const rb_tree_itterator<Iterator2, const Iterator2&, const Iterator2*>& y)
{
    return (x.base() != y.base());
}



template < class Key, class T, class KeyOfValue, class Compare, class Allocator > 
class rb_tree
{
    public:
    typedef Key                                             key_type;
    typedef T                                               value_type;
    typedef Allocator                                       allocator_type;
    typedef Compare                                         key_compare;
    typedef ft::rb_tree_node<value_type>                    node_type;
    typedef std::allocator<node_type>                       node_allocator_type;
    typedef typename node_type::node_ptr                    node_ptr;
    typedef typename node_type::const_node_ptr              const_node_ptr;

    typedef ft::rb_tree_itterator<T, T&, T*>                iterator;
    typedef ft::rb_tree_itterator<T, const T&, const T*>    const_iterator;
    typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

    protected:
    node_allocator_type _node_alloc;
    node_ptr            _root;
    node_ptr            _NIL;
    key_compare         _comp;
    size_t              _size;

    public:
    rb_tree() :  _size(0) 
    {
        _NIL = alloc_node(BLACK, value_type());
        _NIL->_left = _NIL;
        _NIL->_right = _NIL;
        _NIL->_parent = _NIL;
        _root = _NIL;
    }

    rb_tree(const key_compare& comp, const allocator_type& alloc) : _node_alloc(alloc), _comp(comp), _size(0)
    {
        _NIL = alloc_node(BLACK, value_type());
        _NIL->_left = _NIL;
        _NIL->_right = _NIL;
        _NIL->_parent = _NIL;
        _root = _NIL;
    }

    template <class InputIterator>  
    rb_tree(InputIterator first, InputIterator last, const key_compare& comp , const allocator_type& alloc) : _node_alloc(alloc), _comp(comp), _size(0)
    {
        _NIL = alloc_node(BLACK, value_type());
        _NIL->_left = _NIL;
        _NIL->_right = _NIL;
        _NIL->_parent = _NIL;
        _root = _NIL;
        insert_node(first, last);
    }

    rb_tree(const rb_tree& tree) : _size(0)
    {
        if (this == &tree)
            return ;
        clear();
        dealloc_nil();
        *this = rb_tree(tree.begin(), tree.end(), tree.get_comp(), tree.get_allocator());
    }

    void swap(rb_tree& tree)
    {
        node_ptr temp_root = _root;
        node_ptr temp_nil = _NIL;
        size_t temp_size = _size;

        _root = tree._root;
        _NIL = tree._NIL;
        _size = tree._size;
        tree._root = temp_root;
        tree._NIL = temp_nil;
        tree._size = temp_size;
    }

    node_ptr make_node(const value_type& data)
    {
        node_ptr new_node = alloc_node(RED, data);
        new_node->_left = _NIL;
        new_node->_right = _NIL;
        new_node->_parent = _NIL;
        return (new_node);
    }

    node_ptr minimum(node_ptr node, node_ptr _NIL) const
    {
        node_ptr x = node;
        while (x->_left != _NIL)
            x = x->_left;
        return (x);
    }

    node_ptr maximum(node_ptr node, node_ptr _NIL) const
    {
        node_ptr x = node;
        while (x->_right != _NIL)
            x = x->_right;
        return (x);
    }

    node_ptr successor(node_ptr node) const 
    {
        node_ptr x = node;
        node_ptr y = node->_parent;
        if (node->_right != _NIL)
            return (minimum(x->_right, _NIL));
        while (y != _NIL && x == y->_right)
        {
            x = y;
            y = y->_parent;
        }
        return (y);
    }

    node_ptr predecessor(node_ptr node) const
    {
        node_ptr x = node;
        node_ptr y = node->_parent;
        if (node->_left != _NIL)
            return (maximum(x->_left, _NIL));
        while (y != _NIL && x == y->_left)
        {
            x = y;
            y = y->_parent;
        }
        return (y);
    }

    bool is_empty() const
    {
        if (_root == _NIL)
            return (true);
        return (false);
    }

    bool is_exist(const key_type& k) const
    {
        if (find_node(k) != _NIL)
            return (true);
        return (false);
    }

    bool is_hint(iterator hint, const key_type& k)
    {
        node_ptr hint_node = hint.base();
        node_ptr hint_next_node = (hint++).base();

        if (hint_node == _NIL)
        {
            node_ptr max = maximum(_root, _NIL);
            if (_comp(KeyOfValue()(max->_data), k))
                return (true);
            return (false);
        }
        else
        {
            if (_comp(KeyOfValue()(hint_next_node->_data), k))
            {
                if (_comp(k, KeyOfValue()(hint_next_node->_data)))
                    return (true);
            }
            return (false);
        }
    }

    node_ptr get_root() const { return (_root); }
    node_ptr get_nil() const { return (_NIL); }
    size_t get_size() const { return (_size); }
    allocator_type get_allocator() const { return (_node_alloc); }
    key_compare get_comp() const { return (_comp); }

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
            node_ptr node = make_node(*first);
            if (!is_exist(KeyOfValue()(node->_data)))
                insert_node(node);
            first++;
        }
    }

    template <class InputIterator> 
    iterator insert_node(InputIterator hint, const value_type& data)
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

    iterator insert_node(const value_type& data)
    {
        node_ptr node = make_node(data);
        return (insert_node(node));
    }

    void delete_node(node_ptr node)
    {
        node_ptr y = _NIL;
        node_ptr x = _NIL;
        rb_tree_color color = node->_color;
        if (!is_exist(KeyOfValue()(node->_data)))
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
            y = predecessor(node);

            color = y->_color;
            x = y->_left;

            transplant(y, y->_left);
            y->_left = node->_left;
            y->_left->_parent = y;

            transplant(node, y);
            y->_right = node->_right;
            y->_right->_parent = y;
            y->_color = node->_color;

        }

        if (color == BLACK)
            delete_fixup(x);
        if (x == _NIL)
            x->_parent = _NIL;
        _node_alloc.deallocate(node, 1);
        _node_alloc.destroy(node);
        _size--;
    }

    void dealloc_nil()
    {
        _node_alloc.deallocate(_NIL, 1);
        _node_alloc.destroy(_NIL);
    }

    void clear()
    {
        inoder_dealloc_tree(_root);
    }

    void inoder_dealloc_tree(node_ptr node)
    {
        if (node != _NIL)
        {
            inoder_dealloc_tree(node->_left);
            inoder_dealloc_tree(node->_right);
            _node_alloc.destroy(node);
            _node_alloc.deallocate(node, 1);
        }
    }

    node_ptr find_node(const key_type & k) const
    {
        node_ptr x = _root;
        while (x != _NIL)
        {
            if (k == KeyOfValue()(x->_data))
                break ;
            if (_comp(k, KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }
        return (x);
    }

    iterator begin()
    {
        return (iterator(minimum(_root, _NIL), _root, _NIL));
    }

    const_iterator begin() const
    {
        return (const_iterator(minimum(_root, _NIL), _root, _NIL));
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
        return (reverse_iterator(end()));
    }

    const_reverse_iterator rbegin() const
    {
        return (const_reverse_iterator(end()));
    }

    reverse_iterator rend()
    {
        return (reverse_iterator(begin()));
    }

    const_reverse_iterator rend() const
    {
        return (const_reverse_iterator(begin()));
    }

    iterator lower_bound(const key_type& k)
    {
        if (is_exist(k))
            return (iterator(find_node(k), _root, _NIL));

        node_ptr x = _root;
        node_ptr y = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }
        if (_comp(KeyOfValue()(y->_data), k))
            y = successor(y);
        return (iterator(y, _root, _NIL));
    }

    const_iterator lower_bound(const key_type& k) const
    {
        if (is_exist(k))
            return (const_iterator(find_node(k), _root, _NIL));

        node_ptr x = _root;
        node_ptr y = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }
        if (_comp(KeyOfValue()(y->_data), k))
            y = successor(y);
        return (const_iterator(y, _root, _NIL));
        
    }

    iterator upper_bound (const key_type& k)
    {
        node_ptr x = _root;
        node_ptr y = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }
        if (is_exist(k) || _comp(KeyOfValue()(y->_data), k))
            y = successor(y);
        return (iterator(y, _root, _NIL));
    }
    
    const_iterator upper_bound (const key_type& k) const
    {
        node_ptr x = _root;
        node_ptr y = _NIL;
        while (x != _NIL)
        {
            y = x;
            if (_comp(k, KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }
        if (is_exist(k) || _comp(KeyOfValue()(y->_data), k))
            y = successor(y);
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
        if (y->_left != _NIL)
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
        if (y->_right != _NIL)
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
        node_ptr y = hint.base();

        if (y == _NIL)
            y = maximum(_root, _NIL);

        // 트리에 노드 연결
        node->_parent = y;
        if (_comp(KeyOfValue()(node->_data), KeyOfValue()(y->_data)))
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
            if (_comp(KeyOfValue()(node->_data), KeyOfValue()(x->_data)))
                x = x->_left;
            else
                x = x->_right;
        }

        // 트리에 노드 연결
        node->_parent = y;
        if (_comp(KeyOfValue()(node->_data), KeyOfValue()(y->_data)))
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
        else                                   // Case 4 : 형제 오른쪽 자식이 Red
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

    void delete_right()
    {
        node_ptr tail = maximum(_root, _NIL);
        
        tail->_parent->_right = tail->_left;
        _node_alloc.destroy(tail);
        _node_alloc.deallocate(tail, 1);
        _size--;
    }
    void delete_left()
    {
        node_ptr tail = minimum(_root, _NIL);
        
        tail->_parent->_left = tail->_right;
        _node_alloc.destroy(tail);
        _node_alloc.deallocate(tail, 1);
        _size--;
    }
};

}

#endif