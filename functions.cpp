#include "functions.hpp"

#include <string>

using namespace std;

string hashing(string hashInput){

    unsigned int hash;

    string hashStr = std::to_string(hash);
    int hashStrLen = hashStr.size();

    unsigned int index = hash;
    static const string hex = "0123456789abcdef";
    string outHash;

    for(int i = 0; i < 64; i++){
        index += int(hashStr[i % hashStrLen]) + i;      //fixfix
        outHash += hex[index % 16];
    }

    cout << outHash << std::endl;

    return outHash;

    

}

void readFile(string file){

    string input, output;
    ifstream in("fileInput/" + file);
    ofstream out("fileInput/" + file);

    if(!in.is_open()){
        cout << "Failed opening " << file << endl;
        return;}
    
    string line;
    while(getline(in, line)){
        out << hashing(line) << endl;
    }

    in.close();

}

void consoleInput(){
    string input;
    cout << "Your input: ";
    cin >> input;

    hashing(input);
}

void gen_random(int length, string file) {
    
    ofstream out;
    out.open("fileInput/" + file);

    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string random_str = "";

    for (int i = 0; i < length; ++i)
    {
        random_str += characters[distribution(generator)];
    }

    out << random_str;
    out.close();




    // string temp_str;

    // static const char alphanum[] =
    //     "0123456789"
    //     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    //     "abcdefghijklmnopqrstuvwxyz";
    
    // // srand( (unsigned) time(NULL) * getpid());        // FIX THIS STUFF

    // // temp_str.reserve(length);

    // for (int i = 0; i < length; ++i) 
    //     temp_str += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    // cout << temp_str;
    
    // // out << temp_str;
    // out.close();
    
}

void fileInput(){
    int choice;
    char temp;

    cout << "Select file: " << endl
    << "---------------" << endl
    << "1. a.txt" << endl
    << "2. b.txt" << endl
    << "3. randomText1.txt" << endl
    << "4. randomText2.txt" << endl
    << "5. 1500symbols_1.txt" << endl
    << "6. 1500symbols_2.txt" << endl
    << "7. empty.txt" << endl
    << "8. konstitucija.txt" << endl;

    choiceCheck(choice, 8);

    if(choice == 5 || choice == 6){
        cout << "Do you want to generate new file? (Y/N)" << endl;
        cin >> temp;

        if(temp == 'Y' || temp == 'y'){
            if(choice == 5){
                gen_random(1500, "1500symbols_1.txt");
            }
            else gen_random(1500, "1500symbols_2.txt");
        }

    }

    if(choice == 1) readFile("a.txt");
    else if(choice == 2) readFile("b.txt");
    else if(choice == 3) readFile("randomText1.txt");
    else if(choice == 4) readFile("randomText2.txt");
    else if(choice == 5) readFile("1500symbols_1.txt");
    else if(choice == 6) readFile("1500symbols_2.txt");
    else if(choice == 7) readFile("empty.txt");
    else if(choice == 8) readFile("konstitucija.txt");

}

void comparison(){

}

int choiceCheck(int &rt, int count){				// choice checkup
	while(true){
        int t = 0;
		cin >> rt;
		
        for(int i = count; i > 0; i--){
            if(i == rt) t++;
        }

        if(t == 1) return rt;
        else cout << "Wrong input. Try again. " << endl;

	}
};