#include <stdio.h>
#include <stdlib.h>


struct books
{
  char title[20];
  char author[20];
  int isbn;
  int quantity;
} b[100];

struct patron
{
  char name[20];
  int id;
  int num;
  int borisbn[10];
} p[100];

int
main ()
{
  int i, input, count, pcount, j, a, x, y, opt;

  i = input = count = pcount = j = 0;


  while (input != 10)
	{
	  printf ("\n\n********######" "WELCOME TO E-LIBRARY " "#####********\n");
	  printf ("\n\n1. Add book\n2. Remove book\n");
	  printf ("3. Add patron\n");
	  printf ("4.Remove patron\n" "5. List all books in the library\n");
	  printf ("6.List all patrons\n");
	  printf ("7.Borrow book\n");
	  printf ("8.Return book\n");
	  printf ("9.Display all books borrowed by a patron\n");
	  printf ("10. Exit");

	  printf ("\n\nEnter one of " "the above: ");
	  scanf ("%d", &input);
	  switch (input)
		{


		case 1:

		  printf
			("1.Add new book\n2.Add existing book\n\nEnter your option: ");
		  scanf ("%d", &opt);
		  if (opt == 1)
			{
			  printf ("Enter book name = ");
			  scanf ("%s", b[i].title);

			  printf ("Enter author name = ");
			  scanf ("%s", b[i].author);

			  printf ("Enter ISBN = ");
			  scanf ("%d", &b[i].isbn);

			  printf ("Enter quantity = ");
			  scanf ("%d", &b[i].quantity);
			  count++;
			  i++;
			}

		  if (opt == 2)
			{
			  printf ("Enter ISBN = ");
			  scanf ("%d", &a);
			  int z = 0;
			  for (z; z < count; z++)
				{
				  if (a == b[z].isbn)
					{
					  printf ("Enter Quantity =");
					  scanf ("%d", &y);
					  b[j].quantity += y;
					}
				}
			}


		  break;


		case 2:
		  printf ("Enter isbn to delete book\n");
		  scanf ("%d", &a);
		  for (i = 0; i < count; i++)
			{
			  if (b[i].isbn == a)
				{
				  for (i; i < count - 1; i++)
					{
					  b[i] = b[i + 1];
					}

				}

			}
		  count--;
		  i--;
		  break;

		case 3:
		  printf ("Enter patron name = ");
		  scanf ("%s", p[j].name);
		  printf ("Enter id = ");
		  scanf ("%d", &p[j].id);
		  p[j].num = 0;
		  j++;
		  pcount++;
		  break;


		case 4:
		  printf ("Enter id to delete\n");
		  scanf ("%d", &a);
		  for (i = 0; i < pcount; i++)
			{
			  if (p[i].id == a)
				{
				  for (i; i < pcount - 1; i++)
					{
					  p[i] = p[i + 1];
					}

				}

			}
		  pcount--;
		  j--;
		  break;
		case 5:
		  for (i = 0; i < count; i++)
			{
			  printf ("\nbook name =%s\n", b[i].title);
			  printf ("author name =%s\n", b[i].author);
			  printf ("ISBN =%d\n", b[i].isbn);
			  printf ("Quantity =%d\n", b[i].quantity);
			}
		  break;
		case 6:
		  for (j = 0; j < pcount; j++)
			{
			  printf ("\npatron name = %s\n", p[j].name);
			  printf ("Enter id = %d\n", p[j].id);
			  printf ("No of books borrowed = %d\n", p[j].num);
			}
		  break;
		case 7:
		  printf ("Enter id = ");
		  scanf ("%d", &a);
		  for (j = 0; j < pcount; j++)
			{
			  if (a == p[j].id)
				{
				  printf ("Enter ISBN = ");
				  scanf ("%d", &x);
				  for (i = 0; i < count; i++)
					{
					  if (x == b[i].isbn)
						{
						  int k = p[j].num;
						  p[j].num = p[j].num + 1;
						  b[i].quantity = b[i].quantity - 1;
						  p[j].borisbn[k] = x;
						}
					}
				}
			}
		  break;
		case 8:
		  printf ("Enter id = ");
		  scanf ("%d", &a);
		  for (j = 0; j < pcount; j++)
			{
			  if (a == p[j].id)
				{
				  printf ("Enter ISBN = ");
				  scanf ("%d", &x);
				  int k = p[j].num;
				  for (int l = 0; l < k; l++)
					{
					  if (x == p[j].borisbn[l])
						{
						  p[j].borisbn[l] = p[j].borisbn[l + 1];
						  p[j].num = p[j].num - 1;

						  for (i = 0; i < count; i++)
							{
							  if (x == b[i].isbn)
								{
								  b[i].quantity = b[i].quantity + 1;
								}
							}
						}
					}
				}
			}
		  break;
		case 9:
		  printf ("Enter id = ");
		  scanf ("%d", &a);
		  for (j = 0; j < pcount; j++)
			{
			  if (a == p[j].id)
				{
				  int k = p[j].num;
				  for (int l = 0; l < k; l++)
					{
					  printf ("Borrowed book isbn= %d\n", p[j].borisbn[l]);
					}
				}
			}
		  break;
		case 10:
		  exit (0);

		}
	}
  return 0;
}
