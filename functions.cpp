#include "functions.hpp"
#include <string>

using namespace std;
using namespace std::chrono;


string hashing(string hashInput){

    // hash initialization      // bad
    // int hash[64];

    /*
    string initial_hash = "791b2b977a2abe0384319f25b6fcf436f0da44bdeeef143a34171ef1fdba7087"; // 64

    //if(initial_hash.length() != 64){
    //    cout << "initial_hash length is not 64." << endl
    //    << "Exiting program.";
    //    return 0;
    //}

    for(int i = 0; i < 64; i++){        // 0 - 15
        hash[i] = 0;
        if(isdigit(initial_hash[i])) hash[i] = (int)initial_hash[i] - 48; // 48 = 0 in ascii
        else hash[i] = (int)initial_hash[i] - 87; // 97 = a in ascii (-10 num)

        // cout << hash[i] << " ";
    }

    */


    // hashing function     //working
    if(hashInput == " ") return "961b6dd3ede3cb8ecbaacbd68de040cd78eb2ed5889130cceb4c49268ea4d506";

    const int initial_hash_seed = 9464;                 // initial seed
    unsigned int initial_hash = initial_hash_seed;

    for(int i = 0; i <= hashInput.length(); i++){       // random h
        initial_hash = (initial_hash * 47) + int(hashInput[i]) + hashInput.length() * 27;
    }


    string initial_hash_str = to_string(initial_hash);      // 4 choosing char
    int initial_hash_str_size = initial_hash_str.size();
    
    const string hex = "0123456789abcdef";          // hex str
    string hashOutput;

    unsigned int random_var = initial_hash * initial_hash_seed;     // random variable
    int random_num = 17;

    for(int i = 0; i < 64; i++){        // for 64c // randomizing var // creating hashout
        random_var += initial_hash_str[i * random_num % initial_hash_str_size] + initial_hash_seed * i * 3;
        hashOutput += hex[random_var % 16];
        random_num = random_num * 3 - 11;
    }

    // cout << hashOutput;

    return hashOutput;

}

void readFile(string file){

    string input, output;
    ifstream in("fileInput/" + file + ".txt");
    ofstream out("fileOutput/" + file + "_hash.txt");

    if(!in.is_open()){
        cout << "Failed opening " << file << endl;
        return;}

    if (file == "empty"){           // if file is empty
        out << "961b6dd3ede3cb8ecbaacbd68de040cd78eb2ed5889130cceb4c49268ea4d506";
    }
    
    string line;

    // high_resolution_clock::time_point t1 = high_resolution_clock::now();    // konstitucijai

    while(getline(in, line)){
        out << hashing(line) << endl;
    }

    // cout << "failo 'konstitucija.txt' hash'avimo laikas: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    in.close();
    out.close();

}

void consoleInput(){
    string input;
    cout << "Your input: ";
    cin >> input;

    cout << hashing(input);

}

void gen_random(int length, string file) {
    
    ofstream out;
    out.open("fileInput/" + file + ".txt");

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

    // ---

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
    << "8. konstitucija.txt" << endl
    << "9. all files" << endl
    << "----------------" << endl;

    choiceCheck(choice, 9);

    if(choice == 5 || choice == 6){
        cout << "Do you want to generate new file? (Y/N)" << endl;
        cin >> temp;

        if(temp == 'Y' || temp == 'y'){
            if(choice == 5){
                gen_random(1500, "1500symbols_1");
            }
            else gen_random(1500, "1500symbols_2");
        }

    }

    if(choice == 1) readFile("a");
    else if(choice == 2) readFile("b");
    else if(choice == 3) readFile("randomText1");
    else if(choice == 4) readFile("randomText2");
    else if(choice == 5) readFile("1500symbols_1");
    else if(choice == 6) readFile("1500symbols_2");
    else if(choice == 7) readFile("empty");
    else if(choice == 8) readFile("konstitucija");
    else if(choice == 9) {
        readFile("a");
        readFile("b");
        readFile("randomText1");
        readFile("randomText2");
        readFile("1500symbols_1");
        readFile("1500symbols_2");
        readFile("empty");
        readFile("konstitucija");
    }

}

void comparison(){

    MD5 md5;
    SHA1 sha1;
    SHA256 sha256;

    // reading file / using konstitucija.txt

    ifstream in("fileInput/konstitucija.txt");
    if(!in.is_open()){
        cout << "Failed opening 'konstitucija.txt'.";
        return;
    }

    string line;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();        // CUSTOM HASH
    while(getline(in, line)){
        hashing(line);
    }
    cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    // t1 = high_resolution_clock::now();        // MD5
    // while(getline(in, line)){
    //     md5(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    // t1 = high_resolution_clock::now();        // SHA1
    // while(getline(in, line)){
    //     sha1(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

    // t1 = high_resolution_clock::now();        // SHA256
    // while(getline(in, line)){
    //     sha256(line);
    // }
    // cout << "Custom hash time: " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;


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