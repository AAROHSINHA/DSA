
#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(){
int arr[7]={7,4,5,9,8,2,1};
int chota=INT_MAX;
int mindx=-1;
//selection srt

for (int i = 0; i < 6; i++){   //n-1 passes
    chota = INT_MAX;
for (int j = i; j <=6; j++){
if(arr[j]<chota){
    chota=arr[j];
    mindx=j;
}
 }
//swap min and first ekement of unsoted array
    int temp=arr[mindx];
    arr[mindx]=arr[i];
    arr[i]=temp;


}
for (int i = 0; i < 7; i++)
{
   printf("%d\n",arr[i]);
}
    return 0;
}