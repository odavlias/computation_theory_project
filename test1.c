#include "ptuclib.h"

/* program  test1 */ 


int [[10]] my_vector;
int i;
int main() {
for(i=0;i<=4;i++){
	
my_vector[i] = i;
writeInteger(my_vector[i]);}
writeString("Done!");
 
}
 
