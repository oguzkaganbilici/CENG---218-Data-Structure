#include<iostream>
using namespace std;

class BTNode {
public:
    int key;
    BTNode *leftChild;
    BTNode *rightChild;

    BTNode(int x): key(x), leftChild(nullptr), rightChild(nullptr) {};
};

class BT {
private:
    BTNode *root;

    void insert(int x, BTNode *&t) {
        BTNode *newNode = new BTNode(x);

        if (t == nullptr) {
            t = newNode;
            return;
        }
        else if (x > t->key) insert(x, t->rightChild);
        else if (x < t->key) insert(x, t->leftChild);
        else {
            return;
        }
    }
    BTNode *clear(BTNode *root) {
        if (root == nullptr) return nullptr;

        root->leftChild = clear(root->leftChild);
        root->rightChild = clear(root->rightChild);
        delete root;
        return nullptr;
    }
    BTNode *findInOrderPre(BTNode *r) {
        if (r == nullptr) return nullptr;
        while (r->rightChild != nullptr) {
            r = r->rightChild;
        }
        return r;
    }
    BTNode *deleteNode(int x, BTNode *r) {
        if (r == nullptr) return nullptr;
        if (r->key < x) return deleteNode(x, r->rightChild);
        else if (r->key > x) {
            return deleteNode(x, r->leftChild);
        }
        else {
            if (!r->leftChild && !r->rightChild) {
                delete r;
                return nullptr;
            }
            else if (!r->rightChild) {
                BTNode *temp = r->leftChild;
                delete r;
                return temp;
            }
            else if (!r->leftChild) {
                BTNode *temp = r->rightChild;
                delete r;
                return temp;
            }
            else {
                BTNode *minNode = findInOrderPre(r->leftChild);
                r->key = minNode->key;
                r->leftChild = deleteNode(minNode->key, r->leftChild);
            }
        }
        return r;
    }
    int height(BTNode *root) {
        if (root == nullptr) return 0;

        int leftHeight = height(root->leftChild);
        int rightHeight = height(root->rightChild);

        if (leftHeight > rightHeight) return leftHeight+1;
        return rightHeight+1;
    }
    int totalSum(BTNode *root) {
        if (root == nullptr) return 0;
        return root->key + totalSum(root->rightChild) + totalSum(root->leftChild);
    }
    int maxVal(BTNode *t) {
        if (t == nullptr) return -1;
        if (t->rightChild) return maxVal(t->rightChild);
        return t->key;
    }
    int minVal(BTNode *t) {
        if (t == nullptr) return -1;
        if (t->leftChild) return minVal(t->leftChild);
        return t->key;
    }
    void inOrderTraversal(BTNode *r) {
        if (r == nullptr) return;
        inOrderTraversal(r->leftChild);
        cout<<r->key<< " -> ";
        inOrderTraversal(r->rightChild);
    }
    void preOrderTraversal(BTNode *r) {
        if (r == nullptr) return;
        cout<<r->key<< " -> ";
        preOrderTraversal(r->leftChild);
        preOrderTraversal(r->rightChild);
    }
    void postOrderTraversal(BTNode *r) {
        if (r == nullptr) return;
        postOrderTraversal(r->leftChild);
        postOrderTraversal(r->rightChild);
        cout<<r->key<< " -> ";
    }
    bool isMemberRecursive(int x, BTNode *r) {
        if (r == nullptr) return false;
        if (r -> key == x) return true;
        if (r->key < x) return isMemberRecursive(x, r->rightChild);
        if (r->key > x) return isMemberRecursive(x, r->leftChild);
    }
    int toplam(BTNode *r) {
        if (r == nullptr ) return 0;
        int sum = r->key;
        sum += toplam(r->leftChild);
        sum += toplam(r->rightChild);
        return sum;
    }
public:
    BT(): root(nullptr) {};

    void clear() {
        root = clear(root);
    }
    void insert(int x) {
        insert(x, root);
    }
    void deleteNode(int x) {
        root = deleteNode(x, root);
    }
    int height() {
        return height(root);
    }
    int totalSum() {
        return totalSum(root);
    }
    int maxVal() {
        return maxVal(root);
    }
    int minVal() {
        return minVal(root);
    }
    void inOrderTraversal() {
        inOrderTraversal(root);
    }
    void preOrderTraversal() {
        preOrderTraversal(root);
    }
    void postOrderTraversal() {
        postOrderTraversal(root);
    }
    bool isMember(int x) {
        BTNode *walker = root;

        while (walker != nullptr) {
            if (walker -> key == x) return true;
            if (walker -> key < x) walker = walker -> rightChild;
            else {
                walker = walker -> leftChild;
            }
        }
        return false;
    }
    bool isMemberRecursive(int x) {
        return isMemberRecursive(x, root);
    }

    int toplam() {
        return toplam(root);
    }


};

int main() {
    BT newTree;
    newTree.insert(8);
    newTree.insert(5);
    newTree.insert(11);
    newTree.insert(1);
    newTree.insert(6);
    newTree.insert(9);
    newTree.insert(13);
    newTree.insert(3);
    newTree.insert(7);
    newTree.insert(4);

    cout<<"Max Val: "<<newTree.maxVal()<<endl;
    cout<<"Min Val: "<<newTree.minVal()<<endl;

    newTree.deleteNode(6);

    cout<<"In-Order Traversal: ";
    newTree.inOrderTraversal();
    cout<<endl<<"Pre-Order Traversal: ";
    newTree.preOrderTraversal();
    cout<<endl<<"Post-Order Traversal: ";
    newTree.postOrderTraversal();

    cout<<endl<<"is member? : "  << newTree.isMember(11);
    cout<<endl<<"is member? recursive: "<< newTree.isMember(2);


    cout<<endl<<"toplam: "<<newTree.totalSum();
}