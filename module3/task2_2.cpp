/*
 * Карбовский Сергей, гр. АПО-11
 * Задача 2. Порядок обхода
 * Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
 * Требуется построить бинарное дерево, заданное наивным порядком вставки.
 * Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K,
 * то узел K добавляется в правое поддерево root; иначе в левое поддерево root.
 * Выведите элементы в порядке pre-order (сверху вниз).
 */

#include <iostream>
#include <stack>
#include <cstddef>

template<class _T>
struct BinaryTreeNode
{
    typedef _T value_t;

    BinaryTreeNode(value_t key):
        key(key)
    {
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
    value_t key;
    BinaryTreeNode<value_t> *left;
    BinaryTreeNode<value_t> *right;
};


template <class _T>
class BinaryTree
{
public:
    typedef _T value_t;

    BinaryTree()
    {
        root = NULL;
    }
    ~BinaryTree()
    {
        delete root;
    }

    void add(value_t key)
    {
        BinaryTreeNode<value_t> *nodeToAppend = new BinaryTreeNode<value_t>(key);
        if (!root)
        {
            root = nodeToAppend;
            return;
        }

        BinaryTreeNode<value_t> *current = root;
        BinaryTreeNode<value_t> *next = root;

        while (next)
        {
            current = next;
            if (key <= current->key)
                next = next->left;
            else next = next->right;
        }
        if (key <= current->key)
            current->left = nodeToAppend;
        else current->right = nodeToAppend;
    }

    void preOrderPrint()
    {
        std::stack<BinaryTreeNode<value_t> *> nodes;
        nodes.push(root);
        BinaryTreeNode<value_t> *current = root;
        while (!nodes.empty())
        {
            current = nodes.top();
            std::cout << current->key;
            nodes.pop();
            if (current->right)
                nodes.push(current->right);
            if (current->left)
                nodes.push(current->left);
            //не печатать пробелы после последнего элемента
            if (!nodes.empty())
                std::cout << " ";
        }
    }

private:
        BinaryTreeNode<value_t> *root;
};

int main()
{
    BinaryTree<int> tree;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int key;
        std::cin >> key;
        tree.add(key);
    }
    tree.preOrderPrint();
    return 0;
}

