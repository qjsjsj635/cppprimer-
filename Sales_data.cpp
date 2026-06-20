// #if 0
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;

class Sales_data
{
    friend std::istream& read(std::istream& cin, Sales_data& book);
    friend std::ostream& print(std::ostream& cout, Sales_data& book);

private:
    string bookNo;//string类默认初始化 值初始化为空串
    unsigned price=0;//Sales_data类默认初始化 值未定义
    unsigned units_sold = 0;//默认构造函数初始化为0，这里只是声明
    double revenue = 0.0;//同上

public:
    Sales_data(string isbn, unsigned singleprice, unsigned number)
        : bookNo(isbn), units_sold(number), price(singleprice),revenue(singleprice*number) {}   
    Sales_data(const string isbn1):Sales_data(isbn1,0,0){} 
    Sales_data() :Sales_data("", 0, 0) {};

    string& isbn() { return bookNo; }
    unsigned& singleprice() { return price; }
    unsigned& number() { return units_sold; }

    Sales_data& combine(Sales_data& book)
    {
        units_sold += book.units_sold;
        revenue += book.revenue;
        return *this;
    }
private:
   inline  double av_price()
    {
        return revenue / units_sold;
    }
};

std::istream& read(std::istream& cin, Sales_data& book)
{
    cin >> book.bookNo >> book.units_sold >> book.price;
    book.revenue = book.price * book.units_sold;
    return cin;
}

std::ostream& print(std::ostream& cout, Sales_data& book)
{
    cout << book.bookNo << book.units_sold << book.av_price() << book.revenue;
    return cout;
}

Sales_data& add(Sales_data& p1, Sales_data& p2)
{
    static Sales_data sum = p1.combine(p2);
    return sum;
}

int main()
{

    Sales_data total;                     // 保存当前求和结果的变量
    if (read(cin, total)) {               // 读入第一笔交易
        Sales_data trans;                 // 保存下一条交易数据的变量
        while (read(cin, trans)) {        // 读入剩余的交易
            if (total.isbn() == trans.isbn()) // 检查 isbn
                total.combine(trans);     // 更新变量 total 当前的值
            else {
                print(cout, total) << std::endl; // 输出结果
                total = trans;             // 处理下一本书
            }
        }
        print(cout, total) << std::endl;       // 输出最后一条交易
    }
    else {                              // 没有输入任何信息
        std::cerr << "No data?!" << std::endl; // 通知用户
    }
    return 0;
}
// #endif
#if 0
//two
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;

class Sales_data
{
public:
    string bookNo;//string类默认初始化 值初始化为空串
    unsigned price;//Sales_data类默认初始化 值未定义
    unsigned units_sold = 0;//默认构造函数初始化为0，这里只是声明
    double revenue = 0.0;//同上

public:
    #if 0
    Sales_data(string isbn, unsigned singleprice, unsigned number): bookNo(isbn), units_sold(number), price(singleprice),revenue(singleprice*number) {}   
   Sales_data(const string isbn):bookNo(isbn){} 
   Sales_data()=default;//这里为units_sold,revenue,price执行默认初始化，前两者被初始化为0 对price什么也不做
    #endif
    Sales_data(std::istream& cin);
   
    string& isbn() { return bookNo; }
    unsigned& singleprice() { return price; }
    unsigned& number() { return units_sold; }

    Sales_data& combine(Sales_data& book)
    {
        units_sold += book.units_sold;
        revenue += book.revenue;
        return *this;
    }

    inline double av_price()
    {
        return revenue / units_sold;
    }

};

std::istream& read(std::istream& cin, Sales_data& book)
{
    cin >> book.bookNo >> book.units_sold >> book.price;
    book.revenue = book.price * book.units_sold;
    return cin;
}

std::ostream& print(std::ostream& cout, Sales_data& book)
{
    cout << book.bookNo << book.units_sold << book.av_price() << book.revenue;
    return cout;
}
Sales_data::Sales_data(std::istream& cin)
{
    read(cin, *this);
}
Sales_data& add(Sales_data& p1, Sales_data& p2)
{
    static Sales_data sum = p1.combine(p2);
    return sum;
}

int main()
{
    Sales_data total(cin);
    if (!total.isbn().empty())
    {              
        while (true)
        {
            Sales_data trans(cin);  // 读入剩余的交易
            if (!cin) break;
            if (total.isbn() == trans.isbn()) // 检查 isbn
                total.combine(trans);     // 更新变量 total 当前的值
            else {
                print(cout, total) << std::endl; // 输出结果
                total = trans;             // 处理下一本书
            }
        }
        print(cout, total) << std::endl;       // 输出最后一条交易
    }
    else
    {                              
        std::cerr << "No data?!" << std::endl; // 通知用户
    }
    return 0;
}
#endif