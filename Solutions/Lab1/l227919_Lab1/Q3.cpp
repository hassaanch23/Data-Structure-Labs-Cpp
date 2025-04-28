#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    int item_id;
    string title;
    string author;
    string publication_year;
    bool is_available;

public:
    LibraryItem()
    {
        item_id = 0;
        title = "";
        author = "";
        publication_year = "";
        is_available = true;
    }

    LibraryItem(int item_id, const string& title, const string& author, const string& publication_year)
        : item_id(item_id), title(title), author(author), publication_year(publication_year), is_available(true)
    {
    }

    virtual void display()
    {
        cout << "ITEM ID: " << item_id << endl;
        cout << "TITLE: " << title << endl;
        cout << "AUTHOR: " << author << endl;
        cout << "PUBLICATION YEAR: " << publication_year << endl;
        cout << "AVAILABILITY: " << (is_available ? "Available" : "Not Available") << endl;
    }
};

class Book : public LibraryItem
{
private:
    int ISBN;
    string genre;

public:
    Book(int item_id, const string& title, const string& author, const string& publication_year, int ISBN, const string& genre)
        : LibraryItem(item_id, title, author, publication_year), ISBN(ISBN), genre(genre)
    {
    }

    void display() override
    {
        LibraryItem::display();
        cout << "ISBN: " << ISBN << endl;
        cout << "GENRE: " << genre << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issue_number;
    string topic;

public:
    Magazine(int item_id, const string& title, const string& author, const string& publication_year, int issue_number, const string& topic)
        : LibraryItem(item_id, title, author, publication_year), issue_number(issue_number), topic(topic)
    {
    }

    void display() override
    {
        LibraryItem::display();
        cout << "ISSUE NUMBER: " << issue_number << endl;
        cout << "TOPIC: " << topic << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    string director;

public:
    DVD(int item_id, const string& title, const string& author, const string& publication_year, int duration, const string& director)
        : LibraryItem(item_id, title, author, publication_year), duration(duration), director(director)
    {
    }

    void display() override
    {
        LibraryItem::display();
        cout << "DURATION: " << duration << " minutes" << endl;
        cout << "DIRECTOR: " << director << endl;
    }
};

class LIBRARY
{
private:
    int num;
    int max;
    LibraryItem** library;

public:
    LIBRARY()
    {
        num = 0;
        max = 10;
        library = new LibraryItem * [max];
    }

    void additems(LibraryItem* item)
    {
        if (num < max)
        {
            library[num] = item;
            num++;
        }
    }

    void displaydetails()
    {
        cout << "ALL THE ITEMS IN LIBRARY ARE:" << endl;
        for (int i = 0; i < num; i++)
        {
            library[i]->display();
            cout << endl;
        }
    }
};

int main()
{
    LIBRARY librarySystem;

    Book book1(1, "Witcher", "Henry", "2023", 123456, "Action");
    Magazine magazine1(2, "Gravity", "Newton", "1966", 5, "Science");
    DVD dvd1(3, "Arijit Singh Songs", "T Series", "2020", 120, "DIRECTOR");

    librarySystem.additems(&book1);
    librarySystem.additems(&magazine1);
    librarySystem.additems(&dvd1);

    librarySystem.displaydetails();

    return 0;
}
