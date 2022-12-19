#ifndef FWM_HEADER_H
#define FWM_HEADER_H

typedef struct NGO_database
{
	int reg_id;
	char name[20];
	int beneficiaries;
	int estd_year;
	char address[100];
	long int telephone_number;
	int rctr_n;//request counter
	int dctr_n;
	struct NGO_database *next_n;
}ngo;
typedef struct NGO_database_temp
{
	int reg_id;
	char name[20];
	int beneficiaries;
	int estd_year;
	char address[100];
	long int telephone_number;
	int rctr_n;//request counter
	int dctr_n;
}ng;


typedef struct Hotel_database
{
	int reg_id;
	char name[20];
	char address[100];
	long int contact_number;
	int rctr_h;//request counter
	int dctr_h;
	struct Hotel_database *next_h;
}hotel;
typedef struct Hotel_database_temp
{
	int reg_id;
	char name[20];
	char address[100];
	long int contact_number;
	int rctr_h;//request counter
	int dctr_h;
}ht;

//functions for NGO database maintenance
int NGO_Registration();
int NGO_Edit();
int NGO_View();

//Functions for NGO_file_handling.c
int NGO_to_list();
int list_to_NGO();

//functions for Hotel database maintenance
int Hotel_Registration();
int Hotel_Edit();
int Hotel_View();

//Functions for Hotel_file_handling.c
int Hotel_to_list();
int list_to_Hotel();

//functions for Admin to maintain NGO database
int NGO_Record_Maintenance();
int Admin_NGO_Add();
int Admin_NGO_Edit();
int Admin_NGO_Delete();
int Admin_NGO_View();
int Admin_check();

//functions for Admin to maintain Hotel database
int Hotel_Record_Maintenance();
int Admin_Hotel_Add();
int Admin_Hotel_Edit();
int Admin_Hotel_Delete();
int Admin_Hotel_View();

//function for Admin to  report the database 
int Admin_Report();

//function to request food
int Food_request();
int NGO_request();
int Hotel_request();

//functions to accept food request
int yes();
int no();

#endif
