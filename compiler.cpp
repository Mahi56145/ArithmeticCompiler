#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// Function to decode URL-encoded strings (e.g., convert %2B to +)
string urlDecode(const string& str) {
    string result;
    char ch;
    int i, ii;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == '%') {
            sscanf(str.substr(i + 1, 2).c_str(), "%x", &ii);
            ch = static_cast<char>(ii);
            result += ch;
            i += 2;
        } else if (str[i] == '+') {
            result += ' '; // Convert + to space
        } else {
            result += str[i];
        }
    }
    return result;
}

// Function to evaluate basic arithmetic expressions
double evaluateExpression(const string& expr) {
    stringstream ss(expr);
    double result, num;
    char op;

    ss >> result;  // Read first number
    while (ss >> op >> num) {  // Read operator and next number
        if (op == '+') result += num;
        else if (op == '-') result -= num;
        else if (op == '*') result *= num;
        else if (op == '/') result /= num;
    }

    return result;
}

int main() {
    cout << "Content-Type: text/html\n\n";
    cout << "<html><body>";

    // Debugging output
    cout << "<h2>Debugging Info:</h2>";

    // Read the query string from the environment
    char* query = getenv("QUERY_STRING");
    if (!query) {
        cout << "<p>Error: QUERY_STRING is NULL</p>";
    } else {
        string query_str = query;
        cout << "<p>QUERY_STRING: " << query_str << "</p>";

        // Extract expression from query
        size_t pos = query_str.find("=");
        if (pos != string::npos) {
            string encodedExpr = query_str.substr(pos + 1);
            string expr = urlDecode(encodedExpr); // Decode the expression

            cout << "<p>Encoded Expression: " << encodedExpr << "</p>";
            cout << "<p>Decoded Expression: " << expr << "</p>";

            double result = evaluateExpression(expr);
            cout << "<p>Result: " << result << "</p>";
        } else {
            cout << "<p>Error: Expression not found in query</p>";
        }
    }

    cout << "</body></html>";
    return 0;
}

