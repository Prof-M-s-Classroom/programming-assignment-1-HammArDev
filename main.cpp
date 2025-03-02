#include <iostream>
#include <string>
#include "SpaceRoute.cpp"

using namespace std;

int main() {
    string mars = "Mars";
    string jupiter = "Jupiter";
    string saturn = "Saturn";
    string earth = "Earth";
    string venus = "Venus";

    SpaceRoute<string> voyagerRoute;

    voyagerRoute.addWaypointAtBeginning((earth));
    voyagerRoute.addWaypointAtBeginning((mars));
    voyagerRoute.addWaypointAtBeginning(saturn);
    voyagerRoute.addWaypointAtEnd(venus);
    voyagerRoute.addWaypointAtIndex(3, jupiter);
    voyagerRoute.removeWaypointAtBeginning();
    voyagerRoute.removeWaypointAtEnd();
    voyagerRoute.print();
    voyagerRoute.traverseForward();
    voyagerRoute.traverseBackward();
    voyagerRoute.removeWaypointAtIndex(1);
    voyagerRoute.traverseBackward();
    voyagerRoute.addWaypointAtEnd(earth);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.print();
    voyagerRoute.setWaypoint(3, venus);
    voyagerRoute.print();
    cout<<voyagerRoute.getSize();


    /*voyagerRoute.addWaypointAtEnd(mars);
    voyagerRoute.addWaypointAtEnd(jupiter);
    voyagerRoute.addWaypointAtEnd(saturn);
    voyagerRoute.addWaypointAtBeginning(earth);
    voyagerRoute.addWaypointAtIndex(2, venus);*/
    //
    // cout << "Voyager Route (Forward):\n";
    // voyagerRoute.traverseForward();
    //
    // cout << "\nVoyager Route (Backward):\n";
    // voyagerRoute.traverseBackward();
    //
    // cout << "\nPrinting Route: \n";
    // voyagerRoute.print();
    //
    // voyagerRoute.removeWaypointAtIndex(2);
    // cout << "\nAfter Removing Venus: \n";
    // voyagerRoute.print();

    return 0;
}