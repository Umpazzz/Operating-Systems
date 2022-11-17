#include<stdio.h>
int main()
{
  int frames[10], temp[10], pages[10];
  int total_pages, m, n, position, k, l, total_frames;
  int a = 0, b = 0, page_fault= 0;
  printf("\nEnterTotal Number of Frames:\t");
  scanf("%d", &total_frames);
  for(m = 0; m < total_frames; m++)
  {
    frames[m]=-1;
  }
  
  printf("Enter Total Number of Pages:\t");
  scanf("%d", &total_pages);
  printf("Enter Values for Reference String:\n");
  for(m = 0; m < total_pages; m++)
  {
    printf("Value No.[%d]:\t", m + 1);
    scanf("%d", &pages[m]);
  }
  for(n = 0; n < total_pages; n++)
  {
    a = 0, b = 0;
    for(m = 0; m < total_frames; m++)
    {
      if(frames[m]==pages[n])
      {
        a = 1; b = 1;
        page_fault--;
        break;
      }
    }
    if(a == 0)
    {
      for(m = 0; m < total_frames; m++)
      {
        if(frames[m] == -1)
        {
          frames[m] = pages[n];
          b = 1; break;
        }
      }
    }
    if(b == 0)
    {
      for(m = 0; m < total_frames; m++)
      {
        temp[m] = 0;
      }
      for(k = n -1, l = 1; l <= total_frames-1; l++, k--)
      {
        for(m = 0; m < total_frames; m++)
        {
          if(frames[m] == pages[k])
          {
            temp[m] = 1;
          }
        }
      }
      for(m = 0; m < total_frames; m++)
      {
        if(temp[m] == 0)
        position = m;
      }
      
      frames[position] = pages[n];
    }
    page_fault++;
    printf("\n");
    for(m = 0; m < total_frames; m++)
    {
      printf("%d\t", frames[m]);
    }
  }
printf("\nTotalNumber of Page Faults:\t%d\n", page_fault);
return 0;
}

/* EnterTotal Number of Frames:    4
Enter Total Number of Pages:    12
Enter Values for Reference String:
Value No.[1]:   1
Value No.[2]:   2
Value No.[3]:   3
Value No.[4]:   4
Value No.[5]:   1
Value No.[6]:   2
Value No.[7]:   5
Value No.[8]:   1
Value No.[9]:   2
Value No.[10]:  3
Value No.[11]:  4
Value No.[12]:  5

1   -1  -1  -1
1   2   -1  -1
1   2   3   -1
1   2   3   4
1   2   3   4
1   2   3   4
1   2   5   4
1   2   5   4
1   2   5   4
1   2   5   3
1   2   4   3
5   2   4   3
TotalNumber of Page Faults: 8 */
