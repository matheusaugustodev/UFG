#include <stdio.h>

int
main ()
{
  int n, i, j, contador, qtd, vetor[5000];
 qtd=0;
  scanf ("%d", &n);
  if (n <= 5000)
    {

      for (i = 0; i < n; i++)
	{
	  scanf ("%d", &vetor[i]);
	}
      for (i = 0; i < n; i++)
	{
	  contador = 0;
	  for (j = 0; j < n; j++)
	    {
	      if (i != j)
		{
		  if (vetor[i] == vetor[j])
		    {
		      contador++;
		    }

		}
	    }
if(contador==0) {
    qtd++;
}


	    }
	    printf("%d\n", qtd);
	}





  return 0;
}
