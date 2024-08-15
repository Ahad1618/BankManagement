#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menu();
void user_menu();
void admin_menu();
void account_creation();
void amount_transfer();
void amount_withdrawal();
void amount_deposit();
int sub_transfer(int id);
void check_bal();
int validate_pin(int pin);//
int validate_pin2(int pin);
void display_subscription_limits(char subscription);
void subscription_details(int acc_id, int pin);
void extra(int id,int pin);
int array_check();
struct bank_account
{
  char user_name[100];
  char subscription;
  int acc_id,pin;
  int phone;
  double balance;//file handling
};
struct admin
{
  int admin_id;
  int pin;
}manager[2]={{111,121},{222,131}};
struct bank_account user[100]={{"Ahad",'A',3544,111,0333,5000},{"Ali",'A',4000,677,0233,2000},{"mustufa",'A',9873,222,7718,1000}};//stores data of 100 users
int main()
{
  int choice=0;
  int b;
  FILE *y;
  y=fopen("C:\\Users\\Ahad\\Desktop\\temp.txt","r");
  fscanf(y,"%d",&b); 
  fclose(y);
  FILE *file;
  // Open a file in binary write mode
  file = fopen("example.bin", "rb");
  fread(user, sizeof(user), 1, file);
  // Close the file
  fclose(file);
  menu();
  return 0;
}
void menu()
{
  int choice;
  printf("press 1 to access administrator panel\n");
  printf("press 2 to access user panel\n");
  printf("press 3 to exit\n");
  scanf("%d",&choice);
  if (choice==1)
  {
    admin_menu();
  }
  else if (choice==2)
  {
    user_menu();
  }
  else if (choice==3)
  {
  int b;
  FILE *o;
  o=fopen("C:\\Users\\Ahad\\Desktop\\temp.txt","r");
  fscanf(o,"%d",&b); 
  fclose(o); 
  //over writing at the exit
  FILE *file;
  // Open a file in binary write mode
  file = fopen("example.bin", "wb");
  fwrite(user, sizeof(user), 1, file);
  // Close the file
  fclose(file);
  exit(0);
  }
  else
  {
    printf("wrong button pressed!\n");
    menu();
  }
}
void admin_menu()
{
  int choice,pin,a,id,choice3=0,choice4=0;
  printf("Welcome! dear manager please enter your admin id\n");
  scanf("%d",&id);
  int user_index = -1; // To store the index of the user in the array

    // Search for the account in the user array
    for (int i = 0; i < 2; i++) {
        if (id == manager[i].admin_id) {
            user_index = i;
            break;
        }
    }
    if (user_index == -1) 
    {
      printf("Account not found.\n");
      do{
      printf("press 1 to enter account again\npress 2 to go back to user menu\n");
      scanf("%d",&choice);
      if (choice==1)
      {
        admin_menu();
      }
      else if (choice==2)
      {
        user_menu();
      }
      }while(choice!=1 && choice!=2);
    }
    else
    {  
    printf("Account found\n");
    do{
    printf("please enter your pin\n");
    scanf("%d",&pin);
    if (validate_pin2(pin)==1)
    {
    do{    
    printf("press 1 to show current users info table\n");
    printf("press 2 to go back\n");
    scanf("%d",&choice);
    if (choice==1)
    {
      int b;
      FILE *o;
      o=fopen("C:\\Users\\Ahad\\Desktop\\temp.txt","r");
      fscanf(o,"%d",&b); 
      fclose(o); 
      //again over writing 
      FILE *file;
      // Open a file in binary write mode
      file = fopen("example.bin", "wb");
      fwrite(user, sizeof(user), 1, file);
      // Close the file
      fclose(file);
  
      FILE *f;
      // Open a file in binary write mode
      f = fopen("example.bin", "rb");
      fread(user, sizeof(user), 1, f);
      // Close the file
      fclose(f);
      for (int i = 0; i < b; i++)
      {
          printf("user name:%s subscription:%c id:%d pin:%d phone:%d balance:%f\n",user[i].user_name,user[i].subscription,user[i].acc_id,user[i].pin,user[i].phone,user[i].balance);
      }
      do{
      printf("press 1 to go back to main menu\n");
      scanf("%d",&choice4);
      if (choice4==1)
      {
        menu();
      }
      else
      {
        printf("wrong button pressed\n");
      }
      }while(choice4!=1);
    }
    else if (choice==2)
    {
      menu();
    }
    else
    {
      printf("wrong button entered\n");
    }
    }while(choice!=2 && choice!=1);
   }
   else
   {
    printf("invalid pin\n");
    do{
    printf("press 1 to re enter pin\n");
    scanf("%d",&choice3);
    }while(choice3!=1);
  }
  }while(choice3==1);
  }
  }  
void user_menu()
{
  int choice,id,pin;
  printf("press 1 for account creation\n");//file handling
  printf("press 2 for amount transfer\n");
  printf("press 3 for amount withdrawal\n");
  printf("press 4 to amount deposit\n");
  printf("press 5 to check balance\n");
  printf("press 6 to check subscription details\n");
  printf("press 7 to go back\n");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:
    account_creation();
    break;
  case 2:
    amount_transfer();
    break;
  case 3:
    amount_withdrawal();
    break;
  case 4:
    amount_deposit();
    break;  
  case 5:
    check_bal();
    break;
  case 6:
    printf("please enter account id\n");
    scanf("%d",&id);
    printf("please enter pin\n");
    scanf("%d",&pin);
    subscription_details(id,pin);
    break;
  case 7:
    menu();
    break;
  default:
     printf("wrong button pressed plaase try again\n");
     user_menu();
    break;
  }
  }
  void account_creation()
  {
    char choice;
    int id,b;
    
    //reading from the file the value of index which was updated last time the program was executed
    FILE *p;
    p=fopen("C:\\Users\\Ahad\\Desktop\\temp.txt","r");
    fscanf(p,"%d",&b);
    fclose(p);
    do{
    printf("\t\t\twelcome to user registration system\npress y to continue\npress n to go back\n");
    scanf(" %c",&choice);
    if (choice=='y'||choice=='Y')
    {
      int a=0;
      do{
      printf("please enter a 4 digit id(1000-9999)\n");
      scanf("%d",&id);
      if (id>=1000 && id <=9999)
      {
        user[b].acc_id=id;
      }
      else
      {
         printf("invalid id\npress 1 to re enter id\n");
         scanf("%d",&a);
      }
      }while(a==1);

    }
    else if (choice=='n'||choice=='N')
    {
      user_menu();
    }
    else
    {
      printf("wrong button! press again\n");
    }
    }while(choice!='y' && choice!='Y' && choice!='n' && choice!='N');

    int num;
    printf("Enter the number of letters in your name\n");
    scanf("%d",&num);
    printf("enter name:");
    for (int j = 0; j < num; j++)
    {
      scanf(" %c",&user[b].user_name[j]);
    }
    printf("enter the subscription type\n");
    scanf(" %c",&user[b].subscription);
    
    printf("enter the pin(3 digit or 4 digit)\n");
    scanf("%d",&user[b].pin);

    printf("enter your phone number\n");
    scanf("%d",&user[b].phone);
    user[b].balance=0;
    b++;
    //writing the updated index in file to save it for the next time
    FILE *t;
    t=fopen("C:\\Users\\Ahad\\Desktop\\temp.txt","w");
    fprintf(t,"%d",b);
    fclose(t);

    /*FILE *fptr;
    fptr=fopen("C:\\Users\\Ahad\\Desktop\\command.txt","a");
    fprintf(fptr,"id:%d,user_name:%s,pin:%d,subscription:%c,phone_number:%d,balance:%lf\n",user[b].acc_id,user[b].user_name,user[b].pin,user[b].subscription,user[b].phone,user[b].balance);
    fclose(fptr);*/
    int opt;
    do{
    printf("account created successfully\npress 1 to go back\n");
    scanf("%d",&opt);
    if (opt==1)
    {
      user_menu();
    }
    else
    {
      printf("wrong button pressed! press again\n");
    }
    }while(opt!=1);
  }
    void amount_transfer()
  {
    char a;
    int id,t_id,amount=0,choice2=0,index,pin,choice4;
    char choice3;
    printf("enter your account id\n");
    scanf("%d",&id);
    int flag=0;
for (int i = 0; i < 100; i++)
{
  if (id==user[i].acc_id)
  {
    printf("Acc found! dear user Sir\\Mam,");
    do{
    printf("please enter your pin\n");
    scanf("%d",&pin);
    if (validate_pin(pin)==1)
    {
      do{
      printf("please enter the account id in which you want to transfer funds\n");
      scanf("%d",&t_id);
      index=sub_transfer(t_id);
      if (index!=-1)
      {
        printf("enter the amount you want to transfer\n");
        scanf("%d",&amount);
        if(user[i].balance>=amount)
        {
        user[index].balance=user[index].balance+amount;
        user[i].balance=user[i].balance-amount;
        printf("amount transfered successsfully!\n");
        printf("updated balance:\n");
        printf("sender balance:%.2lf\nreceiver blance:%.2lf\n",user[i].balance,user[index].balance);

        printf("press y if you want to transfer again\npress n if you are done\n");
        scanf(" %c",&choice3);
        }
        else
        {
          do{
          printf("amount is insufficient!\npress 1 to recharge your account\npress 2 to return to user menu\n");
          scanf("%d",&choice4);
           if (choice4==1)
           {
           amount_deposit();
           }
           else if(choice4==2)
           {
           user_menu();
           }
           else
           {
            printf("wrong button pressed\npress again\n");
           }
           }while(choice4!=1 && choice4!=2);
        }
      }
      else if (index==-1)
      {
        do{
        printf("Account id not found\n press y to enter account id again\n");
        scanf(" %c",&choice3);
        }while(choice3!='y');
      }
      }while(choice3=='y'||choice3=='Y');
    }//the if condition will end with choice2=0 therefore the lower while loop is ineffective
    else
    {
      do{
      printf("invalid pin entered\npress 1 to enter pin again\n");
      scanf("%d",&choice2);
      }while(choice2!=1);
    }
    }while(choice2==1);//this loop will only run if choice2 is 1
    break;
  }
  else
  {
    flag++;
  }
}
if (flag>=100)
{
  printf("invalid account id entered\npress y to enter account id again\npress n to go back to user menu\n");
  scanf(" %c",&a);
}
else
{
printf("Press y to go back to user menu\nPress n to transfer amount again\nPress s to update subscription\n");
scanf(" %c",&a);
}
if (a=='y' || a=='Y')
{
  user_menu();
}
else if (a=='n' || a=='N')
{
  amount_transfer();
}
else if (a == 's' || a == 'S')
{

  subscription_details(id, pin);
}
}
int sub_transfer(int id)
{
  int flag=0;
  for (int i = 0; i < 100; i++)
  {
    if (id==user[i].acc_id)
    {
      return i;
      break;
    }
    else
    {
      flag++;
    }
  }
  if (flag>=100)
  {
    return -1;
  }
}

int validate_pin(int pin)
{
  int flag=0;
  for (int i = 0; i < 100; i++)
  {
    if (pin==user[i].pin)
    {
      return 1;
      break;
    }
    else
    {
      flag++;
    }
  }
  if (flag>=100)
  {
    return 0;
  }
}
int validate_pin2(int pin)
{
  int flag=0;
  for (int i = 0; i < 2; i++)
  {
    if (pin==manager[i].pin)
    {
      return 1;
      break;
    }
    else
    {
      flag++;
    }
  }
  if (flag>=2)
  {
    return 0;
  } 
}
void amount_deposit()
{
    int account_id,choice,choice2=0,choice3=0,pin;
    double deposit_amount;

    printf("Enter your account ID: ");
    scanf("%d", &account_id);

    int user_index = -1; // To store the index of the user in the array

    // Search for the account in the user array
    for (int i = 0; i < 100; i++) {
        if (account_id == user[i].acc_id) {
            user_index = i;
            break;
        }
    }

    if (user_index == -1) 
    {
      do{
      printf("Account not found.\npress 1 to enter account again\npress 2 to go back to user menu\n");
      scanf("%d",&choice);
      if (choice==1)
      {
        amount_deposit();
      }
      else if (choice==2)
      {
        user_menu();
      }
      else
      {
        printf("please press one of the provided button\n");
      }
      }while(choice!=1 && choice!=2);
    }
    else
    {
    printf("Account found\n");
    do{  
    printf("please enter the pin\n");
    scanf("%d",&pin);
    if(validate_pin(pin)==1)
    {
    do{
    printf("Enter the amount to deposit: ");
    scanf("%lf", &deposit_amount);

    if (deposit_amount <= 0) 
    {
        do{    
        printf("Invalid amount.\npress 1 to enter amount again\n");
        scanf("%d",&choice2);
        }while(choice2!=1);
    }
    }while(choice2==1);
    // Update the user's balance
    user[user_index].balance += deposit_amount;

    printf("Deposit successful. Your new balance is: %.2lf\n", user[user_index].balance);
    printf("press 1 to deposit more amount\npress 2 to go back to user menu\n");
    do{
    scanf("%d",&choice2);
    if (choice2==1)
    {
      amount_deposit();
    }
    else if(choice2==2)
    {
      user_menu();
    }
    else
    {
      printf("wrong button!\npress again\n");
    }
    }while(choice2!=1 && choice2!=2);
    }
    else if(validate_pin(pin)==0)
    {
      do{
      printf("invalid pin\npress 1 to re enter pin\n");
      scanf("%d",&choice3);
      }while(choice3!=1);
    }
    }while(choice3==1);   
}
}
void amount_withdrawal()
{
    int account_id,choice,choice2=0,pin,choice3=0;
    double withdrawal_amount;

    printf("Enter your account ID: ");
    scanf("%d", &account_id);

    int user_index = -1; // To store the index of the user in the array

    // Search for the account in the user array
    for (int i = 0; i < 100; i++)
    {
        if (account_id == user[i].acc_id)
        {
            user_index = i;
            break;
        }
    }
    if (user_index == -1)
    {
        printf("Account not found.\n");
        do{
        printf("press 1 to enter account id again and press 2 to go back\n");
        scanf("%d",&choice);
        if (choice==1)
        {
          amount_withdrawal();
        }
        else if (choice==2)
        {
          user_menu();
        }
        }while(choice!=1 && choice!=2);
    }
    else
    {
      printf("account found\n");
      do{
      printf("Enter your pin\n");
      scanf("%d",&pin);
      if(validate_pin(pin)==1)
      { 
        do{
        printf("Enter the amount to withdraw: ");
        scanf("%lf", &withdrawal_amount);
   
        if (withdrawal_amount <= 0)
        {
            printf("Invalid amount.\n");
            do{
            printf("press 1 to enter amount again\n");
            scanf("%d",&choice2);
            }while(choice2!=1);
        }
        } while (choice2==1);
        if (user[user_index].balance >= withdrawal_amount)
        {
            user[user_index].balance -= withdrawal_amount;
            printf("Withdrawal successful. Your new balance is: %.2lf\n", user[user_index].balance);
            do{
            printf("press 1 to withdraw more amount\npress 2 to go back to user menu\npress 3 to update subscription\n");
            scanf("%d",&choice2);
            if (choice2==1)
            {
              amount_withdrawal();
            }
            else if(choice2==2)
            {
              user_menu();
            }
            else if (choice2==3)
            {
              subscription_details(account_id,pin);
            }
            else
            {
              printf("wrong button pressed\n");
            }
            }while(choice2!=1 && choice2!=2 && choice2!=3);
         }
        else
        {
         printf("Insufficient funds\n");
         do{ 
         printf("npress 1 to deposit funds press 2 to go back to user menu\npress 3 to update subscription");
         scanf("%d",&choice2);
         if (choice2==1)
         {
           amount_deposit();
         }
         else if(choice2==2)
         {
           user_menu();
         }
         else if(choice2==3)
         {
           subscription_details(account_id,pin);
         }
         else
         {
          printf("wrong button! please press again\n");
         }
         }while(choice2!=1 && choice2!=2 && choice2!=3);
        }
    }
    else if (validate_pin(pin)==0)
    {
      printf("Invalid pin entered\n");
      do{
      printf("press 1 to re enter pin\n");
      scanf("%d",&choice3);
      }while(choice3!=1);
    }
    }while(choice3==1);
  }
}  
void check_bal()
{
    int account_id,choice;
    printf("Enter your account ID: ");
    scanf("%d", &account_id);

    int user_index = -1;

    // Search for the account in the user array
    for (int i = 0; i < 100; i++)
    {
        if (account_id == user[i].acc_id)
        {
            user_index = i;
            break;
        }
    }
    if (user_index == -1)
    {
        printf("Account not found\n");
        do{
        printf("press 1 to enter id again\npress 2 to go back\n");
        scanf("%d",&choice);
        if (choice==1)
        {
          check_bal();
        }
        else if(choice==2)
        {
          user_menu();
        }
        else
        {
          printf("wrong button pressed\n press again\n");
        }
        }while(choice!=1 && choice!=2);
    }
    else
    {
      printf("Account balance for id %d: %.2lf\n", user[user_index].acc_id, user[user_index].balance);
      do{
      printf("press 1 to check balance again\npress 2 to go back\n");
      scanf("%d",&choice);
      if (choice==1)
      {
        check_bal();
      }
      else if (choice==2)
      {
        user_menu();
      }
      else
      {
        printf("wrong button\npress again\n");
      }
      }while(choice!=1 && choice!=2);
    }
}
void subscription_details(int acc_id, int pin)
{
    int choice,choice1;
    int user_index = -1;

    for (int i = 0; i < 100; i++)
    {
        if (acc_id == user[i].acc_id && pin == user[i].pin)
        {
            user_index = i;
            break;
        }
    }

     if (user_index == -1)
    {
        do{
        printf("Invalid account credentials.\npress 1 to enter id again\npress 2 to go back\n");
        scanf("%d",&choice);
          if (choice==1)
          {

            extra(acc_id,pin);
          }
          else if(choice==2)
          {
            user_menu();
          }
          else
          {
            printf("wrong button pressed\n");
          }
          }while(choice!=1 && choice!=2);
    }

    char subscription_type;

    while(1)
    {
    printf("select subscription type you want to upgrade to (B,C) or (A)which you have by default: ");
    scanf(" %c", &subscription_type);
    // Validate subscription type
    if (subscription_type != 'B' && subscription_type != 'C' && subscription_type != 'A')
    {
        printf("Invalid subscription type.\n please again");
    }
    else
    {
    break;
    }
    }
    user[user_index].subscription = subscription_type;
    printf("Subscription details updated successfully.\n");
    display_subscription_limits(subscription_type);
    do{
    printf("press 1 to go back\n");
    scanf("%d",&choice1);
    if (choice1==1)
    {
      user_menu();
    }
    }while(choice1!=1);
}
void display_subscription_limits(char subscription)
{
    switch (subscription)
    {
    case 'A':
        printf("Default Subscription Type A - Transaction Limit: 3, Account Limit: Rs.25000\n");
        break;
    case 'B':
        printf("Subscription Type B - Transaction Limit: 5, Account Limit: Rs.50000\n");
        break;
    case 'C':
        printf("Subscription Type C - Transaction Limit: 10, Account Limit: Rs.100000\n");
        break;
    default:
        break;
    }
}
void extra(int id,int pin)
{
  printf("please enter the account id again\n");
  scanf("%d",&id);
  printf("please enter the pin\n");
  scanf("%d",&pin);
  subscription_details(id,pin);
}