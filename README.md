[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
/**This method adds the data to the beginning of the route
*O(1) because of the instant access to the beginning by the head pointer
* @param data
*/
void addWaypointAtBeginning(T& data)

/** This method adds the data to the end of the route
* O(1) because of the instant access to the end by the tail pointer
* @param data
*/
void addWaypointAtEnd(T& data) {

/**This inserts the waypoint at the specified index
* Exception-index is out of bounds(<0 or greater than size)
* O(n) because it calls a O(n) function, getWaypoint()
* @param index - integer
* @param data - waypoint
*/
void addWaypointAtIndex(int index, T& data) {

/**This method removes the data to the beginning of the route
* O(1) because of the instant access to the beginning by the head pointer
*/
void removeWaypointAtBeginning()

/**This method removes the data to the end of the route
*O(1) because of the instant access to the end by the tail pointer
*/
void removeWaypointAtEnd() {

/**This inserts the waypoint at the specified index
* Exception-index is out of bounds(<0 or greater than size)
* @param index
* O(n) because it calls a O(n) function, getWaypoint()
*/
void removeWaypointAtIndex(int index) {

/**This method prints out the Space Route in forward order
* Is O(n) as it needs to visit every Node once
*/
void traverseForward() {

/**This method prints out the Space Route in forward order
* Is O(n) as it needs to visit every Node once
*/
void traverseBackward() {

/**This method retrieves the waypoint at your desired index
* Exception-index is out of bounds(<0 or greater than size)
* O(n) as, though it splits the search into 2, the algorithm still needs to search n/2 elements
* @param index
* @return waypoint with data, if exception is encountered, will return null instead
*/
Node<T>* getWaypoint(int index) {

/**This method modifies an existing waypoint at your desired index
*O(n) because it calls a O(n) function, getWaypoint()
* @param index
* @param data - the replacement data for that node
*/
void setWaypoint(int index, T& data) {

/**Displays the entire space route
* Is O(n) as it needs to visit every Node once
*/
void print(){

/**Returns the size of list
* @return int
*/
int getSize() {
