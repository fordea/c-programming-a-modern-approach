#include <stdio.h>
#include <stdlib.h>

struct flight {
    int departure_time;
    int arrival_time;
};

int compare_flights(const void *p1, const void *p2);

int main(void)
{
    FILE *fp;
    char buffer[1024];
    struct flight *flights;
    int max_flights = 10, num_flights = 0;
    if ((fp = fopen("flights.dat", "r")) == NULL) {
        fprintf(stderr, "Error, cannot open file flights.dat.\n");
        exit(EXIT_FAILURE);
    }
    if ((flights = malloc(sizeof(struct flight) * max_flights)) == NULL) {
        fprintf(stderr, "Cannot allocate space for new flights.\n");
        exit(EXIT_FAILURE);
    }

    int dep_hour, dep_min, arr_hour, arr_min;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (num_flights == max_flights) {
            flights = realloc(flights, sizeof(struct flight) * (max_flights *= 2));
            if (flights == NULL) {
                fprintf(stderr, "Cannot allocate space for new flights.\n");
                exit(EXIT_FAILURE);
            }
        }
        if ((sscanf(buffer, "%d:%d %d:%d", &dep_hour, &dep_min, &arr_hour, &arr_min)) != 4) {
            fprintf(stderr, "Cannot read flight times on line %d. Format is hh:mm hh:mm\n", num_flights + 1);
            continue;
        }
        flights[num_flights].departure_time = dep_hour * 60 + dep_min;
        flights[num_flights].arrival_time = arr_hour * 60 + arr_min;
        ++num_flights;
    }
    qsort(flights, num_flights, sizeof(struct flight), compare_flights);
    int hour, minute, input_time;
    printf("Please enter a time(hh:mm): ");
    scanf("%2d :%2d", &hour, &minute);

    input_time = hour * 60 + minute;

    int prev_f, curr_f;

    for (prev_f = 0, curr_f = 1; curr_f < num_flights; prev_f++, curr_f++)
        if ((abs(input_time - flights[curr_f].departure_time)) >=
            (abs(input_time - flights[prev_f].departure_time)))
            break;

    printf("Closest Flight\nDeparts: %.2d:%.2d  Arrives: %.2d:%.2d\n",
            flights[prev_f].departure_time / 60,
            flights[prev_f].departure_time % 60,
            flights[prev_f].arrival_time / 60,
            flights[prev_f].arrival_time % 60);

    free(flights);
    fclose(fp);
    return 0;
}

int compare_flights(const void *p1, const void *p2)
{
    struct flight *flight1 = (struct flight *)p1;
    struct flight *flight2 = (struct flight *)p2;

    if (flight1->departure_time < flight2->departure_time) {
        return -1;
    } else if (flight1->departure_time > flight2->departure_time) {
        return 1;
    } else {
        if (flight1->arrival_time < flight2->arrival_time) {
            return -1;
        } else if (flight1->arrival_time > flight2->arrival_time) {
            return 1;
        } else {
            return 0;
        }
    }
}
