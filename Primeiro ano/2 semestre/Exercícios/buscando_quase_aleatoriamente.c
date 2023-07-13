#include <stdio.h>

int buscabinaria(int *vet, int ini, int fim, int valor)
{
    if (fim >= ini) 
    {
        int mid = ini + (fim - ini) / 2;
 
        if (vet[mid] == valor)
        {
          return mid;
        }
      
        if (vet[mid] > valor)
        {
          return buscabinaria(vet, ini, mid - 1, valor);
        } 

        return buscabinaria(vet, mid + 1, fim, valor);
    }

    return -1;
}

int buscabinariadec(int *vet, int ini, int fim, int valor)
{

    while (ini <= fim) 
    {

        int mid = ini + (fim - ini) / 2;
 
 
        if (valor == vet[mid]) 
		{
			return mid;
        }

        else if (valor < vet[mid]) 
		{
			ini = mid + 1;
        }
        else 
		{
			fim = mid - 1;
        }
    }
 
    return -1;
}

int main()
{
	int N, M, num;
	int i, pos1, pos2;
	
	scanf("%d", &N);
	
	int vet[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &vet[i]);
	}
	
	scanf("%d", &M);
	
	for(i=0; i<M; i++)
	{
		scanf("%d", &num);
		pos1 = buscabinaria(vet, 0, N/2, num);
		pos2 = buscabinariadec(vet, N/2, N, num);
		
		if(pos1 == -1 && pos2 == -1)
		{
			printf("-1 ");
		}
		
		else 
		{
			if(pos1 > pos2)
			{
				printf("%d ", pos1);
			}
			
			else
			{
				printf("%d ", pos2);
			}
		}
	}
}
