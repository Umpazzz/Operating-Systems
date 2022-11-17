#include <stdio.h>
int main()
{
  int referenceString[10], pageFaults= 0, m, n, s, pages, frames;
  printf("\nEnterthe number of Pages:\t");
  scanf("%d", &pages);
  printf("\n What are the total number of frames:\t");
  {
  scanf("%d", &frames);
  }
  printf("\nEnterreference string values:\n");

  for(m=0;m<pages;m++)
  {
    printf("Value No. [%d]:\t", m + 1);
    scanf("%d", &referenceString[m]);
  }
  
  int temp[frames];
  for(m = 0; m < frames; m++)
  {
     temp[m] = -1;
  }
  for(m = 0; m < pages; m++)
  {
    s = 0;
    for(n = 0; n < frames; n++)
    {
      if(referenceString[m] == temp[n])
      {
        s++;
        pageFaults--;
      }
    }
    pageFaults++;
    if((pageFaults<= frames) && (s == 0))
    {
      temp[m] = referenceString[m];
    }
    else if(s == 0)
    {
      temp[(pageFaults-1) % frames] = referenceString[m];
    }
    printf("\n");
    for(n = 0; n < frames; n++)
    {
      printf("%d\t", temp[n]);
    }
  }
printf("\nTotalPage Faults:\t%d\n", pageFaults);
return 0;
}

/* Enter the number of Pages:  7

 What are the total number of frames:   3

Enterreference string values:
Value No. [1]:  1
Value No. [2]:  3
Value No. [3]:  0
Value No. [4]:  3
Value No. [5]:  5
Value No. [6]:  6
Value No. [7]:  3

1   -1  -1
1   3   -1
1   3   0
1   3   0
5   3   0
5   6   0
5   6   3
TotalPage Faults:   6 */
