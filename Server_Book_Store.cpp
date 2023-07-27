
#include "Header_Book_Store.h"

void BookStore::display(string book_id, string book_name, string book_author, string book_price)
{
    cout << book_id << "\t\t" << book_name << "\t\t" << book_author << "\t\t" << book_price << endl;
}

BookStore::BookStore() : books_list{}, price{}, shop_cart(0), final_price(0) {}

void BookStore::add_to_cart(int book_id)
{
    shop_cart += price[book_id];
}

int BookStore::get_total()
{
    final_price = shop_cart;
    shop_cart = 0;

    return final_price;
}

// string BookStore::get_book_name(int book_id) const
// {
//     string str1;
//     string str2;
//     int counter1;
//     int counter2;

//     for (counter1 = 0; counter1 < BOOKLISTSIZE; counter1++)
//     {
//         if (book_id == atoi(books_list[counter1].substr(0, 5).c_str()))
//         {
//             str2 = books_list[counter1].substr(10, 40);

//             for (counter2 = 0;  counter2 < str2.length(); counter2++)
//             {
//                 if ((str2[counter2] >= 'A' && str2[counter2] <= 'Z') || (str2[counter2] >= 'a' && str2[counter2] <= 'z'))
//                     str1.push_back(str2[counter2]);
//             }
//         }
//     }
//     return str1;
// }

int BookStore::is_valid(int book_id) const
{
    int counter;

    for (counter = 0; counter < BOOKLISTSIZE; counter++)
    {
        if (book_id == atoi(books_list[counter].substr(0, 5).c_str()))
            return 1;
    }
    return 0;
}

void BookStore::set_price()
{
    int cnt;

    for (cnt = 0; cnt < BOOKLISTSIZE; cnt++)
    {
        price.insert(make_pair(atoi(books_list[cnt].substr(0, 5).c_str()), atoi(books_list[cnt].substr(80, 5).c_str())));
    }
}

void BookStore::read_data(int category)
{
    int cnt = 0;
    ifstream file;

    switch (category)
    {

    case ADVENTURE:
        file.open("Database/Adventure.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();

        break;

    case BIOGRAPHY:
        file.open("Database/Biography.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();

        break;

    case FICTIONAL:
        file.open("Database/Fiction.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();
        break;

    case MYSTERY:
        file.open("Database/Mystery.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();
        break;

    case PROGRAMMING:
        file.open("Database/Programming.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();
        break;

    case RELIGIOUS:
        file.open("Database/Religious.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();
        break;

    case SCIENCE:
        file.open("Database/Science_Fiction.txt");
        if (!file)
        {
            cerr << "ERROR\n";
            exit(-1);
        }

        while (getline(file, books_list[cnt]))
            cnt++;

        file.close();
        break;

    default:
        cout << "Invalid category.\n";
    }
}

void BookStore::display_books()
{
    int cnt;

    cout << "\n\033[1mBook ID\t\t"
         << "Book Name\t\t\t\t\t\t"
         << "Author\t\t\t\t\t"
         << "Price\033[0m\n";

    for (cnt = 0; cnt < BOOKLISTSIZE; cnt++)
    {
        display(books_list[cnt].substr(0, 5), books_list[cnt].substr(10, 40), books_list[cnt].substr(50, 30), books_list[cnt].substr(80, 5));
    }
}