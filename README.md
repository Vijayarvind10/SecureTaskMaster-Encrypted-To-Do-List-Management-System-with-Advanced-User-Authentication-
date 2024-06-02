# Cryptographically Secured Task Management System with Encrypted User Authentication and Encrypted Data Storage in C++

## Description

This project is a highly secure task management system designed to ensure the confidentiality and integrity of user data through advanced cryptographic techniques. Implemented in C++, this system features encrypted user authentication, secure task storage, and robust task management functionalities. The application allows users to register, log in, and manage their tasks with complete confidence in the security of their data.

## Key Features

- **User Registration and Login:** Secure user authentication using SHA-256 hashing for password storage.
- **Encrypted Task Storage:** All tasks and user data are encrypted to prevent unauthorized access.
- **Task Management:** Features for creating, editing, deleting, and viewing tasks.
- **Reminders and Notifications:** Set and manage reminders for tasks.

## Algorithms and Techniques

1. **SHA-256 Hashing Algorithm:**
   - Used for securely storing user passwords.
   - Provides a high level of security by hashing passwords before storing them, ensuring that plaintext passwords are never saved.

2. **File-Based Secure Storage:**
   - User credentials and tasks are stored in encrypted form within files.
   - Ensures that even if the files are accessed without authorization, the data remains unreadable.

3. **Custom Encryption and Decryption:**
   - Tasks and reminders are encrypted using a custom encryption algorithm before storage and decrypted upon retrieval.
   - Enhances security by ensuring that sensitive information is protected at rest.

4. **Task Management Algorithms:**
   - Efficient algorithms for adding, editing, deleting, and viewing tasks.
   - Includes features for setting and managing task reminders.



## Usage

Upon running the program, users will be prompted to register or log in. Once authenticated, they can securely create, edit, delete, and view their tasks. The system ensures that all sensitive data, including user credentials and tasks, are stored securely using encryption.

## Future Enhancements

- **Database Integration:** Replace file-based storage with a secure database to handle larger volumes of data and improve scalability.
- **Enhanced Encryption Algorithms:** Implement more advanced encryption techniques to further strengthen data security.
- **User Interface:** Develop a graphical user interface to improve user experience.
