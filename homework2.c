#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void processing1();
void processing2();
void delay(unsigned int milsec)
{
	clock_t goal = milsec + clock();
	while (goal > clock());
}
int p[10], pr[10], n, i, j, count = 0, random_p, temp, max, min;

int main()
{
	printf("Enter the number of processses: ");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		p[i] = i + 1;
	do
	{
		random_p = rand(n);
	} while (random_p != 0);
	random_p = 3;
	printf("Control process is P%d \n", random_p);
	printf("Enter the priority of processes \n");
	for (i = 0; i < n; i++)
	{
		printf("Priority of process P%d : ", p[i]);
		scanf_s("%d", &pr[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (pr[i] > pr[j])
			{
				temp = pr[i];
				pr[i] = pr[j];
				pr[j] = temp;

				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		if (p[i] < random_p)
		{
			max = random_p;
			processing1();
		}
		else
		{
			min = random_p + 1;
			processing2();
		}
	}

	_getch();
}

void processing1()
{
	for (j = 0; j < random_p; j++)
	{
		if (i != j)
			printf("Process P%d -----> <request> to P%d \n", p[i], p[j]);
		else
			continue;
	}
	printf("\n");
	for (j = 0; j < random_p; j++)
	{
		if (i != j)
		{
			printf("Process P%d -----> <ack> P%d \n", p[j], p[i]);
			count++;
		}
		else
			continue;
	}
	printf("\n");
	if (count == (random_p - 1))
	{
		printf("Process P%d is entering Critical Section. \n", p[i]);
		delay(10000);
	}
	printf("\n");
	for (j = 0; j < random_p; j++)
	{
		if (i != j)
			printf("Process P%d -----> <reply> to P%d \n", p[i], p[j]);
		else
			continue;
	}
}

void processing2()
{
	for (j = random_p + 1; j < n; j++)
	{
		if (i != j)
			printf("Process P%d -----> <request> to P%d \n", p[i], p[j]);
		else
			continue;
	}
	printf("\n");
	for (j = random_p + 1; j < n; j++)
	{
		if (i != j)
		{
			printf("Process P%d -----> <ack> P%d \n", p[j], p[i]);
			count++;
		}
		else
			continue;
	}
	printf("\n");

	if (count == (n - random_p - 1))
	{
		printf("Process P%d is entering Crital Section. \n", p[i]);
		delay(10000);
	}
	printf("\n");
	for (j = random_p + 1; j < n; j++)
	{
		if (i != j)
			printf("Process P%d -----> <reply> to P%d \n", p[i], p[j]);
		else
			continue;
	}
}

/*OUTPUT:
Enter the no. of processses 5
Control process is P3
Enter the priority of processes
Priority of process P1 :2
Priority of process P2 :1
Priority of process P3 :5
Priority of process P4 :3
Priority of process P5 :4

Process P2 is sending request to P1
Process P2 is sending request to P3
Process P1 is acknowledging P2
Process P3 is acknowledging P2
Process P2 is entering CS
Process P2 is sending reply to P1
Process P2 is sending reply to P3

Process P1 is sending request to P2
Process P1 is sending request to P3
Process P2 is acknowledging P1
Process P3 is acknowledging P1
Process P1 is entering CS
Process P1 is sending reply to P2
Process P1 is sending reply to P3

Process P4 is sending request to P5
Process P5 is acknowledging P4
Process P4 is entering CS
Process P4 is sending reply to P5

Process P5 is sending request to P4
Process P4 is acknowledging P5
Process P5 is entering CS
Process P5 is sending reply to P4

Process P3 is sending request to P1
Process P3 is sending request to P2
Process P1 is acknowledging P3
Process P2 is acknowledging P3
Process P5 is entering CS
Process P3 is sending reply to P1
Process P3 is sending reply to P2
*/