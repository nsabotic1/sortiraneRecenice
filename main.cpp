
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
std::string PretvoriSlova(std::string s)
{
    for(auto &x: s) {
    if(x>='A' && x<='Z') x+=32;
    }
    return s;
}

bool DaLiJeKraci( std::string s1, std::string s2){
    if(s1.length()==s2.length()){
        std::string s3=PretvoriSlova(s1);
        std::string s4=PretvoriSlova(s2);
        return s3<s4;
    }
    if(s1.length()<s2.length()) return true;
    else return false;

}
void SortirajRecenice( std::string *poc,std::string *kraj)
{
    if(poc>kraj) throw std::domain_error ("Nije moguce sortiranje");
    std::sort(poc,kraj,DaLiJeKraci);

}
int main ()
{
      try{
      int n = 0;
      std::cout<<"Unesite broj recenica: ";
      std::cin>>n;
      std::cin.ignore(10000,'\n');
      std::string *nizS=nullptr;
      nizS= new std::string [n];
      std::string *poc= nizS;
      std::string *pokazivac=nizS;
      std::string *josjedan=nizS;
      std::cout<<"Unesite recenice: ";
      for(int i = 0 ; i<n;i++){
          std::getline(std::cin,*pokazivac);
          pokazivac++;
      }
      SortirajRecenice(nizS,pokazivac);
      std::cout<<"\nRecenice nakon sortiranja: "<<std::endl;
      for(int i = 0;i<n; i++){
          std::cout<<*josjedan++<<" ";
          std::cout<<std::endl;
      }
      std::string recenica;
      std::cout<<"\nUnesite recenicu za pretragu: ";
      std::getline(std::cin, recenica);
      if(binary_search(nizS,pokazivac,recenica,DaLiJeKraci)){
      std::cout<<"Recenica se nalazi na poziciji: "<<lower_bound(nizS,pokazivac,recenica,DaLiJeKraci)-poc;
      }
      else std::cout<<"Trazena recenica se ne nalazi u nizu!";
      delete [] nizS;
      }
      catch(std::bad_alloc){
          std::cout<<"Izuzetak: Nije moguce sortiranje!";
      }
    return 0;
}
