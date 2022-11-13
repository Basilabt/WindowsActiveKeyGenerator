#include<iostream>
#include<string>
#include<iomanip>
using namespace std;



// Dec.

void printScreenTitle(string);
void runProgram(void);
short readNumberOfKeys(void);
bool isValidKeysNumber(short);
void makeSound(void);
void generateActivationKeys(short);
void printActivationKey(short,string);
string generateKey(void);
char getChar(void);
void appendDash(short,string&);
short generateRandomNumber(short,short);
char readConfirmationAnswer(short);

int main() {
    
    srand((unsigned)time(NULL));
    

    runProgram();
    
    return 0 ;
}

// Def.

void runProgram() {

    printScreenTitle("Windows Active Key Generator");
    
    short numberOfKeys = readNumberOfKeys();
    
    if(toupper(readConfirmationAnswer(numberOfKeys)) == 'Y') {
        generateActivationKeys(numberOfKeys);
    }
    
    cout << "\nPress Any Key To Exit" << endl;
    system("pause>0");
        
}

void printScreenTitle(string title) {
    cout << "==================================================================" << endl;
    cout << "\t"<< title << endl;
    cout << "==================================================================" << endl;
}


short readNumberOfKeys() {
    
    short number = 0 ;
    
    cout << "Enter Number Of Keys To Generate  ? ";
    cin >> number;
    cout << "\n";
    
    while(!isValidKeysNumber(number)) {
        makeSound();
        cout << "Invalid Number , Enter Number Of Keys To Generate  ? ";
        cin >> number;
        cout << "\n";
    }
     
    
    return number;
}

bool isValidKeysNumber(short number) {
    return number >= 1 ? number <= 32000 : false;
}

void makeSound() {
    cout << "\a";
}


char readConfirmationAnswer(short numberOfKeys) {
    
    char answer = 'n';
    
    cout << "Are You Sure You Want To Generate " << numberOfKeys << " Activation Key ? [ Y | N ] ? ";
    cin >> answer;
    
    return answer;
}

void generateActivationKeys(short numberOfKeys) {
    
    cout << "\n\n";
    
    string key = "";
    
    for( short i=1 ; i<=numberOfKeys ; i++) {
        
        key = generateKey();
        
        printActivationKey(i,key);
        
    }
}

string generateKey() {
    
    const short keyCharachters = 25;
    
    string key = "";
    
    
    for(short i=1 ; i<= keyCharachters ; i++) {
        
        key += getChar();
        
        appendDash(i,key);
        
    }
    
    
    return key.substr(0,key.length()-1);
}

char getChar() {
    
    // A -- Z : ASCII ( 65 -- 90 )
    // 0 -- 9 : ASCII ( 48 -- 57 )
    
    // random Number To Choose Between a Char or Number.
    // between ( 0 & 4 ) 3 even numbers that means more probability to get a char over a number.
    short randomNumber = generateRandomNumber(0,4);
    
    return (randomNumber%2==0) ? char(generateRandomNumber(65,90)) : char(generateRandomNumber(48,57));
    
}

short generateRandomNumber(short from , short to) {
    return rand() % ( to - from + 1 ) + from ;
}

void appendDash(short charNumber , string& key) {
    if(charNumber % 5 == 0)
        key += "-";
}

void printActivationKey(short number , string key) {
    cout << left << setw(2) << number << ") " << "Activation Key: " << key << endl;
}
