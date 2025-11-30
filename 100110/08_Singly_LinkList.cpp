/*
Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. The first member is the President and the last member is the Secretary.
Write a C++ program to:
●	Add/delete members (including President/Secretary)
●	Count members
●	Display members
●	Concatenate two division lists

*/

#include <iostream>
using namespace std;

class Node{
public:
    string name;
    int rollNo;
    string position;
    Node* next;

    Node(string n, int r, string p){
        name = n;
        rollNo = r;
        position = p;
        next = nullptr;
    }
};


class list{
    Node* head;
public:
    list(){
        head = nullptr;
    }
    void push_front(string name, int rollNo, string position){
        Node* newNode = new Node(name, rollNo, position);
        if(head == nullptr){
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void displayList(){
        Node* temp = head;
        while(temp != nullptr){
            cout<< temp->name <<endl;
            cout<<temp->rollNo <<endl;
            cout << temp->position << endl;
            cout<<"---------------------------"<<endl;
            temp = temp->next;
        }
    }

    void push_back(string name, int rollNo, string position){
        Node* newNode = new Node(name, rollNo, position);
        if(head == nullptr){
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void pop_front(){
        if(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    int countMembers(){
        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteByRollNo(int rollNo){
        if(head == nullptr) return;
        if(head->rollNo == rollNo){
            pop_front();
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr && temp->next->rollNo != rollNo){
            temp = temp->next;
        }
        if(temp->next != nullptr){
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void concatenate(list &other){
        if(head == nullptr){
            head = other.head;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = other.head;
    }

    ~list(){
        while(head != nullptr) pop_front();
    }
};


int main(){
    list ll;

    ll.push_back("Ajinkya", 36, "President");
    ll.push_back("Ajaya", 35, "Vice-president");
    ll.push_back("Rishi", 32, "Secretary");
    ll.displayList();
    cout<<endl;
    ll.pop_front();
    ll.displayList();

}