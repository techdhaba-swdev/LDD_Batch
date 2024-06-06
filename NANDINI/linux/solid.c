1. Single Responsibility Principle :
   - The user interface (menu) is separated from the directory operations.
   - The showMenu function is responsible to  the user interaction.

2. Open/Closed Principle :
   - The DirectoryOperations structure allows the code to be extended with new operations without modifying existing code.

3. Liskov Substitution Principle:
   - Since this is not an object-oriented language, we ensure functions work correctly with the Directory type.

4. Interface Segregation Principle :
   - The operations are split into small, specific functions (add, search, and display).

5. Dependency Inversion Principle:
   - The showMenu function depends on the DirectoryOperations abstraction rather than the concrete implementations of the operations.
