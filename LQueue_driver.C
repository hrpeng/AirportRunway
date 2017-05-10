/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;
    cout << "Input an element to move to the front of the queue:"<< endl;
    int num;
    cin >> num;
    q1.move_to_front(num);
    cout << "Contents of queue q1 after moving element to front (via  print):\n";
    print(q1);
    cout << endl;
    
    
   

   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();
   //system("PAUSE");

    Queue q3;
    Queue q4;
    q3 = q1;
    q4 = q1;
    cout << "Print before merge ";
    q3.merge_two_queues(q4);
    cout << "Print merged q4: ";
    q4.display(cout);
    cout << "Print merged q3: ";
    q3.display(cout);
    cout << endl;
    
    
    

   return 0;
}
