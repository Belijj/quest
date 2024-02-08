# CLOTHES SHOP
```mermaid
---
title: Animal example
---
classDiagram
 User <|--Shop
 clothes <|--Shop
 class User{
    string login
    string passwd
    string name
    string adress
 }
 class clothes{
    string color
    string brand
    string type
    string size
    int price
 }
 class cart{
   int quant
   string clothes
   int price
 }
cart <--clothes
checkout <-- User

class checkout{
   "inherit adress,\ncard from user, all other from cart"
}
checkout <| -- cart