#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include<iostream>
#include<vector>


using namespace std;
class Management
{
    public:
        Management();
        Management(string ,string ,string , int ,int);
        ~Management();
        void set_name(string n);
        void set_description(string description);
        void set_Date(string D);
        void set_priority(int P);
        string get_name();
        string get_description();
        string get_Date();
        int get_priority();
        void set_duration(int);
        int get_duration();
        void set_task(Management M);
        friend ostream& operator<<(ostream& out , Management);
        friend istream& operator >> (istream& in, Management Manage);
        bool operator < (const Management)const;
        void operator = (const Management);
        bool operator == (const Management);
        vector<Management> load();
        void SendToFile(Management);
        void SortVector(vector<Management>&);
        void Display();
        void sett();
        vector<Management>load(string);
        // Amr Saeed -------------------------------------------------------------
        friend bool orderByDuration ( Management& task1, Management& task2 );
        friend bool orderByDate ( Management& task1 , Management& task2 );
    private:
     string Date;
     string name;
     string description;
     int priority;
     int duration;
};

#endif // MANAGEMENT_H
