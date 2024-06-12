#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"
#include "donation.h"
#include "person.c"
#include "donation.c"


float exchangeRates[] = {5.0, 0.35, 0.40, 1.45, 7.25};

int main()
{
    struct Person user;
    printf("Enter user ID: ");
    scanf("%d", &user.id);

    printf("Enter user name: ");
    scanf("%s", user.name);

    printf("Enter user surname: ");
    scanf("%s", user.surname);

    printf("Enter user email: ");
    scanf("%s", user.email);

    printf("Enter user password: ");
    scanf("%s", user.password);

    printf("\nWelcome!, %s %s!\n", user.name, user.surname);

    struct DonationSystem donationSystem;
    initializeDonationSystem(&donationSystem);

    int continueProgram = 1;
    int isAnonymous;
    enum DonationCategory category;
    enum DonationCountry country;
    float amount;

    while (continueProgram)
    {
        printf("\nPlease press 0 for donation or press 1 to end the program: ");
        scanf("%d", &continueProgram);

        if (continueProgram == 1)
        {
            printf("The program has been terminated. Thank you for your interest and cooperation!\n");
            break;
        }
        else if (continueProgram == 0)
        {
            do
            {
                printf("Please enter 0 to make a public donation, enter 1 to make an anonymous donation: ");
                scanf("%d", &isAnonymous);

                printf("Please enter the donation category (0: FOOD, 1: CLOTHING, 2: MONEY, 3: OTHERS): ");
                scanf("%u", &category);

                if (category == FOOD)
                {
                    int foodChoice;

                    printf("Choose a food type:\n");
                    printf("1. Fast Food\n");
                    printf("2. Vegetarian\n");
                    printf("3. Vegan\n");
                    printf("4. Dessert\n");

                    printf("Enter your choice (1-4): ");
                    scanf("%d", &foodChoice);
                    switch (foodChoice)
                    {
                    case 1:
                        printf("Thank you for your donation in the Fast Food category!\n");
                        break;
                    case 2:
                        printf("Thank you for your donation in the Vegetarian category!\n");
                        break;
                    case 3:
                        printf("Thank you for your donation in the Vegan category!\n");
                        break;
                    case 4:
                        printf("Thank you for your donation in the Dessert category!\n");
                        break;
                    default:
                        printf("Invalid choice. Please enter a number between 1 and 4.\n");
                        break;
                    }
                }
                else if (category == CLOTHING)
                {
                    int clothingChoice;

                    printf("Choose a clothing category:\n");
                    printf("1. Casual Wear\n");
                    printf("2. Formal Wear\n");
                    printf("3. Sportswear\n");
                    printf("4. Shoes and Boots\n");

                    printf("Enter your choice (1-4): ");
                    scanf("%d", &clothingChoice);

                    switch (clothingChoice)
                    {
                    case 1:
                        printf("Thank you for your donation in the Casual Wear category!\n");
                        break;
                    case 2:
                        printf("Thank you for your donation in the Formal Wear category!\n");
                        break;
                    case 3:
                        printf("Thank you for your donation in the Sportswear category!\n");
                        break;
                    case 4:
                        printf("Thank you for your donation in the Shoes and Boots category!\n");
                        break;
                    default:
                        printf("Invalid choice. Please enter a number between 1 and 4.\n");
                        break;
                    }
                }
                else if (category == MONEY)
                {
                    printf("Enter the country for the money donation (0: USA, 1: EUROPE, 2: ASIA, 3: AFRICA, 4: OTHER): ");
                    scanf("%u", &country);

                    printf("Enter the amount for the donation: ");
                    scanf("%f", &amount);

                    if (isAnonymous == 0)
                    {
                        // public donation
                        printf("You selected public donation.\n");
                        makeDonation(&donationSystem, user.id, amount * exchangeRates[country], isAnonymous, category, country);
                    }
                    else if (isAnonymous == 1)
                    {
                        // private donation
                        printf("You selected anonymous donation.\n");
                        makeDonation(&donationSystem, user.id, amount * exchangeRates[country], isAnonymous, category, country);
                    }
                    else
                    {
                        printf("Invalid input. Please enter 0, 1\n");
                    }

                    // total open donations
                    double totalPublicDonation = getTotalDonation(&donationSystem, user.id, 0, category, country);
                    printf("Total public donation: %.2f\n", totalPublicDonation);

                    // total private donations
                    double totalAnonymousDonation = getTotalDonation(&donationSystem, user.id, 1, category, country);
                    printf("Total anonymous donation: %.2f\n", totalAnonymousDonation);

                    // total all donations
                    double totalDonation = totalPublicDonation + totalAnonymousDonation;
                    printf("Total donation: %.2f\n", totalDonation);
                }
                else if (category == OTHERS)
                {
                    printf("Please enter the specific donation category for 'OTHERS': ");
                    char specificCategory[50];
                    scanf("%s", specificCategory);

                    printf("Thank you for your donation in the '%s' category!\n", specificCategory);
                }
                else
                {
                    printf("Invalid donation category. Please enter 0, 1, 2 or 3.\n");
                }

                printf("Do you want to make another donation? (1 for yes, 0 for no): ");
                scanf("%d", &continueProgram);
            } while (continueProgram == 1);
            printf("Thank you for your interest and cooperation!\n");
        }
        else
        {
            printf("Invalid input. Please enter 0 or 1.\n");
        }
    }
    


    FILE *donationFile = fopen("donations.txt", "w");
    if (donationFile == NULL)
    {
        fprintf(stderr, "Error opening or creating donations.txt\n");
        exit(EXIT_FAILURE);
    }

    fprintf(donationFile, "%d %.2f %d %u\n", user.id, amount, isAnonymous, category, country);
    fclose(donationFile);

    freeDonationSystem(&donationSystem);

    return 0;
}