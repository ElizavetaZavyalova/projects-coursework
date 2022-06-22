#include <list>
#include <iostream>
#include <execution>
#include <algorithm>

struct IdSplay;
 
template<typename Tkey>
class comparer
{
public:
    virtual int compare(const Tkey& left, const Tkey& right) = 0;
    virtual ~comparer() = default;

};

 
template<typename Tkey>
class Comparer : public comparer <Tkey>
{

public:
    int compare(const Tkey& left, const Tkey& right)override {

        if (left > right)
            return 1;
        if (left < right)
            return -1;
        else
            return 0;
    }
    ~Comparer() {}
};

template<typename Tkey> 
class Splay {
    friend struct IdSplay;
private:
    struct SplayNode {
        SplayNode* leftChild=nullptr;
        SplayNode* rightChild = nullptr;
        SplayNode* parent = nullptr;
        Tkey data;
        std::list<IdSplay*> ids;
        SplayNode(const Tkey& key = Tkey())
            : leftChild(nullptr), rightChild(nullptr), parent(nullptr), data(key) {}
    };
    void clear(SplayNode* Node) {
        if (Node != nullptr) {
            clear(Node->leftChild);
            clear(Node->rightChild);
            delete Node;
        }

    }
    SplayNode* root = nullptr;
    comparer<Tkey>* compare = nullptr;
private:
    SplayNode* _Successor(SplayNode* localRoot) const {
        SplayNode* successor = localRoot;

        if (successor->rightChild != nullptr) {
            successor = _Minimum(successor->rightChild);
        }
        else {
            while (successor != root
                || successor != successor->parent->leftChild) {
                successor = successor->parent;
            }
        }

        return successor;
    }

    SplayNode* _Predecessor(SplayNode* localRoot) const {
        SplayNode* predecessor = localRoot;

        if (predecessor->leftChild != nullptr) {
            predecessor = _Maximum(predecessor->leftChild);
        }
        else {
            while (predecessor != root
                || predecessor != predecessor->parent->rightChild) {
                predecessor = predecessor->parent;
            }
        }

        return predecessor;
    }

    SplayNode* _Minimum(SplayNode* localRoot) const {
        SplayNode* minimum = localRoot;

        while (minimum->leftChild != nullptr)
            minimum = minimum->leftChild;

        return minimum;
    }

    SplayNode* _Maximum(SplayNode* localRoot) const {
        SplayNode* maximum = localRoot;

        while (maximum->rightChild != nullptr)
            maximum = maximum->rightChild;

        return maximum;
    }

    SplayNode* _Search(const Tkey& key, bool splay=1) {
        SplayNode* searchedElement = root;
        while (searchedElement != nullptr) {
            if (this->compare->compare(key, searchedElement->data) > 0) {

                searchedElement = searchedElement->rightChild;
            }
            else if (this->compare->compare(key, searchedElement->data) < 0) {

                searchedElement = searchedElement->leftChild;
            }
            else if (this->compare->compare(key, searchedElement->data) == 0) {
                if (splay) {
                    _Splay(searchedElement);
                }
                return searchedElement;
            }
        }

        return searchedElement;
    }

    void _LeftRotate(SplayNode* localRoot) {
        SplayNode* rightChild = localRoot->rightChild;

        localRoot->rightChild = rightChild->leftChild;
        if (rightChild->leftChild != nullptr)
            rightChild->leftChild->parent = localRoot;

        _Transplant(localRoot, rightChild);

        rightChild->leftChild = localRoot;
        rightChild->leftChild->parent = rightChild;
    }

    void _RightRotate(SplayNode* localRoot) {
        SplayNode* leftChild = localRoot->leftChild;

        localRoot->leftChild = leftChild->rightChild;
        if (leftChild->rightChild != nullptr)
            leftChild->rightChild->parent = localRoot;

        _Transplant(localRoot, leftChild);

        leftChild->rightChild = localRoot;
        leftChild->rightChild->parent = leftChild;
    }

    void _Transplant(SplayNode* localParent, SplayNode* localChild) {
        if (localParent->parent == nullptr)
            root = localChild;
        else if (localParent == localParent->parent->leftChild)
            localParent->parent->leftChild = localChild;
        else if (localParent == localParent->parent->rightChild)
            localParent->parent->rightChild = localChild;

        if (localChild != nullptr)
            localChild->parent = localParent->parent;
    }
    void _Remove(SplayNode* removeElement = nullptr) {

        if (removeElement != nullptr) {
            if (removeElement->rightChild == nullptr)
                _Transplant(removeElement, removeElement->leftChild);
            else if (removeElement->leftChild == nullptr)
                _Transplant(removeElement, removeElement->rightChild);
            else {
                SplayNode* newLocalRoot = _Minimum(removeElement->rightChild);

                if (newLocalRoot->parent != removeElement) {

                    _Transplant(newLocalRoot, newLocalRoot->rightChild);

                    newLocalRoot->rightChild = removeElement->rightChild;
                    newLocalRoot->rightChild->parent = newLocalRoot;
                }

                _Transplant(removeElement, newLocalRoot);

                newLocalRoot->leftChild = removeElement->leftChild;
                newLocalRoot->leftChild->parent = newLocalRoot;

                _Splay(newLocalRoot);
            }

            delete removeElement;
        }
    }
    void _Splay(SplayNode* pivotElement) {
        while (pivotElement != root) {
            if (pivotElement->parent == root) {

                if (pivotElement == pivotElement->parent->leftChild) {
                    _RightRotate(pivotElement->parent);
                }
                else if (pivotElement == pivotElement->parent->rightChild) {
                    _LeftRotate(pivotElement->parent);
                }
            }
            else {
                // Zig-Zig step.
                if (pivotElement == pivotElement->parent->leftChild &&
                    pivotElement->parent == pivotElement->parent->parent->leftChild) {

                    _RightRotate(pivotElement->parent->parent);
                    _RightRotate(pivotElement->parent);

                }
                else if (pivotElement == pivotElement->parent->rightChild &&
                    pivotElement->parent == pivotElement->parent->parent->rightChild) {

                    _LeftRotate(pivotElement->parent->parent);
                    _LeftRotate(pivotElement->parent);
                }
                // Zig-Zag step.
                else if (pivotElement == pivotElement->parent->rightChild &&
                    pivotElement->parent == pivotElement->parent->parent->leftChild) {

                    _LeftRotate(pivotElement->parent);
                    _RightRotate(pivotElement->parent);

                }
                else if (pivotElement == pivotElement->parent->leftChild &&
                    pivotElement->parent == pivotElement->parent->parent->rightChild) {

                    _RightRotate(pivotElement->parent);
                    _LeftRotate(pivotElement->parent);
                }
            }
        }
    }
    bool remove_id(std::list<IdSplay*>&ids, IdSplay* id) {
         
            ids.remove(id);
            if (ids.empty()) {
                return 1;
            }
            return 0; 
         
    }
    void push_id(std::list<IdSplay*>&ids, IdSplay* id) {
        ids.push_back(id);
    }

public:
    Splay(comparer<Tkey>* compare):Splay() {
        set_compare(compare);
    }
    Splay() {
        root = nullptr;
       // this->compare = new Comparer;
    }
    void set_compare(comparer<Tkey>* compare) {
        this->compare= compare;
    }

    virtual ~Splay() {  
        clear(root);
    }
    SplayNode* Insert(const Tkey& key, IdSplay*id) {
        SplayNode* preInsertPlace = nullptr;
        SplayNode* insertPlace = root;

        while (insertPlace != nullptr) {
            preInsertPlace = insertPlace;

            if (this->compare->compare(key, insertPlace->data)> 0)
                insertPlace = insertPlace->rightChild;
            else if (this->compare->compare(key, insertPlace->data)< 0)
                insertPlace = insertPlace->leftChild;
            else if (this->compare->compare(key, insertPlace->data) == 0) {
                push_id(insertPlace->ids, id);
                _Splay(insertPlace);
                 return insertPlace;
            }
        }

        SplayNode* insertElement = new SplayNode(key);
        insertElement->parent = preInsertPlace;

        if (preInsertPlace == nullptr)
            root = insertElement;
        else if (this->compare->compare(insertElement->data, preInsertPlace->data) > 0)
            preInsertPlace->rightChild = insertElement;
        else if (this->compare->compare(insertElement->data, preInsertPlace->data) < 0)
            preInsertPlace->leftChild = insertElement;

        _Splay(insertElement);
        return insertElement;
    }

    void Remove(SplayNode* removeElement, IdSplay*id) {
        _Splay(removeElement);
        if (remove_id(removeElement->ids, id)) {
            _Remove(removeElement);
        }

     }
 
    void Search(SplayNode* SplayElement) {
        _Splay(SplayElement);
    }
    std::list<IdSplay*>& Search(const Tkey& key, bool splay=1) {
        SplayNode *FoundNode = _Search(key, splay);
        if (FoundNode != nullptr) {
            return FoundNode->ids;
            
        }
        throw  std::exception("key not found");
    }

    bool isEmpty() const { return root == nullptr; }

    Tkey Successor(const Tkey& key) {
        if (_Successor(_Search(key)) != nullptr) {
            return _Successor(_Search(key))->getValue();
        }
        else {
            return -1;
        }
    }

    Tkey Predecessor(const Tkey& key) {
        if (_Predecessor(_Search(key)) != nullptr) {
            return _Predecessor(_Search(key))->getValue();
        }
        else {
            return -1;
        }
    }
};
