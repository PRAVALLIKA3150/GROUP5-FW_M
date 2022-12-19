/*********************************************************************************************
 *   *FILENAME		:main.c
 *
 *   *DESCRIPTION	      :This file defines the functions that consists of various subfunctions to perform operations.


**********************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>

#include "../Header/fwm_header.h"

/*********************************************************************************************
 *   *FUNCTION NAME	:main
 *
 *   *DESCRIPTION	:This function call the other functions to perform various operations 
 			 by taking choice option from the user.
 *   *RETURNS	:NGO_Registration 	- Adds the NGO details
 			 NGO_Edit 		      - Edits the NGO details
			 NGO_View 		      - Shows the NGO records
			 Hotel_Registration 	- Adds the hotel details
			 Hotel_Edit 		- Edits the hotel details
			 Hotel-View 		- Shows the Hotel records
			 Admin_NGO_Add 		- Adds the NGO details by admin
			 Admin_NGO_Edit 	      - Edits the NGO details by admin
			 Admin_NGO_Delete 	- Deletes the NGO details by admin
			 Admin_NGO_View 	      - Shows the NGO records
			 Admin_Hotel_Add  	- Adds the Hotel details by admin
			 Admin_Hotel_Edit 	- Edits the Hotel details by admin
			 Admin_Hotel_Delete 	- Deletes the Hotel records
			 Admin_Hotel_View 	- Shows the Hotel records 
			
 			 exit 			- exit the main function

***********************************************************************************************/


int main()
{
	NGO_to_list();	//NGO File handling function
	Hotel_to_list();	//Hotel File handling fuction
	int NGO_choice=0;
	int Hotel_choice=0;
	int Admin_choice=0;
	int Food_request=0;
	int choice=0;
	while(choice!=5)
	{	//Main menu options
		printf("\n..............MENU..............\n");
		printf("\n 1.NGO ");
		printf("\n 2.Hotel ");
		printf("\n 3.Admin ");
		printf("\n 4.Food request ");
		printf("\n 5.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:NGO_choice=0;
				while(NGO_choice!=4)
				{	//NGO  menu options
					printf("\n..............NGO DATA..............\n");
					printf("\n 1.Registration");
					printf("\n 2.Edit Details");
					printf("\n 3.View Details");
					printf("\n 4.Go Back\n");
					printf("\nEnter your NGO Choice: ");
					scanf("%d",&NGO_choice);
					switch(NGO_choice)
					{
						case 1:NGO_Registration();
						       break;
						case 2:NGO_Edit();
						       break;
						case 3:NGO_View();
						       break;
						case 4:break;
						default:printf("\n Enter the correct NGO Choice: \n");
					}
				}
				break;
			case 2:Hotel_choice=0;
				while(Hotel_choice!=4)
				{	//Hotel menu options
					printf("\n..............HOTEL DATA.............\n");
					printf("\n 1.Registration");
					printf("\n 2.Edit Details");
					printf("\n 3.View Details");
					printf("\n 4.Go Back\n");
					printf("\nEnter your choice: ");
					scanf("%d",&Hotel_choice);
					switch(Hotel_choice)
					{
						case 1:Hotel_Registration();
						       break;
						case 2:Hotel_Edit();
						       break;
						case 3:Hotel_View();
						       break;
						case 4:break;
						default:printf("\nEnter the correct Hotel choice: ");
					}
				}
				break;
			case 3:Admin_choice=0;
				while(Admin_choice!=4)

				{	//Admin menu options
					int NGO_Record=0;
					int Hotel_Record=0;
					printf("\n..............ADMIN MENU..............\n");
					printf("\n 1.NGO Record");
					printf("\n 2.Hotel Record");
					printf("\n 3.Admin Report");
					printf("\n 4.Go back\n");
					printf("\nEnter your choice: ");
					scanf("%d",&Admin_choice);
					switch(Admin_choice)
					{
						case 1:NGO_Record_Maintenance();
						       while(NGO_Record!=5)
						       {
							       //Admin NGO menu options
							       printf("\n..............NGO Record Menu..............\n");
							       printf("\n 1.Add NGO Record");
							       printf("\n 2.Edit NGO Record");
							       printf("\n 3.Delete NGO Record");
							       printf("\n 4.View NGO Record");
							       printf("\n 5.Go Back\n");
							       printf("\nEnter your choice: ");
							       scanf("%d",&NGO_Record);
							       switch(NGO_Record)
							       {
								       case 1:Admin_NGO_Add();
									      break;
								       case 2:Admin_NGO_Edit();
									      break;
								       case 3:Admin_NGO_Delete();
									      break;
								       case 4:Admin_NGO_View();
									      break;
								       case 5:break;
								       default:printf("\nEnter the correct choice: ");
							       }
						       }
						       break;
						case 2:Hotel_Record_Maintenance();
						       while(Hotel_Record!=5)
						       {
							       //Admin Hotel menu options
							       printf("\n..............Hotel Record Menu..............\n");
							       printf("\n 1.Add Hotel Record");
							       printf("\n 2.Edit Hotel Record");
							       printf("\n 3.Delete Hotel Record");
							       printf("\n 4.View Hotel Record");
							       printf("\n 5.Go Back\n");
							       printf("\nEnter your choice: ");
							       scanf("%d",&Hotel_Record);
							       switch(Hotel_Record)
							       {
								       case 1:Admin_Hotel_Add();
									      break;
								       case 2:Admin_Hotel_Edit();
									      break;
								       case 3:Admin_Hotel_Delete();
									      break;
								       case 4:Admin_Hotel_View();
									      break;
								       case 5:break;
								       default:printf("\nEnter the correct choice: ");
							       }
						       }
						       break;
						case 3:Admin_Report();
						       break;
						case 4:break;
						default:printf("\nEnter the correct Admin Choice: ");

					}
				}
				break;
			case 4:Food_request=0;
				while(Food_request!=3)
				{
					//Food Request options
					printf("\n..............CHOOSE OPTIONS..............\n");
					printf("\n1.NGO Request");
					printf("\n2.Hotel Request");
					printf("\n3.Go Back\n");
					printf("\nEnter Choice: ");
					scanf("%d",&Food_request);
					switch(Food_request)
					{
						case 1:NGO_request();
						       break;
						case 2:Hotel_request();
						       break;
						case 3:break;
						default:printf("\nEnter the correct food request choice: ");

					}
				}     
				break;
			case 5:break;
			default:printf("\nEnter the correct choice: ");

		}
	}
	list_to_NGO();	//NGO file handling function
	list_to_Hotel();	//Hotel file handling function
	return EXIT_SUCCESS;
}


