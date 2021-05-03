//****************************************************************************** 
// File name:	 Source.cpp
// Author:		 Joseph Foroughi
// Date:		   4/24/2021
// Class:		   CS 250
// Hours:      4~ hours
// Assignment: Polymorphism
// Purpose:		 Demonstrate Polymorphism
//******************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include "Parcel.h"
#include "Postcard.h"
#include "Letter.h"
#include "Overnight.h"

int const MAX = 25;
int const PRINT_ALL = 1;
int const ADD_INSURANCE = 2;
int const ADD_RUSH = 3;
int const DELIVER = 4;
int const QUIT = 5;
char const OVERNIGHT_PACKAGE = 'O';
char const LETTER = 'L';
char const POSTCARD = 'P';


using namespace std;

int main() {
  int choice;
  int selectedMail;
  char mailType = QUIT;
  Parcel *mail[MAX];
  ifstream inFile;
  inFile.open("Mail.txt");

  for (int uninatialized = 0; uninatialized < MAX; uninatialized++)
  {
    mail[uninatialized] = nullptr;
  }

  for (int pos = 0; pos < MAX; pos++) {
    if (!inFile.eof()) {
      inFile >> mailType;
      switch (mailType) {
      case POSTCARD: 
        mail[pos] = new Postcard;
        break;

      case LETTER:  
        mail[pos] = new Letter;
        break;

      case OVERNIGHT_PACKAGE: 
        mail[pos] = new Overnight;
        break;
      }
      mail[pos]->read(inFile);
    }
  }

  cout << "Mail Simulator!" << endl << endl;

  do {
    cout << "1. Print All" << endl
         << "2. Add Insurance" << endl
         << "3. Add Rush" << endl
         << "4. Deliver" << endl
         << "5. Quit" << endl << endl;
    do {
      cout << "Choice> ";
      cin >> choice;
    } while (choice < PRINT_ALL || QUIT < choice);
    cout << endl;

    if (choice != QUIT) {
      if (choice == PRINT_ALL) {
        for (int i = 0; i < MAX; i++) {
          if (mail[i] != nullptr) {
            mail[i]->print(cout);
          }
        }
      }
      else {
        do {
          cout << "TID> ";
          cin >> selectedMail;
          selectedMail--;
        } while (mail[selectedMail] == nullptr || (selectedMail < MAX && 0 > selectedMail));

        switch (choice) {
        case ADD_INSURANCE:
          mail[selectedMail]->setInsured();
          mail[selectedMail]->print(cout);
          break;

        case ADD_RUSH:
          mail[selectedMail]->setRush();
          mail[selectedMail]->print(cout);
          break;

        case DELIVER:
          cout << "Delivered!" << endl
               << mail[selectedMail]->getDeliveryDay() << " day, $";
          cout << fixed << setprecision(2) 
               << mail[selectedMail]->getCost() << endl;
          mail[selectedMail]->print(cout);
          delete mail[selectedMail];
          mail[selectedMail] = nullptr;
          break;
        }
      }
      cout << endl;
    }
    

  } while (choice != QUIT);

  //deallocate dynamic memory after a check
  for (int check = 0; check < MAX; check++)
  {
    if (mail[check] != nullptr)
    {
      delete mail[check];
    }
  }

  cout << "Reached the end!\n";
  return EXIT_SUCCESS;
}