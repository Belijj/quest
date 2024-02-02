#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class User {
public:
    string login;
    string passwd;
    string name;
    string address;
};

class Clothes {
public:
    string color;
    string brand;
    string type;
    string size;
    int price;

    void displayClothesDetails() const {
        cout << "Type: " << type << " - Brand: " << brand << " - Color: " << color << " - Size: " << size << " - Price: $" << price << endl;
    }
};

class Cart {
public:
    int quant;
    Clothes clothes;
    int totalPrice;

    void displayCartItem() const {
        cout << "Item: " << clothes.type << " - Size: " << clothes.size << " - Quantity: " << quant << " - Price: $" << totalPrice << endl;
    }
};

class Checkout : public Cart, public User {
public:
      void displayCheckoutInfo() const {
        cout << "User Information:" << endl;
        cout << "Login: " << login << " - Name: " << name << " - Address: " << address << endl;

        cout << "\nCart Information:" << endl;
        displayCartItem();

}
};

User authenticateUser() {
    User user;
    cout << "Enter your login: ";
    cin >> user.login;

    cout << "Enter your password: ";
    cin >> user.passwd;

    // Simulated authentication (in a real application, you'd validate against a database)
    if (user.login != "example" || user.passwd != "password") {
        cout << "Invalid login credentials. Exiting program." << endl;
        exit(1);
    }

    return user;
}

void displayClothesMenu(const vector<Clothes>& clothesMenu) {
    cout << "===== Clothes Menu =====" << endl;
    for (const Clothes& item : clothesMenu) {
        item.displayClothesDetails();
    }
    cout << "=========================" << endl;
}

void addToCart(vector<Cart>& cart, const vector<Clothes>& clothesMenu, int index, int quantity) {
    Cart newCartItem;
    newCartItem.clothes = clothesMenu[index];
    newCartItem.quant = quantity;
    newCartItem.totalPrice = quantity * newCartItem.clothes.price;

    cart.push_back(newCartItem);

    cout << "Item added to the cart successfully!" << endl;
}

void displayCart(const vector<Cart>& cart) {
    cout << "===== Shopping Cart =====" << endl;
    for (const Cart& item : cart) {
        item.displayCartItem();
    }
    cout << "=========================" << endl;
}

int main() {
    // Simulated login
    User user = authenticateUser();

    vector<Clothes> clothesMenu = {
        {"Red", "Nike", "Hoodie", "M", 40},
        {"Blue", "Adidas", "T-Shirt", "L", 25},
        {"White", "Polo", "Shirts", "S", 30},
        {"Black", "Levi's", "Pants", "32", 50},
        {"Gray", "Nike", "Socks", "One Size", 8},
        {"Blue", "Calvin Klein", "Underwear", "M", 15},
        {"Black", "New Era", "Hats", "One Size", 20},
        {"Indigo", "Checkout", "Checkout", "One Size", 0}  // Added Checkout type for checkout
    };

    vector<Cart> shoppingCart;
    Checkout checkout;

    cout << "Welcome, " << user.name << "! You are now logged in." << endl;

    while (true) {
        displayClothesMenu(clothesMenu);

        cout << "Enter the index of the item you want to add to the cart (or -1 to finish shopping): ";
        int itemIndex;
        cin >> itemIndex;

        if (itemIndex == -1) {
            break;
        }

        if (itemIndex < 0 || itemIndex >= static_cast<int>(clothesMenu.size())) {
            cout << "Invalid item index. Please try again." << endl;
            continue;
        }

        cout << "Enter the quantity: ";
        int quantity;
        cin >> quantity;

        addToCart(shoppingCart, clothesMenu, itemIndex, quantity);
    }

    displayCart(shoppingCart);

    cout << "Enter your name: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, user.name);

    cout << "Enter your address: ";
    getline(cin, user.address);

    // Display checkout details
    cout << "\n===== Checkout Details =====" << endl;
    displayCart(shoppingCart);
    cout << "User Information:" << endl;
    cout << "Name: " << user.name << endl;
    cout << "Address: " << user.address << endl;
    checkoutInstance.displayCheckoutInfo();
    return 0;
}                                                                                                                                                                              