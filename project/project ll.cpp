// ********Library book management system*******
#include <iostream>
#include <string>   //stores a sequence of letter and other character
#include <conio.h>  //stand for consule input output and is used to access getchar,clsrc 
#include <unistd.h> //used to access sleep function
#include <fstream>  // It provides the capability of creating, writing and reading a file
#define MAX 30

using namespace std;

string que[15];
string quee[8];
int front=-1,frontt=-1,rear=-1,rearr=-1,value=15,val=8;

struct personrecord
{
	string PID;
	string PName;
	string Phone;
	int BorrowNo;
	int ReturnNo;
	string BorrowingBook[3][5];
	string ReturningBook[15][5];
	personrecord* Next;
};


struct BookRecord
{
	string bID;
	string btitle;
	string category;
	string genre;
	bool availability;
	BookRecord* Next2;
};


personrecord* Head = NULL;
BookRecord* Head2 = NULL;

int place = 0, place2 = 0, posi = 0;
string  option1, option2;
char choice;
char choice22;
int position;

string Booktitle, bcateg, bgenre, borrowdate, bkid, pid;

string PIDInput;
string PNameInput;
string PhoneInput;
string BorrowingBookInput[3][5];
string ReturningBookInput[15][5];
int BorrowNoInput;

string bkidinput;
string btitleInput;
string categoryInput;
string genreInput;
bool availabilityInput;

string genre1 = "Fantasy";
string genre2 = "Science";
string genre3 = "Historical";
string genre4 = "Realistic";
string genre5 = "Fan";
string genre6 = "Narrative";
string genre7 = "Biography";
string genre8 = "Periodicals";
string genre9 = "Self-help";
string genre10 = "Reference";
string category1 = "Fiction";
string category2 = "Non-Fiction";


void Menu_display();
void Admin_Login();
void AddBook();
void AddPatron();
void DisplayBook(BookRecord* Head);
void DisplayBookA(BookRecord* Head);
BookRecord* SearchBook(string title, BookRecord* Head);
bool SearchP(string pid, personrecord* Head);
bool Searchb(string bid, BookRecord* Head);
void returnbook();
void borrowBook(string biD, BookRecord* Head2);
bool borrowBookp(string biD, personrecord* Head);
void SearchPRecord(personrecord* Head);
void PreturnedB(personrecord* Head);
BookRecord* UpdateBook(string biD, BookRecord* Head);
void UpdatePInfo();
void DisplayPatrons(personrecord* Head);
void InsertArbitraryp(string patronid, string pname, string phone, int index);
void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index);

												/////////////////////////////
												// Adds person in the list //
												////////////////////////////    

void InsertArbitraryp(string personid, string pname, string phone, int index)
{
	personrecord* New_node = new personrecord;
	New_node->PID = personid;
	New_node->PName = pname;
	New_node->Phone = phone;
	New_node->BorrowNo = 0;
	New_node->ReturnNo = 0;
	if (index <= place) 
	{
		if (index == 0)
		 {
			personrecord* Position = new personrecord;
			Position->PID = personid;
			Position->PName = pname;
			Position->Phone = phone;                            //insertion at head
			Position->BorrowNo = 0;
			Position->ReturnNo = 0;
			Position->Next = Head;
			Head = Position;
		 }
		else if (index == place) 
		{
			personrecord* Position2 = new personrecord;
			Position2->PID = personid;
			Position2->PName = pname;
			Position2->Phone = phone;
			Position2->BorrowNo = 0;                            //head at tail
			Position2->ReturnNo = 0;
			Position2->Next = NULL;
			
			if (Head == NULL)
				Head = Position2;
				
			else 
			{
				personrecord* MyCurrent1 = Head;
				
				while (MyCurrent1->Next != NULL)
				 {
					MyCurrent1 = MyCurrent1->Next;
				 }
				 
				MyCurrent1->Next = Position2;
			}
		}
		
		else 
		{
			personrecord* new_record = new personrecord;
			new_record->PID = personid;
			new_record->PName = pname;                            //insertion at middle
			new_record->Phone = phone;
			new_record->BorrowNo = 0;
			new_record->ReturnNo = 0;
			personrecord* prev = Head;
			for (int i = 0; i < index - 1; i++)
			prev = prev->Next;
			new_record->Next = prev->Next;
			prev->Next = new_record;
		}
	}
	
	else if (index > place)
	{
		personrecord* Position2 = new personrecord;
		Position2->PID = personid;
		Position2->PName = pname;
		Position2->Phone = phone;                    // if user sends grater index number to insert then will insert at end
		Position2->BorrowNo = 0;
		Position2->ReturnNo = 0;
		Position2->Next = NULL;
		
		if (Head == NULL) 
		{
			Head = Position2;
		}
		else 
		{
			personrecord* MyCurrent1 = Head;
			
			while (MyCurrent1->Next != NULL)
		    {
				MyCurrent1 = MyCurrent1->Next;
			}
			
			MyCurrent1->Next = Position2;
		}
	}
}

                                                /////////////////////////////
												// Adds Books in the list //
												////////////////////////////

void InsertArbitraryb(string bid, string Btitle, string bcategory, string bgerne, bool avaiable, int index) 
{
	BookRecord* New_node = new BookRecord;
	New_node->bID = bid;
	New_node->btitle = Btitle;
	New_node->category = bcategory;
	New_node->genre = bgerne;
	New_node->availability = avaiable;
	
	if (index <= place2) 
	{
		if (index == 0)
		{
			BookRecord* Position = new BookRecord;
			Position->bID = bid;
			Position->btitle = Btitle;
			Position->category = bcategory;                  //isertion at head.
			Position->genre = bgerne;
			Position->availability = avaiable;
			Position->Next2 = Head2;
			Head2 = Position;
		}
		
		else if (index == place2)
		{
			BookRecord* Position2 = new BookRecord;
			Position2->bID = bid;
			Position2->btitle = Btitle;
			Position2->category = bcategory;
			Position2->genre = bgerne;
			Position2->availability = avaiable;              //insertion at tail
			Position2->Next2 = NULL;
			if (Head2 == NULL)
				Head2 = Position2;
				
			else 
			{
				BookRecord* MyCurrent1 = Head2;
				
				while (MyCurrent1->Next2 != NULL) 
				{
					MyCurrent1 = MyCurrent1->Next2;
				}
				
				MyCurrent1->Next2 = Position2;
			}
		}
		
		else 
		{
			BookRecord* new_record = new BookRecord;
			new_record->bID = bid;
			new_record->btitle = Btitle;
			new_record->category = bcategory;
			new_record->genre = bgerne;
			new_record->availability = avaiable;                //insertion at position 
			BookRecord* prev = Head2;
			for (int i = 0; i < index - 1; i++)
				prev = prev->Next2;
			new_record->Next2 = prev->Next2;
			prev->Next2 = new_record;
		}
	}
	
	else if (index > place2) 
	{
		BookRecord* Position2 = new BookRecord;
		Position2->bID = bid;
		Position2->btitle = Btitle;
		Position2->category = bcategory;
		Position2->genre = bgerne;
		Position2->availability = avaiable;    // if user higher index then it will insert it at tail
		Position2->Next2 = NULL;
		if (Head2 == NULL) 
		{
			Head2 = Position2;
		}
		else 
		{
			BookRecord* MyCurrent1 = Head2;
			
			while (MyCurrent1->Next2 != NULL) 
			{
				MyCurrent1 = MyCurrent1->Next2;
			}
			MyCurrent1->Next2 = Position2;
		}
	}
}
                                                //////////////////////
												// Display all books//
												///////////////////// 


void DisplayBook(BookRecord* Head)
{
	BookRecord* MyCurrent1 = Head;
	
	if (MyCurrent1 == NULL)
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	
	while (MyCurrent1 != NULL) 
	{
		cout << " Book ID           : " << MyCurrent1->bID << endl;
		cout << " Book title        : " << MyCurrent1->btitle << endl;
		cout << " Book category     : " << MyCurrent1->category << endl;        // displaying all the books
		cout << " Book Genre        : " << MyCurrent1->genre << endl;
		cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
		cout << "|------------------------------------------------------------------|" << endl;
		MyCurrent1 = MyCurrent1->Next2;
	}
}
                                            /////////////////// 
											// Display patrons//
											///////////////////


void DisplayPatrons(personrecord* Head) 
{
	personrecord* MyCurrent1 = Head;
	if (MyCurrent1 == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	while (MyCurrent1 != NULL) 
	{
		cout << " Person ID              : " << MyCurrent1->PID << endl;
		cout << " Person Name            : " << MyCurrent1->PName << endl;
		cout << " Person Phone NO        : " << MyCurrent1->Phone << endl;
		cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;   		//display All person
		cout << " The borrowed books: \n" << endl;
		for (int i = 0; i < MyCurrent1->BorrowNo; i++)
		{
			cout << " Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
			cout << " Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
			cout << " Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
			cout << " Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
			cout << " Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
			cout << "|------------------------------------------------|" << endl;
		}
		
		MyCurrent1 = MyCurrent1->Next;
	}
}

                                      	////////////////////////////
										//	 	p return b		//							
										//return books by person //
										////////////////////////////

void PreturnedB(personrecord* Head) 
{
	personrecord* MyCurrent1 = Head;
	int check=0;
	string name;
	cout << "\nEnter Person Name or ID: "; 
	cin >> name;
	
	if (MyCurrent1 == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	
	while (MyCurrent1 != NULL) 
	{
		if (name == MyCurrent1->PName || name == MyCurrent1->PID) 
		{
			cout << " Person ID              : " << MyCurrent1->PID << endl;
			cout << " Person Name            : " << MyCurrent1->PName << endl;
			cout << " Person Phone NO        : " << MyCurrent1->Phone << endl;           //last borrowed book and last returned books displaying.
			cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;
			cout << "\n The Number of Returned books: " <<MyCurrent1->ReturnNo<< endl;
			++check;
			break;
		}
	
		else
		{
			MyCurrent1 = MyCurrent1->Next;
		}
			
		
	}
	if(check==0)
		{
		cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
		}
}

                                            //////////////////////////
											// Search person record //
											/////////////////////////       

void SearchPRecord(personrecord* Head) 
{
	personrecord* MyCurrent1 = Head;
	int check=0;
	string sname;
	cout << "\nEnter Person Name or ID: "; 
	cin >> sname;
	
	if (MyCurrent1 == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	
	while (MyCurrent1 != NULL) 
	{
		
		if (sname == MyCurrent1->PName || sname == MyCurrent1->PID) 
		{
			cout << " Person ID              : " << MyCurrent1->PID << endl;
			cout << " Person Name            : " << MyCurrent1->PName << endl;
			cout << " Person Phone NO        : " << MyCurrent1->Phone << endl;
			cout << " Number of borrowed book: " << MyCurrent1->BorrowNo << endl;
			cout << " The borrowed books: \n" << endl;
			check++;
			for (int i = 0; i < MyCurrent1->BorrowNo; i++)
			{
				cout << " Book ID                : " << MyCurrent1->BorrowingBook[i][0] << endl;
				cout << " Book title             : " << MyCurrent1->BorrowingBook[i][1] << endl;
				cout << " Book category          : " << MyCurrent1->BorrowingBook[i][2] << endl;
				cout << " Book Genre             : " << MyCurrent1->BorrowingBook[i][3] << endl;
				cout << " Borrow Date            : " << MyCurrent1->BorrowingBook[i][4] << endl;
				cout << "|------------------------------------------------|" << endl;
			}
			break;
		}
		
		else
		{
			MyCurrent1 = MyCurrent1->Next;
		}
		
	}
	if(check==0)
	{
	
		cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
}
}
                                               	////////////////////////
												// Display aval books //
												////////////////////////


void DisplayBookA(BookRecord* Head)
{
	BookRecord* MyCurrent1 = Head;
	
	if (MyCurrent1 == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	
	while (MyCurrent1 != NULL) 
	{
		if (MyCurrent1->availability == true)
		{

			cout << " Book ID           : " << MyCurrent1->bID << endl;
			cout << " Book title        : " << MyCurrent1->btitle << endl;                     //displaying only avaible books
			cout << " Book category     : " << MyCurrent1->category << endl;
			cout << " Book Genre        : " << MyCurrent1->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
		}
		
		MyCurrent1 = MyCurrent1->Next2;
	}
}
                                           	////////////////
											// SEARCH BOOK //
											///////////////


BookRecord* SearchBook( BookRecord* Head) 
{
	BookRecord* MyCurrent = Head;
	int check=0;
	string sbtitle;
	cout << "\nEnter the book title, genre, catagory to search: "; 
	cin>>sbtitle;
	if (MyCurrent == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	while (MyCurrent != NULL)
	{
		if (MyCurrent->btitle == sbtitle || MyCurrent->genre == sbtitle || MyCurrent->category == sbtitle  ) 
		{
			cout << " Book ID           : " << MyCurrent->bID << endl;
			cout << " Book title        : " << MyCurrent->btitle << endl;
			cout << " Book category     : " << MyCurrent->category << endl;                               //search books
			cout << " Book Genre        : " << MyCurrent->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent->availability << endl;
			check++;
			cout << "|-------------------------------------------------------------------------|" << endl;
			return MyCurrent;
		}

	  	MyCurrent = MyCurrent->Next2;
	}
	if(check==0)
	cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
	return NULL;
}
                                           	///////////////////
											// SEARCH BOOK id //
											///////////////////

bool Searchb(string bid, BookRecord* Head)
{
	BookRecord* MyCurrent = Head;
	
	while (MyCurrent != NULL) 
	{
		if (MyCurrent->bID == bid) 
		{
			return true;
		}                                       //called in add book function to cheak weather this new book id is already used or not.
		else 
		{
			MyCurrent = MyCurrent->Next2;
		}
	}
	return false;
}
                                          	/////////////////
											// Search p id //
											////////////////

bool SearchP(string pid, personrecord* Head)
{
	personrecord* MyCurrent = Head;
	
	while (MyCurrent != NULL) 
	{
		if (MyCurrent->PID == pid) 
		{
			return true;        //called in boroooow book to cheak weather the specific person is already  in the list or not.
		}
		else
		{
			MyCurrent = MyCurrent->Next;
		}
	}
	return false;
}
                                         	////////////////
											// UPDATE BOOK //
											////////////////


BookRecord* UpdateBook(string biD, BookRecord* Head)
{
	start:
	int check=0;
	BookRecord* MyCurrent1 = Head;
	string Booktitle, bcategory, bgenre;
	
	while (MyCurrent1 != NULL)
	 {
		if (MyCurrent1->bID == biD) 
		{
			check++;
			getchar();
			cout << "Enter Book title: ";
			getline(cin, Booktitle, '\n');
			cout << "Enter Book Category(1. Fiction  2. Non-Fiction): "; 
			cin >> option1;
			if (option1 == "1") 
			{
				bcategory = category1;
				cout << "\nBook genres: ";
				cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
				cin >> option2;
		    	if (option2 == "1") 
				{
					bgenre = genre1;
				}
				else if (option2 == "2") 
				{
					bgenre = genre2;
				}
				else if (option2 == "3") 
				{
					bgenre = genre3;
				}
				else if (option2 == "4") 
				{
					bgenre = genre4;
				}
				else if(option2 == "5")
				{
					bgenre = genre5;
				}
				else
				{
				cerr << "\n\n\a \t\t<!!!>    Wrong Choice   <!!!>" << endl;
				sleep(3);
			  	goto start;
				}
			}
			
			else if (option1 == "2")
			{
				bcategory = category2;
				cout << "Book genres: ";
				cout << "1. Narrative   2. Biography   3. Periodicals  4. Self-help  5. Reference\nEnter one option:  ";
				cin >> option2;
				if (option2 == "1") 
				{
					bgenre = genre6;
				}
				else if (option2 == "2") 
				{
					bgenre = genre7;
				}
				else if (option2 == "3") 
				{                          //updating all the data of the book and displaying the new data of the book
					bgenre = genre8;
				}
				else if (option2 == "4") 
				{
					bgenre = genre9;
				}
				else if(option2 == "5")
				{
					bgenre = genre5;
				}
				else
				{
					cerr << "\n\n\a\t\t <!!!>    Wrong Choice   <!!!>" << endl;
					sleep(3);
				    goto start;	
				}
			}
			else
				{
					cerr << "\n\n\a\t\t <!!!>    Wrong Choice   <!!!>" << endl;
					sleep(3);
			    	goto start;	
				}
			
			MyCurrent1->btitle = Booktitle;
			MyCurrent1->category = bcategory;
			MyCurrent1->genre = bgenre;
			
			cout << "The New Details" << endl;
			cout << " Book ID           : " << MyCurrent1->bID << endl;
			cout << " Book title        : " << MyCurrent1->btitle << endl;
			cout << " Book category     : " << MyCurrent1->category << endl;
			cout << " Book Genre        : " << MyCurrent1->genre << endl;
			cout << " Book availability(1=True & 0= False) : " << MyCurrent1->availability << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
			return MyCurrent1;
		}
		else
		{
			MyCurrent1 = MyCurrent1->Next2;
		}
		
	}
	if(check==0)
	cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
	return NULL;
}
                                             ///////////////////////
											// update person info //
											///////////////////////

void UpdatePInfo()
{
	int check=0;
	personrecord* MyCurrent = Head;
	cout << "Enter Person ID to update: "; 
	cin >> PIDInput;
	
	while (MyCurrent != NULL) 
	{
		if (MyCurrent->PID == PIDInput) 
		{
			cout << "\nPlease fill up The new info: \n" << endl;
			getchar();
			cout << "Enter Person Name: "; 
			getline(cin, PNameInput, '\n');
			cout << "Enter Phone No   : "; 
			getline(cin, PhoneInput, '\n');
			MyCurrent->PName = PNameInput;
			MyCurrent->Phone = PhoneInput;
			check++;
			break;
		}
		
		else 
		{	
			MyCurrent = MyCurrent->Next;
		}
	}
	if(check==0)
	cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
	return;
}

                                     	//////////////////
										//Borring book  //
										/////////////////

bool borrowBookp(string piD, personrecord* Head) 
{
	personrecord* MyCurrent2 = Head;
	
	while (MyCurrent2 != NULL) 
	{
		if (MyCurrent2->PID == pid) 
		{
			if (MyCurrent2->BorrowNo >= 3) 
		 {
			cout << "\n <!>  person has reached the maximum number of borrowing books(which is 3 books)<!>\n";
			cout << "\nNoted: person may return one of the borrowed book to be able to borrow a new book\n";
			return false;
		//	break;
	     }
			cout << "\nNote: return the book within 15 days after the borrowing date!\n";
			cout << "Enter borrowing date(Y/M/D): "; 
			cin >> borrowdate;
			for (int i = MyCurrent2->BorrowNo; i < MyCurrent2->BorrowNo + 1; i++) 
			{
				MyCurrent2->BorrowingBook[i][0] = bkid;
				MyCurrent2->BorrowingBook[i][1] = Booktitle;
				MyCurrent2->BorrowingBook[i][2] = bcateg;
				MyCurrent2->BorrowingBook[i][3] = bgenre;      //called in borrow book it chaek weather the person is eligible for borrow the book or not if yes then give him and return true or false answer to the borow book function.
				MyCurrent2->BorrowingBook[i][4] = borrowdate;
			}
			MyCurrent2->BorrowNo += 1;
			cout << "The Borrowing Details" << endl;
			cout << " Person ID         : " << MyCurrent2->PID << endl;
			cout << " Person Name       : " << MyCurrent2->PName << endl;
			cout << " Book ID           : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][0] << endl;
			cout << " Book title        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][1] << endl;
			cout << " Book category     : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][2] << endl;
			cout << " Book Genre        : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][3] << endl;
			cout << " Borrow Date       : " << MyCurrent2->BorrowingBook[MyCurrent2->BorrowNo - 1][4] << endl;
			cout << "|-------------------------------------------------------------------------|" << endl;
			return true;
		//	break;
		}
		else
			MyCurrent2 = MyCurrent2->Next;
	}
	return true;
}
                                       		////////////////
											// Borrow Book //
											////////////////


void borrowBook(string biD, BookRecord* Head2) 
{
	BookRecord* MyCurrent1 = Head2;
	
	while (MyCurrent1 != NULL)
	 {
		if (MyCurrent1->bID == biD && MyCurrent1->availability == true) 
		{
			bkid = MyCurrent1->bID;
			Booktitle = MyCurrent1->btitle;
			bcateg = MyCurrent1->category;                                      //  borrowing book
			bgenre = MyCurrent1->genre;
			cout << "Enter Person ID: ";
			 cin >> pid;
			if (SearchP(pid, Head) == false)
			{
				cout << "\nThis PID is not avaiable yet. Pls try again with new ID\n" << endl;
				break;
			}
			else 
			{
			  int a=borrowBookp(pid, Head);
			  if(a==true)
			  {
			  	MyCurrent1->availability = false;
			  }
			  else
			  {
			  	MyCurrent1->availability = true;
			  }
				//MyCurrent1->availability = false;
				break;
			}
		}
		else
			MyCurrent1 = MyCurrent1->Next2;
	}
}
                                            //////////////// 
											// return book //
											////////////////


void returnbook() 
{
	personrecord* MyCurrent1 = Head;
	int check=0;
	string personid, bid;
	cout << "\nEnter Person ID: "; 
	cin >> personid;
	cout << "\nEnter Book ID to return it: "; 
	cin >> bid;
	if (MyCurrent1 == NULL) 
	{
		cout << "NO recode yet!!, please insert new recodes first..." << endl;
	}
	
	while (MyCurrent1 != NULL) 
	{
		if (personid == MyCurrent1->PID) 
		{
			for (int i = 0; i < MyCurrent1->BorrowNo; i++) 
			{
				if (MyCurrent1->BorrowingBook[i][0] == bid) 
				{
					for (int ii = MyCurrent1->ReturnNo; ii < MyCurrent1->ReturnNo + 1; ii++)
					{
						MyCurrent1->ReturningBook[ii][0] = MyCurrent1->BorrowingBook[ii][0];
	 					MyCurrent1->ReturningBook[ii][1] = MyCurrent1->BorrowingBook[ii][1];
						MyCurrent1->ReturningBook[ii][2] = MyCurrent1->BorrowingBook[ii][2];
						MyCurrent1->ReturningBook[ii][3] = MyCurrent1->BorrowingBook[ii][3];
						MyCurrent1->ReturningBook[ii][4] = MyCurrent1->BorrowingBook[ii][4];
						check++;
						
					}
					BookRecord* reader = Head2;
					while (reader != NULL)
					 {
						if (reader->bID == bid)
						 {
							
							reader->availability = true;
							MyCurrent1->ReturnNo += 1;
							MyCurrent1->BorrowNo -= 1;
							cout << "\n <!> The book has been returned successfully  <!>\n";
							break;
						 }
						reader = reader->Next2;
					 }
					 
					int a, j, k;
					int NoColumn = 5;
					int NORows = 3;
					for (a = 0; a < NORows; a++)
					 {
						for (k = a; k < NORows - 1; k++) 
						{
							for (j = 0; j < NoColumn; j++) 
							{
								MyCurrent1->BorrowingBook[k][j] = MyCurrent1->BorrowingBook[k + 1][j];
							}
						}
						a--;
						NORows--;
					}
				}
			}
			
			break;
		}
		else
		{
			MyCurrent1 = MyCurrent1->Next;
		}
	}
	if(check==0)
	{
		cerr << "\n\n \t\t\a<!!!>    No such id found   <!!!>" << endl;
	}
}
											//////////////
											// ADD BOOK //
											/////////////

void AddBook()
{
	cout << "\n\nPlease fill up the following requirements: \n" << endl;
	cout << "Enter Book ID: "; 
	cin >> bkidinput;
	if (Searchb(bkidinput, Head2) == true)
	{
		cout << "\n This ID has been used before !!\n" << endl;
	}
	else
	{
		getchar();
		cout << "Enter Book Title: ";
		getline(cin, btitleInput, '\n');
		cout << "Enter Book Category(1. Fiction  2. Non-Fiction): "; 
		cin >> option1;
		if (option1 == "1") 
		{
			categoryInput = category1;
			cout << "Enter Book genre: ";
			cout << "1. Fantasy   2. Science   3. Historical  4. Realistic  5. Fan\nEnter one option:  ";
			cin >> option2;
			
		    if (option2 == "1") 
			{
				genreInput = genre1;
			}
	     	else if (option2 == "2")
			{
				genreInput = genre2;
			}                                                 //Adding books in rack and sending its data as a parameter to arbitray function to put it in the sepecific nodes
	    	else if (option2 == "3")
			{
				genreInput = genre3;
			}
	    	else if (option2 == "4")
			{
				genreInput = genre4;
			}
	    	else if(option2 == "5")
			{
				genreInput = genre5;
			}
		else
			{
				cerr << "\n\n \t\t\a<!!!>    Wrong Choice   <!!!>" << endl;
				sleep(3);
				AddBook();
			}
				availabilityInput = true;
				cout << "Enter the position you want to save the recode: "; 
				cin >> position;
				InsertArbitraryb(bkidinput, btitleInput, categoryInput, genreInput, availabilityInput, position);
				place2++;
		}
		
    	else if(option1 == "2") 
		{
		categoryInput = category2;
		cout << "Enter Book genre: ";
		cout << "1. Narrative   2. Biography   3. Periodicals  4. Self-help  5. Reference\nEnter one option:  ";
		cin >> option2;
	    	if (option2 == "1") 
			{
				genreInput = genre6;
			}
	    	else if (option2 == "2")
			{
				genreInput = genre7;
			}
		    else if (option2 == "3") 
			{
				genreInput = genre8;
			}
		    else if (option2 == "4") 
			{
				genreInput = genre9;
			}
		    else if(option2 == "5")
			{
				genreInput = genre5;
			}
			
			else
			{
				cerr << "\n\n \t\t\a<!!!>    Wrong Choice   <!!!>" << endl;
				sleep(3);
				AddBook();
			}
			
				availabilityInput = true;
				cout << "Enter the position you want to save the recode: "; 
				cin >> position;
				InsertArbitraryb(bkidinput, btitleInput, categoryInput, genreInput, availabilityInput, position);
				place2++;
		}
	else
		{
				cerr << "\n\n\a \t\t<!!!>    Wrong Choice   <!!!>" << endl;
				sleep(3);
				AddBook();
		}
	}
	return;
}
                                         	////////////////
											// ADD PERSON //
											///////////////

void AddPatron()
{
	cout << "\nPlease fill up the following requirements: \n" << endl;
	cout << "Enter Patron ID: "; 
	cin >> PIDInput;
	if (SearchP(PIDInput, Head) == true)
    {
		cout << "\n This ID has been used before !!\n" << endl;
	}
	else
	{                                                                                   //add person
		getchar();
		cout << "Enter Patron Name: "; 
		getline(cin, PNameInput, '\n');
		cout << "Enter Phone No: "; 
		getline(cin, PhoneInput, '\n');
		cout << "Enter the position you want to save the recode: "; 
		cin >> position;
	if(isdigit(position)==true)
	   {
		   AddPatron();
       }
	else
	   {
		InsertArbitraryp(PIDInput, PNameInput, PhoneInput, position);
		place++;	
	   }
  }
	return;
}
														///////////
														// ADMIN //
														//////////

void Admin_login()
{
		int top=-1;
		string pin;
		string stack[MAX];	
		system("color e0");
		cout << "\n       <=======>  Books Management System(BMS) <=======>\n";
		cout<<endl;
		cout << "\nEnter Password PIN To Access: ";
		cin >> pin;
		
	if(top>=(MAX-1))
	 	{
	 		cout<<"No space"<<endl;
		}
	else
		{
		 	stack[++top]="lol";
		 	stack[++top]="ooo";
		 	stack[++top]="dsa";
		 	
		if(stack[top]==pin)
		  {
		 	system("color e0");
			cout << "\n  <>  Correct PIN <> \n";
			sleep(2);
			system("cls");
		  }
		else
		  {
			system("color 4");
			cout << "\n\a  <> Wrong PIN <>\n";
			system("pause");
			system("cls");
		    Admin_login();
		  }
	   }	   
}
   
												////////////////
												// ALL MENU'S //
												////////////////  
  
void Menu_display()
{
	if(rearr>=val)
		 	{
		 		cout<<"no space queue "<<endl;
			}
		else
			 {
			 	if(frontt==-1)
			 	{
			 		frontt=0;
				}
			 	quee[++rearr]="1. Add New Book";
			 	quee[++rearr]="2. Display Books";
			 	quee[++rearr]="3. Search Book";
			 	quee[++rearr]="4. Update Book Information"; 
			 	quee[++rearr]="5. Back";
			 }
}
	 
	 
void display_Menu_1()
{
		if(frontt==-1||frontt>rearr)
		 	{
		 		cout<<"empty"<<endl;
			}
		else
			{
			 	for(int i=frontt;i<=rearr;i++)
			 	{
			 		cout<<quee[i]<<endl;
				}
			}
}
	          
	          
void Person_menu_display()
{
	 
		if(rear>=value)
	 	  {
	 		cout<<"no space queue "<<endl;
		  }
		 
		 else
		  {
		 	if(front==-1)
		 	 {
		 		front=0;
			 }
			 
		 	que[++rear]="1. Add New Person";
		 	que[++rear]="2. Show the Number of books rerturned";
			que[++rear]="3. Search Person recored";
			que[++rear]="4. Update Person Info";
			que[++rear]="5. Return book";
			que[++rear]="6. View person's record";
			que[++rear]="7. Back\n";
		 }
}
	
	
void display_Menu_2()
{
    if(front==-1||front>rear)
		{
			cout<<"empty"<<endl;
		}
	else
		{
		for(int i=front;i<=rear;i++)
			{
			   	cout<<que[i]<<endl;
			}
		}
		
}
	 											////////////////
												// File's area //
												//////////////// 
	          
void write_in_file(personrecord* Head)
{
      	 ofstream file;
      	 file.open("perdata.txt",ios::app);
      	 personrecord* MyCurrent1 =Head;
      	for(personrecord* MyCurrent1 =Head;MyCurrent1!=NULL;MyCurrent1=MyCurrent1->Next)
      	  {    		
      		file<<"Person id: "<<MyCurrent1->PID<<"\t"<<"person name: "<<MyCurrent1->PName<<"\t"<<"person phone: "<<MyCurrent1->Phone<<"\t"<<endl;
		  }

			cout<<"\n\tData is inserting";
			for(int i=0;i<6;i++)
				{
					cout<<".";
			
					sleep(1);
				}
			cout<<"\n\nData is insrted in a person file"<<endl;
			sleep(2);
			file.close();
}
	
	
void write_in_bookfile(BookRecord* Head2)
{
      	 ofstream file;
      	 file.open("Bookdata.txt",ios::app);
      	 BookRecord* MyCurrent2 =Head2;
      	 for(BookRecord* MyCurrent2 =Head2;MyCurrent2!=NULL;MyCurrent2=MyCurrent2->Next2)
      	   {
             file<<"Book id: "<<MyCurrent2->bID<<"\t"<<"Book title: "<<MyCurrent2->btitle<<"\t\t"<<"Book category: "<<MyCurrent2->category<<"\t"<<"Book Genre: "<<MyCurrent2->genre<<"\t"<<endl;
		   }
		    cout<<"\n\tData is inserting";
			for(int i=0;i<6;i++)
				{
					cout<<".";
			
					sleep(1);
				}
			cout<<"\n\nData is insrted in a book file"<<endl;
			sleep(2);
			file.close();
}
	
	
	
void Read_in_perfile(personrecord* Head)
{
		fstream file; 
		string line;                    
		personrecord* MyCurrent1 =Head;                                         
		file.open("perdata.txt",ios::in); 
		
		cout<<"\n\tOpening the  person's file"; 
		for(int i=0;i<4;i++)
				{
					cout<<".";
			
					sleep(1);
				}
		 	cout<<endl<<endl;
			cout<<"All Person data :\n\n";
			                                               
	    if (file.is_open() )
		 {	        
		while(getline(file,line))
			{
				cout<<line<<endl;
	
		    }
			
		}
		sleep(10);
			file.close();
}
	
	
void Read_in_bookfile(BookRecord* Head2)
{
		fstream file; 
		string line;                    
		BookRecord* MyCurrent2 =Head2;                                         
		file.open("Bookdata.txt",ios::in); 
		
		cout<<"\n\tOpening the book file"; 
		for(int i=0;i<4;i++)
				{
					cout<<".";
			
					sleep(1);
				}
		 	cout<<endl<<endl;
			cout<<"All book data in file : \n\n";                                             
		if (file.is_open())
		while(getline(file,line))
		  {
 		
			cout<<line<<endl;
	
		  }
		sleep(10);
		file.close();
}
	
int main()
{
	system("color e0");
	string sbtitle;
	string bookid, borrowid;			
	Admin_login();
	Menu_display();
	Person_menu_display();

	system("color e0");
	
	do
	{
		system("color e0");
		cerr << "\n\n       <=======>  Books Management System <=======>\n\n"
			<<" 1. Book Services    "<<endl
			<<" 2. Person Services  "<<endl
			<<" 3. To write person data in file  "<<endl
			<<" 4. To write book data in file "<<endl
			<<" 5. To read person record "<<endl
			<<" 6. To read book record   "<<endl
			<<" 7. Exit" << endl << endl;
			
		cout << "Enter one choice: ";
		cin >> choice22;
		
		switch (choice22)
		{
		case '1':
			do
			{
				system("color e0");
				cerr << "\n\n       <=======>  Book Service  <=======>\n";
				cout<<endl;
                display_Menu_1();
				cout << endl;
				cout << "Enter one choice: "; 
				cin >> choice;
				system("color e0");
				switch (choice)
				{
				case '1':
					
					AddBook();
					break;
					
				case '2':
					
					cout << "\n1. Display all books.  "<<endl
					<<"2. Display the avaiable books only. "<<endl
					<<"Enter one option: "; 
					cin >> choice;
					if (choice == '1') 
					{
						DisplayBook(Head2);
					}
					else if (choice=='2')
					{
						DisplayBookA(Head2);
					}
					else
					{
							cerr << "\a\n\n <!!!>    Wrong Choice   <!!!>" << endl;
							break;
					}
					cout << "\nDo you want to borrow any book: (1. Yes  2. NO): "; 
					cin >> choice;
					if (choice == '1') 
					{
						cout << "Enter Book ID: "; 
						cin >> borrowid;
						borrowBook(borrowid, Head2);
					}
					else 
					{
						cout << "\n Backing to the main menu....\n" << endl;
					}
					break;
					
				case '3':
					
					getchar();
					system("color e0");
					SearchBook(Head2);
					cout << "\nDo you want to borrow any book: (1. Yes  2. NO): "; 
					cin >> choice;
					if (choice == '1') 
					{
						cout << "Enter Book ID: "; 
						cin >> borrowid;
						borrowBook(borrowid, Head2);
					}
					else 
					{
						cout << "\n Backing to the main menu....\n" << endl;
					}
					
				break;
				case '4':
					
					cout << "\nEnter Book ID to update: ";
					 cin >> bookid;
					UpdateBook(bookid, Head2);
					
					break;
					
				case '5':
					
					cout << "\n Backing to the main menu....\n" << endl;
					break;
					
				default:
					system("color 4");
					cerr << "\n\n\a <!!!>    Wrong Choice   <!!!>" << endl;
					break;
				}
				system("pause");

				system("cls");
			} while (choice != '5');
			break;
			
		case '2':
			
			do
			{
				system("color e0");
				cerr << "\n\n       <=======>  Persons Service(data)  <=======>\n";
				cout<<endl;
	            display_Menu_2();
		
				cout << "Enter one choice: "; 
				cin >> choice;
				switch (choice)
				{
				case '1':
					
					AddPatron();
					break;
					
				case '2':
					
					PreturnedB(Head);
					break;
					
				case '3':
					
					SearchPRecord(Head);
					break;
					
				case '4':
					
					UpdatePInfo();
					break;
					
				case '5':
					
					returnbook();
					break;
					
				case '6':
					
					DisplayPatrons(Head);
					break;
					
				case '7':
					
					cout << "\n Backing to the main menu....\n" << endl;
					break;
					
				default:
					
					system("color 4");
					cerr << " <!!!>    Wrong Choice   <!!!>" << endl;
					break;
				}
				
				system("pause");
				system("cls");
			} while (choice != '7');
			break;
			
			case '3':
			
				 write_in_file( Head);
				 break;
			
			
			case '4':
				
				 write_in_bookfile(Head2);	
				 break;
				
			case '5':
			
			 Read_in_perfile(Head);	
			 break;
			
			case '6':
			
			 Read_in_bookfile(Head2);	
			 break;
			
		case '7':
			
			cout << "\n <*>  See You Soon ! :)    <*>\n" << endl;
			sleep(2);
			break;
			
		default:
			
			system("color 4");
			cerr << "\n\n\a <!!!>    Wrong Choice   <!!!>" << endl;
			sleep(2);
			break;
		

		}
	//	system("pause");
		system("cls");
	} while (choice22 != '7');
	return 0;
}
