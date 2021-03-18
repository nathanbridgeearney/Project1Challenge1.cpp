#include <iostream> // input-output library
#include <cmath>  // library for sin function
#include "wav.hpp" // make sure to include this helper library
#include <fstream>
// " " instead of <> means that library is in the same folder as your program

using namespace std;


int main() {
    WavSound sound1; // helper
    double sample_rate = 41400; // samples per second
    // your code goes here
    string freq;
    ifstream readFile("odetojoy.txt");
    double dt = 1 / sample_rate;
    int duration = 15;
    int n_samples = duration / dt;
    int *waveform = new int[n_samples]; // creates the array
    string line; int lineN = 0;
    while (getline(readFile, line))lineN ++;
    int w_sample = n_samples/lineN;
    readFile.close();
    int* notes = new int[lineN];
    readFile.open("odetojoy.txt");
    lineN = 0;

    while (getline(readFile, line)) {
        // Output the text from the file
        notes[lineN] = stod(line);
        cout<<line;
        lineN++;
    }

    for (int i = 0; i < lineN; i++) {

        for (int i_sample = 0; i_sample < w_sample; i_sample++) {
            //and here
            waveform[i_sample + i * w_sample] = 7000 * sin(2 * M_PI * notes[i] * i_sample * dt);
           // cout<<"\n making wave " <<  notes[i];
        }
    }



// Close the file
    readFile.close();

    sound1.MakeWavFromInt("tone1.wav", sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav
    delete[](waveform);
    return 0;

}