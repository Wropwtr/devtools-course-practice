// Copyright 2017 Gvozdeva Viktoria

#include <include/queue.h>

template <class valType>
Queue <valType> :: Queue(int _maxSize)
{
    if ( _maxSize > 0) {
        maxSize = _maxSize;
        queuePtr = new valType [maxSize];
        len = 0;
        head = 0;
        tail = -1;
    }
    else throw "Size is incorrect!";
}

template <class valType>
bool Queue<valType> :: operator==(const Queue<valType>& Q) const
{
	if (this == &Q) return true;
	if (len != Q.len) return false;

	for (int i = 0; i < len; i++)
	{
		if (queuePtr[i] != Q.queuePtr[i])
			return false;
	}
	return true;
}

template <class valType>
Queue<valType>& Queue<valType> :: operator=(const Queue<valType>& Q)
{
		if (maxSize != Q.maxSize)
		{
			delete[] queuePtr;
			queuePtr = new valType[Q.maxSize];
		}
		maxSize = Q.maxSize;
		head = Q.head;
		tail = Q.tail;
		len = Q.len;
		for (int i = 0; i <= len; i++)
			queuePtr[i] = Q.queuePtr[i];
		return *this;
}
	
template <class valType>
Queue <valType> :: Queue()
{
		maxSize = 10;
		queuePtr = new valType[maxSize];
		len = 0;
		head = 0;
		tail = -1;
}
template <class valType>
//
//	QueueNode<Q> * work;
//
//	while (BeginQ) {
//		work = BeginQ->next;
//		delete BeginQ;
//		BeginQ = work;
//	}
//	BeginQ = 0;
//	LastQ = 0;
//	count = 0;
//}
Queue<valType> :: ~Queue() {
		delete[] queuePtr;
		queuePtr = NULL;
	/*delete []queuePtr;
	delete queuePtr;*/
	//len = -1;
}

template <class valType>
Queue <valType> :: Queue(const Queue& Q)
{
    maxSize = Q.maxSize;
	head = Q.head;
	tail = Q.tail;
    len = Q.len;
    queuePtr = new valType [maxSize];
    for (int i=0; i<= len; i++)
    queuePtr[i] = Q.queuePtr[i]; 
}

template <class valType>
int Queue <valType> :: GetMaxSize(void)const
{
	return maxSize;
}

template <class valType>
bool Queue <valType> :: IsFull() const
{
    return (len == maxSize);
}
template <class valType>
bool Queue <valType> :: IsEmpty() const
{
    return  ( len  == 0);
}
template <class valType>
void Queue <valType> :: Push(const valType &elem)
{
	if (queuePtr == NULL) throw "Queue was deleted!";
    if ( IsFull() ) throw "Queue is full!";

    else 
        if (tail == maxSize - 1) tail = 0;
        else 
            {
               tail++;
               queuePtr[tail] = elem;
               len++;
            }
}
template <class valType>
valType Queue <valType> :: Pop()
{
	if (queuePtr == NULL) throw "Queue was deleted!";
    if ( IsEmpty() ) throw "Queue is empty!";
    else
    {
        valType elem = queuePtr[head];
        if ( head == maxSize - 1 ) head = 0;
        else 
            head--;
        len--;
        return elem;
    }
}
