# Simple Date-Event Database

This project is a simple database system that allows you to store and query events associated with specific dates. You can add events, print all events, and find or remove events based on conditions related to dates and event descriptions.

## Project Structure

- `main.cpp`: The main entry point of the application.
- `database.h`, `database.cpp`: Contains the `Database` class, which manages the storage and retrieval of events.
- `date.h`, `date.cpp`: Defines the `Date` class for representing and manipulating dates.
- `condition_parser.h`, `condition_parser.cpp`: Responsible for parsing query conditions.
- `node.h`, `node.cpp`: Defines the classes for representing the structure of query conditions (e.g., logical operations, date/event comparisons).
- `token.h`, `token.cpp`: Likely used by the parser for tokenizing input strings.
- `Makefile`: Contains instructions for building the project.
- `*.test.cpp`, `test_*.h`: Files related to unit testing the various components.
- `data.exe`: The compiled executable (after building the project).

## Building the Project

To build the project, you can use the provided `Makefile`. Open your terminal, navigate to the project's root directory, and run the following command:

```bash
make
```

This will compile the source code and create an executable file, typically named `data.exe`.

## Running the Project

After building the project, you can run the executable (e.g., `data.exe`) from your terminal. The program reads commands from standard input.

### Available Commands

- **Add `YYYY-MM-DD event_description`**: Adds an event with the given date and description to the database.
  - Example: `Add 2023-10-27 Meeting with team`
- **Print**: Prints all events currently stored in the database, sorted by date.
- **Del `condition`**: Deletes events from the database that match the specified `condition`. Prints the number of entries removed.
  - Example: `Del date == 2023-10-26`
- **Find `condition`**: Finds and prints events from the database that match the specified `condition`. Prints the number of entries found.
  - Example: `Find event != "Holiday"`
- **Last `YYYY-MM-DD`**: Prints the last event that occurred on or before the specified date. If no such event exists, it prints "No entries".
  - Example: `Last 2023-11-01`

The program will continue to accept commands until the input stream is closed (e.g., by pressing Ctrl+D on Linux/macOS or Ctrl+Z on Windows).

## Query Language for `Find` and `Del` Commands

The `Find` and `Del` commands use a simple query language to specify conditions for matching events. Conditions can be applied to dates or event descriptions.

### Structure

A condition can be:

1.  **A date comparison**: `date <operator> YYYY-MM-DD`
    - Example: `date >= 2023-01-01`
2.  **An event string comparison**: `event <operator> "event_string"`
    - Example: `event != "Cancelled"`
3.  **A logical combination of two other conditions**: `(<condition1>) <logical_op> (<condition2>)`
    - Example: `(date == 2023-10-27) AND (event == "Meeting")`

### Operators

-   **Comparison Operators (`<operator>`)**:
    -   `<`: Less than
    -   `<=`: Less than or equal to
    -   `>`: Greater than
    -   `>=`: Greater than or equal to
    -   `==`: Equal to
    -   `!=`: Not equal to
-   **Logical Operators (`<logical_op>`)**:
    -   `AND`: Logical AND
    -   `OR`: Logical OR

### Examples of Conditions:

-   `date == 2024-01-01`
-   `event == "Birthday Party"`
-   `(date >= 2023-01-01) AND (date <= 2023-12-31)`
-   `(event == "Holiday") OR (event == "Vacation")`
-   `(date < 2023-06-01) AND ((event == "Project A") OR (event == "Project B"))`

**Note:** When using event strings with spaces, enclose them in double quotes, for example: `event == "My Event"`

## Running Tests

The project includes a suite of unit tests to verify the correctness of its components. The tests are defined in files like `condition_parser_test.cpp`, `test_db.h`, and utilize `test_runner.h` for execution.

To run all tests:
1.  Uncomment the `TestAll();` line in the `main()` function within `main.cpp`.
2.  Recompile the project using `make`.
3.  Run the executable (e.g., `./data.exe`).

The test results will be printed to the console.
