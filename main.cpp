// ------------- FILE HEADER -------------
// Author: Yusong Jin
// Assignment: 7
// Date: August 12
// Description: Student Grade Calculator
// Sources: 


// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: 7
// Participation: 100%
// Challenge: 100%
// Labs: 100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count: 1
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]: yes
// B. OUTPUT [yes/no]: yes
// C. CALCULATIONS [yes/no]: yes
// D. LOGIC and ALGORITHMS [yes/no]: yes
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]: yes
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const double ASSIGNMENT_WEIGHT = 0.6;
const double MIDTERM_WEIGHT = 0.2;
const double FINAL_WEIGHT = 0.2;

// Function prototypes
void welcome();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double final);
char calcLetterGrade(double finalScore);

int main() {
    welcome();
    
    int numAssigns = readInt("Enter the number of assignments (0 to 10): ");
    double assignAvg = assignAverage(numAssigns);
    double midterm = readScore("Enter your midterm exam score: ");
    double final = readScore("Enter your final exam score: ");
    
    double finalScore = calcFinalScore(assignAvg, midterm, final);
    char letterGrade = calcLetterGrade(finalScore);
    
    cout << fixed << setprecision(1);
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letterGrade << endl;
    cout << "Thank you for using my Grade Calculator!" << endl;
    
    return 0;
}

// Function implementations
void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int readInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (value >= 0 && value <= 10) {
            return value;
        }
        cout << "Illegal Value! Please try again!!" << endl;
    }
}

double readScore(string prompt) {
    double score;
    while (true) {
        cout << prompt;
        cin >> score;
        if (score >= 0.0 && score <= 4.0) {
            return score;
        }
        cout << "Illegal Score! Please try again!" << endl;
    }
}

double assignAverage(int numAssigns) {
    double total = 0.0;
    for (int i = 0; i < numAssigns; i++) {
        string prompt = "Enter score " + to_string(i+1) + ": ";
        total += readScore(prompt);
    }
    return (numAssigns == 0) ? 0.0 : total / numAssigns;
}

double calcFinalScore(double assignAvg, double midterm, double final) {
    return assignAvg * ASSIGNMENT_WEIGHT + midterm * MIDTERM_WEIGHT + final * FINAL_WEIGHT;
}

char calcLetterGrade(double finalScore) {
    if (finalScore >= 3.3) return 'A';
    if (finalScore >= 2.8) return 'B';
    if (finalScore >= 2.0) return 'C';
    if (finalScore >= 1.2) return 'D';
    return 'F';
}




// ------------- DESIGN -------------
/* 
Program Name: Grade Calculations

Program Description: Student Grade Calculator

Design:
A. INPUT
Define the input variables including name data type. 
int numAssignments;
double midtermScore;
double finalExamScore;

B. OUTPUT
Define the output variables including data types. 
double assignmentAverage;
double finalNumericScore;
char letterGrade;

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
Assignment Average = SUM(assignmentScores) / numAssignments
Final Numeric Score = (assignmentAverage * ASSIGN_WEIGHT) + (midtermScore * MIDTERM_WEIGHT) + (finalExamScore * FINAL_WEIGHT);
Letter Grade Conversion:
    A: 3.3 <= finalNumericScore <= 4.0
    B: 2.8 <= score < 3.3
    C: 2.0 <= score < 2.8
    D: 1.2 <= score < 2.0
    F: 0.0 < score < 1.2 

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.

BEGIN
// Constant Definitions
CONST ASSIGNMENT_WEIGHT = 0.6
CONST MIDTERM_WEIGHT = 0.2
CONST FINAL_WEIGHT = 0.2

// Function Declarations
FUNCTION welcome()
FUNCTION readInt(prompt: string) RETURNS int
FUNCTION readScore(prompt: string) RETURNS double
FUNCTION assignAverage(numAssigns: int) RETURNS double
FUNCTION calcFinalScore(assignAvg: double, midterm: double, final: double) RETURNS double
FUNCTION calcLetterGrade(finalScore: double) RETURNS char

// Main Program
BEGIN main()
    CALL welcome()
    
    SET numAssigns = CALL readInt("Enter the number of assignments (0 to 10): ")
    SET assignAvg = CALL assignAverage(numAssigns)
    SET midterm = CALL readScore("Enter your midterm exam score: ")
    SET final = CALL readScore("Enter your final exam score: ")
    
    SET finalScore = CALL calcFinalScore(assignAvg, midterm, final)
    SET letterGrade = CALL calcLetterGrade(finalScore)
    
    PRINT "Your Final Numeric score is " + finalScore (1 decimal place)
    PRINT "Your Final Grade is " + letterGrade
    PRINT "Thank you for using my Grade Calculator!"
END

// Function Implementations
FUNCTION welcome()
    PRINT "Welcome to my Final Grade Calculator!"
    PRINT "Please enter the following information..."
    PRINT "The number of assignments must be between 0 and 10."
    PRINT "All scores entered must be between 0 and 4."
END FUNCTION

FUNCTION readInt(prompt)
    LOOP
        PRINT prompt
        READ value
        IF value >= 0 AND value <= 10 THEN
            RETURN value
        END IF
        PRINT "Illegal Value! Please try again!!"
    END LOOP
END FUNCTION

FUNCTION readScore(prompt)
    LOOP
        PRINT prompt
        READ score
        IF score >= 0.0 AND score <= 4.0 THEN
            RETURN score
        END IF
        PRINT "Illegal Score! Please try again!"
    END LOOP
END FUNCTION

FUNCTION assignAverage(numAssigns)
    SET total = 0.0
    FOR i FROM 0 TO numAssigns-1
        SET prompt = "Enter score " + (i+1) + ": "
        SET total = total + CALL readScore(prompt)
    END FOR
    IF numAssigns == 0 THEN
        RETURN 0.0
    ELSE
        RETURN total / numAssigns
    END IF
END FUNCTION

FUNCTION calcFinalScore(assignAvg, midterm, final)
    RETURN assignAvg*ASSIGNMENT_WEIGHT + midterm*MIDTERM_WEIGHT + final*FINAL_WEIGHT
END FUNCTION

FUNCTION calcLetterGrade(finalScore)
    IF finalScore >= 3.3 THEN
        RETURN 'A'
    ELSE IF finalScore >= 2.8 THEN
        RETURN 'B'
    ELSE IF finalScore >= 2.0 THEN
        RETURN 'C'
    ELSE IF finalScore >= 1.2 THEN
        RETURN 'D'
    ELSE
        RETURN 'F'
    END IF
END FUNCTION
END


SAMPLE RUNS
Copy from assignment document.
Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 6
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 3.3
Enter score 5: 3.1
Enter score 6: 2.5
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.4
Your Final Grade is A
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 3
Enter score 1: 3 
Enter score 2: 4 
Enter score 3: 2.5 
Enter your midterm exam score: 2.5
Enter your final exam score: 2
Your Final Numeric score is 2.8
Your Final Grade is B
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 12
Illegal Value! Please try again!!
Enter the number of assignments (0 to 10): 5
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 5.5
Illegal Score! Please try again!
Enter score 4: 3.5
Enter score 5: 3.1
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.5
Your Final Grade is A
Thank you for using my Grade Calculator!
*/