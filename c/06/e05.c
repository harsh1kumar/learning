/*
 * Framework for symbol table for a C preprocessor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 3
#define HASH_MULTI 31

struct list
{
	struct list * next;
	char * name;
	char * defn;
};

unsigned int hash(char * s);
char * add_str(char * s);
void init_table(void);
struct list * lookup(char * s);
struct list * install(char * name, char * defn);
int undef_rem(char * name);
void print_val(char * name);
void print_table(void);

int main()
{
	init_table();

	print_table();
	install("MAXVAL", "25");
	print_table();
	install("LOW", "1");
	print_table();
	install("HIGH", "46");
	print_table();
	install("NOW", "wtf");
	print_table();

	print_val("LOW");

	install("LOW", "2");
	print_table();
	print_val("LOW");

	print_val("MAXVAL");
	print_val("HIGH");
	print_val("BOW");
	print_val("NOW");

	undef_rem("LOW");
	print_val("LOW");
	print_table();

	undef_rem("MAXVAL");
	print_table();
	undef_rem("HIGH");
	print_table();
	undef_rem("NOW");
	print_table();

	return 0;
}

/*************************
 * 	HASH TABLE
 *************************/

struct list * table[HASHSIZE];

/* Calculate hash */
unsigned int hash(char * s)
{
	unsigned int hashval;

	for(hashval = 0; *s; ++s)
		hashval = *s + (HASH_MULTI * hashval);

	return hashval % HASHSIZE;
}

/* Makes all the pointers in table to NULL */
void init_table()
{
	int i;
	for (i=0; i< (sizeof table)/(sizeof table[0]); ++i)
		table[i] = NULL;
}


/* Returns the pointer to the list element which stores name */
struct list * lookup(char * name)
{
	struct list * p = table[hash(name)];

	while(p!=NULL && strcmp(p->name, name))
		p = p->next;

	return p;
	
}

/* Allocate memory for s & save value of s in that memory */
char * add_str(char * s)
{
	char * p;

	p = (char *)malloc( strlen(s)*sizeof(char));
	if (p == NULL)
	{
		printf("Error: Memory allocation failed for %s\n", s);
		return NULL;
	}
	strcpy(p, s);

	return p;
}

/* Adds name & defn in the hash table */
struct list * install(char * name, char * defn)
{
	struct list * p;

	if ( (p=lookup(name)) == NULL )
	{
		/* Defination not present.*/
		p = (struct list *)malloc(sizeof(struct list));
		if (p == NULL)
		{
			printf("Error: Memory allocation for list element failed while adding %s\n", name);
			return NULL;
		}
		p->name = add_str(name);
		p->defn = add_str(defn);
		p->next = NULL;

		int hashval = hash(name);
		struct list * q = table[hashval];
		if ( q == NULL)
		{
			table[hashval] = p;
		}
		else
		{
			while(q->next != NULL)
				q = q->next;
			q->next = p;
		}

		return p;
	}
	else
	{
		/* Defination already present. Redefining */
		free(p->defn);
		p->defn = add_str(defn);
		return p;
	}
}

/* Used for undef when a defination has to be removed from the list */
int undef_rem(char * name)
{
	struct list * p, * q = lookup(name);

	if (q==NULL)
	{
		fprintf(stderr, "Error: Trying to undef %s which is not defined\n", name);
		return 0;
	}

	unsigned int hashval = hash(name);
	p = table[hashval];
	if (p == q)
	{
		/* Entry is pointed by table element */
		table[hashval] = table[hashval]->next;
		free(q);
		return 1;
	}
	else
	{
		/* Entry some where inside the list */
		while(p->next != q)
			p = p->next;

		p->next = q->next;
		free(q);
		return 1;
	}
}

void print_val(char * name)
{
	struct list * l = lookup(name);

	if (l == NULL)
		printf("%s not defined\n", name);
	else
		printf("%s = %s\n", l->name, l->defn);
}

void print_table()
{
	int i;
	for(i=0; i < HASHSIZE; ++i)
		printf(":%p\n", table[i]);
	printf("\n");
}

