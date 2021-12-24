#define MAXQUEUE    5
 
typedef struct plane {
    int id;
    int tm;
} Plane;
 
typedef Plane QueueEntry;
 
typedef struct queue {
    int count;
    int front;
    int rear;
    QueueEntry entry[MAXQUEUE];
} Queue;

// Header files
#include 'common.h'
#include 'queue.h'
 
typedef enum action { ARRIVE, DEPART } Action;
 
int main(void)
{  Queue landing, takeoff;
    Queue *pl = &landing;
    Queue *pt = &takeoff;
    Plane plane;
 
    int curtime;
    int endtime;
    double expectarrive;
    double expectdepart;
    int i;
    int idletime;
    int landwait;
    int nland;
    int nplanes;
    int nrefuse;
    int ntakeoff;
    int pri;
    int takeoffwait;
    CreateQueue(pl);
    CreateQueue(pt);
    nplanes = nland = ntakeoff = nrefuse = 0;
    landwait = takeoffwait = idletime = 0;
    Start(&endtime, &expectarrive, &expectdepart);
    for (curtime = 1; curtime <= endtime; curtime++) {
        pri = PoissonRandom(expectarrive);
        for (i = 1; i <= pri; i++) {/* Add to landing queue.    */
            NewPlane(&plane, &nplanes, curtime, ARRIVE);
            if (QueueFull(pl))
                Refuse(plane, &nrefuse, ARRIVE);
            else
                Append(plane, pl);
        }
 
        pri = PoissonRandom(expectdepart);
        for (i = 1; i <= pri; i++) {/* Add to takeoff queue.    */
            NewPlane(&plane, &nplanes, curtime, DEPART);
            if (QueueFull(pt))
                Refuse(plane, &nrefuse, DEPART);
            else
                Append(plane, pt);
        }
 
        if (!QueueEmpty(pl)) {      /* Bring plane to land. */
            Serve(&plane, pl);
            Land(plane, curtime, &nland, &landwait);
        } else if (!QueueEmpty(pt)) {   /* Allow plane to take off. */
            Serve(&plane, pt);
            Fly(plane, curtime, &ntakeoff, &takeoffwait);
        } else
            Idle(curtime, &idletime);
    }
 
    Conclude(nplanes, nland, ntakeoff, nrefuse, landwait,
            takeoffwait, idletime, endtime, pt, pl);
    return 0;
}
void Start(int *endtime, double *expectarrive, double *expectdepart)
{    Boolean ok;
 
    printf("This program simulates an airport with only one runway.\n"
            "One plane can land or depart in each unit of time.\n"
            "Up to %d planes can be waiting to land or take off "
            "at any time.\n", MAXQUEUE);
 
    printf("How many units of time will the simulation run? ");
    scanf("%d", endtime);
 
    Randomize();    /* Initialize random number generation. */
    do {
        printf("Expected number of arrivals per unit time (real number)? ");
        scanf("%lf", expectarrive);
        printf("Expected number of departures per unit time? ");
        scanf("%lf", expectdepart);
 
        if (*expectarrive < 0.0 || *expectdepart < 0.0) {
            printf("These numbers must be nonnegative.\n");
            ok = FALSE;
        } else if (*expectarrive + *expectdepart > 1.0) {
            printf("The airport will become saturated. "
                   "Read new numbers? ");
            ok = !UserSaysYes(); /* If user says yes, repeat loop. */
        } else
            ok = TRUE;
    } while (ok == FALSE);
}
 
void NewPlane(Plane *p, int *nplanes, int curtime, Action kind)
{
    (*nplanes)++;
    p->id = *nplanes;
    p->tm = curtime;
    switch(kind) {
    case ARRIVE:
        printf("      Plane %3d ready to land.\n", *nplanes);
        break;
    case DEPART:
        printf("      Plane %3d ready to take off.\n", *nplanes);
        break;
    }
}
 
void Refuse(Plane p, int *nrefuse, Action kind)
{
    switch(kind) {
    case ARRIVE:
        printf("      Plane %3d directed to another airport.\n", p.id);
        break;
    case DEPART:
        printf("      Plane %3d told to try later.\n", p.id);
        break;
    }
    (*nrefuse)++;
}
void Land(Plane p, int curtime, int *nland, int *landwait)
{    int wait;
 
    wait = curtime - p.tm;
    printf("%3d : Plane %3d landed; in queue %d units.\n",
            curtime, p.id, wait);
    (*nland)++;
    *landwait += wait;
}
void Fly(Plane p, int curtime, int *ntakeoff, int *takeoffwait)
{    int wait;
 
    wait = curtime - p.tm;
    printf("%3d : Plane %3d took off; in queue %d units.\n",
            curtime, p.id, wait);
    (*ntakeoff)++;
    *takeoffwait += wait;
}
void Idle(int curtime, int *idletime)
{
    printf("%3d : Runway is idle.\n", curtime);
    (*idletime)++;
}
 
void Conclude(int nplanes, int nland, int ntakeoff,
              int nrefuse, int landwait, int takeoffwait,
              int idletime, int endtime,
              Queue *pt, Queue *pl)
{
    printf("Simulation has concluded after %d units.\n", endtime);
    printf("Total number of planes processed:    %3d\n", nplanes);
    printf("   Number of planes landed:          %3d\n", nland);
    printf("   Number of planes taken off:       %3d\n", ntakeoff);
    printf("   Number of planes refused use:     %3d\n", nrefuse);
    printf("   Number left ready to land:        %3d\n", QueueSize(pl));
    printf("   Number left ready to take off:    %3d\n", QueueSize(pt));
    if (endtime > 0)
        printf("   Percentage of time runway idle:   %6.2f\n",
            ((double) idletime / endtime) * 100.0);
    if (nland > 0)
        printf("   Average wait time to land:        %6.2f\n",
            (double) landwait / nland);
    if (ntakeoff > 0)
        printf("   Average wait time to take off:    %6.2f\n",
            (double) takeoffwait / ntakeoff);
}
void Randomize(void)
{    srand((unsigned int) (time(NULL) % 10000));
}
 
int PoissonRandom(double expectedvalue)
{   int n = 0;
    double limit;
    double x;
 
    limit = exp(-expectedvalue);
    x = rand() / (double) INT_MAX;
    while (x > limit) {
        n++;
        x *= rand() / (double) INT_MAX;
    }
    return n;
}