#include <stdio.h>
#include <stdbool.h>

struct point { int x, y; };
struct rectangle {struct point upper_left, lower_right; };

int compute_width(struct rectangle r);
int compute_height(struct rectangle r);
int compute_area(struct rectangle r);
struct point compute_center(struct rectangle r);
struct rectangle shift_rectangle(struct rectangle r, int x, int y);
bool check_point_in_rectangle(struct point p, struct rectangle r);


int main(void)
{
    struct point upper_left = {0, 0};
    struct point lower_right = {10, 5};

    struct rectangle r1 = {upper_left, lower_right};
    printf("Area: %d\n", compute_area(r1));
    struct point center = compute_center(r1);
    printf("Center: %d,%d\n", center.x, center.y);
    struct rectangle r2 = shift_rectangle(r1, 10, 10);
    struct point center2 = compute_center(r2);
    printf("Center: %d,%d\n", center2.x, center2.y);

    struct point p1 = {15, 10};
    printf("Rectangle upper left: %d,%d\n", r2.upper_left.x, r2.upper_left.y);
    printf("Rectangle lower right: %d,%d\n", r2.lower_right.x, r2.lower_right.y);
    printf("Point %d,%d is in rectangle?: %d", p1.x, p1.y,
            check_point_in_rectangle(p1, r2));

    return 0;
}

int compute_width(struct rectangle r)
{
    return r.lower_right.x - r.upper_left.x;
}

int compute_height(struct rectangle r)
{
    return r.lower_right.y - r.upper_left.y;
}

int compute_area(struct rectangle r)
{
    return compute_width(r) * compute_height(r);
}

struct point compute_center(struct rectangle r)
{
    struct point center;
    center.x = r.upper_left.x + compute_width(r) / 2;
    center.y = r.upper_left.y + compute_height(r) / 2;
    return center;
}

struct rectangle shift_rectangle(struct rectangle r, int x, int y)
{
    r.upper_left.x += x;
    r.upper_left.y += y;
    r.lower_right.x += x;
    r.lower_right.y += y;

    return r;
}

bool check_point_in_rectangle(struct point p, struct rectangle r)
{
    if (!(p.x >= r.upper_left.x && p.x <= r.lower_right.x))
        return false;

    if (!(p.y >= r.upper_left.y && p.y <= r.lower_right.y))
        return false;

    return true;
}
