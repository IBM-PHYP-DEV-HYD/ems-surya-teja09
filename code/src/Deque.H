#ifndef DEQUE_H
#define DEQUE_H

#include "string.h"
#include <iostream>

using namespace std;

#define REAR_DIRECTION      -1
#define FRONT_DIRECTION      1

enum UserChoice
{
    DEFAULT                  = 0,
    INT_DEQUE                = 1,
    FLOAT_DEQUE              = 2,
    STRING_DEQUE             = 3,
    STRUCT_DEQUE             = 4,
};

/*Structure to store the Node information: Data, Previous Node, Next Node */
template <class T>
struct Node
{
    T mdata;
    Node* mPrev;
    Node* mNext;

    Node(T valueParm);
};

template <class T>
Node<T>::Node(T valueParm) : mdata(valueParm), mPrev(NULL), mNext(NULL){}

/*Deque and methods to perform operation on the Deque*/
template <class T>
class Deque
{
public:
    Node<T>* mHead;
    Node<T>* mRear;
    int mNodeCount;     // Number nodes present in the Deque

public:
    void pushFront(T dataParm);
    void pushBack(T dataParm);
    void popFront(void);
    void popBack(void);
    T front(void);
    T rear(void);
    int getSize(void);
    void reSizeDeque(int sizeParm, T defaultValueParm, int directionParm);
    void clearDeque(void);
    void createDequeWithGivenSize(int sizeParm, T defaultValueParm);
    Deque();
    ~Deque();
};

template <class T>
Deque<T>::Deque(void) : mHead(NULL), mRear(NULL), mNodeCount(0){}

template <class T>
Deque<T>::~Deque()
{
    clearDeque();
}

// Student structure to store user defined data to the Deque
struct Student
{
    string mName;
    int mAge;
    int mRollNo;
    char mGender;

    // Overloading of input and output operators
    friend ostream& operator<<(ostream& os, const Student& s)
    {
        os << "{Name: " << s.mName << ", Age: " << s.mAge << ", Roll Number: " << s.mRollNo << ", Gender: " << s.mGender <<"}";
        return os;
    }

    friend istream& operator>>(istream& is, Student& s)
    {
        cout << "Enter name: ";
        is >> s.mName;
        cout << "Enter age: ";
        is >> s.mAge;
        cout << "Enter Roll Number: ";
        is >> s.mRollNo;
        cout << "Enter Gender: ";
        is >> s.mGender;
        return is;
    }
};

/*This funtion helps to add the element to the Deque from the front end
@return: Void
@params: Data to be added to the Deque
*/
template <class T>
void Deque<T>::pushFront(T dataParm)
{
    Node<T>* sNewNode = new Node<T>(dataParm);  

    //sNewNode->mdata = dataParm;
    sNewNode->mPrev = NULL;

    if(mHead == NULL)
    {
        mHead = mRear = sNewNode;
        sNewNode->mNext = NULL;
    }
    else
    {
        sNewNode->mNext = mHead;
        mHead->mPrev = sNewNode;
        mHead = sNewNode;
    }
    ++mNodeCount;
}

/** This funtion helps to add the element to the Deque from the rear end
@return: void
@params: Data to be added to the Deque
*/
template <class T>
void Deque<T>::pushBack(T dataParm)
{
    Node<T>* sNewNode = new Node<T>(dataParm); 

    //sNewNode->mdata = dataParm;

    sNewNode->mNext = NULL;    

    if(mHead == NULL)
    {
        mHead = mRear = sNewNode;
        sNewNode->mNext = NULL;
    } 
    else
    {
        sNewNode->mPrev = mRear;
        mRear->mNext = sNewNode;
        mRear= sNewNode;
    }   
    ++mNodeCount;
}

/** This funtion helps to removes the element to the Deque from the front end
@return: void
@params: void
*/
template <class T>
void Deque<T>::popFront(void)
{
    Node<T>* sTempNode;
    sTempNode = mHead;

    if((mRear == NULL) && (mHead == NULL))
    {
        cout << "No elemenets found" << endl;
        return;
    }
    else if(mHead->mNext == NULL)
    {
        mRear = NULL;
        mHead = NULL;       
    }
    else
    {
        mHead = mHead->mNext;
        mHead->mPrev = NULL;
    }
    delete(sTempNode);
    --mNodeCount;
}

/** This funtion helps to removes the element to the Deque from the rear end
@return: void
@params: void
*/
template <class T>
void Deque<T>::popBack(void)
{
    Node<T>* sTempNode;
    sTempNode = mRear;

    if((mRear == NULL) && (mHead == NULL))
    {
        cout << "No elemenets found" << endl;
        return;
    }
    else if(mRear->mPrev == NULL)
    {
        mRear = NULL;
        mHead = NULL;
    }
    else
    {
        mRear = mRear->mPrev;
        mRear->mNext = NULL;
    }
    delete(sTempNode);
    --mNodeCount;
}

/** This funtion returns the first elemenet present in the deque
@return: Template class data
@params: void
*/
template <class T>
T Deque<T>::front(void)
{
    return mHead->mdata;
}

/** This funtion returns the last elemenet present in the deque
@return: Template class data
@params: void
*/
template <class T>
T Deque<T>::rear(void)
{
    return mRear->mdata;
}

/** This funtion returns the size/number of elements present inside the deque
@return: int
@params: void
*/
template <class T>
int Deque<T>::getSize(void)
{
    return mNodeCount;
}

/** This funtion resizes the Deque according to the given size by the user in defined direction
@return: void
@param: 1. int
        2. Default values for the resized deque
        3. Direction of the resize.
*/
template <class T>
void Deque<T>::reSizeDeque(int sizeParm, T defaultValueParm, int directionParm)
{
    if(sizeParm > mNodeCount)
    {
        sizeParm = sizeParm - mNodeCount;
        if(directionParm == REAR_DIRECTION)
        {
            for(uint8_t sIterator = 0; sIterator < sizeParm; sIterator++)
            {
                pushBack(defaultValueParm);
            }
        }
        else if(directionParm == FRONT_DIRECTION)
        {
            for(uint8_t sIterator = 0; sIterator < sizeParm; sIterator++)
            {
                pushFront(defaultValueParm);
            }
        }
    }
    else if(sizeParm < mNodeCount)
    {
        int sUserDecision = 0;
        cout << "Do you really want to delete the elements: " << endl << "1. Yes \r\n" << "2. No \r\n" << endl;

        cin >> sUserDecision;
        switch(sUserDecision)
        {
            case 1:
            {
                if(directionParm == REAR_DIRECTION)
                {
                    while(mNodeCount != sizeParm)
                    {
                        popBack();
                    }
                }
                else if(directionParm == FRONT_DIRECTION)
                {
                    while(mNodeCount != sizeParm)
                    {
                        popFront();
                    }
                }
                break;
            }
            case 2:
            {
                /*Free flow to default condition*/
            }
            default:
            {
                return;
            }
        }
    }
}

/** This funtion clears all the elements present in the deque
@return: void
@params: void
*/
template <class T>
void Deque<T>::clearDeque(void)
{
    if(mHead == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node<T>* sCurrNode;
        while(mHead != NULL)
        {
            sCurrNode = mHead;
            mHead = mHead->mNext;
            delete(sCurrNode);
            --mNodeCount;
        }
    }
}

/** This funtion creates an deque with specified size by the user
@return: void
@params: 1. int.
         2. Default value.
*/
template <class T>
void Deque<T>::createDequeWithGivenSize(int sizeParm, T defaultValueParm)
{
    if(mHead == NULL)
    {
        Node<T>* sNewNode = new Node<T>;
        Node<T>* sCurrNode;
        sNewNode->mdata = defaultValueParm;
        mHead = mRear = sNewNode;
        sCurrNode = mHead;
        sNewNode->mPrev = NULL;
        sNewNode->mNext = NULL;
        ++mNodeCount;
        for(uint8_t sIterator = 1; sIterator < sizeParm; sIterator++)
        {
            Node<T>* sNewNode = new Node<T>;
            sCurrNode->mNext = sNewNode;
            sNewNode->mPrev = sCurrNode;
            sNewNode->mNext = NULL;
            sNewNode->mdata = defaultValueParm;
            mRear = sNewNode;
            sCurrNode = sNewNode;
            ++mNodeCount;
        }
    }
}

#endif