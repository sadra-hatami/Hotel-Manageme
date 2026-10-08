<div align="center">

# Hotel Management
# 🏨

### A C++ console program for rooms, check-in, and checkout

A small terminal hotel desk: an admin adds rooms, a guest checks in, and checkout prints the bill. Records stay in memory for the current run.

<br>

# 👨‍💻 **Sadra Hatami**

### *Developer • Software Engineer • Creator*

<br>

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Console](https://img.shields.io/badge/Interface-Console-2C3E50?style=for-the-badge)](https://en.wikipedia.org/wiki/Command-line_interface)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](https://opensource.org/license/mit)
![Open Source](https://img.shields.io/badge/Open_Source-Project-black?style=for-the-badge&logo=github)
[![Stars](https://img.shields.io/github/stars/sadra-hatami/Hotel-Manageme?style=for-the-badge)](https://github.com/sadra-hatami/Hotel-Manageme/stargazers)

<br>

[🌐 GitHub Profile](https://github.com/sadra-hatami)
•
[📧 Email](mailto:sadra.hatami.1732@gmail.com)

</div>

---

# 📑 Table of Contents

- [About](#-about)
- [Why This Project?](#-why-this-project)
- [Key Features](#-key-features)
- [Menus](#-menus)
- [Project Structure](#-project-structure)
- [Technologies](#️-technologies)
- [Build](#-build)
- [Usage](#️-usage)
- [Notes](#-notes)
- [FAQ](#-faq)
- [Contact](#-contact)
- [License](#-license)
- [Support](#-support)

---

# 📖 About

**Hotel Management** is a console program written in C++.

The main menu splits the desk into admin and customer. Admin work adds rooms. Customer work checks availability, searches a room, checks a guest in, looks up a booking, prints a guest list, and checks a guest out.

Rooms and guests live in arrays, up to 100 of each. Nothing is written to disk, so closing the program clears the desk.

> **Tagline:** *A C++ console program for rooms, check-in, and checkout.*

---

# 🚀 Why This Project?

A first hotel program is a clean place to practice menus, structs, and a bill.

This one keeps that scope:

- Two roles, admin and customer
- Room type, size, air conditioning, and daily rent
- Check-in with an advance payment
- Checkout that shows the remaining amount and frees the room

It is a study program, not a booking website.

---

# ✨ Key Features

- 🏨 Add rooms
- 🔎 Check availability and search by type
- 🛎️ Check-in with name, address, phone, and stay length
- 🧾 Booking id and bill
- 👤 Search a guest and print a guest summary
- 🚪 Checkout and free the room
- 💻 Console menus only

---

# 🎮 Menus

**Main**

1. Operate as admin
2. Operate as customer
3. Exit

**Customer**

1. Check availability of rooms
2. Search room
3. Check-in
4. Search customer
5. Guest summary
6. Checkout
7. Back

A room is marked suite or normal, big or small, and AC or non-AC. A guest is checked in or checked out.

---

# 📁 Project Structure

```text
Hotel-Manageme/
├── Project.cpp
└── README.md
```

`Project.cpp` is the program. Do not commit a compiled `.exe`.

---

# 🛠️ Technologies

- C++
- Standard library streams and strings
- No database and no extra packages

---

# 🚀 Build

```bash
git clone https://github.com/sadra-hatami/Hotel-Manageme.git
cd Hotel-Manageme
g++ Project.cpp -o hotel
./hotel
```

On Windows, MinGW can build the same file. Run `hotel.exe` if that is the output name.

---

# ▶️ Usage

1. Build and run.
2. Add rooms as admin.
3. Switch to customer.
4. Check in, then search or check out.

Phone input in this program expects a 10-digit number.

---

# 📝 Notes

- Records are in memory only. A restart clears them.
- The repository should hold source and this README, not the binary or the original archive.
- This is a practice desk, not a hotel service.

---

# ❓ FAQ

### Does it save bookings?

No. Arrays are cleared when the program exits.

### Is this a website?

No. It is a terminal menu.

---

# 📬 Contact

**Developer:**

### Sadra Hatami

📧 [Email](mailto:sadra.hatami.1732@gmail.com)

🌐 [GitHub](https://github.com/sadra-hatami)

---

# 📄 License

This project is licensed under the **MIT License**.

---

# ⭐ Support

If this program is useful as a study sample, please consider giving it a ⭐ on GitHub.

---

<div align="center">

## Designed & Developed with ❤️ for the developer community of Iran and the world by **Sadra Hatami**

</div>
