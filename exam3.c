#include <stdio.h>

struct Point
{
  int x;
  int y;
  int status;
  int most;
}Point;


int main()
{
  int count;
  struct Point fruit_point[36];

  scanf("%d",&count);
  for (int i=0;i<count;i++)
  {
    scanf("%d %d",&fruit_point[i].x,&fruit_point[i].y);
    fruit_point[i].status=0;
    fruit_point[i].most=0;
  }

  int status_all=0; //Not comp;
  int dao_count=0;

  while(status_all==0)
  {
    for(int i=0;i<count;i++) //Most
    {
      if(fruit_point[i].status==0)
      {
        for(int j=0;j<count;j++)
        {
          if((fruit_point[j].x == fruit_point[i].x) || (fruit_point[j].y==fruit_point[i].y) || (abs((fruit_point[j].y - fruit_point[i].y)) == abs((fruit_point[j].x - fruit_point[i].x))))
            fruit_point[i].most += 1;
        }
      }
    }

    int most=0;
    int most_addr=0;
    for(int i=0;i<count;i++)
    {
      if(fruit_point[i].most > most)
        {
          most = fruit_point[i].most;
          most_addr = i;
        }
    }

    for(int i=0;i<count;i++)
    {
      if((fruit_point[most_addr].x == fruit_point[i].x) || (fruit_point[most_addr].y==fruit_point[i].y) || (abs((fruit_point[most_addr].y - fruit_point[i].y)) == abs((fruit_point[most_addr].x - fruit_point[i].x))))
            fruit_point[i].status = 1;
    }

    dao_count += 1;

    status_all = 1;

    for(int i=0;i<count;i++)
    {
      if(fruit_point[i].status == 0)
      {
        status_all = 0;
        break;
      }
    }

  }

  printf("%d\n",dao_count);
  return 0;
}