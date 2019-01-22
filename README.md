# cs162_project1
The Langton's ant simulation

<This is for the LoadedDie>
  if (num%2 ==0){
int num = 6;
number 1,2,3, 4, 5,6 are all 1/6. 
Then, how to modify 1 is to be twice----that means 1/6 *2 = 2/6 =1/3
(1,2,3,4,5,6,1,2,3,1,2,3)
Int array[12] = {} //12= 6*2 = num*2
For (int i=0; I <num< i++) {
   Array[i] =i+1;
} //{1,2,3,4,5,6}
For(int i=0; int <num/2<i++){
       Array[i+num] = i+(num/2+1);
}
For(int i=0; int<num/2<i++){
     Array[i+num+num/2] = i+(num/2+1);
}
}
Array[12]={1,2,3,4,5,6, 4,5,6, 4,5,6}
Random number -----7
Array[7] =4

if (num%2 !=0){
int num = 7;
number 1,2,3, 4, 5,6, 7 are all 1/7. 
Then, how to modify 1 is to be twice----that means 1/7 *2 = 2/7 =4/14
(1,2,3,4,5,6,7, 4, 5, 6, 7, 5, 6, 7)
Int array[14] = {} //14= 7*2 = num*2
For (int i=0; I <num< i++) {
   Array[i] =i+1;
} //{1,2,3,4,5,6, 7}
For(int i=0; int <(num/2) +1<i++){
       Array[i+num] = i+(num/2+1);
}
I =0, array[0+7] =0+4// I =1, array[8] // i=2, array[9]//I =3, array[10]
//{……4, 5, 6,7}
For(int i=0; int<num/2<i++){
     Array[i+num+(num/2+1)] = i+(num/2+2);
}
I=0, array[0+7+4] = 0+5 //i=1, array[12] //i=2, array [13]
Array[14]={1,2,3,4,5,6, 7, 4,5,6,7, 5,6, 7}
Ex) Random number -----7
Array[7] =4


#include <cmath>
Ceil (3.5) = 4
Floor (3.5) =3
