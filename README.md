# Donation-Tracking

# 1) Aim of the project

Donation Management System is a program that offers users various donation options and manages these donations. The main purpose of the project is to allow users to donate in certain categories (food, clothing, money and other) and to track these donations according to 
categories. Displays total hidden and open donations with open donation and secret donation functions. 

# 2) Program Structs and Relationships

2.1)The main purpose of use of “Person” struct :
   
- This structure contains basic information of donating users. Keeps the user's name, surname, e-mail address, password and ID
  
2.2)The main purpose of use of Donation struct : 

- This structure contains donation information. Checks whether donations are anonymous
  
2.3)The main purpose of donationSystem struct : 

- This structure represents the donation system and maintains a dynamically allocated array to store donations
  
# 3) Rules :
  
3.1) Users can register to the system with their name, surname, e-mail and password information. 

3.2) Users can donate food, clothing, money or other categories. Before donating, the category to donate must be selected. 

3.3) Users can choose to make their donations anonymous or public. Anonymous donations ensure that the identity of the donor is kept private. 

3.4) When monetary donation is selected, the country to donate to must be selected. The donation amount must be converted into the currency of the country to be donated. 

3.5) Users can view total open and anonymous donation amounts. 

3.6) Users can only select available donation categories. In case of an invalid category selection, an error message should be displayed.
