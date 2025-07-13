#include <stdio.h>
#include <string.h>
#include "CLINIC_interface.h"

Patient patients[MAX_PATIENTS];
Slot slots[MAX_SLOTS] = 
{
    {0, "2:00pm - 2:30pm", 0},
    {0, "2:30pm - 3:00pm", 0},
    {0, "3:00pm - 3:30pm", 0},
    {0, "4:00pm - 4:30pm", 0},
    {0, "4:30pm - 5:00pm", 0}
};
int patient_count = 0;

void AddPatient(void)
 {
    int count;
    printf("Enter number of new patients: ");
    scanf("%d", &count);

    for (int i = 0; i < count && patient_count < MAX_PATIENTS; i++, patient_count++) 
	{
		printf("please enter the personal information of patient %d\n",i+1);
        printf("Enter name: ");
        getchar();
        fgets(patients[patient_count].name, 100, stdin);

        printf("Enter age: ");
        scanf("%d", &patients[patient_count].age);

        printf("Enter gender (M/F): ");
        scanf(" %c", &patients[patient_count].gender);

        while (patients[patient_count].gender != 'M' && patients[patient_count].gender != 'm' && patients[patient_count].gender != 'F' && patients[patient_count].gender != 'f') 
		{
            printf("Invalid gender. Try again: ");
            scanf(" %c", &patients[patient_count].gender);
        }

        int valid = 0;
        while (!valid) 
		{
            printf("Enter 4-digit ID: ");
            scanf("%d", &patients[patient_count].ID);
            valid = 1;

            if (patients[patient_count].ID < 1000 || patients[patient_count].ID > 9999) 
			{
                printf("ID must be 4 digits.\n");
                valid = 0;
                continue;
            }

            for (int j = 0; j < patient_count; j++)
			{
				if (patients[patient_count].ID == patients[j].ID) 
				{
					printf("ID already exists.\n");
					valid = 0;
					break;
				}
			}
        }
        printf("Patient added successfully.\n");
    }
}

void EditPatient(void) 
{
    int ID;
	int ID_NotFound=1;
	while(ID_NotFound)
	{
		printf("Enter patient ID to edit: ");
		scanf("%d", &ID);
	
		for (int i = 0; i < patient_count; i++) 
		{
			if (patients[i].ID == ID) 
			{
				printf("New name: ");
				getchar();
				fgets(patients[i].name, 100, stdin);
	
				printf("New age: ");
				scanf("%d", &patients[i].age);
	
				printf("New gender (M/F): ");
				scanf(" %c", &patients[i].gender);
	
				printf("Record updated.\n");
				ID_NotFound=0;
			}
		}
		printf("ID not found.\n");
	}
}

void ViewPatientRecord(void) 
{
    int ID;
    printf("Enter patient ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < patient_count; i++) 
	{
        if (patients[i].ID == ID) 
		{
            printf("Name: %s", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", (patients[i].gender == 'M' || patients[i].gender == 'm') ? "Male" : "Female");
            return;
        }
    }
    printf("Patient not found.\n");
}

void DisplayAvailableSlots(void) 
{
    printf("Available Slots:\n");
    for (int i = 0; i < MAX_SLOTS; i++) 
	{
        if (!slots[i].reserved) 
		{
            printf("%d. %s\n", i + 1, slots[i].time);
        }
    }
}

void ReserveSlot(void) 
{
    int ID, choice;
    printf("Enter patient ID: ");
    scanf("%d", &ID);

    int exists = 0;
    for (int i = 0; i < patient_count; i++) 
	{
        if (patients[i].ID == ID) 
		{
            exists = 1;
            break;
        }
    }
    if (!exists) 
	{
        printf("Patient ID not found.\n");
        return;
    }

    DisplayAvailableSlots();
    printf("Choose slot number to reserve: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_SLOTS || slots[choice - 1].reserved) 
	{
        printf("Invalid slot.\n");
        return;
    }

    slots[choice - 1].reserved = 1;
    slots[choice - 1].ID = ID;
    printf("Slot reserved successfully.\n");
}

void CancelReservation(void) 
{
    int ID;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &ID);

    for (int i = 0; i < MAX_SLOTS; i++) 
	{
        if (slots[i].ID == ID && slots[i].reserved)
		{	
            slots[i].reserved = 0;
            slots[i].ID = 0;
            printf("Reservation cancelled.\n");
            return;
        }
    }
    printf("No reservation found.\n");
}

void ViewReservations(void)
 {
    int found = 0;
    printf("Today's reservations:\n");
    for (int i = 0; i < MAX_SLOTS; i++) 
	{
        if (slots[i].reserved) 
		{
            printf("%s for Patient ID: %d\n", slots[i].time, slots[i].ID);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("No reservations today.\n");
    }
}
