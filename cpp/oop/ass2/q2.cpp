#include <iostream>

using namespace std;

class Point2D {
private:
    double x;
    double y;

public:
    Point2D(double x, double y){
        this->x = x;
        this->y = y;
    }



    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
    
};

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Point3D(){
        x = 0;
        y = 0;
        z = 0;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }
    void operator = (Point2D a){
        x = a.getX();
        y = a.getY();
        z = 0;
    }
};

int main() {
    Point2D point2D(3.0, 4.0);

    Point3D point3D;
    point3D = point2D;

    cout << "Point2D: (" << point2D.getX() << ", " << point2D.getY() << ")" << std::endl;
    cout << "Point3D: (" << point3D.getX() << ", " << point3D.getY() << ", " << point3D.getZ() << ")" << std::endl;

    return 0;
}
