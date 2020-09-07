#include <iostream>

class BST{
private:
    struct Node{
        Node *parent;
        Node *left;
        Node *right;
        int data;

        Node(int x){
            parent = left = right = nullptr;
            data = x;
        }
    };

    Node *removeNode(Node *root, int x){
        if(root == nullptr){
            std::cout << "Drzewo jest puste.\n";
            return root;
        }

        if(x < root->data)
            root->left = removeNode(root->left, x);
        else if(x > root->data)
            root->right = removeNode(root->right, x);
        else{
            if(root->left && root->right){
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = removeNode(root->right, temp->data);
            } else{
                Node *temp = (root->left) ? root->left : root->right;
                delete root;
                return temp;
            }
        }

        return root;
    }

    void inorder(Node *node, int tab = 0){
        if(node != nullptr){
            for(int i = 0; i < tab; i++)
                std::cout << "\t";
            std::cout << node->data << "\n";
            inorder(node->left, tab + 1);
            inorder(node->right, tab + 1);
        }
    }

    Node *root;

public:
    BST(){
        root = nullptr;
    }

    Node *findNode(int x){
        if(root == nullptr){
            std::cout << "Drzewo jest puste.\n";
            return root;
        }

        Node *temp = root;
        while(temp != nullptr){
            if(x < temp->data)
                temp = temp->left;
            else if(x > temp->data)
                temp = temp->right;
            else
                return temp;
        }

        std::cout << "Nie znaleziono zadanego elementu! ";
        return nullptr;
    }

    Node *findMin(Node *node){
        return (node->left) ? findMin(node->left) : node;
    }

    void addNode(int x){
        if(root == nullptr)
            root = new Node(x);
        else{
            Node *newNode = new Node(x);
            Node *temp = root;

            while(true){
                if(x < temp->data){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        newNode->parent = temp;
                        return;
                    } else{
                        temp = temp->left;
                    }
                } else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        newNode->parent = temp;
                        return;
                    } else{
                        temp = temp->right;
                    }
                }
            }
        }
    }

    Node *removeNode(int x){
        return removeNode(root, x);
    }

    void inorder(){
        return inorder(root);
    }
};

int main(){
    BST binaryTree;

    binaryTree.addNode(10);
    binaryTree.addNode(40);
    std::cout << binaryTree.findNode(43) << std::endl;
    binaryTree.addNode(7);
    binaryTree.addNode(42);
    binaryTree.addNode(23);
    binaryTree.addNode(5);
    binaryTree.addNode(65);
    binaryTree.addNode(9);
    binaryTree.addNode(37);
    binaryTree.addNode(41);
    binaryTree.inorder();

    binaryTree.removeNode(40);
    binaryTree.inorder();
    binaryTree.removeNode(10);
    binaryTree.inorder();
    binaryTree.removeNode(7);
    binaryTree.inorder();
}
