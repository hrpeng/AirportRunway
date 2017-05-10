/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}
//--- Definition of move_to_front()
void Queue::move_to_front(QueueElement key)
{
    Queue::NodePointer ptr = myFront;
    
    if (empty())
        return;
    if (key == front())
        return;
    while (ptr->next->data != key){
        ptr = ptr->next;
        if (ptr == myBack)
            return;
        }
    if (ptr->next == myBack){
        ptr->next = NULL;
        myFront = new Node(myBack->data, myFront);
        delete myBack;
        myBack = ptr;
        return;
    }
    int d = ptr->next->data;
    Queue::NodePointer pt = ptr->next;
    ptr->next = ptr->next->next;
    myFront = new Node(d, myFront);
    delete pt;
    return;
    
}

void Queue:: merge_two_queues(Queue & q2)
{
	Queue newQ;
	while(myFront != 0 || q2.myFront != 0){
	if(myFront==0){
		while(q2.myFront != 0){
				newQ.enqueue(q2.myFront->data);
				q2.dequeue();
		}
	}else{
		if(q2.myFront==0){
		while(myFront != 0){
			newQ.enqueue(myFront->data);
			this->dequeue();
			}
		}else{
			while(myFront != 0 && q2.myFront != 0 && myFront->data <= q2.myFront->data){
				newQ.enqueue(myFront->data);
				this->dequeue();
			}	
			while(myFront != 0 && q2.myFront != 0 && myFront->data > q2.myFront->data){
				newQ.enqueue(q2.myFront->data);
				q2.dequeue();
			}
		}
	}
	}
	myFront = newQ.myFront;
	myBack = newQ.myBack;
  newQ.myFront = NULL;
  newQ.myBack = NULL;
	this->display(cout);
	q2.display(cout);
}

    
    this->~Queue();
    this->myFront = newQ.myFront;
    this->myBack = newQ.myBack;
    //cout << myFront << endl;
    //cout << myBack->data << endl;
    this->display(cout);
    q2->display(cout);
    queue2.display(cout);
    //return;
}



