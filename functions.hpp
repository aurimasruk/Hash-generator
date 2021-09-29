#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <string>


#include "includes/md5.h"
#include "includes/sha1.h"
#include "includes/sha256.h"

using namespace std;

void hashing(string);

void consoleInput();

void gen_random(int, string);

void fileInput();

void comparison();

void readFile(string);

void fileGenerator(string, int);

int choiceCheck(int&, int);


#endif