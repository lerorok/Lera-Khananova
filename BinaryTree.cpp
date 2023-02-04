#include <iostream>
using namespace std;

// Определим узел бинарного дерева.
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Создание шаблонного класса Tree для описания методов и самого бинарного дерева
template<class Type>
class Tree{
  public:
    Type root = NULL;
    
    Tree (Type root_new) {
        root = root_new;
    }
  
    Type get_new_node(int data) {
      Type newNode = new Node();
      newNode->data = data;
      newNode->left = newNode->right = NULL;
      return newNode;
    }
    
    // Функция добавления узла в дерево или замены имеющихся значений на новые
    void insert(Type* root, int data) {
      Type newNode = get_new_node(data);
      if (*root == NULL)
        *root = newNode;
      else if (data <= (*root)->data)
        insert(&(*root)->left, data);
      else
        insert(&(*root)->right, data);
    }
    
    
    // Прямой обход дерева (в возрастающем порядке)
    void inorder(Type root) {
      if (root == NULL)
        return;
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
    
    
    // Функция для осуществления замены значения дерева
    void replaceValue(Type root, int oldVal, int newVal) {
        if(root == NULL) return;
        if(root->data == oldVal) {
            root->data = newVal;
        }
        replaceValue(root->left, oldVal, newVal);
        replaceValue(root->right, oldVal, newVal);
    }
    
    
};


int main() {
    Tree<Node*> binary_tree(NULL);
    
    binary_tree.insert(&binary_tree.root, 150); // Заполним ветки дерева значениями
    binary_tree.insert(&binary_tree.root, 1246);
    binary_tree.insert(&binary_tree.root, 231);
    binary_tree.insert(&binary_tree.root, 927);
    binary_tree.insert(&binary_tree.root, 364);
    binary_tree.insert(&binary_tree.root, 248);
    binary_tree.insert(&binary_tree.root, 207);
    binary_tree.insert(&binary_tree.root, 1169);
    binary_tree.insert(&binary_tree.root, 522);
    binary_tree.insert(&binary_tree.root, 201);
    binary_tree.insert(&binary_tree.root, 819);
    
    binary_tree.replaceValue(binary_tree.root, 1246, 200); // Заменяем число 1246 на 200
    
    binary_tree.inorder(binary_tree.root); // Выводим дерево в порядке возрастания элементов ( Кроме 200, поскольку это - замененное число 1246 )
    
    return 0;
}
