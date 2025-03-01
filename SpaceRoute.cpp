#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log):name(n), distance_from_earth(d), mission_log(log){}
    const string& getName(){return name;};
    double getDistance() {return distance_from_earth;}
    const string& getMissionLog() {return mission_log;}
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // Constructor
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // Destructor-come back to this
    // ~SpaceRoute() {
    //     Node<T>* curr = head;
    //     while (head) {
    //         head=head->next;
    //         next->prev=nullptr;
    //
    //     }
    // }
    /**This method adds the data to the beginning of the route
     * @param data
     */
    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node(data);
        //Empty case
        if (!tail) {
            head=newNode;
            tail=newNode;
        }else {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        ++size;
    }

    /** This method adds the data to the end of the route
     * @param data
     */
    void addWaypointAtEnd(T& data) {
        //Empty case
        Node<T>* newNode = new Node(data);
        if (!head) {
            head=newNode;
            tail=newNode;
        }else {
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        ++size;
    }

    /**This inserts the waypoint at the specified index
     * Exception-index is out of bounds(<0 or greater than size)
     * @param index - integer
     * @param data - waypoint
     */
    void addWaypointAtIndex(int index, T& data) {
        //TODO check for valid index
        if (index<0 || index>size-1) {
            cout<<"Invalid index"<<endl;
        }else if (index==0) {
            addWaypointAtBeginning(data);
        }else{
            Node<T>* newNode = new Node(data);
            Node<T>* predNode = head;
            for (int i = 0; i<index-1; ++i) {
                predNode=predNode->next;
            }
            newNode->next=predNode->next;
            newNode->next->prev = newNode;
            predNode->next=newNode;
            newNode->prev=predNode;
            ++size;
        }
    }

    /**This method removes the data to the beginning of the route
     */
    void removeWaypointAtBeginning() {
        if (head==tail) {
            head=nullptr;
            tail=nullptr;
        }else {
            Node<T>* oldHead=head;
            head=oldHead->next;
            oldHead->next=nullptr;
            head->prev=nullptr;
            delete oldHead;
        }
    }

    /**This method removes the data to the end of the route
     */
    void removeWaypointAtEnd() {
        if (head==tail) {
            head=nullptr;
            tail=nullptr;
        }else {
            Node<T>* oldTail=tail;
            tail=tail->prev;
            tail->next=nullptr;
            oldTail->next=nullptr;
            delete oldTail;
        }
    }

    /**This inserts the waypoint at the specified index
     * Exception-index is out of bounds(<0 or greater than size)
     * @param index
     *
     *
     */
    void removeWaypointAtIndex(int index);

    /**This method prints out the Space Route in forward order
     * Is O(n) as it needs to visit every Node once
     */
    void traverseForward() {
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }
    }
    /**This method prints out the Space Route in forward order
     * Is O(n) as it needs to visit every Node once
     */
    void traverseBackward()

    /**This method retrieves the waypoint at your desired index
     * Exception-index is out of bounds(<0 or greater than size)
     * @param index
     * @return waypoint with data, if exception is encountered, will return null instead
     */
    Node<T>* getWaypoint(int index);

    /**This method modifies an existing waypoint at your desired index
     * @param index
     * @param data - the replacement data for that node
     */
    void setWaypoint(int index, T& data);

    /**Displays the entire space route
     * Is O(n) as it needs to visit every Node once
     */
    void print(){
            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

