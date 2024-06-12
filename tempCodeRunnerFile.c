int isAnonymous;
    enum DonationCategory category;

    printf("Press enter 0 to make a public donation, press 1 to make an anonymous donation: \n");
    scanf("%d", &isAnonymous);

    enum DonationCategory category;
    printf("Enter the donation category (0: FOOD, 1: CLOTHING, 2: MONEY, 3: OTHERS): ");
    scanf("%u", &category);



   

    
    if(category == FOOD){
        printf("Thank you for your food donation! \n");
    } else if(category == CLOTHING){
        printf("Thank you for your clothing donation!");
    }  else if(category == MONEY) { 
        enum DonationCountry country;
        printf("Enter the country for the money donation (0: USA, 1: EUROPE, 2: ASIA, 3: AFRICA, 4: OTHER): ");
        scanf("%u", &country);

        float amount;
        printf("Enter the amount for the donation: ");
        scanf("%f", &amount);

    if (isAnonymous == 0) {
         printf("You selected public donation.\n");
            makeDonation(&donationSystem, user.id, amount, isAnonymous, category, country);
        } else if (isAnonymous == 1) {
            // Gizli bağış
            printf("You selected anonymous donation.\n");
            makeDonation(&donationSystem, user.id, amount, isAnonymous, category, country);
        } else {
            printf("Invalid input. Please enter 0 or 1.\n");
        }

    // Toplam açık bağışları görüntüle
    double totalPublicDonation = getTotalDonation(&donationSystem, user.id, 0, category, USA);
    printf("Total public donation: %.2f\n", totalPublicDonation);

    // Toplam gizli bağışları görüntüle
    double totalAnonymousDonation = getTotalDonation(&donationSystem, user.id, 1, category, USA);
    printf("Total anonymous donation: %.2f\n", totalAnonymousDonation);

    // Toplam tüm bağışları görüntüle
    double totalDonation = totalPublicDonation + totalAnonymousDonation;
    printf("Total donation: %.2f\n", totalDonation);

    // Belleği temizleme
    freeDonationSystem(&donationSystem);

    return 0;
}