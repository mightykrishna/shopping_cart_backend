#include<bits/stdc++.h>
#include "datamodel.h"
#include<vector>
using namespace std;
vector<Product> allProducts={
    Product(1,"apple",30),
    Product(2,"mango",50),
    Product(3,"guava",80),
    Product(4,"banana",72),
    Product(5,"strawberry",300),
    Product(6,"pineapple",100),
    
};

Product * chooseProduct(){
    string productList;
    cout<<"Available Products"<<endl;

    for(auto product : allProducts){
        productList.append(product.DisplayName());
    }
    cout<<productList<<endl;
    cout<<"--------------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getshortname()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found"<<endl;
    return NULL;
}
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total=cart.getTotal();
    cout<<"Pay in cash ";
    int paid;
    cin>>paid;
    if(paid>=total){
        cout<<"change "<<paid-total<<endl;
        cout<<"thank you for shopping! ";  
        return true;
    }
    else{
        cout<<"Not enough cash!";
        return false;
    }
}
int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"select an action - (a)dd item , (v)iew cart , (c)heckout"<<endl;
        cin>>action;
        if(action=='a'){
            //todo: add to cart
            // view all products +choose product + add to cart
            Product*product=chooseProduct();
            if(product!=NULL){
                cout<<"Added to the Cart "<< product->DisplayName() <<endl;
                cart.addProduct(*product);
            }
            
        }
        else if(action=='v'){
            //view the cart
            cout<<"----------------"<<endl;
            cout<<cart.viewCart();
            cout<<"-------------"<<endl;
        }
        else{
            //checkouts
            cart.viewCart();
            if(checkout(cart))break;

        }
    }
}