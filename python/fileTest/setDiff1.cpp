#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
 
int main()
{
       int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
       set<int> S( a, a + 9 );
      
       int b[] = { 3, 6, 8, 9 };
       set<int> S2( b, b + 4 );
      
       set<int>::iterator site;
 
       set<int> Su;
       set<int> Si;
       set<int> Sd;
       set<int> Ssd;
      
       //交集
       set_intersection( S.begin(), S.end(),
                                   S2.begin(), S2.end(),
                                   inserter( Si, Si.begin() ) );
                                  
       //并集
       set_union( S.begin(), S.end(),
                     S2.begin(), S2.end(),
                        inserter( Su, Su.begin() ) );
                       
       //差集
       set_difference( S.begin(), S.end(),
                                S2.begin(), S2.end(),
                                   inserter( Sd, Sd.begin() ) );
      
       //对称差集
       set_symmetric_difference( S.begin(), S.end(),
                                                S2.begin(), S2.end(),
                                                 inserter( Ssd, Ssd.begin() ) );
                                                
      
       site = Si.begin();
       cout<<"the intersection of S and S2 is : ";
       while( site != Si.end() )
       {
              cout<< *site <<" ";
              ++ site;
       }
       cout<<endl;
      
       site = Su.begin();
       cout<<"the union of S and S2 is : ";
       while( site != Su.end() )
       {
              cout<< *site <<" ";
              ++ site;
       }
       cout<<endl;
      
       site = Sd.begin();
       cout<<"the difference of S and S2 is : ";
       while( site != Sd.end() )
       {
              cout<< *site <<" ";
              ++ site;
       }
       cout<<endl;
      
       site = Ssd.begin();
       cout<<"the symmetric difference of S and S2 is : ";
       while( site != Ssd.end() )
       {
              cout<< *site <<" ";
              ++ site;
       }
       cout<<endl;
      
       return 0;
}