#include"DataBase.h"
#include<stdlib.h>

DataBase::DataBase()
{
	ShoppingCart T;
	ShoppingCart N;
	int ScSartSerial = 0;
	int ProductSerial = 0;
	this->Scsize = 0;
	int choice;
	bool run = true;
	int unionserial1;
	int unionserial2;
	int serial = 1;
	int amount = 1;
	int choice3;
	int PrintCheck = 0;
	int SerialOfDeletedInShop = -1;
	int Exists1 = 0;
	int Exists2 = 0;
	int indextodelete = -1;
	int NumOfPages;
	int MinAge;
	char genre[MaxDigits];
	char Sentence[MaxDigits];
	int i = 0;
	char CharNUM[MaxDigits];
	int Level;
	
	
	while (run)
	{
		bool run1 = true; // Setting true
		bool run2 = true; // Setting true
		bool run3 = true; // Setting true
		PrintMenu1();
		cin >> choice;
		switch (choice)
		{
		case 1://////////////////////////////// The MANAGER
			char NameOfProduct[MaxDigits];
			char name[MaxDigits];
			int publishyear;
			float price;
			int choice;
			while (run2)
			{
				S.PrintShopMneu(); // Printing the shop menu
				cin >> choice;
				getchar();
				switch (choice)
				{
				case 1:
					strcpy(Sentence, S.getstring()); // Getting a full sentence
					strcpy(NameOfProduct, S.GetWord(Sentence,&i)); // Getting a word from the sentence

					if (strcmp(NameOfProduct,"Children Book") == 0) // Children book
					{
						strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting the name of the book

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the number of pages 
						NumOfPages = atoi(CharNUM);
						if (NumOfPages <= 0)
						{
							cout << "Error: Number of pages must be at least 1" << endl;
							i = 0;
							break;
						}

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the publishing year
						publishyear = atoi(CharNUM);
						if (publishyear <= 0 || publishyear > CurrentYear)
						{
							cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
							i = 0;
							break;
						}

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the minimum age
						MinAge = atoi(CharNUM);
						if (MinAge <= 0 )
						{
							cout << "Error: An Age can not be zero or negative" << endl;
							i = 0;
							break;
						}

						ProductSerial++; // serial++

						Product* T = new KidsB(NameOfProduct, ProductSerial, publishyear, 0.0, NumOfPages, MinAge); // Building the object
						if (S.ItemExists(*T)) // Checking if the ibject is already in the shop
						{
							cout << "Error: Item already exists in the system." << endl;
						}
						else
						{
							S += *T; // Adding it to the shop
						}
						i = 0;
					}
					if (strcmp(NameOfProduct, "Reading Book") == 0) // if reading book
					{
						strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting name

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting number of pages
						NumOfPages = atoi(CharNUM);
						if (NumOfPages <= 0)
						{
							cout << "Error: Number of pages must be at least 1" << endl;
							i = 0;
							break;
						}

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting publishing year
						publishyear = atoi(CharNUM);
						if (publishyear <= 0 || publishyear > CurrentYear)
						{
							cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
							i = 0;
							break;
						}

						strcpy(genre, S.GetWord(Sentence, &i)); // Getting the genre of the book


						ProductSerial++; // serial++

						Product* T = new ReadingB(NameOfProduct, ProductSerial, publishyear, 0.0, NumOfPages, genre); //Building the object
						if (S.ItemExists(*T))// Checking if the ibject is already in the shop
						{
							cout << "Error: Item already exists in the system." << endl;
						}
						else
						{
							S += *T; // Adding it to the shop
						}
						i = 0;
					}
					else if (strcmp(NameOfProduct, "Music Album") == 0) // Music Album
					{
						char AlbumName[MaxDigits]; 
						cout << "\t";
						strcpy(AlbumName, S.GetWord(Sentence, &i));   // Getting the name

						strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the publishing year
						publishyear = atoi(CharNUM);
						if (publishyear <= 0 || publishyear > CurrentYear)
						{
							cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
							i = 0;
							break;
						}

						i = 0; 

						char SongName[MaxDigits];
						int SongLength;
						int NumOfSongs = 0;
						Song* Songs = NULL;
						Song* Temp = NULL;
						Song T;

						strcpy(Sentence, S.getstring()); // Getting the sentence for the song
						strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting the first word
						do
						{
							strcpy(SongName, S.GetWord(Sentence, &i)); // Getting the song name

							strcpy(CharNUM, S.GetWord(Sentence, &i));  // Getting the song length
							SongLength = atoi(CharNUM);

							T.SetName(SongName); // Setting the name
							T.SetLength(SongLength); // Setting the length
							if (SongLength <= 0)
							{
								cout << "Error: A length of a song can not be zero or negative" << endl;
								i = 0;
								break;
							}

							NumOfSongs++; //Number of songs ++

							Temp = Songs;
							Songs = new Song[NumOfSongs];
							for (int i = 0; i < NumOfSongs - 1; i++) // Copying the current songs array
							{
								Songs[i] = Temp[i];
							}
							Songs[NumOfSongs - 1] = T; // Adding the new song

							i = 0;
							cout << "\t";
							strcpy(Sentence, S.getstring()); // Getting the sentence for the song
							strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting the first word

						} while (strcmp(NameOfProduct, "Song") == 0);
						
						ProductSerial++; //serial++
						if (SongLength <= 0)
						{
							i = 0;
							break;
						}
						MusicAlbum* temp = new MusicAlbum(AlbumName, ProductSerial, publishyear, 0.0, Songs, NumOfSongs); //Building the object
						if (S.ItemExists(*temp)) // Checking if the ibject is already in the shop
						{
							cout << "Error: Item already exists in the system." << endl;
						}
						else
						{
							S += *temp; // Adding it to the shop
						}
						i = 0;
					}
					else if (strcmp(NameOfProduct, "Movie") == 0) // Movie
					{
						strcpy(NameOfProduct, S.GetWord(Sentence, &i)); 

						if (strcmp(NameOfProduct, "Action") == 0) // Action Movie
						{
							strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting name

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting publishing year
							publishyear = atoi(CharNUM);
							if (publishyear <= 0 || publishyear > CurrentYear)
							{
								cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
								i = 0;
								break;
							}

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting level
							Level = atoi(CharNUM);
							if (Level > ActionMAXlvl || Level < MovieMinLVL)
							{
								cout << "Error: The level must be in range" << endl;
								i = 0;
								break;
							}

							ProductSerial++; // serial++

							Product* T = new ActionM(NameOfProduct, ProductSerial, publishyear, 0.0, Level); // Building the object
							if (S.ItemExists(*T)) // Cheking if exists in the shop
							{
								cout << "Error: Item already exists in the system." << endl;
							}
							else
							{
								S += *T; // Adding to shop
							}
							i = 0;
						}
						else if (strcmp(NameOfProduct, "Sci-Fi") == 0) // Sci fi movie
						{
							strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting name

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting publishing year
							publishyear = atoi(CharNUM);
							if (publishyear <= 0 || publishyear > CurrentYear)
							{
								cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
								i = 0;
								break;
							}

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // getting level 
							Level = atoi(CharNUM);
							if (Level > ScifiMAXlvl || Level < MovieMinLVL)
							{
								cout << "Error: The level must be in range" << endl;
								i = 0;
								break;
							}

							ProductSerial++; // Serial++

							Product* T = new ScifiM(NameOfProduct, ProductSerial, publishyear, 0.0, Level); // Building the object
							if (S.ItemExists(*T)) // Cheking if exists in the shop
							{
								cout << "Error: Item already exists in the system." << endl;
							}
							else
							{
								S += *T; // Adding to shop
							}
							i = 0;
						}
						else if (strcmp(NameOfProduct, "Thriller") == 0) // thriller movie
						{
							strcpy(NameOfProduct, S.GetWord(Sentence, &i)); // Getting the name

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the publishyear
							publishyear = atoi(CharNUM);
							if (publishyear <= 0 || publishyear > CurrentYear)
							{
								cout << "Error: Publishing year must be at least 1 and not more than the current year" << endl;
								i = 0;
								break;
							}

							strcpy(CharNUM, S.GetWord(Sentence, &i)); // Getting the level
							Level = atoi(CharNUM);
							if (Level > ThrillerMAXlvl || Level < MovieMinLVL)
							{
								cout << "Error: The level must be in range" << endl;
								i = 0;
								break;
							}

							ProductSerial++; // Serial ++

							Product* T = new ThrillerM(NameOfProduct, ProductSerial, publishyear, 0.0, Level); // Building the object
							if (S.ItemExists(*T)) // Cheking if exists in the shop
							{
								cout << "Error: Item already exists in the system." << endl;
							}
							else
							{
								S += *T;  // Adding to shop
							}
							i = 0;
						}
					}
					break;

				case 2: // Deleting an item from the shop
					cin >> indextodelete;
					if ((S -= indextodelete) != -1) // If the object is found and deleted ( the return value is not -1 )
					{
						for (int i = 0; i < this->Scsize; i++) // Deleting the object from all the buskets
						{
							if (this->SC[i].ItemExists(indextodelete))
								this->SC[i] -= indextodelete;
						}
					}
					else
						cout << "Error: Item with corresponding serial does not exist." << endl;
					break;

				case 3: //Printing by index
					int indextoprint;
					cin >> indextoprint;
					if (S.PrintByIndex(indextoprint) == 0) // If Printed it will return a number ( exept 0 ), if zero is returned the serial not exist 
						cout << "Error: Item with corresponding serial does not exist." << endl;
					cout << endl;
					break;
				case 4:
					cout << S << endl; // Printing the shop
					break;
				case 5:
					run2 = false;
					break;
				default: /// If the number is not one of the options
					cout << "There is no such option please choose again!" << endl;
					break;
				}
			}
			break;
		case 2: //////////////////////// The USER
			if (this->S.GetSize() == 0 ) // Checking if there is at least one item in the shop 
			{
				cout << "Error: There are no items in store." << endl;
				break;
			}
				
			while (run1)
			{
				run2 = true;
				run3 = true;
				int choice2;
				PrintMenu2();
				cin >> choice2;
				switch (choice2)
				{
				case 1: /////////////// NEW BUSKET
					
					while (run3)
					{
						
						PrintMenu3();
						cin >> choice3;
						switch (choice3)
						{
						case 1: // Adding by serial and amount
							cout << "Enter product serial and amount:" << endl;
							cin >> serial;
							cin >> amount;
							while (serial > 0 && amount > 0) // if the amount and serial are not zero
							{
								if (S.GetProduct(serial) != NULL) // Checking if the serial exists
								{
									if (T.ItemExists(*S.GetProduct(serial))) // Checking if the product exists in the busket
									{
										T.AddExistingItem(*S.GetProduct(serial), amount); // Adding only the amount of the Existing object
									}
									else
									{
										T += *S.GetProduct(serial); // Adding to the busket
											T.SetAmount(amount, serial - 1); // Setting the amount in the busket
									}
								}
								else
								{
									cout << "Error: Item with corresponding serial does not exist." << endl;
								}
									
								cout << "Enter product serial and amount:" << endl;
								cin >> serial;
								cin >> amount;
								if (serial == 0 && amount == 0) // If they are zero it will build the busket 
								{
									ScSartSerial++; // Shoppingcart Serial++
									T.SetSerial(ScSartSerial); // Setting the serial
									this->AddNewBusket(T); // Adding the busket
									T = N; // Zeroing T to a Default busket
								}
									
							}
							break;

						case 2: ///// Copying a Busket
							cout << "Which product basket to copy? "<< endl;
							cin >> serial;
							if (SerialExists(serial) != -1) // Checking if the serial exists
							{
								if (this->SC[serial - 1].GetSize() > 0)
								{
									T = this->SC[serial - 1]; //Copying the basket
									ScSartSerial++; // Shoppingcart Serial++
									T.SetSerial(ScSartSerial); // Setting the serial
									this->AddNewBusket(T); // Adding the busket
								}
								else
								{
									T = N;
									ScSartSerial++; // Shoppingcart Serial++
									T.SetSerial(ScSartSerial); // Setting the serial
									this->AddNewBusket(T); // Adding the busket
								}
							}
							else
								cout << "Error: Selected product serial number does not exist." << endl;
							T = N; // Zeroing T to a Default busket
							break;

						case 3: /////// Union of two product baskets
							cout << "Which product baskets to use?" << endl;
							cin >> unionserial1;
							cin >> unionserial2;
							if (SerialExists(unionserial1) != -1 && SerialExists(unionserial2) != -1) // Checking if the serials exist
							{
								T = this->SC[SerialExists(unionserial1)] + this->SC[SerialExists(unionserial2)]; //Doing the Union
								ScSartSerial++; // Shoppingcart Serial++
								T.SetSerial(ScSartSerial); // Setting the serial
								this->AddNewBusket(T); // Adding the busket
							}
							else
							{
								cout << "Error: One of the selected product baskets does not exist. " << endl;
							}
							T = N; // Zeroing T to a Default busket
							break;

						case 4: /////// Intersection of two product 
							cout << "Which product baskets to use?" << endl;
							cin >> unionserial1;
							cin >> unionserial2;
							if (SerialExists(unionserial1) != -1 && SerialExists(unionserial2) != -1) // Checking if the serials exist
							{
								T = this->SC[SerialExists(unionserial1)] - this->SC[SerialExists(unionserial2)]; // Doing the Intersection
								ScSartSerial++; // Shoppingcart Serial++
								T.SetSerial(ScSartSerial); // Setting the serial
								this->AddNewBusket(T); // Adding the busket
							}
							else
							{
								cout << "Error: One of the selected product baskets does not exist. " << endl;
							}
							T = N; // Zeroing T to a Default busket
							break;
						case 5: // Exiting the current menu to the previous 
							run3 = false;
							break;
						default: // If the number that been chosen is not exist
							cout << "Wrong choice please choose again" << endl;
							break;
						}
					}
					
					break;
				case 2: // Printing a cart by serial
					int serialtoprint;
					cin >> serialtoprint;
					for (int i = 0; i < this->Scsize; i++) // Going over all the buskets
					{
						if (this->SC[i].GetCartSerial() == serialtoprint) // Checking if the serial is the same
						{
							cout << this->SC[i]; // Printing the busket
							PrintCheck++;
						}
					}
					if(PrintCheck == 0)
						cout << "Error: Product basket with corresponding serial does not exist" << endl;
					PrintCheck = 0;
					break;
				case 3: // Printing all the buskets/Shopping carts
					for (int i = 0; i < this->Scsize; i++)
					{
						cout << this->SC[i];
					}
					break;

				case 4: // Deleting a busket
					ShoppingCart * Temp;
					int serialtodelete;
					int index;
					cin >> serialtodelete;
					index = SerialExists(serialtodelete); // Getting the index of the busket
					if (index != -1 && this->Scsize > 0) // if the index exists
					{
						Temp = new ShoppingCart[this->Scsize - 1]; // Allocating a array that is smaller by 1
						if (Temp == NULL)
						{
							cout << "Allocation Failed";
							exit(1);
						}
						for (int i = 0; i < index; i++) // Copying all the array untill the index
						{
							Temp[i] = this->SC[i];
						}
						int j = index + 1;
						for (int i = index; i < this->Scsize - 1 ; i++) // Copying all the array from the index+1 untill the end if the array
						{
							Temp[i] = this->SC[j];
							j++;
						}
						this->SC = Temp;
						this->Scsize--;
					}
					else
					{
						cout << "Error: Product basket with corresponding serial does not exist" << endl;
					}
					break;

				case 5: //// Exiting the current menu to the previous 
					run1 = false;
					break;
				default: // If the number that been chosen is not exist
					cout << "Wrong choice please choose again" << endl;
					break;
				}
			}
			break;

		case 3: // Exiting the current menu to the previous 
			run = false;
			break;

		default: // If the number that been chosen is not exist
			cout << "Wrong choice please choose again" << endl;
			break;
		}
	}
}
DataBase::~DataBase() // Dtor
{

}
void DataBase::PrintMenu1() const // Prints main menu
{
	cout << "---------------------------------------" << endl;
	cout << "1.Add item to store data base" << endl;
	cout << "2.Handle client" << endl;
	cout << "3.Exit" << endl;
	cout << "---------------------------------------" << endl;
}
void DataBase::PrintMenu2() const // Print the busket menu
{
	cout << "---------------------------------------" << endl;
	cout << "1.Build new product basket" << endl;
	cout << "2.Print product basket" << endl;
	cout << "3.Print all product baskets" << endl;
	cout << "4.Delete product basket" << endl;
	cout << "5.Return" << endl;
	cout << "---------------------------------------" << endl;
}
void DataBase::PrintMenu3() const // Prints the build busket menu
{
	cout << "---------------------------------------" << endl;
	cout << "1.Select products" << endl;
	cout << "2.Copy existing product basket" << endl;
	cout << "3.Union of two product baskets" << endl;
	cout << "4.Intersection of two product baskets)" << endl;
	cout << "5.Return" << endl;
	cout << "---------------------------------------" << endl;
}

void DataBase::AddNewBusket(ShoppingCart& temp) // Adding new busket to the array
{
	ShoppingCart* T;
	T = new ShoppingCart[this->Scsize + 1]; // Allocating a bigger array
	if (T == NULL)
	{
		cout << "Allocationg Failed" << endl;
		exit(1);
	}
	for (int i = 0; i < this->Scsize; i++) // Copying all the current array
	{
		T[i] = this->SC[i];
	}
	T[this->Scsize] = temp; // Adding the new busket

	this->SC = T;
	this->Scsize++;
}

int DataBase::SerialExists(int s) const // Checking if serial of a cart exists
{
	for (int i = 0; i < this->Scsize; i++)
	{
		if (s == this->SC[i].GetCartSerial())
			return i;
	}
	return -1;
}

