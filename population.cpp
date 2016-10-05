//
//  main.cpp
//  3 oct
//
//  Created by Mirna Sumopawiro on 10/3/16.
//  Copyright © 2016 Mirna Sumopawiro. All rights reserved.
//
// Population

#include <iostream>
#include <fstream>
using namespace std;


//function1: main function
//function2: new population size
//function3: number of births
//function4: number of deaths

//Function Prototypes
int numBirth (int, float);
int numDeath (int, float);
int newPopulation (int, int, int);


int main(){
    float birthRate;
    float deathRate;
    int startPopulation;
    int numYears;
    int birthNumber;
    int deathNumber;
    int newNumber;
    fstream outfile("Population.txt", fstream::out);
    
    //validate Starting Population Size
    cout << "Enter the starting size of population\n";
    cin >> startPopulation;
    if (startPopulation < 2){
        cout << "Please enter another number\n";
    }
    
    //validate Birth Rate
    cout << "Enter the annual birth rate\n";
    cin >> birthRate;
    if (birthRate < 0){
        cout << "Please enter a positive number\n";
    }
    
    //validate Death Rate
    cout << "Enter the annual death rate\n";
    cin >> deathRate;
    if (deathRate < 0){
        cout << "Please enter a positive number\n";
    }
    
    //validate number of years
    cout << "Enter the number of year(s)\n";
    cin >> numYears;
    if (numYears < 1){
        cout << "Please enter another number\n";
    }
    
    
    //population for the years
    for (int i=1; i<=numYears; i++){
        birthNumber = numBirth(startPopulation, birthRate);
        deathNumber = numDeath(startPopulation, deathRate);
        newNumber = newPopulation(startPopulation, birthNumber, deathNumber);
        startPopulation = newNumber;
    }
    
    cout << "The size of population is " << newNumber << " after " << numYears << " years" << endl;
    outfile << "The size of population is " << newNumber << " after " << numYears << " years" << endl;
    outfile.close();
    return 0;
    
}



int numBirth(int population1, float birthR){
    int newBirth;
    newBirth = population1 * birthR;
    return newBirth;
}

int numDeath (int population2, float deathR){
    int newDeath;
    newDeath = population2 * deathR;
    return newDeath;
}

int newPopulation (int p, int bp, int dp){
    int newPop;
    newPop = p + bp - dp;
    return newPop;
}