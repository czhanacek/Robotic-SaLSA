
#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <cmath>
#include "Location.h"

#define PI 3.14159

using std::cout;
using std::cin;
using std::endl;

class AppWrapper
{
    public:
        AppWrapper() {
            int currentLocId = 0;
            std::vector<Location *> locations;
            Location * current = new Location(0, 0);
            locations.push_back(current); // this is where we start out
            for(int i = 0; i < 9; i++) {
                Location * newLocation = goToNewLocation();
                current->adjacents.insert(std::pair<Location *, double>(newLocation, current->getDistanceTo(newLocation)));
            }
        }

        Location * goToNewLocation(void) {
            std::random_device generator;
            std::uniform_int_distribution<int> angle_distribution(0,359);
            std::uniform_int_distribution<int> radius_distribution(0,50);
            int radius = radius_distribution(generator);
            int angle = angle_distribution(generator);
            cout << "We decided to turn " << angle << " degrees and drive " << radius << " centimeters" << endl;
            double radians = (angle*PI) / 180;
            double y = std::sin(radians) * radius;
            double x = std::cos(radians) * radius;
            cout << "Now we are at (" << x << ", " << y << ")" << endl;
            return new Location(x, y);

        }
        // TODO add a destructor
        ~AppWrapper();
    protected:
    private:
};
