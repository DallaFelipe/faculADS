#include <stdio.h>
 
int main() {
 
  double nun1;
  double nun2;
    
    scanf("%lf",&nun1);
    scanf("%lf",&nun2);
    
   double media = (nun1 * 3.5 + nun2 * 7.5) / 11.0;
   
   printf("MEDIA = %.5lf\n",media);
 
    return 0;
}