#ifndef PERSON_H
#define PERSON_H

struct Person{
    int id;
    char name[50];
    char surname[50];
    char email[50];
    char password [20];
    double totalDonation;
};

void initializePerson(struct Person *person, int id, const char *name, const char *surname, const char *email, const char *password);
int login (const struct Person *person, const char *email, const char *password);
void readUsersFromFile(const char *filename);

#endif