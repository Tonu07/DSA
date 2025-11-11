#include <stdio.h>
void TowerOfHanoi(int n,char source,char auxiliary,char destination){
if(n=1){
printf("Move disk 1 from %c to %c\n",source,destination);
return;
}
TowerOfHanoi(n-1,source,destination,auxiliary);
printf("Move disk %d from %c to %c\n",n,source,destination);
TowerOfHanoi(n-1,auxiliary,source,destination);
}
int main(){
int n=3; // Number of disks
printf("Solution for Tower of Hanoi with %d disks:\n", n);
TowerOfHanoi(n,'A','B','C');
return 0;
}
//Discks cannot overlap big on small