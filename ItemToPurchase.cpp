#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

ItemToPurchase :: ItemToPurchase(){
  _string = "none";
  _description = "none";
  _price = 0;
  _quantity = 0;
}
ItemToPurchase ::  ItemToPurchase (string name, string description, int price ,int quantity ){
  _name = "0";
  _description = "0";
  _price = 0;
  _quantity = 0;
}

void ItemToPurchase::SetName(string name){
  _name = name;
}
void ItemToPurchase::SetPrice(int price){
  _price = price;
}
void ItemToPurchase::SetQuantity(int quantity){
  _quantity = quantity;
}
void ItemToPurchase::SetDescription(string description){
  _description = description;
}

string ItemToPurchase::GetName(){
  return _name;
}
int ItemToPurchase::GetPrice() {
  return _price;
}
int ItemToPurchase::GetQuantity() {
  return _quantity;
}
string ItemToPurchase::GetDescription(){
  return _description;
}

void ItemToPurchase :: printItemCost () const{
cout << _name <<": " << _quantity << " @ " << _price <<" = " << _quantity*_price;
}
void ItemToPurchase :: printItemDescription() const {
  cout << _name <<": " << _description;
}
