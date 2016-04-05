#include <iostream>
#include <conio.h>
#include <stdlib.h>
//int sze = 0;
using namespace std;

template <class T>
class Node {
  protected:
	T    data;        // to hold generic data of type T
	Node<T>* next;     // to hold pointer to next item
	Node<T>* prev;     // to hold pointer for previous item
	int   count;

  public:
		Node ()
		{next = prev = NULL; count = 0;}

		Node (T dataItem, Node<T>* nextPtr = NULL, Node<T>* prevPtr = NULL)
        {
            data = dataItem; next = nextPtr; prev = prevPtr;
        }

		Node<T>* getNext ()
		 {return next;}

		void setNext(Node<T>* ptr)
		{next = ptr;}

		Node<T>* getPrev ()
        {return prev;}

		void setPrev(Node<T>* ptr)
		{prev = ptr;}

		T  getData ()
        {return data;}

		void setData (T dataItem)
		 {data = dataItem;}


		template <class TT>
		friend ostream& operator<< (ostream& out, Node<TT> n);

		template<class TT>
        bool operator ==( Node<TT> &x){
		return(data==x.getData());
		}

		template <class TT>
        void operator=(Node<TT>& N)
        {
            data = N.data;
            next = N.getNext();
            prev = N.getPrev();
        }

};

/////////////////////////////
template <class T>
class FCISLL {
    public:
        Node<T> *head, *tail ;
    public:
        FCISLL() {head = NULL; tail = NULL;}
        ~FCISLL ();
        void addToHead(T item);
        void add(T itam);
        void addToTail(T item);
        void addToIndex(T item, int index);
        bool search (T item);
        template <class TT>
        friend ostream& operator<<(ostream&, FCISLL<TT>);
        void operator=(FCISLL<T>& M);
        void Sort();
        int sze = 0;
        void print();
        void Save();
        bool IsEmpty();
        ///////////////////////////////////Amr Magdy
        Node<T> removeTail();
        Node<T> removeHead();
        Node<T> removeFromIndex(int index);
        Node<T> removeItem(T value);
        void removewithPredicate(bool(*Predicate)(T &value_mine,T & value_now),T &task);

        // Amr Saeed ------------------------------------------------
        void Sort (bool (*comp)(T& item1, T& item2), int order);
        void Merge ( FCISLL <T> anotherList );

};
template <class T>

ostream& operator<< (ostream& out, Node<T> node) {
    out << node.getData() << endl<<"------------------"<<endl;
    return out;
}

////////////////////////////////
template <class T>
void FCISLL<T>::addToTail(T item) {
    Node<T>* ptr = new Node<T>(item, NULL);
    if (head == NULL)
        head = tail = ptr;
    else {
        tail->setNext(ptr);
        tail = ptr;
    }
    sze++;
}

template <class T>
void FCISLL<T>::addToHead(T item) {
    Node<T>* ptr = new Node<T>(item, head);
    head = ptr;
    if (tail == NULL)
        tail = ptr;
    sze++;
}

template <class T>
FCISLL<T>::~FCISLL () {}

template <class T>
void FCISLL<T>::addToIndex(T item, int index) {
    Node<T>* nPtr = new Node<T>(item, NULL);
    Node<T>* pPtr = head;
    for (int i = 0; pPtr != 0 && i < index - 1; i++)
       pPtr = pPtr->getNext();
    if (pPtr != 0 && !(index < 0)){
      if (index == 0)
         addToHead (item);
      else {
          nPtr->setNext(pPtr->getNext());
          pPtr->setNext(nPtr);
      }
    }
    if (tail == pPtr)
      tail = tail->getNext();
    sze++;
}
template<class T>
void FCISLL<T>::add(T itam)
{
    if(head == NULL)
        {addToHead(itam);}
    else
    {
        Node<T>* New = new Node<T>(itam ,NULL);
        New = head;
        while (New ->getNext() != NULL)
           New = New->getNext();

        Node<T>* temp = new Node<T>;
        temp ->setData(itam);
        temp->setNext(NULL);
        New->setNext(temp);
        tail = temp;
        tail->setPrev(New);
        sze++;
    }
}

template <class T>
bool FCISLL<T>::search(T item) {
    Node<T>* ptr = head;
    while (! t (ptr == NULL) && item != ptr->getData())
        ptr = ptr -> getNext();
    if (ptr != NULL)
        return true;
    else
        return false;
}

template <class T>
ostream& operator<< (ostream& stream, FCISLL<T> list) {
        if (list.head != 0) {
            Node<T>* ptr = list.head;
            stream << *ptr;
            while (ptr != list.tail) {
                ptr = ptr->getNext();
                stream << *ptr;
            }
            stream << "NULL" << endl;
        }
        return stream;
}
template <class T>
void FCISLL<T>::operator=(FCISLL<T>& M)
 {
      head = M->head;
      tail = M->tail;
      Node<T>* temp = new Node<T> ;
      temp = head;
      Node <T>* temp1 = new Node<T>;
      temp1 = M.head;
      while(temp1 != NULL)
      {
          temp = temp1;
          temp =  temp->getNext();
          temp1 = temp1->getNext();
      }
 }
template <class T>
void FCISLL<T>::Sort()
{
  int i = 0 ;
  Node<T> *temp = new Node<T>;
  Node<T> *Temppointer = new Node<T>;
  Node<T> *Swap = new Node<T>;
  temp = head;
  Temppointer = head->getNext();
  while(i < sze)
  {
    temp = head;
    Temppointer = temp ->getNext();
   while (Temppointer != NULL)
   {

      if (temp->getData() < Temppointer->getData())
          {
             Swap->setData(temp->getData());
             temp->setData(Temppointer->getData());
             Temppointer->setData(Swap->getData());
          }
      Temppointer = Temppointer->getNext();
      temp = temp->getNext();
    }
  i++;
  }
}
template <class T>
bool FCISLL<T>::IsEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
template <typename T>
Node<T> FCISLL<T>::removeHead(){
    Node<T> n;
if(head==nullptr){
    cout<<"List is empty"<<endl;
    return n;
}
else{
        Node<T>* temp=head;
        head=head->getNext();
        n=*temp;
        delete temp;
        return n;
}}


template<typename T>
void FCISLL<T>::removewithPredicate(bool(*Predicate)(T &value_mine,T & value_now),T &task){
Node<T> * ptr=head;int x=1; Management n;
while(ptr!=nullptr  ){
        n=ptr->getData();
    if((*Predicate)(n,task))removeFromIndex(x);
    x++;
    ptr=ptr->getNext();
}
}

template <typename T>
Node<T> FCISLL<T>::removeTail(){
      Node<T>* ptr = head;
    Node<T> n;
if(tail==nullptr){
    cout<<"List is empty"<<endl;
    return n;
}
else{
      Node<T> *tem =  head->getNext();
      while(tem->getNext()!=NULL)
      {
          ptr = ptr->getNext();
          tem = tem->getNext();
          if(tem == tail)
          {
              tail = ptr;
          }
      }
      ptr->setNext(NULL);
      n = *tem;
      delete tem;
      return n;
}
}
template<typename T>
Node<T> FCISLL<T>::removeItem(T value){
    Node<T> n;
    Node<T>* ptr = head;  int x=1;
    while(!(ptr->getData() == value) && ptr->getNext() != NULL){
        x++;
        ptr = ptr->getNext();
        if(ptr->getData() == value)
        {
            removeFromIndex(x);
            n = *ptr;
            return n;
        }
    }
    if(x==1){removeHead();return n;}
    else if(x==sze){removeTail();return n;}
    else if(x>sze){
        cout<<"Item doesn't exist"<<endl;
        return n;
        }

    else{
        n=*ptr;
        removeFromIndex(x);
            return n;
        }
}




template <class T>
Node<T> FCISLL<T>::removeFromIndex(int index){
Node<T> * temp=head; Node<T> *ptr=head; Node<T> n;
if(index==1){this->removeHead(); return *temp;}
else{
      Node<T> *tem =  head->getNext();
      for(int i = 1 ; i < index - 1; i++)
      {
          ptr = ptr->getNext();
          tem = tem->getNext();
          if(tem == tail)
          {
              tail = ptr;
          }
      }
      ptr->setNext(tem->getNext());
      n = *tem;
      delete tem;
      return n;
}
}
template <class T>
void FCISLL<T>::print(){
Node<T>* ptr=head;
Node<T>* ptr2 = tail;
if(ptr == NULL || ptr2 == NULL)
{
    cout<<"the List is empty "<<endl;
    return ;
}
while(ptr!=NULL){
cout<<*ptr;
ptr=ptr->getNext();

}
}
template<class T>
void FCISLL<T>::Save()
{
     fstream Base;
     Base.open("MyTasks.txt", ios::out | ios::trunc);
     Node<Management>*temp = new Node<Management>;
     temp = head;
     while(temp != NULL )
      {
       Base<<temp->getData();;
       temp = temp->getNext();
      }

}

//////////////////////////////


template <class T>
void FCISLL<T> :: Sort (bool (*comp)(T& item1, T& item2), int order)
{
   // Check if there is only one element in the list

   if ( head == tail ) return;

   // If order equals 1, then ascending order

   Node <T> * current = head;
   bool sorted = false;

   if ( order ){
       while ( !sorted )
       {
           current = head;
           sorted = true;
           while ( current -> getNext() != nullptr )
           {
               T currentData , nextData;
               currentData = current -> getData();
               nextData = current -> getNext() -> getData();
               if ( (*comp)( nextData , currentData ) ){
                   sorted = false;
                   current -> setData(nextData);
                   current -> getNext() -> setData (currentData);
               }
               current = current -> getNext();
           }
       }
   }

   // else if order equals 0, then Descending order

   else {
       while ( !sorted )
       {
           current = head;
           sorted = true;
           while ( current -> getNext() != nullptr )
           {
               T currentData , nextData;
               currentData = current -> getData();
               nextData = current -> getNext() -> getData();
               if ( (*comp)( currentData , nextData ) ){
                   sorted = false;
                   current -> setData(nextData);
                   current -> getNext() -> setData (currentData);
               }
               current = current -> getNext();
           }
       }
   }
}

// The most suitable sorting algorithms for linked lists are bubble sort, selection sort,
// insertion sort and the last one is shell sort because they are moving sequentially and
// if you want to reach elements in linked list you should move through it by sequence.
// The least suitable sorting algorithms are quick sort and merge sort as they require separating
// data into halves and this is very difficult with linked list since we are not dealing with indexes,
// but we are dealing with pointers to nodes.

template <class T>
void FCISLL <T> :: Merge ( FCISLL <T> anotherList )
{
    // If the first list is empty
    if ( head == nullptr )
    {
        head = anotherList.head;
        tail = anotherList.tail;
    }
    // If the second list is empty
    else if ( anotherList.head == nullptr )
    {
        return;
    }
    // If both lists have items
    else
    {
        tail -> setNext(anotherList.head);
        tail = anotherList.tail;
    }
    sze= sze + anotherList.sze + 2;
}




//#endif
