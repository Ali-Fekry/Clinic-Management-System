#ifndef CLINIC_INTERFACE_H
#define CLINIC_INTERFACE_H

#include "CLINIC_config.h"

// Patient structure
typedef struct {
    char name[100];
    int age;
    char gender;
    int ID;
} Patient;

// Time slot structure
typedef struct {
    int ID;
    char time[20];
    int reserved;
} Slot;

// Mode choice enums
enum AdminOptions {
    ADD_PATIENT = 1,
    EDIT_PATIENT,
    GET_RESERVATION,
    CANCEL_RESERVATION,
    ADMIN_EXIT
};

enum UserOptions {
    VIEW_PATIENT_RECORD = 1,
    VIEW_RESERVATIONS
};

// Global arrays
extern Patient patients[MAX_PATIENTS];
extern Slot slots[MAX_SLOTS];
extern int patient_count;

// Function declarations
void AddPatient(void);
void EditPatient(void);
void ViewPatientRecord(void);
void DisplayAvailableSlots(void);
void ReserveSlot(void);
void CancelReservation(void);
void ViewReservations(void);

#endif
