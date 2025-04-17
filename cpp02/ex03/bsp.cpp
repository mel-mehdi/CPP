#include "Point.hpp"

static Fixed area(Point const &a, Point const &b, Point const &c) {
    Fixed result = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) +  (c.getX() * (a.getY() - b.getY())));
                    
    if (result < 0)
        return result * -1;
    return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    
    if (totalArea == 0)
        return false;
    
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);
    
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;

    return (area1 + area2 + area3 == totalArea);
}
