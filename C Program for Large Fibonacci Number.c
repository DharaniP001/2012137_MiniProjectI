#include <stdio.h>
#define Max 5000

void add(char a[], char b[], char p[])
{
  int k = 0;
  for (int i = Max - 1; i >= 0; i--)
  {
    int d = (a[i] - '0') + (b[i] - '0') + k;
    p[i] = (d % 10) + '0';
    k = d / 10;
  }
}

void copy(char a[], char b[])
{
  for (int i = Max - 1; i >= 0; i--)
    a[i] = b[i];
}

char fibo1[Max];
char fibo2[Max];
char p[Max];

int main()
{

  for (int i = 0; i < Max; i++)
  {
    fibo1[i] = fibo2[i] = p[i] = '0';
  }
  fibo2[Max - 1] = '1';

  int n;
  scanf("%d", &n);

  if (n == 0 || n == 1)
  {
    printf("%c", n + '0');
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      add(fibo1, fibo2, p);
      copy(fibo1, fibo2);
      copy(fibo2, p);
    }

    int ad = 0;
    for (int i = 0; i < Max; i++)
    {
      if ( ad == 0 && p[i] == '0')
        continue;

      if (ad == 0 && p[i] != '0')
        ad = 1;
      printf("%c", p[i]);
    }
    printf("\n");
  }
  return 0;
}
