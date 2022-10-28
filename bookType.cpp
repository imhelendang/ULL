#include "bookType.h"

//Declare static member
int bookType::bookCount = 0;
int bookType::sCode = 0;
const int SHOPPINGCART = 20;

//--------------------------------------------------------------------------------------------------------------------------------------------
//														Setters
//--------------------------------------------------------------------------------------------------------------------------------------------
//This function accepts as arguments a pointer to a string and an integer that will act as a subscript into the array of BookData structures.
//It copies the string  to  the bookTitle  member of the  array element specified by the subscript. Return value: void.
void bookType::setTitle(string title)
{
	bookTitle = title;
}


//This function accepts as arguments a pointer to a string and an integer that will act as a subscript into the array of BookData structures.
//It copies the string to the ISBNmember of the array element specified by the subscript. Return value: void.
void bookType::setISBN(string isbnNum)
{
	isbn = isbnNum;
}


//This function accepts as arguments a pointer to a  string and an integer that will act as a subscript into the array of BookData structures.
//It copies the string to the author member of the array element specified by the subscript. Return value: void
void bookType::setAuthor(string bAuthor)
{
	author = bAuthor;
}


//This function accepts as arguments a pointer to a string and an integer that will act as a subscript into the array of BookData structures.
//It copies the string to the publisher member of the array element specified by the subscript. Return value: void.
void bookType::setPub(string pub)
{
	publisher = pub;
}

//This function accepts as arguments a pointer to a string and an integer that will act as a subscript into the array of BookData structures.
//It copies the string to the dateAdded member of the array element specified by the subscript. Return value: void.
void bookType::setDatedAdded(string nDate)
{
	date = nDate;
}


//This function accepts as arguments an integer (holding a quantity) and an integer that will act as a subscript into the array of BookData structures.
//It copies the quantity parameter to the qtyOnHand member of the array element specified by the subscript. Return value: void.
void bookType::setqty(int nQty)
{
	qty = nQty;
}


//This function accepts as arguments a double and an integer that will act as a subscript into the array of BookData structures.
//It copies the double to the wholesale member of the array element specified by the subscript Return value: void.
void bookType::setWholeSale(double whole)
{
	wholeSale = whole;
}


//This function accepts as arguments a double and an integer that will act as a subscript into the array of BookData structures.
//It copies the double to the retail member of the array element specified by the subscript. Return value: void
void bookType::setRetail(double reTail)
{
	retail = reTail;
}

//Function to increase the variable bookCount
//Postcondition: bookCount + 1
void bookType::incBookCount()
{
	bookCount+=1;
}

//Function to decrease the variable bookCount
//Postcondition: bookCount - 1
void bookType::decBookCount()
{
	bookCount-=1;
}

//Function to set sCode
//Postcondition: sCode = num
void bookType::setSCode(int num)
{
	sCode = num;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
//																Getters
//--------------------------------------------------------------------------------------------------------------------------------------------
//Default constructor
bookType::bookType()
{
	date = "EMPTY";
	qty = 0;
	isbn = "EMPTY";
	bookTitle = "EMPTY";
	retail = 0;
	wholeSale = 0;
}

//Copy constructor
bookType::bookType(const bookType& other)
{
	setTitle(other.getTitle());
	setISBN(other.getISBN());
	setAuthor(other.getAuthor());
	setPub(other.getPub());
	setDatedAdded(other.getDatedAdded());
	setqty(other.getqty());
	setWholeSale(other.getWholeSale());
	setRetail(other.getRetail());
	//incBookCount();
}

//Constructor with parameters
bookType::bookType(string bAuthor, string pub,string addDate, int q, string iNum, string nameBook, double price, double f)
{
	setTitle(nameBook);
	setISBN(iNum);
	setAuthor(bAuthor);
	setPub(pub);
	setDatedAdded(addDate);
	setqty(q);
	setWholeSale(f);
	setRetail(price);
	//incBookCount();
}

bookType::~bookType()
{
	cout << "A book is deleted!" << endl;
	decBookCount();
	delete this;
}

//Function to return the book title.
//Postcondition: The value of bookTitle is returned.
string bookType::getTitle() const
{
	return bookTitle;
}

//Function to return the ISBN.
//Postcondition: The value of isbn is returned.
string bookType::getISBN() const
{
	return isbn;
}

//Function to return the author's name.
//Postcondition: The value of author is returned.
string bookType::getAuthor() const
{
	return author;
}

//Function to return the publisher's name.
//Postcondition: The value of publisher is returned.
string bookType::getPub() const
{
	return publisher;
}

//Function to return the date of the book added.
//Postcondition: The value of date is returned.
string bookType::getDatedAdded() const
{
	return date;
}

//Function to return the quanity of the book.
//Postcondition: The value of qty is returned.
int bookType::getqty() const
{
	return qty;
}

//Function to return the whole sale price.
//Postcondition: The value of wholeSale is returned.
double bookType::getWholeSale() const
{
	return wholeSale;
}

//Function to return the retail price.
//Postcondition: The value of retail is returned.
double bookType::getRetail() const
{
	return retail;
}

//Funtion to return bookCount component
int bookType::getBookCount()
{
	return bookCount;
}

//Function to return sCode
int bookType::getSCode()
{
	return sCode;
}


//--------------------------------------------------------------------------------------------------------------------------------------------
//																Other Functions
//--------------------------------------------------------------------------------------------------------------------------------------------
//						 Equals method
//Fucntion to compare the quanity books
//Precondition: Fucntion is excuted according to parameters
bool bookType::equals(int cart[SHOPPINGCART], int x)
{
	bool same = false;
	if(getqty() == cart[x])
		same = true;

	return same;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
//																Friend Functions
//--------------------------------------------------------------------------------------------------------------------------------------------
//Overload the stream extraction operators
ostream& operator<<(ostream& osObject, const bookType& other)
{
//local declaration, if any
//Output the members of cObject.
//osObject << . . .
//Return the stream object.

	osObject << "* ISBN:             " << other.getISBN() << endl;
	osObject << "* Title:            " << other.getTitle() << endl;
	osObject << "* Author:           " << other.getAuthor() << endl;
	osObject << "* Publisher:        " << other.getPub() << endl;
	osObject << "* Date Added:       " << other.getDatedAdded() << endl;
	osObject << "* Quantity In Hand: " << other.getqty() << endl;
	osObject << "* Wholesale Cost:  $" << other.getWholeSale() << endl;
	osObject << "* Retail Price:    $" << other.getRetail() << endl;
	osObject << "**************************************************************************************************" << endl;
	return osObject;
}

//Overload the stream insertion operators
istream& operator>>(istream& isObject, bookType& other)
{
//local declaration, if any
//Read the data into cObject.
//isObject >> . . .
//Return the stream object.
	cout << fixed << showpoint << right << setprecision(2); //set up number format

	string title = "";
	string ISBN = "";
	string author = "";
	string id = "";
	string pub = "";
	string date = "";
	int qty = 0;
	float whole = 0;
	float retail = 0;

	cout << "Enter Title: ";
	getline(isObject, title);
	other.setTitle(title);

	cout << "Enter ISBN: ";
	getline(isObject, ISBN);
	other.setISBN(ISBN);

	cout << "Enter Author: ";
	getline(isObject, author);
	other.setAuthor(author);

	cout << "Enter Publisher: ";
	getline(isObject, pub);
	other.setPub(pub);

	cout << "Enter Date Added (mm/dd/yyyy): ";
	getline(isObject, date);
	other.setDatedAdded(date);

	cout << "Enter Quanity: ";
	isObject >> qty;
	isObject.ignore();
	other.setqty(qty);

	cout << "Enter Whole Sale Price: ";
	isObject >> whole;
	isObject.ignore();
	while (whole < 0)
		{
			cout << "You have entered invalid price. It must be positive value!\n";
			cout << "Enter Whole Sale Price: ";
			isObject >> whole;
			isObject.ignore();
		}
	other.setWholeSale(whole);

	cout << "Enter Retail Sale Price: ";
	isObject >> retail;
	isObject.ignore();
	while (retail < 0)
		{
			cout << "You have entered invalid price. It must be positive value!\n";
			cout << "Enter Retail Sale Price: ";
			isObject >> retail;
			isObject.ignore();
		}
	other.setRetail(retail);

return isObject;
}


//--------------------------------------------------------------------------------------------------------------------------------------------
//																Overloaded Operators
//--------------------------------------------------------------------------------------------------------------------------------------------
//Overload assignment
const bookType& bookType::operator=(const bookType& other)
{
	//local declaration, if any
	if (this != &other)//avoid self-assignment
	{
		setTitle(other.getTitle());
		setISBN(other.getISBN());
		setAuthor(other.getAuthor());
		setPub(other.getPub());
		setDatedAdded(other.getDatedAdded());
		setqty(other.getqty());
		setWholeSale(other.getWholeSale());
		setRetail(other.getRetail());
	}
//Return the object assigned.
return *this;
}

//Overload the less than operator.
bool bookType::operator<(const bookType& other) const
{
	bool less = false;
		switch(sCode)
			{
				case 0:
					less = getTitle() < other.getTitle();
					break;
				case 1:
					less = getISBN() < other.getISBN();
					break;
				case 2:
					less = getAuthor() < other.getAuthor();
					break;
				case 3:
					less = getPub() < other.getPub();
					break;
				case 4:
					break;
				case 5:
					less = getqty() < other.getqty();
					break;
				case 6:
					less = getWholeSale() < other.getWholeSale();
					break;
				case 7:
					less = getRetail() < other.getRetail();
					break;
			}
	return less;
}

//Overload the less than operator.
bool bookType::operator>(const bookType& other) const
{
	bool greater = false;
	switch(sCode)
		{
			case 0:
				greater = getTitle() > other.getTitle();
				break;
			case 1:
				greater = getISBN() > other.getISBN();
				break;
			case 2:
				greater = getAuthor() > other.getAuthor();
				break;
			case 3:
				greater = getPub() > other.getPub();
				break;
			case 4:
				break;
			case 5:
				greater = getqty() > other.getqty();
				break;
			case 6:
				greater = getWholeSale() > other.getWholeSale();
				break;
			case 7:
				greater = getRetail() > other.getRetail();
				break;
		}
	return greater;
}

//Overload the less than or equal to operator.
bool bookType::operator<=(const bookType& other) const
{
	bool less = false;
	switch(sCode)
		{
			case 0:
				less = getTitle() <= other.getTitle();
				break;
			case 1:
				less = getISBN() <= other.getISBN();
				break;
			case 2:
				less = getAuthor() <= other.getAuthor();
				break;
			case 3:
				less = getPub() <= other.getPub();
				break;
			case 4:
				break;
			case 5:
				less = getqty() <= other.getqty();
				break;
			case 6:
				less = getWholeSale() <= other.getWholeSale();
				break;
			case 7:
				less = getRetail() <= other.getRetail();
				break;
		}
	return less;
}

//Overload the greater than or equal to operator.
bool bookType::operator>=(const bookType& other) const
{
	bool greater = false;
	switch(sCode)
		{
			case 0:
				greater = getTitle() >= other.getTitle();
				break;
			case 1:
				greater = getISBN() >= other.getISBN();
				break;
			case 2:
				greater = getAuthor() >= other.getAuthor();
				break;
			case 3:
				greater = getPub() >= other.getPub();
				break;
			case 4:
				break;
			case 5:
				greater = getqty() >= other.getqty();
				break;
			case 6:
				greater = getWholeSale() >= other.getWholeSale();
				break;
			case 7:
				greater = getRetail() >= other.getRetail();
				break;
		}
	return greater;
}

//Overload the equality operator.
bool bookType::operator==(const bookType& other) const
{
	bool same = false;
	switch(sCode)
		{
			case 0:
				same = getTitle() == other.getTitle();
				break;
			case 1:
				same = getISBN() == other.getISBN();
				break;
			case 2:
				same = getAuthor() == other.getAuthor();
				break;
			case 3:
				same = getPub() == other.getPub();
				break;
			case 4:
				break;
			case 5:
				same = getqty() == other.getqty();
				break;
			case 6:
				same = getWholeSale() == other.getWholeSale();
				break;
			case 7:
				same = getRetail() == other.getRetail();
				break;
		}
	return same;
}