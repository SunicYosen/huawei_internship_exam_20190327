#include <stdio.h>

int main()
{
  int count;
  char input_string[130];

  scanf("%d",&count);
  scanf("%s",input_string);

  int addr=0;
  char mode_flag;
  char one_code[9];

  for(int i = 0; i<count; i++)
  {
    mode_flag=input_string[addr];
    //printf("%d\n",mode_flag);
    for(int j=1;j<9;j++)
    {
      one_code[j-1] = input_string[addr+j];
    }
    addr += 9;

    if(mode_flag == '0')
    {
      for(int k=7;k>=0;k--)
      {
        printf("%c",one_code[k]);
      }
    }
    else
    {
      printf("%s",one_code);
    }
    
    if(i<(count-1))
      printf(" ");
    if(i==(count-1))
      printf("\n");

  }
}