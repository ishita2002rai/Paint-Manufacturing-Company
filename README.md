# Paint Manufacturing Company

**Paint Manufacturing Company** is a console-based project developed in C++ that simulates a simple management system for handling paint products and orders. It provides functionality for both administrators and customers, enabling product addition, order placement, and inventory display.

## 🎨 Features

- **Admin Functionalities**:
  - Add new paint products
  - Delete or update existing products
  - View all available paints
- **Customer Functionalities**:
  - View products
  - Place an order

## 🛠️ Prerequisites

- C++ Compiler (GCC, MinGW, or similar)

## 📦 Installation

1. **Clone the Repository**:

```bash
git clone https://github.com/ishita2002rai/Paint-Manufacturing-Company.git
cd Paint-Manufacturing-Company
```

2. **Compile the Source Code**:

```bash
g++ paint_project.cpp -o paint_project
```

3. **Run the Application**:

```bash
./paint_project
```

On Windows:

```bash
paint_project.exe
```

## 📁 Project Structure

```
Paint-Manufacturing-Company/
├── paint_project.cpp     # Main source code
├── paint.txt             # Product data file
├── order.txt             # Orders file
└── README.md             # Project documentation
```

## 📝 Notes

- Ensure `paint.txt` and `order.txt` exist or are created in the same directory.
- The program operates entirely via console prompts.

