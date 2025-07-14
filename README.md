# 🏥 Clinic Management System (C Project)

A simple console-based clinic management system written in C. Built as a modular project with `main`, `logic`, and `config` files using static arrays.

---

## 🧩 Features
- Admin/User modes with separate access levels
- Add, edit, and view patient records
- Book and cancel time slots (5 predefined slots)
- View today’s reservations
- Admin login with 3 password attempts

---

## 🛠 Technologies Used
- Language: C
- Tools: GCC compiler, Makefile
- Structure: Modular — separate header files, source code, and config

---

## 📁 File Structure
```
Clinic_management_system/
├── include/
│   ├── CLINIC_config.h         # Configuration constants (e.g. MAX_SLOTS, PASSWORD)
│   └── CLINIC_interface.h      # Structs, enums, and function declarations
│
├── src/
│   ├── CLINIC_main.c           # Main menu and user/admin mode handling
│   └── CLINIC_program.c        # Core logic: add/edit/view patients, reservation system
│
├── Makefile                    # For compiling the whole project easily
└── README.md                   # Project documentation (this file)
```
