#include "levenshtein.h"
int levenshtein_distance(char *string1, char *string2){
  //Step 1
  int k,i,j,cost,*d,distance;
  int length1;
  int length2;

  length1 = strlen(string1);
  length2 = strlen(string2);

  if(length1 != 0 && length2 != 0){
    d = malloc((sizeof(int))*(length2+1)*(length1+1));
    length2++;
    length1++;
    //Step 2
    for(k = 0; k < length1; k++)
      d[k] = k;
    for(k = 0; k < length2; k++)
      d[k*length1] = k;
    //Step 3 and 4
    for(i = 1; i < length1; i++){
      for(j = 1; j < length2; j++){
        //Step 5
        if(s[i-1] == t[j-1])
          cost = 0;
        else
          cost = 1;
        //Step 6
        d[j*length1+i] = minimum(d[(j-1)*length1+i]+1, d[j*length1+i-1]+1, d[(j-1)*length1+i-1]+cost);
      }
    }
    distance = d[length1*length2-1];
    free(d);
    return distance;
  } else {
    return -1; //a negative return value means that one or both strings are empty.
  }
}

int minimum(int a, int b, int c){
  int min = a;
  if(b < min)
    min = b;
  if(c < min)
    min = c;
  return min;
}
