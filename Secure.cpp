// security.cpp

#include "security.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "sha256.h" // Include the custom SHA-256 header

using namespace std;

void registerUser(unordered_map<string, string>& userCredentials) {
    string username, password;

    cout << "_________________________________\n";
    cout << "|-----------Register-------------\n";
    cout << "|_________________________________\n";
    cout << "Please enter username: ";
    cin >> username;

    if (userCredentials.count(username) > 0) {
        cout << "Username already exists. Please choose another.\n";
        return;
    }

    cout << "Please enter password: ";
    cin >> password;

    string hashedPassword = customSha256(password);

    // Store username and hashed password in file
    ofstream outfile("credentials.txt", ios::app);
    if (outfile.is_open()) {
        outfile << username << " " << hashedPassword << "\n";
        cout << "Registration successful\n";
        userCredentials[username] = hashedPassword; // Add to in-memory map for faster future lookups
    } else {
        cout << "Error opening file for registration.\n";
    }
    outfile.close();
}

bool loginUser(const unordered_map<string, string>& userCredentials) {
    string username, password;

    cout << "_________________________________\n";
    cout << "|-----------Login----------------|\n";
    cout << "|_________________________________\n";
    cout << "Please enter username: ";
    cin >> username;
    cout << "Please enter password: ";
    cin >> password;

    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && customSha256(password) == it->second) {
        cout << "--- Login successful ---\n";
        // Display details (excluding password for security)
        cout << "Details:\n";
        cout << "Username: " << username << endl;
        return true;
    } else {
        cout << "Incorrect credentials.\n";
        return false;
    }
}

void changePassword(unordered_map<string, string>& userCredentials) {
    string username, password, newPassword, confirmPassword;

    cout << "-----------Change password----------------\n";
    cout << "Please enter username: ";
    cin >> username;
    cout << "Enter the old password: ";
    cin >> password;

    auto it = userCredentials.find(username);
    if (it != userCredentials.end() && customSha256(password) == it->second) {
        cout << "Enter your new password: ";
        cin >> newPassword;
        cout << "Confirm your new password: ";
        cin >> confirmPassword;

        if (newPassword == confirmPassword) {
            string newHashedPassword = customSha256(newPassword);
            userCredentials[username] = newHashedPassword;

            // Update credentials in the file
            ofstream tempfile("temp.txt");
            ifstream infile("credentials.txt");
            if (tempfile.is_open() && infile.is_open()) {
                string line, storedUsername, storedHashedPassword;
                while (getline(infile, line)) {
                    istringstream iss(line);
                    iss >> storedUsername >> storedHashedPassword;

                    if (storedUsername == username) {
                        tempfile << storedUsername << " " << newHashedPassword << "\n";
                    } else {
                        tempfile << line << "\n";
                    }
                }
                infile.close();
                tempfile.close();

                remove("credentials.txt");
                rename("temp.txt", "credentials.txt");

                cout << "Password changed successfully.\n";
            } else {
                cout << "Error opening file for password change.\n";
            }
        } else {
            cout << "New passwords do not match.\n";
        }
    } else {
        cout << "Incorrect username or password.\n";
    }
}
