#include <iostream>
#include <initializer_list>
#include <cstdlib>

class ADTlist
{
private:
   double *data;
   int size;
   void _empty()
   {
      if (data != nullptr)
         delete [] data;
   };
public:
   ADTlist()
   {
      data = nullptr;
      size = 0;
   };
   ADTlist(std::initializer_list<double> _list);
   ~ADTlist();
   void MakeEmpty();
   void PrintList();
   bool is_empty();
   void insert(int _p, double _v);
};

void ADTlist::MakeEmpty()
{
   _empty();
   size = 0;
};

void ADTlist::PrintList()
{
   for (int i = 0;i < size ; i++)
      std::cout << data[i] << "\t";
   std::cout << "\b" << std::endl;
};

bool ADTlist::is_empty()
{
   if ( 0==size )
      return true;
   else 
      return false;
};

void ADTlist::insert(int _p, double _v)
{
   if (_p > size - 1)
   {
      std::cerr << "Out of range." << std::endl;
      std::exit(-1);
   }

   double *data_new = new double[size +1];
   int i = 0;
   for (i=0 ;i <= _p; i++)
      data_new[i] = data[i];
   data_new[i] = _v;
   for (;i < size;i++)
      data_new[i + 1] = data[i];
   _empty();
   data = data_new;
   size++;
};
ADTlist::ADTlist(std::initializer_list<double> _list)
{
   size = _list.size();
   data = new double [_list.size()];
   int i = 0;
   for (double x : _list)
      data[i++] = x;
};
ADTlist::~ADTlist()
{
   _empty();
};
int main()
{
   ADTlist A{21,312,321,43,4};
   A.PrintList();
   A.insert(1, 88);
   A.PrintList();
   std::cout << "HelloWorld!" << std::endl;
   return 0;
}
