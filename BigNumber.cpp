#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

struct BigNumber
{
    static const int base = 10 ;
    int noDigits;
    int Digits[50];
};

void _nhapBN ( BigNumber & bn ) ;
void _generateRandomBN ( BigNumber & bn ) ;
string _toStringBN ( const BigNumber & bn ) ;

BigNumber operator+ ( const BigNumber & bn1 , const BigNumber & bn2 ) ;
BigNumber operator* ( const BigNumber & bn1 , const int & digit ) ;
BigNumber operator* ( const BigNumber & bn1 , const BigNumber & bn2 ) ;

BigNumber operator- ( const BigNumber & bn1 , const BigNumber & bn2 ) ;
bool check(int i);
BigNumber _average ( BigNumber mangBN[] , const int & soPhanTu ) ;

bool operator< ( const BigNumber & bn1 , const BigNumber & bn2 ) ;
void _sortBN ( BigNumber mangBN[] , const int & soPhanTu ) ;

int main()
{
    BigNumber bn1, bn2 ;

    _nhapBN(bn1);
    _nhapBN(bn2);
    cout <<"BN1 " << _toStringBN ( bn1 ) << endl ;
    cout <<"BN2 " << _toStringBN ( bn2 ) << endl ;
    BigNumber bnTong = ( bn1 + bn2 ) ;
    BigNumber bnHieu = ( bn1 - bn2 ) ;
    BigNumber bnTich = ( bn1 * bn2 ) ;
    BigNumber bnTich2 = bn1*3;
    _generateRandomBN(bn1);
    cout<<"TONG " << _toStringBN ( bnTong ) << endl ;
    cout<<"HIEU " << _toStringBN ( bnHieu ) << endl ;
    cout<<"TICH " << _toStringBN ( bnTich ) << endl ;
    cout<<"TICH2 " << _toStringBN ( bnTich2 ) << endl ;

    cout <<"RAN " << _toStringBN ( bn1) << endl ;
    cout <<"RAN " <<bn1.noDigits << endl ;
    return 0 ;
}

void _nhapBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
    for(int i=(49);i>=0;i--){
        bn.Digits[i]=0;
    }
    bn.noDigits=0;
    while(bn.noDigits<=0){
         cout << "Nhap so chu so:" << endl ;
         cin >> bn.noDigits;
    }
        int k=0;
    for(int i=(bn.noDigits-1);i>=0;i--){
            k=k+1;
            bn.Digits[i]=10;

            while(!check(bn.Digits[i])){
                    cout << "Nhap chu so thu " << k << endl ;
                        cin >> bn.Digits[i];

                        }
    }
}
bool check(int i){
if(i>9) return false;
if(i<0) return false;
return true;


}
void _generateRandomBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
    for(int i=0;i<bn.noDigits;i++){
        bn.Digits[i]=rand();
    }
    return ;
}

string _toStringBN ( const BigNumber & bn ) {
    stringstream ss ;
    for (int i = bn.noDigits - 1 ; i >= 0; i-- ) {
        ss << bn.Digits[i];
    }
    return ss.str() ;
}

void _toiGianBN ( BigNumber & bn ) {
    /*
        ... your code here
    */
}

BigNumber operator+ ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnTong ;
    /*
        ... your code here
    */
    int n;
    if(bn1.noDigits>bn2.noDigits){
        n=bn1.noDigits;
    }
    else{
        n=bn2.noDigits;
    }
    int mod=0;
    for(int i=0;i<n;i++){
        int kq=bn1.Digits[i]+bn2.Digits[i]+mod;

        if(kq>=10){
            mod =1;
             bnTong.Digits[i]=kq-10;
        }else{
             bnTong.Digits[i]=kq;
                mod =0;
        }
    }
    if(mod>0){
        bnTong.noDigits=n+1;
        bnTong.Digits[n]=mod;
    }
    else{
        bnTong.noDigits=n;
    }
    return bnTong ;
}

BigNumber operator* ( const BigNumber & bn , const int & digit ) {
    BigNumber bnTich ;
    /*
        ... your code here
    */
    bnTich.noDigits =bn.noDigits;
    for(int i=0;i<50;i++){
        bnTich.Digits[i]=0;
    }
    int mod=0;
    for(int i=0;i<bn.noDigits;i++){
        int kq=bn.Digits[i]*digit+mod;
        if(kq>=10){
                mod =kq/10;
             bnTich.Digits[i]=kq%10;
        }else{
             bnTich.Digits[i]=kq;
                mod =0;
        };

    }
    return bnTich ;
}

BigNumber operator* ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnTich ;
    /*
        ... your code here
    */

    return bn1 ;
}


BigNumber operator- ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    BigNumber bnHieu ;
    /*
        ... your code here
    */
    int mode =0;
    for(int i=0;i<bn1.noDigits;i++){
        if(bn1.Digits[i]>=bn2.Digits[i]){

            bnHieu.Digits[i]=bn1.Digits[i]-bn2.Digits[i]+mod;
              mod =0;
        }
        else{

            bnHieu.Digits[i]=bn1.Digits[i]*10-bn2.Digits[i]+mod;
            mod =-1;
        }
    }
    return bnHieu ;
}

BigNumber _average ( BigNumber mangBN[] , const int & soPhanTu ) {
    return mangBN[0];
}

bool operator< ( const BigNumber & bn1 , const BigNumber & bn2 ) {
    /*
        ... your code here
    */
    return true ;
}

void _sortBN ( BigNumber mangBN[] , const int & soPhanTu ) {

}
