/*
 * string_concat.c
 *
 *  Created on: 23 mar. 2018
 *      Author: Nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mail_split(char* mail, char** user, char** domain) {
	printf("entre a la funcion");
	int mailLenght = sizeof(mail);

	int encontreArroba = 0;
	printf("empiezo el for");
	for (int i = 0; i < mailLenght; i++) {
		if (mail[i] == '@') {
//			encontreArroba = 1;
		} else {
			if (encontreArroba) {
				*domain[i - sizeof(*user) - 1] = mail[i];
			} else {
				*user[i] = mail[i];
			}
			printf("User = %s Domain = %s\n", *user, *domain);
		}
		printf("Arroba encontrada");
	}

}

int main(int argc, char** argv) {

	printf("Log 0");

	char* mail = "nicofeldfeber@gmail.com";

	char* user;
	char* domain;

	mail_split(mail, &user, &domain);

	return 0;
}
