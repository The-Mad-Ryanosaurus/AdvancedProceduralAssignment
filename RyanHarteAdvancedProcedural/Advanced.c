#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct company {

	int companyReg;
	char companyName[30];
	char country[30];
	int yearFounded;
	char email[30];
	char contactName[30];
	int numEmployees;
	float averageTurnover;
	float lastOrder;
	char vatRegistered[5];

	struct company* NEXT;
}companyT;

struct company* createNode();

void loginUser(void);


void addCompany(struct company** top);
void displayCompanyList(companyT* top, int searchID);
int displaySpecificCompany(companyT* top, int searchID);
void updateCompany(companyT* top, int searchID);
void deleteCompany(companyT** top, int searchID);
void outputToFile(struct company* top);
void readFromFile(companyT** top);



void main() {

	companyT* headPtr = NULL;
	companyT* newNode;
	companyT* temp;

	char username[10];
	char password[10];

	char username1[10];
	char password1[10];

	char ch = 0;

	int choice;
	int searchID = 0;
	int result = 0;
	int i;
	int correct = -1;
	int credentialsUser;
	int credentialsPass;
	
	FILE* lPtr;

	lPtr = fopen("login.txt", "r");

	printf("Enter Username:\n");
	gets(username1);
	printf("Enter Password:\n");
	//gets(password1);
	for ( i = 0; i < 10; i++) {

		ch = getch();
		if (ch == 13) 
			break;
		
		password1[i] = ch;
		ch = '*';
		printf("%c", ch);
	}
	password1[i] = '\0';
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		fscanf(lPtr, "%s %s", username, password);

		credentialsUser = strcmp(username, username1);
		credentialsPass = strcmp(password, password1);

		if (credentialsUser == 0 && credentialsPass == 0) {
			printf("\n---Login Successful---\n");
			correct = 1;
			break;
		}
	}

	if (correct == 1) {
		readFromFile(&headPtr);


		printf("Please enter 1 to add a Company to the list\n");
		printf("Please enter 2 to display all Companies Listed\n");
		printf("Please enter 3 to display a specific Company and its details\n");
		printf("Please enter 4 to update a specific Company\n");
		printf("Please enter 5 to delete a specific Company\n");
		printf("Please enter 6 to print a Client Report for all Companies\n");

		scanf("%d", &choice);



		while (choice != -1) {
			if (choice == 1) {
				addCompany(&headPtr);
			}
			else if (choice == 2) {
				displayCompanyList(headPtr, searchID);
			}
			else if (choice == 3) {
				temp = headPtr;
				printf("Enter Company Registration Number for Details\n");
				scanf("%d", &searchID);

				result = displaySpecificCompany(headPtr, searchID);
			}
			else if (choice == 4) {
				temp = headPtr;
				printf("Enter Company Registration Number for Update\n");
				scanf("%d", &searchID);

				updateCompany(headPtr, searchID);
			}
			else if (choice == 5) {
				temp = headPtr;
				printf("Enter Company Resistration Number for Deletion\n");
				scanf("%d", &searchID);

				deleteCompany(&headPtr, searchID);
			}
			else if (choice == 6) {
				outputToFile(headPtr);
			}


			printf("Please enter 1 to add a Company to the list\n");
			printf("Please enter 2 to display all Companies Listed\n");
			printf("Please enter 3 to display a specific Company and its details\n");
			printf("Please enter 4 to update a specific Company\n");
			printf("Please enter 5 to delete a specific Company\n");
			printf("Please enter 6 to print all Company Information to a text file\n");
			scanf("%d", &choice);
		}
		outputToFile(headPtr);
	}
	else


	printf("\n---Username and Password Incorrect---\n");
	printf("\n---Exit Application and try again---\n");

	fclose(lPtr);
	return;
}



void addCompany(struct company** top) {
	struct company* temp;

	temp = *top;

	//struct company* newNode;
	if (*top == NULL) {

		companyT* newNode = (struct company*)malloc(sizeof(struct company));

		printf("Enter Company Registration Number\n");
		scanf("%d", &newNode->companyReg);
		printf("Enter Company Name\n");
		scanf("%s", newNode->companyName);
		printf("Enter Company Country of Operation\n");
		scanf("%s", newNode->country);
		printf("Enter Company Founded Year\n");
		scanf("%d", &newNode->yearFounded);
		printf("Enter Company Email\n");
		scanf("%s", newNode->email);
		printf("Enter Company Contact Name\n");
		scanf("%s", newNode->contactName);
		printf("Enter Company Workforce - Employees working for the Company\n");
		scanf("%d", &newNode->numEmployees);
		printf("Enter Company Average Annual Turnover\n");
		scanf("%f", &newNode->averageTurnover);
		printf("Enter Company Last Order Amount\n");
		scanf("%f", &newNode->lastOrder);
		printf("Enter if Company is VAT Registered - YES or NO\n");
		scanf("%s", newNode->vatRegistered);

		newNode->NEXT = NULL;

		*top = newNode;
		temp = *top;
		return;
	}
	else {
		while (temp != NULL) {
			if (temp->NEXT == NULL) {

				companyT* newNode = (struct company*)malloc(sizeof(struct company));

				printf("Enter Company Registration Number\n");
				scanf("%d", &newNode->companyReg);
				printf("Enter Company Name\n");
				scanf("%s", newNode->companyName);
				printf("Enter Company Country of Operation\n");
				scanf("%s", newNode->country);
				printf("Enter Company Founded Year\n");
				scanf("%d", &newNode->yearFounded);
				printf("Enter Company Email\n");
				scanf("%s", newNode->email);
				printf("Enter Company Contact Name\n");
				scanf("%s", newNode->contactName);
				printf("Enter Company Workforce - Employees working for the Company\n");
				scanf("%d", &newNode->numEmployees);
				printf("Enter Company Average Annual Turnover\n");
				scanf("%f", &newNode->averageTurnover);
				printf("Enter Company Last Order Amount\n");
				scanf("%f", &newNode->lastOrder);
				printf("Enter if Company is VAT Registered - YES or NO\n");
				scanf("%s", newNode->vatRegistered);

				newNode->NEXT = NULL;


				temp->NEXT = newNode;
				return;
			}
		}
		temp = temp->NEXT;

	}
}

void displayCompanyList(companyT* top, int searchID) {

	struct company* temp;

	temp = top;

	while (temp != NULL) {

		printf("Company Registration Number: %d\nCompany Name: %s\nCompany Country of Operation: %s\nCompany Founded: %d\n", temp->companyReg, temp->companyName, temp->country, temp->yearFounded);
		printf("Company Email: %s\nCompany Client Contact: %s\nCompany Workforce: %d\nCompany Avg Annual Turnover: %.2f\nCompany Last Order: %.2f\nCompany VAT Registered: %s\n", temp->email, temp->contactName, temp->numEmployees, temp->averageTurnover, temp->lastOrder, temp->vatRegistered);
		temp = temp->NEXT;
	}
}

int displaySpecificCompany(companyT* top, int searchID) {

	companyT* temp = top;
	int result = -1;
	int count = 0;
	while (temp != NULL) {
		if (temp->companyReg == searchID) {
			result = count;
			printf("Company Registration Number: %d\nCompany Name: %s\nCompany Country of Operation: %s\nCompany Founded: %d\n", temp->companyReg, temp->companyName, temp->country, temp->yearFounded);
			printf("Company Email: %s\nCompany Client Contact: %s\nCompany Workforce: %d\nCompany Avg Annual Turnover: %.2f\nCompany Last Order: %.2f\nCompany VAT Registered: %s\n", temp->email, temp->contactName, temp->numEmployees, temp->averageTurnover, temp->lastOrder, temp->vatRegistered);
			return;
		}
		count++;
		temp = temp->NEXT;
	}
	printf("Company %d is not found in this Database\n", searchID);
	return result;
}

void updateCompany(companyT** top, int searchID) {

	companyT* temp = top;
	int result = -1;
	int count = 0;
	while (temp != NULL) {

		if (temp->companyReg == searchID) {
			result = count;

			printf("Enter Company Registration Number\n");
			scanf("%d", &temp->companyReg);
			printf("Enter Company Name\n");
			scanf("%s", temp->companyName);
			printf("Enter Company Country of Operation\n");
			scanf("%s", temp->country);
			printf("Enter Company Founded Year\n");
			scanf("%d", &temp->yearFounded);
			printf("Enter Company Email\n");
			scanf("%s", temp->email);
			printf("Enter Company Contact Name\n");
			scanf("%s", temp->contactName);
			printf("Enter Company Workforce - Employees working for the Company\n");
			scanf("%d", &temp->numEmployees);
			printf("Enter Company Average Annual Turnover\n");
			scanf("%f", &temp->averageTurnover);
			printf("Enter Company Last Order Amount\n");
			scanf("%f", &temp->lastOrder);
			printf("Enter if Company is VAT Registered - YES or NO\n");
			scanf("%s", temp->vatRegistered);
			return;
		}
		count++;
		temp = temp->NEXT;
	}
}

void deleteCompany(companyT** top, int searchID) {

	struct company* temp1 = *top;
	struct company* temp2 = *top;

	while (temp1 != NULL) {

		if (temp1->companyReg == searchID) {

			printf("Company %d has been selected for Deletion\n", searchID);

			if (temp1 == temp2) {
				//if node is the head of the list
				*top = (*top)->NEXT;
				free(temp1);
			}
			else {
				//temp1 = node to delete 
				//temp2 = node previous to temp1
				temp2->NEXT = temp1->NEXT;
				free(temp1);
			}

			printf("Company %d Successfully Deleted From Database\n", searchID);
			return;

		}
		temp2 = temp1;
		temp1 = temp1->NEXT;

	}
	printf("Company %d is not found in this database\n", searchID);

}

void outputToFile(struct company* top) {

	struct company* temp;
	FILE* fp;
	temp = top;

	fp = fopen("company.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "%d\t", temp->companyReg);
			fprintf(fp, "%s\t", temp->companyName);
			fprintf(fp, "%s\t", temp->country);
			fprintf(fp, "%d\t", temp->yearFounded);
			fprintf(fp, "%s\t", temp->email);
			fprintf(fp, "%s\t", temp->contactName);
			fprintf(fp, "%d\t", temp->numEmployees);
			fprintf(fp, "%.2f\t", temp->averageTurnover);
			fprintf(fp, "%.2f\t", temp->lastOrder);
			fprintf(fp, "%s\n", temp->vatRegistered);
		}
		temp = temp->NEXT;
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

void readFromFile(companyT** top) {

	FILE* ptr;
	companyT* temp;

	
	ptr = fopen("company.txt", "r");
	fscanf(ptr, "\n");

	while (!feof(ptr)) {
		companyT* newNode = (companyT*)malloc(sizeof(companyT));

		fscanf(ptr, "%d", &newNode->companyReg);
		fscanf(ptr, "%s", newNode->companyName);
		fscanf(ptr, "%s", newNode->country);
		fscanf(ptr, "%d", &newNode->yearFounded);
		fscanf(ptr, "%s", newNode->email);
		fscanf(ptr, "%s", newNode->contactName);
		fscanf(ptr, "%d", &newNode->numEmployees);
		fscanf(ptr, "%f", &newNode->averageTurnover);
		fscanf(ptr, "%f", &newNode->lastOrder);
		fscanf(ptr, "%s", newNode->vatRegistered);
		fscanf(ptr, "\n");


		newNode->NEXT = NULL;

		if (*top == NULL) {
			*top = newNode;
			temp = *top;
		}
		else {
			temp->NEXT = newNode;
		}
		temp = newNode;
	}

	if (ptr != NULL) {
		fclose(ptr);
	}

}

