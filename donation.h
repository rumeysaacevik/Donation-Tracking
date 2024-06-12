#ifndef DONATION_H
#define DONATION_H
#include <stdio.h>
#include <stdlib.h>


enum DonationCountry {
    USA,
    EUROPE,
    ASIA,
    AFRICA,
    OTHER,
};

enum DonationCategory{
    FOOD,
    CLOTHING,
    MONEY,
    OTHERS,
};


struct Donation { 
    int personId;
    double amount;
    int isAnonymous;   //0 for public, 1 for anonymous
    enum DonationCategory category; 
};

struct DonationSystem{
    struct Donation **donations;
    int numDonations;
};

void initializeDonationSystem(struct DonationSystem *system);
void makeDonation(struct DonationSystem *system, int personId, double amount, int isAnonymous, enum DonationCategory category, enum DonationCountry country);
double getTotalDonation(const struct DonationSystem *system, int personId, int isAnonymous, enum DonationCategory category, enum DonationCountry country);
void freeDonationSystem(struct DonationSystem *system);
void processMoneyDonation(struct DonationSystem *system, int personId, float amount, int isAnonymous, enum DonationCountry country);
#endif