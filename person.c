#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

void initializePerson(struct Person *person, int id, const char *name, const char *surname, const char *email, const char *password){
    person->id = id;
    strncpy(person->name, name, sizeof(person->name)-1);
    person->name[sizeof(person->name)-1]='0';

    strncpy(person->surname, surname, sizeof(person->surname)-1);
    person->surname[sizeof(person->surname)-1]='0';

    strncpy(person->email, email, sizeof(person->email)-1);
    person->email[sizeof(person->email)-1]='0';

    strncpy(person->password, password, sizeof(person->password)-1);
    person->password[sizeof(person->password)-1]='0';
    person->totalDonation = 0.0;
}

int login(const struct Person *person, const char *email, const char *password){
    return (strcmp(person->email, email)==0 && strcmp(person->password, password)==0);
    
}

void readUsersFromFile(const char *filename){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        fprintf (stderr, "Error opening file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }

    struct Person person;
    while(fscanf(file, "%d %s %s %s %s %1f", &person.id, person.name, person.surname, person.email, person.password, &person.totalDonation)==6){
        printf("Read user: ID: %d, Name: %s, Surname: %s, Email: %s, Password: %s, Total Donation: %.2f\n", 
        person.id, person.name, person.surname, person.email, person.password, person.totalDonation);
    }
    fclose(file);
}