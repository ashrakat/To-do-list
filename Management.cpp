#include "Management.h"
#include<vector>
#include<iostream>
#include<fstream>
#include"FCISLL.h"
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;


FCISLL<Management>List;
Management::Management()
{
    //ctor
}

 void Management::set_name(string n)
 {
     name = n;
 }
void Management::set_description(string d)
{
    description = d;
}
void Management::set_Date(string D)
{
   Date = D;
}
void Management::set_priority(int P)
{
   priority = P ;
}
string Management::get_name()
{
   return name;
}
string Management::get_description()
{
    return description;
}
string Management::get_Date()
{
   return Date;
}
int Management::get_priority()
{
    return priority;
}
void Management::set_duration(int d)
{
    duration = d;
}
int Management::get_duration()
{
    return duration;
}
void Management::set_task(Management M)
{
    Date = M.Date ;
    description = M.description;
    priority = M.priority;
    name = M.name;
    duration = M.duration;
}
Management::Management(string n,string des ,string d, int p ,int dat)
{
    name = n;
    description = des;
    Date = d;
    priority = p;
    duration = dat;
}
istream& operator >> (istream& in, Management Manage)
{       in.ignore();
        getline(in,Manage.name);
        getline(in,Manage.description);
        getline(in,Manage.Date);
        in>>Manage.priority;
        in>>Manage.duration;
       return in;
}
ostream& operator << (ostream& out, Management Manage) {

       out<<Manage.name<<endl;
       out<<Manage.description<<endl;
       out<<Manage.Date<<endl;
       out<<Manage.priority<<endl;
       out<<Manage.duration<<endl;
        return out;
}
bool Management::operator <(const Management M)const
{
    return (priority < M.priority);
}
void Management::operator = (const Management M)
{
    priority = M.priority;
    name = M.name;
    Date = M.Date;
    description = M.description;
    duration = M.duration;
}
void Management::SendToFile(Management M)
{
  fstream Base;
  Base.open("MyTasks.txt",ios::out |ios::app | ios::ate);
  Base<<M.name<<endl;
  Base<<M.description<<endl;
  Base<<M.Date<<endl;
  Base<<M.priority<<endl;
  Base<<M.duration<<endl;
}
void Management::SortVector(vector<Management> &m)
{
    for (int i = 0 ;i < m.size() - 1; i++)
    {
        for(int j = i + 1 ; j < m.size() ;j++)
        {
            if(m[i].get_priority() < m[j].get_priority() )
               {
                   swap(m[i],m[j]);
               }
            else
            {}
        }
    }
}

vector<Management> Management ::load()
{
    fstream Base;
    string garbege;
    Base.open("MyTasks.txt", ios::in | ios::app);
    Management M;
    vector<Management> v;
    while(Base.good()){
    getline(Base,M.name);
    getline(Base,M.description);
    getline(Base,M.Date);
    Base>>M.priority;
    Base>>M.duration;
    getline(Base,garbege);
    if(Base.eof()) break;
    v.push_back(M);
    List.add(M);
    }
   List.Sort();
   return v;
}
vector<Management> Management::load(string FilesName)
{
    fstream Base;
    string garbege;
    Base.open( FilesName , ios::in | ios::app);
    Management M;
    vector<Management> v;
    while(Base.good()){
    getline(Base,M.name);
    getline(Base,M.description);
    getline(Base,M.Date);
    Base>>M.priority;
    Base>>M.duration;
    getline(Base,garbege);
    if(Base.eof()) break;
    v.push_back(M);
    List.add(M);
    }
   List.Sort();
   return v;
}

void Management::Display()
{
   Node<Management>*temp = new Node<Management>;
   temp = List.head;
   while(temp != NULL )
   {
       cout<<temp->getData() <<endl;
       temp = temp->getNext();
   }
}
bool Management::operator == (const Management M)
 {
     if( strcmp(name.c_str(), M.name.c_str()) and strcmp(name.c_str(), M.name.c_str()) and strcmp(description.c_str(), M.description.c_str()) and M.Date==Date and priority==M.priority)return true;
     return false;
 }
Management::~Management()
{
    //dtor
}

