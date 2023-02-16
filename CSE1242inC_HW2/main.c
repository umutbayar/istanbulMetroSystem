/* Umut Bayar 150120043
 *In this project, our aim is to define the metro lines
 * connected to the Istanbul metro system and the metro stations
 * connected to it, to find the nearest metro station or to give
 * walking advice to a user in any location. We have created
 * Metrosystem, MetroLine and MetroStation structs for them.
 * Then we connected them to functions and made them work in harmony with each other.
 * !!!I could not complete only one (Recursive Find Path) function. That's why my code doesn't work exactly right.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Math.h>
#define SIZE 10

typedef struct MetroStation{
    char name[20];
    double x,y;
}MetroStation;
typedef struct MetroLine {
    char color[20];
    MetroStation MetroStations[SIZE];
}MetroLine;
typedef struct MetroSystem{
    char name[20];
    MetroLine MetroLines[SIZE];
}MetroSystem;

int equals(MetroStation s1,MetroStation s2){
    if(strcmp(s1.name,s2.name)==0)
        return 1;
    else
        return 0;
}
void addStation(MetroLine *a1,MetroStation a2){
    int i=0;
    for(;i<10;i++) {
        if (strcmp(a1->MetroStations[i].name, "") == 0) {
            a1->MetroStations[i] = a2;
            break;
        }
    }
}
int hasStation(MetroLine a1,MetroStation a2){
    int i=0;
    for(;i<10;i++) {
        if (strcmp(a1.MetroStations[i].name, a2.name) == 0)
            return 1;
    }
    return 0;
}
MetroStation getFirstStop(MetroLine a1) {
    return a1.MetroStations[0];
}
MetroStation getPreviousStop(MetroLine a1,MetroStation a2){

    MetroStation empty = {"", '\0'};
    int i=0;
    for(;i<10;i++){
        if(strcmp(a1.MetroStations[0].name,a2.name)==0){
            return empty;
        }
        else if(strcmp(a1.MetroStations[i].name,a2.name)==0){
            return a1.MetroStations[i - 1];
        }
    }
}
MetroStation getNextStop(MetroLine a1,MetroStation a2){
    MetroStation empty = {"", '\0'};
    int i=0;
    for(;i<10;i++){
        if(strcmp(a1.MetroStations[0].name,a2.name)==0){
            return empty;
        }
        else if(strcmp(a1.MetroStations[i].name,a2.name)==0){
            return a1.MetroStations[i + 1];
        }
    }
}
void addLine(MetroSystem *s1,MetroLine s2){
    int i=0;
    for(;i<SIZE;i++) {
        if (strcmp(s1->MetroLines[i].color, "") == 0) {
            s1->MetroLines[i]=s2;
            break;
        }
    }
}
void printLine(MetroLine MetroLine){
    printf("Metroline  %s: ",MetroLine.color);
    int i;
    for(;i<10;i++){
        if(strcmp(MetroLine.MetroStations[i].name,"")==0){
        }
        else if(i==sizeof(MetroLine.MetroStations)/sizeof(MetroLine.MetroStations[0])-1)
            printf(" %s",MetroLine.MetroStations[i]);
        else
            printf(" %s,",MetroLine.MetroStations[i]);

    }
    printf(".\n");
}
void printPath (MetroStation MetroStations[]){
    int i=0;
    for(;i<10;i++){
        if(strcmp(MetroStations[i].name,"")==0){
        }
        else{
            printf(" %s,",MetroStations[i]);
        }
    }
}
double getDistanceTravelled(MetroStation MetroStations[]){
    int i=0,n=0;
    for(;i<10;i++){
        if(strcmp(MetroStations[i].name,"")==0){
        }
        else {
            n++;
        }
    }
    int lastStationNumber = n-1;
    if(n==0||n==1){
        return 0.0;
    }
    double distanceTravelled = 0.0;
    if(n!=1){
        for(n;n-1>-1;n--){
            double a = pow((MetroStations[lastStationNumber].x-MetroStations[lastStationNumber-1].x),2);
            double b = pow((MetroStations[lastStationNumber].y-MetroStations[lastStationNumber-1].y),2);
            distanceTravelled = distanceTravelled + sqrt(a+b);
        }
        return distanceTravelled;
    }
    else{
        return distanceTravelled;
    }
}
MetroStation findNearestStation(MetroSystem MetroSystem,double x,double y){
    int m = 0,i=0;
    int k = 0;
    int minValueI =0;
    int minValueK =0;

    for(;i<10;i++){
        if(strcmp(MetroSystem.MetroLines[i].color,"")==0){
            break;
        }
        else {
            for (; k < 10; k++) {
                if (strcmp(MetroSystem.MetroLines[i].MetroStations[k].name, "") == 0) {
                    break;

                } else {

                    double a = pow((MetroSystem.MetroLines[i].MetroStations[k].x - x), 2);
                    double b = pow((MetroSystem.MetroLines[i].MetroStations[k].y - y), 2);
                    if (m == 0) {
                        m = sqrt(a + b);
                        minValueI = i;
                        minValueK = k;
                    } else if (sqrt(a + b) < m) {
                        m = sqrt(a + b);
                        minValueI = i;
                        minValueK = k;
                    }

                }

            }
        }
    }
    return MetroSystem.MetroLines[minValueI].MetroStations[minValueK];
}
int *getNeighboringStations(MetroSystem s1, MetroStation s2,MetroStation neigboringStations[]){
    int i = 0;
    int k = 0;
    for(;i<10;i++){
        for(;k<10;k++){
            int a = -1;
            if(strcmp(s1.MetroLines[i].MetroStations[k].name,s2.name)){
                a++;
                neigboringStations[a] = s1.MetroLines[i].MetroStations[k+1];
                a++;
                neigboringStations[a+1] = s1.MetroLines[i].MetroStations[k-1];
            }
        }
    }
}
void findPath(MetroStation start,MetroStation finish,MetroStation path[]) {
    MetroStation partialPath[10];
//    recursiveFindPath(start, finish, path, partialPath);
}
int recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[SIZE], MetroStation bestPath[SIZE]) {
    int i=0;
    //   MetroSystem İstanbul;
    for ( ;i < SIZE ; i++) {
        if (strcmp(partialPath[i].name, start.name) == 0) {
        }
    }
    if (strcmp(start.name, finish.name) == 0) {
        bestPath = partialPath;
    }
    MetroStation neighbors[SIZE];
    //  getNeighboringStations(İstanbul, start, neighbors);
    MetroStation duplicatePath[SIZE];
    for (; i < SIZE ; i++) {
        duplicatePath[i] = partialPath[i];
    }

    for (; i < SIZE ; i++) {
        if (strlen(duplicatePath[i].name) == 0) {
            duplicatePath[i] = start;
            break;
        }
    }

    for (; i < SIZE ; i++) {
        if (strlen(neighbors[i].name) != 0) {
            recursiveFindPath(neighbors[i], finish, duplicatePath, bestPath);
        }
    }
    if (bestPath[0].name != '\0') {
        return getDistanceTravelled(bestPath);
    }

}
//Declare a MetroSystem with the name of istanbul and an empty content.
MetroSystem istanbul = {"istanbul", '\0'};

int main()
{
    int i;
    double myX=1, myY=2;
    double goalX=62, goalY=45;

    // define 3 metro lines, 9 metro stations, and an empty myPath
    MetroLine red={'\0'}, blue={'\0'}, green={'\0'};
    MetroStation s1, s2, s3, s4, s5, s6, s7, s8, s9;
    MetroStation myPath[SIZE]={'\0'};

    strcpy(red.color, "red");
    strcpy(blue.color, "blue");
    strcpy(green.color, "green");


    strcpy(s1.name, "Haydarpasa"); 		s1.x=0; 	s1.y=0;
    strcpy(s2.name, "Sogutlucesme"); 	s2.x=10; 	s2.y=5;
    strcpy(s3.name, "Goztepe"); 		s3.x=20; 	s3.y=10;
    strcpy(s4.name, "Kozyatagi"); 		s4.x=30; 	s4.y=35;
    strcpy(s5.name, "Bostanci"); 		s5.x=45; 	s5.y=20;
    strcpy(s6.name, "Kartal"); 			s6.x=55; 	s6.y=20;
    strcpy(s7.name, "Samandira"); 		s7.x=60; 	s7.y=40;
    strcpy(s8.name, "Icmeler"); 		s8.x=70; 	s8.y=15;

    //Add several metro stations to the given metro lines.
    addStation(&red, s1); addStation(&red, s2); addStation(&red, s3); addStation(&red, s4); addStation(&red, s5); addStation(&red, s8);

    addStation(&blue, s2); addStation(&blue, s3); addStation(&blue, s4); addStation(&blue, s6); addStation(&blue, s7);

    addStation(&green, s2); addStation(&green, s3); addStation(&green, s5); addStation(&green, s6); addStation(&green, s8);

    // Add red, blue, green metro lines to the Istanbul metro system.
    addLine(&istanbul, red);
    addLine(&istanbul, blue);
    addLine(&istanbul, green);

    // print the content of the red, blue, green metro lines
    printLine(red);
    printLine(blue);
    printLine(green);


    // find the nearest stations to the current and target locations
    MetroStation nearMe = findNearestStation(istanbul, myX, myY);
    MetroStation nearGoal = findNearestStation(istanbul, goalX, goalY);

    printf("\n");

    printf("The best path from %s to %s is:\n", nearMe.name, nearGoal.name);

    // if the nearest current and target stations are the same, then print a message and exit.
    if(equals(nearMe, nearGoal)){
        printf("It is better to walk!\n");
        return 0;
    }

    // Calculate and print the myPath with the minimum distance travelled from start to target stations.
    findPath(nearMe, nearGoal, myPath);

    if(strlen(myPath[0].name) == 0)
        printf("There is no path on the metro!\n");
    else{
        printPath(myPath);
    }
    return 0;
}
