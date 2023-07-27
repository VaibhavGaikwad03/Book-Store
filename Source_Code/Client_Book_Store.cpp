#include <iostream>
#include "Header_Book_Store.h"
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    char c;
    int total;
    int book_id;
    int category;
    BookStore store;
    bool flag = true;

    cout << "\nHello, Welcome to Shree book store!\n";

    while (true)
    {
        cout << "\nChoose any option from the below catagory :\n";
        cout << "1. Adventure\n2. Biography\n3. Fiction\n4. Mystery\n5. Programming\n6. Religious\n7. Science Fiction\n8. Exit\n>_";
        cin >> category;

        if (category == 8)
            break;

        if (category > 8)
        {
            cout << "\nInvalid option selected !\n";
            continue;
        }

        while (true)
        {
            store.read_data(category);
            store.set_price();
            store.display_books();

            cout << "\nEnter book id to purchase a book or to go back enter '0' : ";
            cin >> book_id;

            if (book_id == 0)
                break;

            if (!store.is_valid(book_id))
            {
                cout << "\nBook ID is invalid!\n";
                continue;
            }

            store.add_to_cart(book_id);

            cout << "\nBook is added to cart...\n";
            cout << "\nDo you want any other book? (Y/N): ";
            cin >> c;

            if (c == 'Y' || c == 'y')
                continue;
            else
            {
                total = store.get_total();
                if (total != 0)
                    cout << "\nYour total bill is : " << total << endl;
            }
            break;
        }
    }

    total = store.get_total();
    if (total != 0)
        cout << "\nYour total bill is : " << total << endl;

    cout << "\nThank you for visiting our bookstore! We hope you found a great book to enjoy.\n";
    cout << "Have a wonderful day and happy reading!\n";

    return 0;
}