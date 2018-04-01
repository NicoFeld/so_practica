/*
 * string_concat.c
 *
 *  Created on: 23 mar. 2018
 *      Author: Nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* mail_split(char* mail, char* user, char* domain) {
	printf("entre a la funcion");
	int mailLenght = strlen(mail);

	int encontreArroba = 0;
	printf("empiezo el for");
	for (int i = 0; i < mailLenght; i++) {
		if (mail[i] == '@') {
			encontreArroba = 1;
			printf("Arroba encontrada");
		} else {
			if (encontreArroba) {
				domain[i - strlen(user) - 1] = mail[i];
			} else {
				user[i] = mail[i];
			}
			printf("User = %s Domain = %s\n", user, domain);
		}

	}

}

void dinamyc_mail_split(char* mail, char** user, char** domain) {
	printf("entre a la funcion dinamyc");
	mail_split(mail, *user, *domain);
	printf("termine la funcion dinamyc");
}

int main(int argc, char** argv) {

	printf("Log 0%d",1);

	char* mail = "nicofeldfeber@gmail.com";
	printf("El tamaño del mail es: %d \n",strlen(mail));
	char* user = malloc(strlen(mail));
	char* domain = malloc(strlen(mail));

	dinamyc_mail_split(mail, &user, &domain);

	printf("User final = %s Domain final = %s\n", user, domain);

	return 0;
}
