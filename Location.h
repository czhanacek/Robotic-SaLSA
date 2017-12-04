#ifndef LOCATION_H
#define LOCATION_H

#include <unordered_map>


class Location
{
    public:
        std::unordered_map<Location *, int> adjacents;


        Location(double x, double y) {
            _id = 0;
            _consistency = 1;
            _visited = 1;

            cart_x = x;
            cart_y = y;
        }

        ~Location() {}
        int getConsistency(void) {return _consistency;}
        int getTimesVisited(void) {return _visited;}
        int getId(void) { return _id;}
        double getX(void) { return cart_x;}
        double getY(void) { return cart_y;}

        double getDistanceTo(Location * otherLocation) {
            return std::sqrt(pow(cart_x - otherLocation->getX(), 2) + pow(cart_y - otherLocation->getY(), 2));
        }
    protected:
    private:
        int _consistency;
        int _visited;
        int _id;
        double cart_x;
        double cart_y;

};



#endif // LOCATION_H
