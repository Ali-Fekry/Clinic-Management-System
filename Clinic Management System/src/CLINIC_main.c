#include <stdio.h>
#include "CLINIC_interface.h"

int main() {
    char mode;
    int choice;
    int trials = 3;
    int entered_pass;

    while (1) 
	{
        printf("\nChoose mode: A/a (Admin), U/u (User), E/e (Exit): ");
        scanf(" %c", &mode);

        if (mode == 'A' || mode == 'a') 
		{
            while (trials) 
			{
                printf("Enter admin password: ");
                scanf("%d", &entered_pass);
                if (entered_pass != ADMIN_PASSWORD) 
				{
					trials--;
					printf("Incorrect password. Attempts left: %d\n", trials);
				}
				else
				{
					break;
				}
            }
            if (trials == 0) 
			{
                printf("Access denied.\n");
                return 0;
            }

            printf("\nWelcome to admin mode, please choose one of the following features:\n");
            printf("1. Add Patient\n2. Edit Patient\n3. Reserve Slot\n4. Cancel Reservation\n5. Exit\n");
            scanf("%d", &choice);
            switch (choice) 
			{
                case ADD_PATIENT: 
				{
					AddPatient(); 
					break;
				}
                case EDIT_PATIENT: 
				{
					EditPatient();
					break;
				}
                case GET_RESERVATION: 
				{
					ReserveSlot(); 
					break;
				}
                case CANCEL_RESERVATION: 
				{
					CancelReservation(); 
					break;
				}
                case ADMIN_EXIT: 
				{
					return 0;
				}
                default: 
				{
					printf("Invalid choice.\n");
				}
            }
        } 
		else if (mode == 'U' || mode == 'u') 
		{
            printf("\nwelcome to user mode, please choose one of the followig features:\n1. View Patient Record\n2. View Reservations\n");
            scanf("%d", &choice);
            switch (choice) 
			{
                case VIEW_PATIENT_RECORD: 
				{
					ViewPatientRecord();
					break;
				}
                case VIEW_RESERVATIONS: 
				{
					ViewReservations(); 
					break;
				}
                default: 
				{
					printf("Invalid choice.\n");
				}
            }
        } 
		else if (mode == 'E' || mode == 'e') 
		{
            printf("Exiting...\n");
            return 0;
        } else 
		{
            printf("Invalid mode.\n");
        }
    }
}
