#include <stdio.h>
#include <stdlib.h>
#include "donation.h"

void initializeDonationSystem(struct DonationSystem *system){
    system->donations = NULL;
    system->numDonations = 0;
}
void processMoneyDonation(struct DonationSystem *system, int personId, float amount, int isAnonymous, enum DonationCountry country){
    switch(country){
        case USA: 
         //Donation transactions in USA currency
    printf("Thank you for your donation in US dollars!\n");
    break;
    case EUROPE:
    //donation transactions in european currency
    printf("Thank you for your donation in euros!\n");
    break;
    case ASIA:
    //donation transactions in asian currency
    printf("Thank you for your donation in Asian currency!\n");
    break;
    case AFRICA:
    //donation transactions in african currency
    printf("Thank you for your donation in African currency!\n");
    break;
    case OTHER:
    //Donation procedures for other countries:
    printf("Thank you for your donation!\n");
    break;
    default:
    break;
    }
    
   
}

void makeDonation(struct DonationSystem *system, int personId, double amount, int isAnonymous, enum DonationCategory category, enum DonationCountry country){
    system->donations = realloc(system->donations, (system->numDonations+1) * sizeof(struct Donation*));

    if(system->donations == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    system->donations[system->numDonations]=malloc(sizeof(struct Donation));

    if(system->donations[system->numDonations]==NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    system->donations[system->numDonations]->personId = personId;
    system->donations[system->numDonations]->amount = amount;
    system->donations[system->numDonations]->isAnonymous= isAnonymous;

    system->numDonations++;
}
  /*  struct Donation newDonation;
    newDonation.personId = personId;
    newDonation.amount = amount;
    newDonation.isAnonymous = isAnonymous;

    system->donations[system->numDonations++]=newDonation;
}*/

double getTotalDonation(const struct DonationSystem *system, int personId, int isAnonymous, enum DonationCategory category, enum DonationCountry country){
    double total = 0.0;

    for(int i = 0; i<system->numDonations; ++i){
        if(system->donations[i]->personId == personId && system->donations[i]->isAnonymous==isAnonymous){
            total += system->donations[i]->amount;
        }
    }
    return total;
}

void freeDonationSystem(struct DonationSystem *system){
    for(int i = 0; i<system->numDonations; ++i){
        free(system->donations[i]);
    }
    free(system->donations);
    system->numDonations = 0;
}