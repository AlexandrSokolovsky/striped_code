/*
main.cpp
Соколовский А.В.
23.10.2022

основной файл с main()
программа, которая выделяет 32КБ памяти, заполняет полосатым кодом - 52525, записывает в файл в бинарном виде

закомментирована функция для считывания с файла read_from_file
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int write_to_file(unsigned short int &);
//int read_from_file(unsigned short int &);

int main()
{ 

	

	unsigned short int word = atoi("052525");
	unsigned short int *ptr = (unsigned short int*)calloc(32*1024/sizeof(unsigned short int), sizeof(unsigned short int));
	//read_from_file(*ptr);
	
	int size = 32 * 1024 / sizeof(unsigned short int);

	for (int i = 0; i < size; i++)
	{
		*(ptr+i) = word;
	}



	write_to_file(*ptr);

	free(ptr);

	return 0;
}

/*
запись в файл в бинарном виде
unsigned short int &ptr - массив, заполенный полосатым кодом
*/
int write_to_file(unsigned short int &ptr)
{

	FILE *write_ptr;

	write_ptr = fopen("striped_code_array.bin", "wb+");
	fwrite(&ptr, 32 * 1024, 1, write_ptr);

	fclose(write_ptr);

	return 0;
}

/*
int read_from_file(unsigned short int &ptr)
{
	int size = 0;

	FILE *rptr;


	rptr = fopen("striped_code_array.bin", "rb+");
	if (rptr)
	{
		fseek(rptr, 0, SEEK_END);
		size = ftell(rptr);
		fseek(rptr, 0, SEEK_SET);

		fread(&ptr, size, 1, rptr);

		fclose(rptr);		
	}

	for (int i = 0; i < size / sizeof(unsigned short int); i++)
	{
		printf("0%u\n", *(&ptr + i));
	}

	return 0;
}
*/