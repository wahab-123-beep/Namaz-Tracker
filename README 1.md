# Namaz Tracker - C++ OOP Project

## About the Project

Namaz Tracker is a console-based application developed in C++ using Object-Oriented Programming (OOP) concepts. It helps users record the daily status of the five prayers: Fajr, Zuhar, Asr, Maghrib, and Isha.

The application displays motivational messages for prayer statuses and stores prayer records in a text file.

## Features

- Record the date and status of each of the five daily prayers.
- Use three prayer statuses: `read`, `qaza`, and `skip`.
- Display a motivational message for each prayer.
- Show a summary of prayer statuses for the entered day.
- Save prayer records to `namaz.txt`.
- View saved records through the Admin option.
- Clear saved records using the Reset File option.
- Enter multiple daily records in one session.

## OOP Concepts Used

- **Classes and Objects:** `Motivation`, `PrayerRecord`, `User`, `RegularUser`, and `Admin`.
- **Inheritance:** `RegularUser` and `Admin` inherit from the `User` base class.
- **Abstraction:** `User` defines the pure virtual function `interact()`.
- **Polymorphism:** The `interact()` function is overridden in derived classes and called through a `User` pointer.
- **Encapsulation:** Prayer information and record-related operations are grouped in the `PrayerRecord` class.
- **File Handling:** `fstream` operations are used to save, read, and clear records in `namaz.txt`.

## Technologies

- C++
- Standard C++ Library
- Text-file handling (`ifstream` and `ofstream`)

## How to Run

1. Download or clone this repository.
2. Open `Namaz Tracker Project.cpp` in a C++ IDE or editor.
3. Compile the source file using a C++ compiler.
4. Run the compiled program.
5. Select an option from the menu:
   - `1` — Regular User: enter prayer records.
   - `2` — Admin: display saved records.
   - `3` — Reset File: clear saved records.

### Example Compilation

Using g++:

```bash
g++ "Namaz Tracker Project.cpp" -o namaz-tracker
```

Run on Windows:

```bash
namaz-tracker.exe
```

Run on Linux/macOS:

```bash
./namaz-tracker
```

## Data Storage

Prayer records are appended to a local text file named `namaz.txt` in the program's working directory. Keep this file if you want to retain saved records.

**Note:** The current version is a console-based academic project. It does not include a graphical user interface or a database.

## Future Improvements

- Validate prayer status input.
- Add date-based search and record summaries.
- Improve record formatting and error handling.
- Add a more structured menu and user authentication.

## Author

Developed as a C++ Object-Oriented Programming (OOP) project.
