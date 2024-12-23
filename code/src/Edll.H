#ifndef EDLL_H
#define EDLL_H

#include "Deque.H"

template <class T>
class Edll : public Deque<T>
{
public:
    void addNodeAtParticularPosition(T dataParm, int posParm);
    void removeNodeAtParticularPosition(int posParm);

#if 0
    void print(void);
#endif
};

template <class T>
void Edll<T>::addNodeAtParticularPosition(T dataParm, int posParm)
{
    if(posParm == 0)
    {
        Deque<T>::pushFront(dataParm);
    }
    else if(posParm == Deque<T>::mNodeCount)
    {
        Deque<T>::pushBack(dataParm);
    }
    else if(posParm <= Deque<T>::mNodeCount)
    {
        Node<T>* sTempNode = Deque<T>::mHead;
        for(unsigned int sIterator = 0; sIterator < posParm - 1; sIterator++)
        {
            sTempNode = sTempNode->mNext;
            cout << "Iteration: " << sIterator << endl;
        }
        Node<T>* sNewNode = new Node<T>;
        sNewNode->mdata = dataParm;
        sNewNode->mNext = sTempNode->mNext;
        sNewNode->mPrev = sTempNode;
        sTempNode->mNext->mPrev = sNewNode;
        sTempNode->mNext = sNewNode;
        ++Deque<T>::mNodeCount;
    }
    else
    {
        cout << "Invalid Position passed, pass a valid position between 0 : " << Deque<T>::mNodeCount << endl;
    }
}

template <class T>
void Edll<T>::removeNodeAtParticularPosition(int posParm)
{
    if(posParm == 0)
    {
        Deque<T>::popFront();
    }
    else if(posParm == Deque<T>::mNodeCount)
    {
        Deque<T>::popBack();
    } 
    else if(posParm < Deque<T>::mNodeCount)
    {
        Node<T>* sTempNode = Deque<T>::mHead;
        for(unsigned int sIterator = 0; sIterator < posParm; sIterator++)
        {
            sTempNode = sTempNode->mNext;
        }
        sTempNode->mPrev->mNext = sTempNode->mNext;
        sTempNode->mNext->mPrev = sTempNode->mPrev;
        delete(sTempNode);
        --Deque<T>::mNodeCount;
    }
    else
    {
        cout << "Invalid Position passed, pass a valid position between 0 :" << Deque<T>::mNodeCount << endl;
    }    
}

#if 0
template <class T>
void Edll<T>::print(void)
{
    if(Deque<T>::mHead == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node<T>* current = Deque<T>::mHead;
        while(current != NULL)
        {
            cout << current->mdata << " ";
            current = current->mNext;
        }
        cout << "\n";
    }
}
#endif

#endif