#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
public:
                    //mutators
  ItemToPurchase(); //default constructor
  ItemToPurchase (string , string , int ,int  );
  void SetName(string );
  void SetPrice(int );
  void SetQuantity(int);
                    // accessors
  string GetName()const;
  int GetPrice()const;
  int GetQuantity() const;

  // extended class
                  // mutators
  void SetDescription();
                  // accessors
  string GetDescription() const;

  void printItemCost() const;
  void printItemDescription() const;
private:
  string _description;
  string _name;
  int _price;
  int _quantity;
};
#endif
