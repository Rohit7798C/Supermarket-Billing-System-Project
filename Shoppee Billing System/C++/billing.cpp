#include<iostream>
#include<fstream>
using namespace std;
class shopping{
    // Declaring the functions
    private:
        int pcode;           //product code
        float price;          
        float dis;           //discount on the product
        string pname;        //product name
    
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};
// Defining the functions
void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;
    
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t     SuperMarket Main Menu     \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t_______________________________\n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t   | 1) Administrator |\n";
    cout<<"\t\t\t\t   |                  |\n";
    cout<<"\t\t\t\t   | 2) Buyer         |\n";
    cout<<"\t\t\t\t   |                  |\n";
    cout<<"\t\t\t\t   | 3) Exit          |\n";
    cout<<"\t\t\t\t   |                  |\n";
    cout<<"\t\t\t\t   Please Select : ";
    cin>>choice;
    switch(choice){
        case 1 : 
        cout<<"\t\t\t\t   Please Login!\n";
        cout<<"\t\t\t\t   Enter Email ";
        cin>>email;
        cout<<"\t\t\t\t   Password    ";
        cin>>password;

        if(email=="abc@gmail.com" && password=="abc@123"){
            administrator();
        }
        else{
            cout<<"\t\t\t\tInvalid email/password\n";
        }

        case 2:
        {
            buyer();
        }

        case 3 : 
        {
            exit(0);       // 0 tells that program executed without any errors
        }

        default:
        {
            cout<<"Please select from the given options!!";
        }
    }
    goto m;    //goto is a jump statement , which jumps to the main menu again (as 'm' is declared above,so it goes to m)
}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t   Administrator Menu ";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______1) Add the Product______|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______2) Modify the Product___|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______3) Delete the Product___|";
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|______4) Back to main menu____|";

    cout<<"\n\t\t\t Please Enter your Choice : ";
    cin>>choice;
    switch(choice){
        case 1: 
            add();
            break;
        case 2: 
            edit();
            break;
        case 3: 
            rem();
            break;
        case 4: 
            menu();
            break;
        default:
            cout<<"Invalid Choice";
    }
    goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t\t\t   Buyer  \n";
    cout<<"\t\t\t\t\t _________\n";
    cout<<"\t\t\t\t\t                  \n";
    cout<<"\t\t\t\t\t  1)Buy Product   \n";
    cout<<"\t\t\t\t\t                  \n";
    cout<<"\t\t\t\t\t  2)Go Back       \n";

    cout<<"\t\t\t\t\t  Enter your Choice: ";
    cin>>choice;

    switch (choice)
    {
    case 1: 
        receipt();
        break;
    case 2: 
        menu();
        break;
    
    default:
        break;
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;               //Creating an object of the fstream class to use the File handling operations.
    int c;                      //product_code
    int token = 0;              //No.of tokens means no. of duplicates
    float p;                    //product_price
    float d;                    //discount
    string n;                   //product_name

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t\t\t Product Code of the Product : ";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the Product : ";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the Product : ";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on the Product : ";
    cin>>dis;

    // Now we have to open a file to store the product details, because add() func is used by the admin
    // So that we can display the cust that we have these products in our market-

    data.open("database.txt",ios::in);     //Opening the file in read only mode

    if(!data){                  //If the file doesn't exists, it will be created
        data.open("database.txt",ios::app|ios::out);   
        //It will be created to write and append new content at the end of the existing content.
        // out means:writing and app means : adding at the end of the existing content

        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n"; //to write inside the file

        data.close();
    }
    else{
        data>>c>>n>>p>>d;          //This line reads four values from the file(data) and stores them into variables c,n,p,d
        while(!data.eof()){
            if(c == pcode){
                token++;           //No. of matches found (Means there is duplicacy)
            }
            data>>c>>n>>p>>d;     //Reading the next four values (iteration)
        }
        data.close();      

        if (token==1){          //means there is duplicacy, or if the code entered by the administrator already exists,then we will again goto the main menu   
            goto m;
        }

        else{                 //means the code inserted by admin is unique, so it will be added to file
            data.open("database.txt",ios::app|ios::out);                    //Opening file
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";      //Writing 
            data.close();    //Closing file
        }         
    }
    cout<<"\n\n\t\t  Record Inserted Successfully!!";
}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record!!";
    cout<<"\n\t\t\t Product Code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doesn't exists!";        //Checking if the file to be edited exist or not
    }
    else{                                    //if the file exists
        data1.open("database1.txt",ios::app|ios::out);      //We will open the new file in writing mode.
        data>>pcode>>pname>>price>>dis;      //reading data from file named data and storing the data in the variables 
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t New Code of Product : ";
                cin>>c;
                cout<<"\n\t\t Name of the Product: ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                // Entering all the details of the product with help of data1 object into the new file
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t Record Edited!";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");   //renaming database1.txt to database.txt

        if(token==0){
            cout<<"\n\n Record not found!!";
        }
    }
}

void shopping :: rem(){
    fstream data, data1;
    int token=0;
    int pkey;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Enter Product Code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist!";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t Product Deleted successfully!!";
                token++;
            }
            else{
                // If the product is not find , then all the remaining products will be added to data1 and will be dsiplayed
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t Record Not Found!!";
        }
    }
}

void shopping :: list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n_________________________________\n";
    cout<<"| Product No. \t Name \t  Price |\n";
    cout<<"|_______________________________|\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt(){
    fstream data;
    //We declare arrays, since we have to store multiple product keys and quantities
    int arrc[100];      //array for multiple product codes
    int arrq[100];      //array for multiple product quantities
    char choice;
    int c=0;            //count variable 
    float amount=0;
    float dis=0;        //discount variable 
    float total=0;
    
    cout<<"\n\n\t\t\t RECEIPT";
    data.open("database.txt",ios::in);

    if(!data){            //If file does not exist
        cout<<"\n\n Empty Database!!";
    }
    else{                //If file exists, then we are closing it, that we opened earlier
        data.close();

        list();         //We call the list() func to show which products are available in out supermarket

        cout<<"\n_______________________________\n";
        cout<<"\n                               \n";
        cout<<"\n   Please place the Order      \n";
        cout<<"\n                               \n";
        cout<<"\n_______________________________\n";

        do{
            m:
            cout<<"\n\nEnter the Product code : ";
            cin>>arrc[c];
            cout<<"\n\nEnter the Product Quantity : ";
            cin>>arrq[c];

            for(int i=0;i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\n\n Duplicate product Code. Please try again!!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to try another product ? If yes then press y else no : ";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t__________________________RECEIPT______________________\n";
        cout<<"\n Product No. \t Product Name \t Product Quantity \t Price \t Amount \t Discount \n";
        
        for (int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(arrc[i]==pcode){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_________________________________________________________________________________________\n";
    cout<<"\n Total Amount : "<<total<<"\n";
}

int main(){
    shopping s;     //creating the object of shopping class
    s.menu();       //Since, menu() function contains all the function , we only call the menu() function
}
