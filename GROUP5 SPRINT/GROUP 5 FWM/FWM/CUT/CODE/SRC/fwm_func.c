/*******************************************************
 * FILENAME		      :fwm_function.c
 *
 * DESCRIPTION		:This file defines the functions that perform various operations on NGO and Hotel database.
 *******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<string.h>
#include "../Header/fwm_header.h"

ngo *start_n,*new_n,*ptr_n,*prev_n,*last_n;
hotel *start_h,*new_h,*ptr_h,*prev_h,*last_h;

/********************************************************
 * FUNCTION NAME	      :NGO_Registration
 *
 * DESCRIPTION		:This function adds the NGO information by taking data as input from the user with respective validations.
 *
 * RETURNS		      :No returns.
 *
 ********************************************************/

int NGO_Registration()
{
	//Add the NGO registration details.
	int i=0;
	if((new_n=(ngo *)calloc(1,sizeof(ngo)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		//Validation for NGO Registration Id starts from here.
		char check_id[5];
		int flag=0;
		printf("\nEnter NGO Registration id: ");
		scanf("%s",check_id);
		if(strlen(check_id) != 5)
		{
			printf("\nNGO Registration Id should contain 5 digits\n");
			continue;
		}
		for(i=0;check_id[i]!='\0';i++)
		{
			if(!isdigit(check_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nNGO Registration Id should be an integer value\n");
			continue;
		}
		new_n->reg_id=atoi(check_id);
		for(ptr_n=(start_n);(ptr_n!=NULL);ptr_n=ptr_n->next_n)
		{
			if(ptr_n->reg_id == new_n->reg_id)
			{
				printf("\nThis registration id already exists\n");
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			break;
		}
		break;
	}

	while(1)
	{
		//Validation for NGO name starts from here.
		printf("\nEnter NGO Name: ");
		scanf("%s",new_n->name);
		int length=strlen(new_n->name);
		if(length>50)
		{
			printf("\nNGO name should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty\n");
			continue;
		}
		int flag=0;
		for(int i=0;i<length;i++)
		{
			if(!isalpha(new_n->name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		//Validation for Number of NGO beneficiaries starts from here.
		char check_beneficiaries[10];
		printf("\nEnter number of NGO Beneficiaries: ");
		scanf("%s",check_beneficiaries);
		if(strlen(check_beneficiaries)>15)
		{
			printf("\nNumber of beneficiaries should not be graeter than 15 digits\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_beneficiaries[i]!='\0';i++)
		{
			if(!isdigit(check_beneficiaries[i]))
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_n->beneficiaries=atoi(check_beneficiaries);
 		break;
	}

	while(1)
	{
		//Validation for NGO Established Year starts from here.
		char check_year[5];
		printf("\nEnter NGO Established Year: ");
		scanf("%s",check_year);
		if(strlen(check_year)>4)
		{
			printf("\nEnter year in range (1000-2022)\n");
			continue;
		}
		int a=atoi(check_year);
		if(a<=1000 || a>=2022)
		{
			printf("\nEnter year in range (1000-2022)\n");
			continue;
				
		
		}
		new_n->estd_year=a;
		break;
	}
	while(1)
	{
		//Validation for NGO Address starts from here. 
		printf("\nEnter NGO Address: ");
		scanf("%s",new_n->address);
		int length=strlen(new_n->address);
		if(length>50)
		{
			printf("\nNGO address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty\n");
			continue;
		}
		break;
	}
	while(1)
	{
		//Validation for NGO Telephone Number starts from here.
		char check_telephone_number[11];
		printf("\nEnter NGO Telephone Number: ");
		scanf("%s",check_telephone_number);
		if(strlen(check_telephone_number)>10)
		{
			printf("\nTelephone number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_telephone_number[i]!='\0';i++)
		{
			if(!isdigit(check_telephone_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_n->telephone_number=atol(check_telephone_number);
 		break;
	}
	new_n->rctr_n=0;
	new_n->dctr_n=0;
	if(!start_n)
	{
		start_n=new_n;
		new_n->next_n=NULL;
	}
	else if(new_n->reg_id<start_n->reg_id)
	{
		new_n->next_n=start_n;
		start_n=new_n;
	}
	else
	{
		for(ptr_n=start_n;(ptr_n) && ptr_n->reg_id < new_n->reg_id; prev_n=ptr_n,ptr_n=ptr_n->next_n);
		prev_n->next_n=new_n;
		new_n->next_n=ptr_n;
	}
	return EXIT_SUCCESS;
}

/**********************************************************
 * FUNCTION NAME	:NGO_Edit
 *
 * DESCRIPTION	:This function edits the NGO information by taking NGO registration id as an input from the user with respective validations.
 *
 * RETURNS		:No returns.
 **********************************************************/

int NGO_Edit()
{
       // system("clear");
       // Edit the NGO registration details.
        if(!start_n)
	{
		printf("\n No NGO Record to edit\n");
		return EXIT_FAILURE;
	}
	printf("\n......Edit information of the NGO......\n");
	//Validation for NGO registration Id for editing.
	int check_id;
	while(1)
	{
		int flag=0;
		char reg_id[5];
		printf("\nEnter NGO Registration id for editing details: ");
	        scanf("%s",reg_id);
		for(int i=0;reg_id[i]!='\0';i++)
		{
			if(!isdigit(reg_id[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nNGO Registration Id should be an integer value\n");
			continue;
		}
		else
		{
			check_id=atoi(reg_id);
			break;
		}
		break;
	}
	for(ptr_n=start_n;(ptr_n) && (ptr_n->reg_id!=check_id);ptr_n=ptr_n->next_n);
	if(!ptr_n)
	{
		printf("\nNo such NGO registration id exists\n");
		return EXIT_FAILURE;
	}
	//Validation for NGO name for Editing.
	while(1)
	{
		char check_name[51];
		printf("\nEnter the name of the NGO for editing or enter N to skip: ");
		scanf("%s",check_name);
		if(strlen(check_name)>50)
		{
			printf("\n Name should not be greater than 50 alphabets\n");
			continue;
		}
		int flag=0;
		int length=strlen(check_name);
		for(int i=0;i<length;i++)
		{
			if(!isalpha(check_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only");
			continue;
		}
		else
		{
			if((strcmp(check_name,"N"))!=0)
			{
				strcpy(ptr_n->name,check_name);
			}
			break;
		}
		break;
	}
	//Validation for Number of NGO beneficiaries for editing.
	while(1)
	{
		char check_beneficiaries[20];
		printf("\nEnter number of NGO beneficiaries for editing or enter N to skip: ");
		scanf("%s",check_beneficiaries);
		int flag=0;
		if((strcmp(check_beneficiaries,"N"))==0)
		{
			break;
		}
		for(int i=0;check_beneficiaries[i]!='\0';i++)
		{
			if(!isdigit(check_beneficiaries[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		if((strlen(check_beneficiaries))>15)
		{
			continue;
		}
		ptr_n->beneficiaries=atoi(check_beneficiaries);
		break;
	}
	//Validation for NGO established year for editing.
	while(1)
	{
		char check_year[5];
		printf("\nEnter Established year of NGO for editing or enter N to skip: ");
		scanf("%s",check_year);
		if(strlen(check_year)>4)
		{
			printf("\nEnter year in range(1000-2022)\n");
			continue;
		}
		if(strcmp(check_year,"N")==0)
		{
			break;
		}

		int a=atoi(check_year);
			if(a<=1000 || a>=2022)

			{
				printf("\nEnter year in range(1000-2022)\n");
				continue;
			}
		ptr_n->estd_year=a;
		break;
	}
	//Validation for NGO Address for Editing.
	while(1)
	{
		char check_address[50];
		printf("\nEnter NGO Address for editing or enter N to skip: ");
		scanf("%s",check_address);
		int length=strlen(check_address);
		if(length>50)
		{
			printf("\nNGO address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty\n");
			continue;
		}
		else
		{
			if((strcmp(check_address,"N"))!=0)
			{
				strcpy(ptr_n->address,check_address);
			}
			break;
		}
		break;
	}
	//Validation for NGO telephone number for editing.
	while(1)
	{
		char check_telephone_number[11];
		printf("\nEnter NGO Telephone Number for editing or enter N to skip: ");
		scanf("%s",check_telephone_number);
		int flag=0;
		if(strcmp(check_telephone_number,"N")==0)
		{
			break;
		}

		for(int i=0;check_telephone_number[i]!='\0';i++)
		{
			if(!isdigit(check_telephone_number[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		if(strlen(check_telephone_number)>10)
		{
			printf("\nTelephone number should not be greater than 10 digits\n");
			continue;
		}

	ptr_n->telephone_number=atol(check_telephone_number);
	break;
	}
return EXIT_SUCCESS;
}

/***********************************************************
 * FUNCTION NAME	      :NGO_View
 *
 * DESCRIPTION		:This function displays the NGO records by taking NGO registration id as an input from user.
 *
 * RETURNS		      :No returns
 ***********************************************************/

int NGO_View()
{
	//To view NGO details.
	if(!start_n)
	{
		printf("\nThe record is empty");
		return EXIT_FAILURE;
	}
	printf("\nThe list of NGO's are\n");
	printf("\nRegister Id       Name	Beneficiaries	Estd year	Address	   Telephone Number   rctr     dctr\n");
	for(ptr_n=start_n;(ptr_n);ptr_n=ptr_n->next_n)
	{
		printf("\n    %d        %s	  %d	         %d	         %s          %ld       %d       %d\n",ptr_n->reg_id,ptr_n->name,ptr_n->beneficiaries,ptr_n->estd_year,ptr_n->address,ptr_n->telephone_number,ptr_n->rctr_n,ptr_n->dctr_n);
	}
	printf("\n");
	return EXIT_SUCCESS;
}

/***********************************************************
 * FUNCTION NAME	      :Hotel_Registration
 *
 * DESCRIPTION		:This function adds the Hotel information by taking data as input from the user with respective validations.
 *
 * RETURNS		      :No returns
 ***********************************************************/

int Hotel_Registration()
{
	//Add the Hotel registration details.
	int i=0;
	if((new_h=(hotel *)calloc(1,sizeof(hotel)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		//Validation for Hotel Registration Id starts from here.
		char check_id[5];
		int flag=0;
		printf("\nEnter Hotel Registration id: ");
		scanf("%s",check_id);
		if(strlen(check_id) != 5)
		{
			printf("\n Hotel Registration Id should contain 5 digits\n");
			continue;
		}
		for(i=0;check_id[i]!='\0';i++)
		{
			if(!isdigit(check_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nHotel Registration Id should be an integer value\n");
			continue;
		}
		new_h->reg_id=atoi(check_id);
		for(ptr_h=(start_h);(ptr_h!=NULL);ptr_h=ptr_h->next_h)
		{
			if(ptr_h->reg_id == new_h->reg_id)
			{
				printf("\nThis registration id already exists\n");
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			break;
		}
		break;
	}	
	while(1)
	{
		//Validation for Hotel Name starts from here.
		printf("\nEnter Hotel Name: ");
		scanf("%s",new_h->name);
		int length=strlen(new_h->name);
		if(length>50)
		{
			printf("\nHotel name should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nHotel name should not be empty\n");
			continue;
		}
		int flag=0;
		for(int i=0;i<length;i++)
		{
			if(!isalpha(new_h->name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		//Validation for Hotel Address starts from here.
		printf("\nEnter Hotel Address: ");
		scanf("%s",new_h->address);
		int length=strlen(new_h->address);
		if(length>50)
		{
			printf("\nHotel address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nHotel name should not be empty!\n");
			continue;
		}
		break;
	}
	while(1)
	{
		//Validation for Hotel Contact Number starts from here.
		char check_contact_number[11];
		printf("\nEnter Hotel Contact Number: ");
		scanf("%s",check_contact_number);
		if(strlen(check_contact_number)>10)
		{
			printf("\nContact number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_contact_number[i]!='\0';i++)
		{
			if(!isdigit(check_contact_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_h->contact_number=atol(check_contact_number);
 		break;
	}
	new_h->rctr_h=0;
	new_h->dctr_h=0;
	if(!start_h)
	{
		start_h=new_h;
		new_h->next_h=NULL;
	}
	else if(new_h->reg_id<start_h->reg_id)
	{
		new_h->next_h=start_h;
		start_h=new_h;
	}
	else
	{
		for(ptr_h=start_h;(ptr_h) && ptr_h->reg_id < new_h->reg_id; prev_h=ptr_h,ptr_h=ptr_h->next_h);
		prev_h->next_h=new_h;
		new_h->next_h=ptr_h;
	}
	return EXIT_SUCCESS;

}

/**********************************************************
 * FUNCTION NAME	      :Hotel_Edit
 *
 * DESCRIPTION		:This function edits the Hotel information by taking Hotel registration id as an input from the user with respective validations.
 *
 * RETURNS		      :No returns.
 **********************************************************/

int Hotel_Edit()
{
	//Edit the Hotel registration details.
	int i=0;
        //system("clear");
	if(!start_h)
	{
		printf("\nNo Hotel Record available for edit\n");
		return EXIT_FAILURE;
        }
	int check_id;
	printf("\n......Edit Information Of Hotel.......\n");
	//Validation of Hotel registration Id for editing.
	while(1)
	{
		int flag=0;
		char reg_id[5];
		printf("\nEnter hotel id: ");
                scanf("%s",reg_id);
		for(int i=0;reg_id[i]!='\0';i++)
		{
			if(!isdigit(reg_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nHotel Id should be numeric values\n");
			continue;
		}
		else
		{
			check_id=atoi(reg_id);
			break;
		}
		break;
	}
	for(ptr_h=(start_h);(ptr_h!=NULL) && (ptr_h->reg_id!=check_id);ptr_h=ptr_h->next_h);
	if(!ptr_h)
	{
		printf("\nHotel id does not exist\n");
		return EXIT_FAILURE;
	}
	//Validation of Hotel name for Editing.
	while(1)
	{
		char check_name[51];
		printf("\nEnter Hotel name for editing or enter N to skip: ");
		scanf("%s",check_name);
		if(strlen(check_name)>50)
		{
			printf("\nName sould not be greater than 50 alphabets\n");
			continue;
		}
		int flag=0;
		int length=strlen(check_name);
		for(i=0;i<length;i++)
		{
			if(!isalpha(check_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			if((strcmp(check_name,"N"))!=0)
			{
				strcpy(ptr_h->name,check_name);
			}
			break;
		}
		break;
	}
	//Validation of Hotel Address for editing.
	while(1)
	{
		char check_address[50];
		printf("\nEnter the Hotel address for editing or enter N to skip: ");
		scanf("%s",check_address);
		if(strlen(check_address)>50)
		{
			printf("\nHotel Address should be less than 50\n");
			continue;
		}
		if(strlen(check_address)==0)
		{
			printf("\nHotel Address should not be empty\n");
			continue;
		}
		else
		{
			if((strcmp(check_address,"N"))!=0)
			{
				strcpy(ptr_h->address,check_address);
			}
			break;
		}
		break;
	}
	//Validation of Hotel contact number for editing.
	while(1)
	{
		char check_contact_number[11];
		printf("\nEnter Hotel contact Number for editing or enter N to skip: ");
		scanf("%s",check_contact_number);
		if(strlen(check_contact_number)>10)
		{
			printf("\nContact number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		if((strcmp(check_contact_number,"N"))==0)
		{
			break;
		}

		for(int i=0;check_contact_number[i]!='\0';i++)
		{
			if(!isdigit(check_contact_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}

	ptr_h->contact_number=atol(check_contact_number);
	break;
	}
return EXIT_SUCCESS;
}

/***********************************************************
 * FUNCTION NAME	      :Hotel_View
 *
 * DESCRIPTION		:This function displays the Hotel records by taking Hotel registration id as an input from user.
 *
 * RETURNS		      :No returns
 ***********************************************************/

int Hotel_View()	
{
	//To view Hotel details.
	if(!start_h)
	{
		printf("\nThe record is empty");
		return EXIT_FAILURE;
	}
	printf("\nThe list of Hotels are\n");
	printf("\nRegister Id	Name	Address	      Contact Number     rctr      dctr\n");
	for(ptr_h=start_h;(ptr_h);ptr_h=ptr_h->next_h)
	{
		printf("\n%3d	%12s	%4s	%18ld     %5d     %5d\n",ptr_h->reg_id,ptr_h->name,ptr_h->address,ptr_h->contact_number,ptr_h->rctr_h,ptr_h->dctr_h);
	}
	printf("\n");
	return EXIT_SUCCESS;
}

int NGO_Record_Maintenance()
{
}

/********************************************************
 * FUNCTION NAME	      :Admin_NGO_Add
 *
 * DESCRIPTION		:This function adds the NGO information by taking data as input from the user with respective validations.
 *
 * RETURNS		      :No returns.
 *
 ********************************************************/

int Admin_NGO_Add()
{
	//Adding of NGO details by admin.
	int i=0;
	if((new_n=(ngo *)calloc(1,sizeof(ngo)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		//Validation for NGO Registration Id starts from here.
		char check_id[5];
		int flag=0;
		printf("\nEnter NGO Registration id: ");
		scanf("%s",check_id);
		if(strlen(check_id) != 5)
		{
			printf("\nNGO Registration Id should contain 5 digits\n");
			continue;
		}
		for(i=0;check_id[i]!='\0';i++)
		{
			if(!isdigit(check_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nNGO Registration Id should be an integer value\n");
			continue;
		}
		new_n->reg_id=atoi(check_id);
		for(ptr_n=(start_n);(ptr_n!=NULL);ptr_n=ptr_n->next_n)
		{
			if(ptr_n->reg_id == new_n->reg_id)
			{
				printf("\nThis registration id already exists\n");
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			break;
		}
		break;
	}

	while(1)
	{
		//Validation for NGO name starts from here.
		printf("\nEnter NGO Name: ");
		scanf("%s",new_n->name);
		int length=strlen(new_n->name);
		if(length>50)
		{
			printf("\nNGO name should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty!\n");
			continue;
		}
		int flag=0;
		for(int i=0;i<length;i++)
		{
			if(!isalpha(new_n->name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		//Validation for number of NGO beneficiaries starts from here.
		char check_beneficiaries[20];
		printf("\nEnter number of NGO Beneficiaries: ");
		scanf("%s",check_beneficiaries);
		if(strlen(check_beneficiaries)>15)
		{
			printf("\nNumber of Beneficiaries should not be greater than 15\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_beneficiaries[i]!='\0';i++)
		{
			if(!isdigit(check_beneficiaries[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_n->beneficiaries=atoi(check_beneficiaries);
 		break;
	}
	while(1)
	{
		//Validation for NGO Established Year starts from here.
		char check_year[5];
		printf("\nEnter NGO Established Year: ");
		scanf("%s",check_year);
		if(strlen(check_year)>4)
		{
			printf("\nEnter year in range (100-2022)\n");
			continue;
		}
		int a=atoi(check_year);
		if(a<=1000 || a>=2022)
		{
			printf("\nEnter year in range (1000-2022)\n");
			continue;
				
		
		}
		new_n->estd_year=a;
		break;
	}

	while(1)
	{
		//Validation for NGO Address starts from here. 
		printf("\nEnter NGO Address:");
		scanf("%s",new_n->address);
		int length=strlen(new_n->address);
		if(length>50)
		{
			printf("\nNGO address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty!\n");
			continue;
		}
		break;
	}
	while(1)
	{
		//Validation for NGO Telephone Number starts from here.
		char check_telephone_number[11];
		printf("\nEnter NGO Telephone Number: ");
		scanf("%s",check_telephone_number);
		if(strlen(check_telephone_number)>10)
		{
			printf("\nTelephone number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_telephone_number[i]!='\0';i++)
		{
			if(!isdigit(check_telephone_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_n->telephone_number=atol(check_telephone_number);
 		break;

	}
	if(!start_n)
	{
		start_n=new_n;
		new_n->next_n=NULL;
	}
	else if(new_n->reg_id<start_n->reg_id)
	{
		new_n->next_n=start_n;
		start_n=new_n;
	}
	else
	{
		for(ptr_n=start_n;(ptr_n) && ptr_n->reg_id < new_n->reg_id; prev_n=ptr_n,ptr_n=ptr_n->next_n);
		prev_n->next_n=new_n;
		new_n->next_n=ptr_n;
	}
	return EXIT_SUCCESS;
}

/**********************************************************
 * FUNCTION NAME	      :Admin_NGO_Edit
 *
 * DESCRIPTION		:This function edits the NGO information by taking NGO registration id as an input from the user with respective validations.
 *
 * RETURNS		      :No returns.
 **********************************************************/

int Admin_NGO_Edit()
{
	//Editing NGO details by Admin.
	if(!start_n)
	{
		printf("\n No NGO Record to edit\n");
		return EXIT_FAILURE;
	}
	int check_id;
	printf("\n......Edit information of the NGO......\n");
	//Validation of NGO registration details for editing.
	while(1)
	{
		int flag=0;
		char reg_id[5];
		printf("\nEnter NGO Registration id for editing details: ");
	        scanf("%s",reg_id);
		for(int i=0;reg_id[i]!='\0';i++)
		{
			if(!isdigit(reg_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nNGO Registration Id should be an integer value\n");
			continue;
		}
		else
		{
			check_id=atoi(reg_id);
			break;
		}
		break;
	}
	for(ptr_n=(start_n);(ptr_n!=NULL) && (ptr_n->reg_id!=check_id);ptr_n=ptr_n->next_n);
	if(!ptr_n)
	{
		printf("\nNo such NGO registration id exists\n");
		return EXIT_FAILURE;
	}
	//Validation of NGO name for editing.
	while(1)
	{
		char check_name[51];
		printf("\nEnter the name of the NGO for editing or enter N to skip: ");
		scanf("%s",check_name);
		if(strlen(check_name)>50)
		{
			printf("\nName should not be graeter than 50 alphabets\n");
			continue;
		}
		int flag=0;
		int length=strlen(check_name);
		for(int i=0;i<length;i++)
		{
			if(!isalpha(check_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			if((strcmp(check_name,"N"))!=0)
			{
				strcpy(ptr_n->name,check_name);
			}
			break;
		}
		break;
	}
	while(1)
	{
		//Validation of number of NGO beneficiaries for editing.
		char check_beneficiaries[20];
		printf("\nEnter number of NGO beneficiaries for editing or enter N to skip: ");
		scanf("%s",check_beneficiaries);
		if(strlen(check_beneficiaries)>15)
		{
			printf("\nNumber of beneficiaries shpuld not be greater than 15 digits\n");
			continue;
		}
		int flag=0;
		if((strcmp(check_beneficiaries,"N"))==0)
		{
			break;
		}
		for(int i=0;check_beneficiaries[i]!='\0';i++)
		{
			if(!isdigit(check_beneficiaries[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		ptr_n->beneficiaries=atoi(check_beneficiaries);
		break;
	}
	while(1)
	{
		//Validation of NGO Established year for editing.
		char check_year[5];
		printf("\nEnter Established year of NGO for editing or enter N to skip: ");
		scanf("%s",check_year);
		if(strlen(check_year)>4)
		{
			printf("\nEnter year in range (1000-2022)\n");
			continue;
		}
		if(strcmp(check_year,"N")==0)
		{
			break;
		}

		int a=atoi(check_year);
			if(a<=1000 || a>=2022)

			{
				printf("\nEnter year in range(1000-2022)\n");
				continue;
			}
		ptr_n->estd_year=a;
		break;
	}
	while(1)
	{
		//Validation of NGO address for editing.
		char check_address[50];
		printf("\nEnter NGO Address for editing or enter N to skip: ");
		scanf("%s",check_address);
		int length=strlen(check_address);
		if(length>50)
		{
			printf("\nNGO address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nNGO name should not be empty\n");
			continue;
		}
		else
		{
			if((strcmp(check_address,"N"))!=0)
			{
				strcpy(ptr_n->address,check_address);
			}
			break;
		}
		break;
	}
	while(1)
	{
		//Validation of NGO telephone number for editing.
		char check_telephone_number[11];
		printf("\nEnter NGO Telephone Number for editing or enter N to skip: ");
		scanf("%s",check_telephone_number);
		if(strlen(check_telephone_number)>10)
		{
			printf("\nTelephone number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		if((strcmp(check_telephone_number,"N"))==0)
		{
			break;
		}

		for(int i=0;check_telephone_number[i]!='\0';i++)
		{
			if(!isdigit(check_telephone_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}

	ptr_n->telephone_number=atol(check_telephone_number);
	break;
	}
return EXIT_SUCCESS;
}

/*************************************************************
 * FUNCTION NAME	      :Admin_Hotel_Delete
 *
 * DESCRIPTION		:This function deletes the Hotel information by taking the Hotel registration id as the input from the user with respective validations.
 *
 * RETURNS		      :No returns.
**************************************************************/

int Admin_NGO_Delete()
{
	//Deleting of NGO details by Admin.
	if(!start_n)
	{
		printf("\nEmpty NGO Record\n");
		return EXIT_FAILURE;
	}
	int ngo_reg_id;
	printf("\nEnter NGO Registration Id for deleting: ");
	scanf("%d",&ngo_reg_id);
	if(ngo_reg_id==start_n->reg_id)
	{
		ptr_n=start_n;
		start_n=start_n->next_n;
		free(ptr_n);
	}
	else
	{
		for(ptr_n=start_n;(ptr_n) && ptr_n->reg_id!=ngo_reg_id;prev_n=ptr_n,ptr_n=ptr_n->next_n);
		if(!ptr_n)
		{
			printf("\nRegistration Id %d not found for deletion\n",ngo_reg_id);
			return EXIT_FAILURE;
		}
		prev_n->next_n=ptr_n->next_n;
		free(ptr_n);
	}
	return EXIT_SUCCESS;
}

/***********************************************************
 * FUNCTION NAME	      :Admin_NGO_View
 *
 * DESCRIPTION		:This function displays the NGO records by taking NGO registration id as an input from user.
 *
 * RETURNS		      :No returns
* ***********************************************************/

int Admin_NGO_View()
{
	//To view NGO details.
	if(!start_n)
	{
		printf("\nThe NGO Record is Empty");
		return EXIT_FAILURE;
	}
	printf("\nRegister Id	Name	Beneficiaries	Estd year	Address		Telephone Number\n");
	for(ptr_n=start_n;(ptr_n);ptr_n=ptr_n->next_n)
	{
		printf("\n%3d	%14s	%5d	%13d	%14s	%20ld\n",ptr_n->reg_id,ptr_n->name,ptr_n->beneficiaries,ptr_n->estd_year,ptr_n->address,ptr_n->telephone_number);
	}
	printf("\n");
	return EXIT_SUCCESS;

}



int Hotel_Record_Maintenance()
{
}

/***********************************************************
 * FUNCTION NAME	      :Admin_Hotel_Add
 *
 * DESCRIPTION		:This function adds the Hotel information by taking data as input from the user with respective validations.
 *
 * RETURNS		      :NO returns
 ***********************************************************/

int Admin_Hotel_Add()
{
	//Adding of Hotel Details by Admin.
	int i=0;
	if((new_h=(hotel *)calloc(1,sizeof(hotel)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		//Validation for Hotel Registration Id starts from here.
		char check_id[5];
		int flag=0;
		printf("\nEnter Hotel Registration id: ");
		scanf("%s",check_id);
		if(strlen(check_id) != 5)
		{
			printf("\n Hotel Registration Id should contain 5 digits\n");
			continue;
		}
		for(i=0;check_id[i]!='\0';i++)
		{
			if(!isdigit(check_id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nHotel Registration Id should be an integer value\n");
			continue;
		}
		new_h->reg_id=atoi(check_id);
		for(ptr_h=(start_h);(ptr_h!=NULL);ptr_h=ptr_h->next_h)
		{
			if(ptr_h->reg_id == new_h->reg_id)
			{
				printf("\nThis registration id already exists\n");
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			break;
		}
		break;
	}	
	while(1)
	{
		//Validation for Hotel Name starts from here.
		printf("\nEnter Hotel Name: ");
		scanf("%s",new_h->name);
		int length=strlen(new_h->name);
		if(length>50)
		{
			printf("\nHotel name should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nHotel name should not be empty\n");
			continue;
		}
		int flag=0;
		for(int i=0;i<length;i++)
		{
			if(!isalpha(new_h->name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			break;
		}
		break;
	}
	while(1)
	{
		//Validation for Hotel Address starts from here.
		printf("\nEnter Hotel Address: ");
		scanf("%s",new_h->address);
		int length=strlen(new_h->address);
		if(length>50)
		{
			printf("\nHotel address should have less than 50 characters\n");
			continue;
		}
		if(length==0)
		{
			printf("\nHotel name should not be empty!\n");
			continue;
		}
		break;
	}
	while(1)
	{
		//Validation for Hotel Contact Number starts from here.
		char check_contact_number[11];
		printf("\nEnter Hotel Contact Number: ");
		scanf("%s",check_contact_number);
		if(strlen(check_contact_number)>10)
		{
			printf("\nContact number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		for(int i=0;check_contact_number[i]!='\0';i++)
		{
			if(!isdigit(check_contact_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}
		new_h->contact_number=atol(check_contact_number);
 		break;
	}	

	if(!start_h)
	{
		start_h=new_h;
		new_h->next_h=NULL;
	}
	else if(new_h->reg_id<start_h->reg_id)
	{
		new_h->next_h=start_h;
		start_h=new_h;
	}
	else
	{
		for(ptr_h=start_h;(ptr_h) && ptr_h->reg_id < new_h->reg_id; prev_h=ptr_h,ptr_h=ptr_h->next_h);
		prev_h->next_h=new_h;
		new_h->next_h=ptr_h;
	}
	return EXIT_SUCCESS;
}

/**********************************************************
 * FUNCTION NAME	            :Admin_Hotel_Edit
 *
 * DESCRIPTION		      :This function edits the Hotel information by taking Hotel registration id as an input from the user with respective validations.
 *
 * RETURNS		            :No returns.
 **********************************************************/

int Admin_Hotel_Edit()
{
	//Editing of Hotel Details by Admin.
	int i=0;
        //system("clear");
	if(!start_h)
	{
		printf("\nNo Hotel Record available for edit\n");
		return EXIT_FAILURE;
        }
	int check_id;
	printf("\n......Edit Information Of Hotel.......\n");
	while(1)
	{
		//Validation for Hotel Registration Id for editing.
		int flag=0;
		char id[5];
		printf("\nEnter hotel id: ");
                scanf("%s",id);
		for(i=0;id[i]!='\0';i++)
		{
			if(!isdigit(id[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nHotel Id should be numeric values\n");
			continue;
		}
		else
		{
			check_id=atol(id);
			break;
		}
		break;
	}
	for(ptr_h=(start_h);(ptr_h!=NULL) && (ptr_h->reg_id!=check_id);ptr_h=ptr_h->next_h);
	if(ptr_h==NULL)
	{
		printf("\nHotel id does not exist\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		//Validation of Hotel name for editing.
		char check_name[51];
		printf("\nEnter Hotel name for editing or enter N to skip: ");
		scanf("%s",check_name);
		if(strlen(check_name)>50)
		{
			printf("Name should not be greater than 15 alphabets\n");
			continue;
		}
		int flag=0;
		int length=strlen(check_name);
		for(i=0;i<length;i++)
		{
			if(!isalpha(check_name[i]))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nEnter alphabets only\n");
			continue;
		}
		else
		{
			if((strcmp(check_name,"N"))!=0)
			{
				strcpy(ptr_h->name,check_name);
			}
			break;
		}
		break;
	}
	while(1)
	{
		//Validation of Hotel Address for editing.
		char check_address[50];
		printf("\nEnter the Hotel address for editing or enter N to skip: ");
		scanf("%s",check_address);
		if(strlen(check_address)>50)
		{
			printf("\nHotel Address should be less than 50\n");
			continue;
		}
		if(strlen(check_address)==0)
		{
			printf("\nHotel Address should not be empty\n");
			continue;
		}
		else
		{
			if((strcmp(check_address,"N"))!=0)
			{
				strcpy(ptr_h->address,check_address);
			}
			break;
		}
		break;
	}
	while(1)
	{
		//Validation of contact number for editing.
		char check_contact_number[11];
		printf("\nEnter Hotel contact Number for editing or enter N to skip: ");
		scanf("%s",check_contact_number);
		if(strlen(check_contact_number)>10)
		{
			printf("\nContact number should not be greater than 10 digits\n");
			continue;
		}
		int flag=0;
		int i=0;
		if((strcmp(check_contact_number,"N"))==0)
		{
			break;
		}

		for(i=0;check_contact_number[i]!='\0';i++)
		{
			if(!isdigit(check_contact_number[i]))
			{
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an numeric value\n");
			continue;
		}

	ptr_h->contact_number=atol(check_contact_number);
	break;
	}
return EXIT_SUCCESS;
}

/*************************************************************
 * FUNCTION NAME	      :Admin_Hotel_Delete
 *
 * DESCRIPTION		:This function deletes the Hotel information by taking the Hotel registration id as the input from the user with respective validations.
 *
 * RETURNS		      :No returns.
 *************************************************************/

int Admin_Hotel_Delete()
{
	//Deleting of Hotel details.
	if(!start_h)
	{
		printf("\nEmpty Hotel Record\n");
		return EXIT_FAILURE;
	}
	int hotel_reg_id;
	printf("\nEnter Hotel Registration Id for deleting: ");
	scanf("%d",&hotel_reg_id);
	if(hotel_reg_id==start_h->reg_id)
	{
		ptr_h=start_h;
		start_h=start_h->next_h;
		free(ptr_h);
	}
	else
	{
		for(ptr_h=start_h;(ptr_h) && ptr_h->reg_id!=hotel_reg_id;prev_h=ptr_h,ptr_h=ptr_h->next_h);
		if(!ptr_h)
		{
			printf("\nRegistration Id %d not found for deletion\n",hotel_reg_id);
			return EXIT_FAILURE;
		}
		prev_h->next_h=ptr_h->next_h;
		free(ptr_h);
	}
	return EXIT_SUCCESS;

}

/***********************************************************
 * FUNCTION NAME	      :Admin_Hotel_View
 *
 * DESCRIPTION		:This function displays the Hotel records by taking Hotel registration id as an input from user. 
 *                   
 * RETURNS		      :No returns
 ***********************************************************/

int Admin_Hotel_View()
{
	//Viewing of Hotel details.
	if(!start_h)
	{
		printf("\nThe Hotel record is empty");
		return EXIT_FAILURE;
	}
	printf("\nRegistration Id	Name	Address		Contact Number\n");
	for(ptr_h=start_h;(ptr_h);ptr_h=ptr_h->next_h)
	{
		printf("\n%3d	%10s	%10s	%5ld\n",ptr_h->reg_id,ptr_h->name,ptr_h->address,ptr_h->contact_number);
	}
	printf("\n");
	return EXIT_SUCCESS;

}

int Admin_Report()
{
	int MAX_rctr_h=0;//Maximum request counter.
	char htl[20];
	for(ptr_h=start_h;(ptr_h);ptr_h=ptr_h->next_h)
	{
		if(MAX_rctr_h<ptr_h->rctr_h)
		{
			MAX_rctr_h=ptr_h->rctr_h;
			strcpy(htl,ptr_h->name);
		}
	}
	printf("\nHotel %s received maximum requests\n",htl);
	for(ptr_h=start_h;(ptr_h);ptr_h=ptr_h->next_h)
	{
		if(ptr_h->dctr_h==1)
		{
			printf("\n Total number of NGO requests are %d for hotel %s",ptr_h->rctr_h,ptr_h->name);
		}
	}

	for(ptr_n=start_n;(ptr_n);ptr_n=ptr_n->next_n)
	{
		if(ptr_n->dctr_n==1)
		{
			printf("\n Total number of Hotel requests are %d for NGO %s",ptr_n->rctr_n,ptr_n->name);
		}
	}
}

int Food_request()
{
}

/**************************************************************
 * FUNCTION NAME	      :NGO_request
 *
 * DESCRIPTION		:This function sends the request to the hotel by giving hotel registration id as an input from the user.
 * 			
 *RETURNS		      :No returns.
 **************************************************************/

int NGO_request()
{
	Hotel_View();
	int check_id=0;
	printf("\nEnter the Hotel Registration Id: ");
	scanf("%d",&check_id);
	int flag=0;
	for(ptr_h=start_h;(ptr_h);ptr_h=ptr_h->next_h)
	{
		if(check_id==ptr_h->reg_id)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nGiven Hotel registration id not found ");
	}
	else
	{
		printf("\nRequest has sent to  the Hotel with  registration id %d\n",ptr_h->reg_id);
		ptr_h->rctr_h++;
		ptr_h->dctr_h=1;
		int ch=0;
		while(ch!=3)
		{
			printf("\n");
			printf("\n1.Yes");
			printf("\n2.No");
			printf("\n3.Exit\n");
			printf("\nAre you ready to supply.Enter your choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:yes();
				       break;
				case 2:no();
				       break;
				case 3:break;
				default:printf("\nInvalid choice");
			}
		break;
		}
		return EXIT_SUCCESS;
	}
}


/**************************************************************
 * FUNCTION NAME	      :Hotel_request
 *
 * DESCRIPTION		:This function sends the request to the NGO by giving  NGO registration id as an input from the user.
 *
 *RETURNS		      :No returns.
 **************************************************************/
int Hotel_request()
{
	NGO_View();
	int check_id=0;
	printf("\nEnter the NGO Registration Id: ");
	scanf("%d",&check_id);
	int flag=0;
	for(ptr_n=start_n;(ptr_n);ptr_n=ptr_n->next_n)
	{
		if(check_id==ptr_n->reg_id)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\nGiven NGO registration id not found ");
	}
	else
	{
		printf("\nRequest has sent to  the NGO with registration id %d\n",ptr_n->reg_id);
		ptr_n->rctr_n++;
		ptr_n->dctr_n=1;
	}
}
int yes()
{
	printf("\n Hotel is ready to supply food");
}
int no()
{
	printf("\nHotel cannot provide food, so choose alternative hotel");
	Admin_check();
}

int Admin_check()
{
	NGO_request();
}

/***********************************************************
 *  FUNCTION NAME	:NGO_to_list
 *
 *  DESCRIPTION 	:This funcion allocate memory for the NGO to open and read the file from beginning till end of file and put  each NGO into the list.
 *   			
 *  RETURNS		:No Returns.
 *
 *****************************************************************************************/


int NGO_to_list()
{
ngo *new_n,*ptr_n;
	ng n;
	FILE *fp;
	if((fp=fopen("NGO","rb"))==NULL)
	{
		return EXIT_FAILURE;
	}

	if((new_n=(ngo *)calloc(1,sizeof(ngo)))==NULL)
	{
		printf("\nMemory allocation failed\n");
		return EXIT_FAILURE;
	}
	fread(&n,sizeof(ng),1,fp);
	while(!feof(fp))
	{
		new_n->reg_id=n.reg_id;
		strcpy(new_n->name,n.name);
		strcpy(new_n->address,n.address);
		new_n->beneficiaries=n.beneficiaries;
		new_n->estd_year=n.estd_year;
		new_n->telephone_number=n.telephone_number;
		new_n->rctr_n=n.rctr_n;
		new_n->dctr_n=n.dctr_n;
		if(start_n==NULL)
		{
			start_n=last_n=new_n;
			new_n->next_n=NULL;
		}

		else
		{
			last_n->next_n=new_n;
			last_n=new_n;
			new_n->next_n=NULL;
		}
		if((new_n=(ngo *)calloc(1,sizeof(ngo)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		fread(&n,sizeof(ng),1,fp);
	}
	free(new_n);
	fclose(fp);
}


/*************************************************************
 *  FUNCTION NAME	      :list_to_NGO
 *
 *  DESCRIPTION		:This function is used to write NGO data in to the file by traversing the list.
 *   			
 *  RETURNS		      :No returns.
 **************************************************************/


int list_to_NGO()
{
	ngo *ptr_n,*new_n;
	ng n;

	FILE *fp;
	if((fp=fopen("NGO","wb"))==NULL)
	{
		return EXIT_FAILURE;
	}
	for(ptr_n=start_n;(ptr_n);ptr_n=ptr_n->next_n)
	{
		n.reg_id=ptr_n->reg_id;
		strcpy(n.name,ptr_n->name);
		strcpy(n.address,ptr_n->address);
		n.beneficiaries=ptr_n->beneficiaries;
		n.estd_year=ptr_n->estd_year;
		n.telephone_number=ptr_n->telephone_number;
		n.rctr_n=ptr_n->rctr_n;
		n.dctr_n=ptr_n->dctr_n;
		fwrite(&n,sizeof(ng),1,fp);
	}
	fclose(fp);
	free(ptr_n);
}


/***************************************************************
 *  FUNCTION NAME	:Hotel_to_list
 *
 *  DESCRIPTION 	:This funcion allocate memory for the Hotel to open and read the file from beginning till end of file and put each Hotel into the list.
 *
 *  RETURNS		:No Returns.
 ***************************************************************/


int Hotel_to_list()
{
	hotel *new_h,*ptr_h;
	ht n;
	FILE *fp;
	if((fp=fopen("Hotel","rb"))==NULL)
	{
		return EXIT_FAILURE;
	}

	if((new_h=(hotel *)calloc(1,sizeof(hotel)))==NULL)
	{
		printf("\nMemory allocation failed\n");
		return EXIT_FAILURE;
	}
	fread(&n,sizeof(ht),1,fp);
	while(!feof(fp))
	{
		new_h->reg_id=n.reg_id;
		strcpy(new_h->name,n.name);
		strcpy(new_h->address,n.address);
		new_h->contact_number=n.contact_number;
		new_h->rctr_h=n.rctr_h;
		new_h->dctr_h=n.dctr_h;
		if(start_h==NULL)
		{
			start_h=last_h=new_h;
			new_h->next_h=NULL;
		}

		else
		{
			last_h->next_h=new_h;
			last_h=new_h;
			new_h->next_h=NULL;
		}
		if((new_h=(hotel *)calloc(1,sizeof(hotel)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		fread(&n,sizeof(ht),1,fp);
	}
	free(new_h);
	fclose(fp);
}


/**********************************************************
 *  FUNCTION NAME	      :list_to_Hotel
 *
 *  DESCRIPTION		:This function is used to write Hotel data in to the file by traversing the list.
 *
 *  RETURNS		      :No returns.
 *
 ***********************************************************/


int list_to_Hotel()
{
	hotel *ptr_h,*new_h;
	ht n;

	FILE *fp;
	if((fp=fopen("Hotel","wb"))==NULL)
	{
		return EXIT_FAILURE;
	}
	for(ptr_h=(start_h);(ptr_h);ptr_h=ptr_h->next_h)
	{
		n.reg_id=ptr_h->reg_id;
		strcpy(n.name,ptr_h->name);
		strcpy(n.address,ptr_h->address);
		n.contact_number=ptr_h->contact_number;
		n.rctr_h=ptr_h->rctr_h;
		n.dctr_h=ptr_h->dctr_h;
		fwrite(&n,sizeof(ht),1,fp);
	}
	fclose(fp);
	free(ptr_h);
}
