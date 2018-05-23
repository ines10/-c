#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Produit{
protected:
    int code;
    int quantite ;
    float prixUnitaire ;
public:
    vector<string> tab ;
    Produit(){}
    Produit(int code,int quantite,int prixUnitaire){
        this->code=code;
        this->quantite=quantite;
        this->prixUnitaire=prixUnitaire;
        cout<<"donner le nombre de matiere " ;
        int n = 0 ;
        cin>>n ; string ab = "" ;
        for (int i = 0; i < n ; ++i) {
            cout<<"donner la matiere numero "<<n<<endl ;
            cin>>ab ;
            tab.push_back(ab) ;
        }
    }
    int getCode() const{
        return  code;
    }

    virtual void affiche(){
        cout<<"produit"<<endl<<code<<endl<<quantite<<endl<<prixUnitaire
            <<endl ;
        cout<<"**********liste des matiere primaire********"<<endl ;

        for (auto i = tab.begin() ; i != tab.end() ; i++ ){
            cout<<(*i)<<endl  ;
        };

    }


};
class ProduitAlimetaire:public Produit{
private:
    string dateF;
    string dateE;
    float remise;
public:
    ProduitAlimetaire(){
        this->remise=0.2;
    }
    ProduitAlimetaire(string dateF,string dateE, int code,int quantite,int prixUnitaire):Produit(code,quantite,prixUnitaire){
        this->dateE=dateE;
        this->dateF=dateF;
        this->code=code;
        this->quantite=quantite;
        this->prixUnitaire=prixUnitaire;
    }
    void afficher(){
        cout<<"produit alementaire "<<endl ;
        cout<<code<<endl<<quantite<<endl<<prixUnitaire<<endl<<dateF<<dateE<<endl ;
        cout<<"*************listed des matiere **********"<<endl ;
        for (auto i = tab.begin() ; i != tab.end() ; i++ ){
            cout<<(*i)<<endl  ;
        };
    }



};
class  panier {
private:
    long numerounique ;
public:
    vector<Produit*>Panier ;
    panier(){}
    panier(long numero){
        this->numerounique = numero ;
    }

    vector<Produit*>::iterator chercherproduit(long codeBarre){
        vector<Produit*>::iterator i ;
        for (i = Panier.begin()  ; i!= Panier.end() ; i++) {
            if ((*i)->getCode() == codeBarre) {
                return i ;
            }
        }
        return Panier.end() ;
    }
    void Ajoutproduit( Produit &P) {
        if (chercherproduit(P.getCode()) == Panier.end()){
            Produit *A = new Produit(P) ;
            Panier.push_back(A) ;
            cout<<"ajout avec succes "<<endl  ;
        } else{
            auto i = chercherproduit(P.getCode()) ;
            //(*i)->setquantite(1) ;
            cout <<"il existe deja , quantite +1 "<<endl ;

        }
    }
    void AjouterproduitAlemtaire(ProduitAlimetaire &PA) {
        if (chercherproduit(PA.getCode()) == Panier.end()){
            Produit *A = new ProduitAlimetaire(PA) ;
            Panier.push_back(A) ;
            cout<<"ajout avec succes "<<endl  ;
        } else{
            auto i = chercherproduit(PA.getCode()) ;
            //(*i)->setquantite(1) ;
            cout <<"il existe deja "<<endl ;
        }
    }
    void supprimerproduit(long codebarre) {
        auto i = chercherproduit(codebarre) ;
        if (i == Panier.end()){
            cout<<"le produit n'existe pas "<<endl ;
        } else{
            delete(*i) ;
            cout<<"le delete avec succese"<<endl ;
        }
    }
    void afficher() {
        vector<Produit*>::iterator i ;
        for(i = Panier.begin() ; i != Panier.end() ; i++) {
            (*i)->affiche() ;
        }
    }
    int  max() {
        vector<Produit*>::iterator i ;
        vector<string>::iterator j ;  int compteure = 0 ;
        int max = 0  ;
        for (i = Panier.begin() ; i != Panier.end() ; i++) {
            for ( j = ((*i)->tab.begin()) ; j != ((*i)->tab.end() ); i++ ) {

                compteure++ ;
            }
            if ((*i)->getCode() > (*i+1)->getCode()) {
                //max = compteure ;
                //ii = i ;
            }

        }
        return  (*i)->getCode() ;
    }


};

int main() {
    Produit p(1212,20,12.000);
    int k=0;
    //p.affiche();
    ProduitAlimetaire pp("12/04/2018","23/09/2017",12341,22,16.000);
    //pp.affiche();
    panier P (12);
    P.Ajoutproduit(p);
    P.AjouterproduitAlemtaire(pp);
    P.afficher();
    P.supprimerproduit(1212);
    P.afficher();

    k=P.max();
    cout<<"***************"<<endl;
    cout<<k<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}