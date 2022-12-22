#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void FuncToFind (){
    
    //enter the information about people and prices
    int n,m;
    cout<<"Enter the number of people: ";
    cin>>n;
    cout<<"Enter the number of subway trips: ";
    cin>>m;


    double a,b,c;
    int k;
    cout<<"Enter the price of a single-trip ticket: ";
    cin>>a;
    cout<<"Enter the price of an unlimited ticket for one person: ";
    cin>>b;
    cout<<"Enter the price of an unlimited ticket for a group of (k) people: ";
    cin>>c;
    cout<<"Enter the number of(k) people: ";
    cin>>k;
    cout<<endl;
    
  

    //find the prices for all options
    double PriceFirst, PriceSecond, PriceThird;

    //find prices if all people can buy the unlimited tickets for groups
    if(n%k==0 && n>0 && k>0 && m>0 && a>0 && b>0 && c>0){
        
        cout<<"If people need to buy the same tickets or "
        <<"they can buy all tickets for groups:"<<endl<<endl;

        PriceFirst = a*n*m;
        cout<<"If everyone buys the single-trip ticket,"
        <<" the price will be: "<<PriceFirst<<endl;

        PriceSecond = b*n;
        cout<<"If everyone buys the unlimited ticket,"
        <<" the price will be: "<<PriceSecond<<endl;

        PriceThird=(n/k)*c;
        cout<<"If all people can form group of (k) people"<<
        " they can buy the unlimited tickets"<<
        " and price will be: "<<PriceThird<<endl;

        vector <double> prices ={PriceFirst, PriceSecond, PriceThird};
        double min=PriceFirst;
        for ( int i: prices){
            if(min>i){
                min=i; 
            }
        }
        cout<<"The cheapest price is "<<min<<endl<<endl;


    }
    //find prices if not all people can buy the unlimited tickets for groups
    if (n%k!=0 && n>0 && k>0 && m>0 && a>0 && b>0 && c>0)
    {
        //first variant: If people need to buy the same tickets
        cout<<"If people need to buy the same tickets:"<<endl;

        PriceFirst = a*n*m;
        cout<<"If everyone buys the single-trip ticket,"
        <<" the price will be: "<<PriceFirst<<endl;

        PriceSecond = b*n;
        cout<<"If everyone buys the unlimited ticket,"
        <<" the price will be: "<<PriceSecond<<endl;

        cout<<"You can't buy an unlimited ticket for groups,"
        <<" there are not enough people or there are too many!"<<endl;

        vector <double> prices ={PriceFirst, PriceSecond};
        double min=PriceFirst;
        for ( int i: prices){
            if(min>i){
                min=i; 
            }
        }
        cout<<"The cheap one is "<< min<<endl<<endl;

        //second variant:If people can buy different tickets:
        cout<<"If people can buy different tickets:"<<endl;
        //if to buy unlimited tickets for groups is the cheapest variant
        double ForOne=c/k;
        int CanBuyForGroup=floor(n/k);
        int Other=n%k;

        if(ForOne<b && ForOne<(a*m)){
            cout<<"You can buy the unlimited tickets for "
            << CanBuyForGroup<<" groups"<<endl;
        }
        if(b<a*m){
            cout<<"You can buy the unlimited tickets for "
            << Other<<" people"<<endl;
            double coolprice1= (CanBuyForGroup*c)+(Other*b);
            cout<<"Then another cheap price is "<< coolprice1<<endl;
        }
         if(a*m<b){
            cout<<"You can buy the single-trip tickets for "
            << Other<<" people"<<endl;
            double coolprice2= (CanBuyForGroup*c)+(Other*a*m);
            cout<<"Then another cheap price is "<< coolprice2<<endl;
        }

    }else{
        cout<<"Something went wrong!"<<endl;
    }
}

int main(){

    FuncToFind ();
    return 0;
}
