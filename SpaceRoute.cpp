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
    /**Constructor
     * O(1) as it has 3 constant time operations
     */
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /**Destructor
     * O(n) as it has to visit every node and delete it
     */
    ~SpaceRoute() {
        Node<T>* oldHead=head;
        while (oldHead!=tail) {
            head=oldHead->next;
            oldHead->next=nullptr;
            head->prev=nullptr;
            delete oldHead;
            oldHead=head;
        }
        delete head;
    }

    /**This method adds the data to the beginning of the route
     *O(1) because of the instant access to the beginning by the head pointer
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
     * O(1) because of the instant access to the end by the tail pointer
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
     * O(n) because it calls a O(n) function, getWaypoint()
     * @param index - integer
     * @param data - waypoint
     */
    void addWaypointAtIndex(int index, T& data) {
        if (index==0) {
            addWaypointAtBeginning(data);
            return;
        }if (index==size-1) {
            addWaypointAtEnd(data);
            return;
        }
        Node<T>* predNode = getWaypoint(index);
        if (!predNode) {
            cout<<"Invalid index"<<endl;
        }else{
            Node<T>* newNode = new Node(data);
            newNode->next=predNode->next;
            newNode->next->prev = newNode;
            predNode->next=newNode;
            newNode->prev=predNode;
            ++size;
        }
    }

    /**This method removes the data to the beginning of the route
     * O(1) because of the instant access to the beginning by the head pointer
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
            --size;
        }
    }

    /**This method removes the data to the end of the route
     *O(1) because of the instant access to the end by the tail pointer
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
            --size;
        }
    }

    /**This inserts the waypoint at the specified index
     * Exception-index is out of bounds(<0 or greater than size)
     * @param index
     * O(n) because it calls a O(n) function, getWaypoint()
     */
    void removeWaypointAtIndex(int index) {
        if (index==0) {
            removeWaypointAtBeginning();
            return;
        }else if (index==size-1) {
            removeWaypointAtEnd();
            return;
        }else{
            Node<T>* delNode= getWaypoint(index);
            if (!delNode) {
                cout<<"Invalid index"<<endl;
            }else{
                Node<T>* predNode=delNode->prev;
                predNode->next=delNode->next;
                delNode->next->prev=predNode;
                delNode->next=nullptr;
                delNode->prev=nullptr;
                delete delNode;
                --size;
        }
    }
    }

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

    /**This method prints out the Space Route in forward order
     * Is O(n) as it needs to visit every Node once
     */
    void traverseBackward() {
    Node<T>* current = tail;
    while (current) {
        current->print();
        current = current->prev;
    }
    cout << endl;
}

    /**This method retrieves the waypoint at your desired index
     * Exception-index is out of bounds(<0 or greater than size)
     * O(n) as, though it splits the search into 2, the algorithm still needs to search n/2 elements
     * @param index
     * @return waypoint with data, if exception is encountered, will return null instead
     */
    Node<T>* getWaypoint(int index) {
        if (index<0||index>size-1) {
            return nullptr;
        }
        if (index==size-1) {
            return tail;
        }else if (index>(size+1)/2) {
            int newIndex = size-1-index;
            Node<T>* curr = tail;
            for (int i=0; i<newIndex; ++i) {
                curr=curr->prev;
            }
            return curr;
        }else {
            Node<T>* curr = head;
            for (int i=0; i<index; ++i) {
                curr=curr->next;
            }
            return curr;
        }
    }

    /**This method modifies an existing waypoint at your desired index
     *O(n) because it calls a O(n) function, getWaypoint()
     * @param index
     * @param data - the replacement data for that node
     */
    void setWaypoint(int index, T& data) {
        Node<T>* curr = getWaypoint(index);
        if (!curr) {
            cout<<"Invalid Index"<<endl;
        }else {
            curr->data=data;
        }
    }

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

    /**Returns the size of list
     * @return int
     */
    int getSize() {
        return size;
    }
};

