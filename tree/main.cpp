#include <iostream>


/*
 * Node is a generical class
 * that can be represented anything else
 * this will be use in a tree class
 * */
template <class T>
class Node{

private:
    Node *left;
    Node *right;
    T value;


public:

    Node(T value, Node *left=NULL, Node *right=NULL){
        this->value = value;
        this->left = left;
        this->right = right;
    }

    /*
     * get a value
     * @param None
     * @return T type [generic]
     * */
    inline T get_value(){
        return this->value;
    }

    /*
     * set value into node
     * @param value [generic]
     * */
    inline void set_value(T value){
        this->value = value;
    }

    /*
     * get node from the left side
     * @param None
     * @return node from the left
     * */
    inline Node* get_left_node(){
        return this->left;
    }

    /*
     * get node from the right side
     * @param None
     * @return node from the right
     * */
    inline Node* get_right_node(){
        return this->right;
    }

    /*
     * set node in a left side
     * @param node is a node
     * */
    inline void set_left(Node *node){
        this->left = node;
    }

    /*
     * set node in a right side
     * @param node is a node
     * */
    inline void set_right(Node *node){
        this->right = node;
    }
};


/*
 * A binary tree is a special
 * type of graph that store
 * a maximum of two values
 * the ones on the left being
 * smaller than right.
 * */
template <class T>
class Tree {

private:
    Node <T> *root;

public:

    Tree(){
        this->root = NULL;
    }

    inline Node<T>* get_root(){
        return this->root;
    }

    inline void set_root(Node<T> *node){
        this->root = node;
    }

    inline void insert(T value){
        if(this->root == NULL){
            std::cout << "Create a ROOT node with value: " << value << std::endl;
            Node<T> *father = new Node<T>(value);
            this->root = father;
        }else{
            where_to_insert(this->root, value);
        }
    }

    inline void where_to_insert(Node<T> *node, T value)
    {
        if(node->get_value() > value){
            if(node->get_left_node() != NULL){
                where_to_insert(node->get_left_node(), value);
            }else{
                std::cout << "Create a left node with value: " << value << std::endl;
                Node<T> *new_node = new Node<T>(value);
                node->set_left(new_node);
            }
        }else{
            if(node->get_right_node() != NULL){
                where_to_insert(node->get_right_node(), value);
            }else{
                std::cout << "Create a right node with value: " << value << std::endl;
                Node<T> *new_node = new Node<T>(value);
                node->set_right(new_node);
            }
        }
    }

    inline void in_order(Node<T> *node){
        if(node != NULL){
            in_order(node->get_left_node());
            std::cout << node->get_value() << " ";
            in_order(node->get_right_node());
        }
    }

};


template<typename T>
inline void create_a_tree(){
    Tree<T> *tree = new Tree<T>();
    tree->insert(1);
    tree->insert(3);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(7);
    tree->insert(5);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);
    tree->in_order(tree->get_root());
}

int main() {
    create_a_tree<int>();

    return EXIT_SUCCESS;
}
