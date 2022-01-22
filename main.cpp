#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>




int main() {
    const int NUM_ROWS = 10;
    const int NUM_COLS = 10;
    double oldTemps[NUM_ROWS][NUM_COLS];
    double newTemps[NUM_ROWS][NUM_COLS];
    int i;
    int j;
    const double DIFFERENCE = 0.1;
    double maxChange;
    int counter = 0;


    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;

    for(i = 0; i < NUM_ROWS; ++i){
        for(j = 0; j < NUM_COLS; ++j){
            if((i == 0 || i == (NUM_ROWS -1)) && (j > 0 && j < (NUM_COLS -1) )){
                oldTemps[i][j] = 100.000;
            }
            else if(j == 0 || j == (NUM_COLS - 1)){
                oldTemps[i][j] = 0.000;
            }
            else{
                oldTemps[i][j] = 0.000;
            }
        }
    }

    for(i = 0; i < NUM_ROWS; ++i){
        for(j = 0; j < NUM_COLS; ++j){
            if(j < (NUM_COLS - 1)){
                cout << setw(9) << fixed << setprecision(3) << oldTemps[i][j] << ",";
            }
            else{
                cout << setw(9) << fixed << setprecision(3) << oldTemps[i][j];
            }
        }
        cout << endl;
    }

    cout << endl;

    do{

        counter = counter + 1;

        for(i = 0; i < NUM_ROWS; ++i){
            for(j = 0; j < NUM_COLS; ++j){
                if((i == 0 || i == (NUM_ROWS -1)) && (j > 0 && j < (NUM_COLS -1) )){
                    newTemps[i][j] = oldTemps[i][j];
                }
                else if(j == 0 || j == (NUM_COLS - 1)){
                    newTemps[i][j] = oldTemps[i][j];
                }
                else{
                    newTemps[i][j] = (oldTemps [i][j-1] + oldTemps [i][j+1] + oldTemps [i-1][j] + oldTemps [i+1][j]) / 4;
                }
            }
        }

        maxChange = newTemps[0][0] - oldTemps[0][0];

        for(i = 0; i < NUM_ROWS; ++i){
            for(j = 0; j < NUM_COLS; ++j){
                if(newTemps[i][j] - oldTemps[i][j] > maxChange){
                    maxChange = newTemps[i][j] - oldTemps[i][j];
                }
                else {
                    maxChange = maxChange;

                }
            }
        }

        for(i = 0; i < NUM_ROWS; ++i){
            for(j = 0; j < NUM_COLS; ++j){
                oldTemps[i][j] = newTemps[i][j];
            }
        }

        if (counter == 1) {
            cout << "Printing plate after one iteration ...";
            cout << endl;
            for(i = 0; i < NUM_ROWS; ++i){
                for(j = 0; j < NUM_COLS; ++j){
                    if(j < (NUM_COLS - 1)){
                        cout << setw(9) << fixed << setprecision(3) << newTemps[i][j] << ", ";
                    }
                    else{
                        cout << setw(9) << fixed << setprecision(3) << newTemps[i][j];
                    }
                }
                cout << endl;
            }
        }

        if (counter == 3) {

        }


    } while(maxChange > DIFFERENCE);

    cout << endl;
    cout << "Printing final plate...";
    cout << endl;
    for(i = 0; i < NUM_ROWS; ++i){
        for(j = 0; j < NUM_COLS; ++j){
            if(j < (NUM_COLS - 1)){
                cout << setw(9) << fixed << setprecision(3) << newTemps[i][j] << ", ";
            }
            else{
                cout << setw(9) << fixed << setprecision(3) << newTemps[i][j];
            }
        }
        cout << endl;
    }

    cout << "Writing final plate to Hotplate.csv…" << endl;
    ofstream myfile ("Hotplate.csv");
    if(myfile.is_open()) {

        for(i = 0; i < NUM_ROWS; ++i){
            for(j = 0; j < NUM_COLS; ++j){
                if(j < (NUM_COLS - 1)){
                    myfile << setw(9) << fixed << setprecision(3) << newTemps[i][j] << ", ";
                }
                else{
                    myfile << setw(9) << fixed << setprecision(3) << newTemps[i][j];
                }
            }
            cout << endl;
        }
    }

    myfile.close();



    return 0;
}