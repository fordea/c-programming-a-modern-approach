#include <stdio.h>

#define PI 3.14159
#define CIRCLE 0
#define RECTANGLE 1

struct point { int x, y; };

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

double compute_area(struct shape s);
struct shape shift_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape s, double scalefactor);

int main(void)
{
    s.shape_kind = CIRCLE;
    s.u.circle.radius = 5;
    printf("Area of circle with radius %d: %.2f\n", s.u.circle.radius,
            compute_area(s));

    s.shape_kind = RECTANGLE;
    s.center.x = 12;
    s.center.y = 20;
    s.u.rectangle.height = 5;
    s.u.rectangle.width = 10;
    printf("Center of rectangle: %d,%d\n", s.center.x, s.center.y);
    printf("Area of rectangle with height %d and width %d: %.0f\n", 
            s.u.rectangle.height, s.u.rectangle.width, compute_area(s));

    s = shift_shape(s, 5, 10);
    printf("Center of shifted rectangle: %d,%d\n", s.center.x,
            s.center.y);

    s.shape_kind = CIRCLE;
    s.u.circle.radius = 5;
    s = scale_shape(s, 1.5);
    printf("Circle new radius after scaled by 1.5: %d\n", s.u.circle.radius);
    return 0;
}

double compute_area(struct shape s)
{
    if (s.shape_kind == CIRCLE) {
        return PI * s.u.circle.radius * s.u.circle.radius;
    }
    else  if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
}

struct shape shift_shape(struct shape s, int x, int y)
{
    s.center.x += x;
    s.center.y += y;
    return s;
}

struct shape scale_shape(struct shape s, double scalefactor)
{
    if (s.shape_kind == CIRCLE) {
        s.u.circle.radius *= scalefactor;
    }
    else if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= scalefactor;
        s.u.rectangle.width *= scalefactor;
    }
    return s;
}
