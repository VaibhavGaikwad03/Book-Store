#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define ADVENTURE 1
#define BIOGRAPHY 2
#define FICTIONAL 3
#define MYSTERY 4
#define PROGRAMMING 5
#define RELIGIOUS 6
#define SCIENCE 7
#define BOOKLISTSIZE 11
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ios;
using std::make_pair;
using std::map;
using std::string;

class BookStore
{
    int shop_cart;
    int final_price;
    map<int, int> price;
    string books_list[BOOKLISTSIZE];

    void display(string book_id, string book_name, string book_author, string book_price);
public:
    BookStore();
    void add_to_cart(int book_id);
    int get_total();
    // string get_book_name(int book_id); const
    int is_valid(int book_id) const;
    void set_price();
    void read_data(int category);
    void display_books();
};