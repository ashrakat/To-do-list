#include <iostream>
#include<fstream>
#include"Management.h"
#include"FCISLL.h"
using namespace std;


bool orderByDuration ( Management&, Management& );
bool orderByDate ( Management&, Management& );

int main()
{
    Management tasks,Base,child;
    vector<Management> linkedlist;
    vector<Management>linkedlist1;
    FCISLL<Management>lis;
    FCISLL<Management>lis1;
    linkedlist = Base.load();
    for(int  i = 0 ;i <linkedlist.size() ; i++)
        lis.add(linkedlist[i]);
    lis.Sort();
    cout<<"**************** List to do Stored in file ***************"<<endl;
    Base.Display();
    cout<<"Enter your Edit you would to make "<<endl;
    cout<<"1 - Merge Tasks"<<endl;
    cout<<"2 - remove form head "<<endl;
    cout<<"3 - remove from tail "<<endl;
    cout<<"4 - remove from index "<<endl;
    cout<<"5 - remove an item  "<<endl;
    cout<<"6 - remove with predicate date"<<endl;
    cout<<"7 - Add Tasks"<<endl;
    cout<<"8 - Sorting tasks"<<endl;
    int choice;
    cin>> choice;
     if(choice == 1)
    {
         string File_Name;
         cout<<"Enter file name "<<endl;
         cin>>File_Name;
         linkedlist1 = child.load(File_Name);
         for(int i = 0 ; i < linkedlist1.size() ; i++)
           lis1.add(linkedlist1[i]);
         lis.Merge(lis1);
        cout<<"New list after merging "<<endl;
    }
   else if(choice == 2)
    {
        if(!lis.IsEmpty())
         lis.removeHead();
        else
         cout<<"The list is already empty"<<endl;
    }
    else if(choice == 3)
    {
        if(!lis.IsEmpty())
         lis.removeTail();
        else
         cout<<"The list is already empty"<<endl;
    }
    else if(choice == 4)
    {
        int index;
        cin>>index;
        if(lis.sze >= index )
         lis.removeFromIndex(index);
        else
         cout<<"No such index "<<endl;
    }
    else if(choice == 5)
    {
        cin>>tasks;
        lis.removeItem(tasks);

    }
    else if(choice == 6)
    {   string s;
        cin>>s;
        Management K(s,s,s,0,0);
        lis.removewithPredicate((orderByDate),K);
    }
    else if(choice == 8)
    {
        int sorting;
        cout<<"1 - According to priority , 2 - According to duration , 3 - According to Date "<<endl;
        cin>>sorting;
        if(sorting == 1)
        {
            lis.Sort();
        }
        if(sorting == 2 || sorting == 3)
        {
            cout<<"if ascending press 1 , if descending press 0 "<<endl;
            int sort_choice;
            cin>>sort_choice;
            if(sorting == 2 && sort_choice == 1)
              lis.Sort(orderByDuration,1);
            else if(sorting == 2 && sort_choice == 0)
              lis.Sort(orderByDuration , 0);
            else if(sorting == 3 && sort_choice == 1)
              lis.Sort(orderByDate , 1) ;
            else if(sorting == 3 && sort_choice == 0)
              lis.Sort(orderByDate , 0);
        }
    }
    if (choice == 7)
    {
        string n,d,D;
        int p , dur;
        cin.ignore();
        getline(cin,n );
        getline(cin,d );
        getline(cin,D );
        tasks.set_name(n);
        tasks.set_description(d);
        tasks.set_Date(D);
        cin>> p >>dur;
        tasks.set_priority(p);
        tasks.set_duration(dur);
        lis.add(tasks);
    }
    lis.print();
    lis.Save();
    return 0;
}




bool orderByDuration ( Management& task1, Management& task2 )
{
    return (task1.duration < task2.duration);
}

bool orderByDate ( Management& task1 , Management& task2 )
{
    int day1 , month1 , year1;
    int day2 , month2 , year2;

    // First date conversion

    int counter = 0;

    if ( task1.Date[1] == '/' ){
        day1 = task1.Date[0] - '0';
        counter += 2;
    }
    else {
        day1 = (task1.Date[0] - '0')*10 + task1.Date[1] - '0';
        counter += 3;
    }
    if ( task1.Date[counter+1] == '/' ){
        month1 = task1.Date[counter] - '0';
        counter += 2;
    }
    else {
        month1 = (task1.Date[counter] - '0')*10 + task1.Date[counter+1] - '0';
        counter += 3;
    }
    year1 = (task1.Date[counter] - '0')*1000 + (task1.Date[counter+1] - '0')*100 +
            (task1.Date[counter+2] - '0')*10 + (task1.Date[counter+3] - '0');

    // Second date conversion

    counter = 0;

    if ( task2.Date[1] == '/' ){
        day2 = task2.Date[0] - '0';
        counter += 2;
    }
    else {
        day2 = (task2.Date[0] - '0')*10 + task2.Date[1] - '0';
        counter += 3;
    }
    if ( task2.Date[counter+1] == '/' ){
        month2 = task2.Date[counter] - '0';
        counter += 2;
    }
    else {
        month2 = (task2.Date[counter] - '0')*10 + task2.Date[counter+1] - '0';
        counter += 3;
    }
    year2 = (task2.Date[counter] - '0')*1000 + (task2.Date[counter+1] - '0')*100 +
            (task2.Date[counter+2] - '0')*10 + (task2.Date[counter+3] - '0');

    // Dates comparison

    if ( year1 < year2 ) return true;
    else if ( year1 > year2 ) return false;

    if ( month1 < month2 ) return true;
    else if ( month1 > month2 ) return false;

    if ( day1 < day2 ) return true;
    return false;
}
