#include <iostream>

using namespace std;

template<class T>
class singly_LinkedList {

private:
    class node {
      public:
            T value;
            node* next;

          node()
          {
            value = T();
            next = nullptr;
         }

      }; // end class node.


  // declaration of head pointer
  private:
       node* head = nullptr;
       node *tail = nullptr;
       int Size =0;

  // start Push_front function
  public:
      // destructor declaration.
      ~singly_LinkedList()
      {
          Clear();

      } // end destructor.

      void Push_front(T val)
      {

          node* t = new node();
          t->value = val;
          t->next = head;
          if(!head) tail = head = t;
          head = t;
          Size++;


      } // end Push_front function.

      //precondition:linked list has at least one node.
      T& Front() {
         return head->value;
      }
      // postcondition: return the value of first node.

      // precondition: linked list has at least one node.
      T& Back() {
        return tail->value;
      } // postcondition: return the value of last node.


    //precondition:linked list has at least one node.
      void Pop_front() {

          node* t = head;
          head = head->next;
          if(!head) tail = nullptr;
          delete t;
          Size++;
      } // postcondition: remove one node from the beginning linkedlist.

        void Clear() {
            node *curent = head;
            while(curent != nullptr) {
                node* t = curent->next;
                delete curent;
                curent = t;
            }
           tail = head = nullptr;

        } //postcondition: remove all nodes from linked list

        //  implementation empty function
         bool Empty () {
         return (head == nullptr);
        } // postcondition: return true if linked list not had any node else return false.

        // implementation size function.
        int SIze() {
          return Size;
        } // postcondition: return the number of node in linked list.

       // declaration Push_back function
       void Push_back(T value) {

           node *t = new node();
           t->value = value;
           t->next = nullptr;
           if(!tail)
           {
               tail = head = t;
           }
           else{

                tail->next = t;
                tail = t;
           }
           Size++;
       } // postcondition: push one node at ending of linked_list


}; // end linked list implementation.


// start Queue class implementation.
template<class T>
class Queue{

 private:
     singly_LinkedList<T> ls;

 public:
     // declaration push function.
    void Push(T val) {

      ls.Push_back(val);
    } // postcondition: put one element at ending of the Queue.

    // implementation front function.
    T Front(){

        return ls.Front();

    } // postcondition: return one value from the front of Queue.

    // implementation pop function
    void pop() {

      ls.Pop_front();

    } // postcondition: remove one element from the beginning of queue.


         //implementation empty function
         bool Empty () {
         return ls.Empty();
        } // postcondition: return true if Queue not had any element else return false.


         // implementation size function.
        int SIze() {
          return ls.SIze();
        } // postcondition: return the number of node in linked list.



};







int main()
{
  Queue<int> q;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  while(!q.Empty())
  {

      cout <<q.Front();
      q.pop();
  }


    return 0;
}

