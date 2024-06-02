# SecureTaskMaster-Encrypted-To-Do-List-Management-System-with-Advanced-User-Authentication-
Description

This project is a highly secure task management system designed to ensure the confidentiality and integrity of user data through advanced cryptographic techniques. Implemented in C++, this system features encrypted user authentication, secure task storage, and robust task management functionalities. The application allows users to register, log in, and manage their tasks with complete confidence in the security of their data.
Key Features

    User Registration and Login: Secure user authentication using SHA-256 hashing for password storage.
    Encrypted Task Storage: All tasks and user data are encrypted to prevent unauthorized access.
    Task Management: Features for creating, editing, deleting, and viewing tasks.
    Reminders and Notifications: Set and manage reminders for tasks.

Algorithms and Techniques

    SHA-256 Hashing Algorithm:
        Used for securely storing user passwords.
        Provides a high level of security by hashing passwords before storing them, ensuring that plaintext passwords are never saved.

    File-Based Secure Storage:
        User credentials and tasks are stored in encrypted form within files.
        Ensures that even if the files are accessed without authorization, the data remains unreadable.

    Custom Encryption and Decryption:
        Tasks and reminders are encrypted using a custom encryption algorithm before storage and decrypted upon retrieval.
        Enhances security by ensuring that sensitive information is protected at rest.

    Task Management Algorithms:
        Efficient algorithms for adding, editing, deleting, and viewing tasks.
        Includes features for setting and managing task reminders.

How to Run

    Compile the Project:
        Use the provided tasks.join configuration to compile the project using g++.
        Ensure all necessary files (todo_main.cpp, todo_list.cpp, Secure.cpp, sha256.cpp, security.cpp, and security.h) are in the project directory.

    Run the Executable:
        Navigate to the bin directory and execute the compiled program.
        Follow the on-screen prompts to register, log in, and manage tasks.

Usage

Upon running the program, users will be prompted to register or log in. Once authenticated, they can securely create, edit, delete, and view their tasks. The system ensures that all sensitive data, including user credentials and tasks, are stored securely using encryption.
Future Enhancements

    Database Integration: Replace file-based storage with a secure database to handle larger volumes of data and improve scalability.
    Enhanced Encryption Algorithms: Implement more advanced encryption techniques to further strengthen data security.
    User Interface: Develop a graphical user interface to improve user experience.
