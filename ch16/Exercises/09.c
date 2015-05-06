#include <stdio.h>
#include <stdbool.h>

struct color {
    int red;
    int green;
    int blue;
};

struct color make_color(int red, int green, int blue)
{
    struct color c = {red, green, blue};
    if (c.red < 0)
        c.red = 0;
    if (c.green < 0)
        c.green = 0;
    if (c.blue < 0)
        c.blue = 0;

    return c;
}

int getRed(struct color c)
{
    return c.red;
}

bool equal_color(struct color color1, struct color color2)
{
    return (  color1.red == color2.red
           && color1.green == color2.green
           && color1.blue == color2.blue
           );
}

struct color brighter(struct color c)
{
    struct color newc;

    /* If all of c's members are 0 set each newc member to 3 and return */
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        newc.red = newc.green = newc.blue = 3;
        return newc;
    }

    /* Set any member of c that lies between 0 and 3 to 3. */
    if (c.red > 0 && c.red < 3)
        c.red = 3;
    if (c.green > 0 && c.green < 3)
        c.green = 3;
    if (c.blue > 0 && c.blue < 3)
        c.blue = 3;

    /* Get the newc values by dividing c members by 0.7 */
    newc.red = (int) (c.red / 0.7);
    newc.green = (int) (c.green / 0.7);
    newc.blue = (int) (c.blue / 0.7);

    /* Set any member of newc that exceeds 255 to 255 */
    if (c.red > 255)
        c.red = 255;
    if (c.green > 255)
        c.green = 255;
    if (c.blue > 255)
        c.blue = 255;

    return newc;
}

struct color darker(struct color c)
{
    struct color newc;

    /* If all of c's members are 0 set each newc member to 3 and return */
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        newc.red = newc.green = newc.blue = 3;
        return newc;
    }

    /* Set any member of c that lies between 0 and 3 to 3. */
    if (c.red > 0 && c.red < 3)
        c.red = 3;
    if (c.green > 0 && c.green < 3)
        c.green = 3;
    if (c.blue > 0 && c.blue < 3)
        c.blue = 3;

    /* Get the newc values by multiplying c members by 0.7 */
    newc.red = (int) (c.red * 0.7);
    newc.green = (int) (c.green * 0.7);
    newc.blue = (int) (c.blue * 0.7);

    /* Set any member of newc that exceeds 255 to 255 */
    if (c.red > 255)
        c.red = 255;
    if (c.green > 255)
        c.green = 255;
    if (c.blue > 255)
        c.blue = 255;

    return newc;
}

int main(void)
{
    struct color c1 = make_color(255, 0, 255);
    struct color c2 = make_color(255, 0, 0);
    struct color c3 = make_color(2, 1, 2);
    struct color brc3 = brighter(c3);
    struct color dac3 = darker(c3);
    printf("struct c1 red value: %d\n", getRed(c1));
    printf("Is struct c1 equal to struct c2?: %d\n", equal_color(c1, c2));
    printf("Brightened struct c3: %d,%d,%d\n", brc3.red, brc3.green, brc3.blue);
    printf("Darkened struct c3: %d,%d,%d\n", dac3.red, dac3.green, dac3.blue);

    return 0;
}
