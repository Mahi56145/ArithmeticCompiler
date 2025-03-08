# ArithmeticCompiler

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: MAHIPAL

*INTERN ID*:CT08PBA

*DOMAIN*: C++ PROGRAMMING

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTHOSH

*OUTPUT:*
# Arithmetic Expression Compiler (Web-Based)

A simple web-based compiler to evaluate arithmetic expressions using **C++ CGI** and a **basic HTML frontend**.

---

## 📌 Features
✅ Parses and evaluates arithmetic expressions (+, -, *, /)  
✅ Works as a **CGI script** in a web server (Apache)  
✅ **Lightweight**: Uses only C++, HTML, and CSS  
✅ **Cross-platform** (Windows & Linux)

---

## 🛠️ Prerequisites
### **For Windows (XAMPP) Users:**
- Install **XAMPP** ([Download Here](https://www.apachefriends.org/index.html))
- Enable **CGI module** in `httpd.conf`

### **For Linux (Ubuntu/Debian):**
- Install Apache and enable CGI:
  ```sh
  sudo apt update && sudo apt install apache2
  sudo a2enmod cgi
  sudo systemctl restart apache2
  ```
- Ensure `/usr/lib/cgi-bin/` exists for CGI scripts.

---

## 📂 Project Structure
```
/compiler-project
│── /cgi-bin
│   ├── compiler.cpp         # C++ source code for the compiler (CGI script)
│   ├── compiler.cgi         # Compiled executable
│── /htdocs
│   ├── index.html           # Frontend HTML for user input
│   ├── styles.css           # Basic CSS styling (optional)
│   ├── script.js            # JavaScript for AJAX requests (optional)
│── /logs
│   ├── error.log            # Apache error logs
│── CMakeLists.txt           # CMake build file (optional)
│── README.md                # This file
```

---

## 🔧 Step 1: Setup Apache for CGI (Windows/Linux)

### **Windows (XAMPP)**
1. Open `C:\xampp\apache\conf\httpd.conf`
2. Find and uncomment:
   ```apache
   LoadModule cgi_module modules/mod_cgi.so
   AddHandler cgi-script .cgi
   ```
3. Restart Apache from XAMPP Control Panel.

### **Linux (Ubuntu/Debian)**
1. Enable CGI:
   ```sh
   sudo a2enmod cgi
   sudo systemctl restart apache2
   ```

---

## 🏗️ Step 2: Compile the CGI Script
1. Navigate to `cgi-bin/` directory:
   ```sh
   cd compiler-project/cgi-bin/
   ```
2. Compile the C++ CGI script:
   ```sh
   g++ compiler.cpp -o compiler.cgi
   ```
3. Move `compiler.cgi` to the CGI directory:
   - **Windows (XAMPP):** Copy `compiler.cgi` to `C:\xampp\cgi-bin\`
   - **Linux:**
     ```sh
     sudo mv compiler.cgi /usr/lib/cgi-bin/
     ```

---

## 🌐 Step 3: Run the Project
1. **Start Apache**:
   - Windows (XAMPP): Open XAMPP Control Panel → **Start Apache**.
   - Linux:
     ```sh
     sudo systemctl restart apache2
     ```
2. **Access the Frontend**:
   Open in a browser:
   ```
   http://localhost/index.html
   ```
3. **Test Expression Evaluation**:
   - Enter an arithmetic expression (e.g., `10 + 2`).
   - Click "Evaluate".
   - Should return: `Result: 12`

---

## 🔍 Step 4: Debugging Issues

### **1. Getting 404 Not Found?**
- Ensure Apache is running.
- Check if `compiler.cgi` is inside `cgi-bin/`.
- Try accessing it directly:
  ```
  http://localhost/cgi-bin/compiler.cgi?expr=10+%2B+2
  ```

### **2. `chmod` or `popen()` Errors?**
- On **Windows**, `chmod` is not required.
- On **Linux**, grant execute permissions:
  ```sh
  sudo chmod +x /usr/lib/cgi-bin/compiler.cgi
  ```

### **3. Wrong Output (e.g., `10+2 = 255`)?**
- Ensure you're using `stringstream` for evaluation (not `bc`).
- Check your C++ parsing logic.

---

## 🚀 Future Improvements
✅ Support parentheses `()` for expressions  
✅ Support **exponentiation (`^`)**  
✅ Improve frontend UI with **AJAX and JavaScript**

---

## 📜 License
This project is **open-source** and free to use.

---

## 💬 Need Help?
Feel free to **open an issue** or **reach out!** 🎯

