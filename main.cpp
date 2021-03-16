#include "wav.hpp" // make sure to include this helper library
// " " instead of <> means that library is in the same folder as your program

using namespace std;


int main(){
    WavSound sound1; // helper
    double sample_rate = 41000; // samples per second
    // your code goes here
    double duration = 5.0;
    double freq;
    double dt = duration/sample_rate;
    int n_samples = sample_rate * duration;
    int * waveform = new int[n_samples]; // creates the array


    for ( int i_sample = 0; i_sample < n_samples ; i_sample++) {
        if ((i_sample / 25625) % 2 == 0) {
            freq = 800;
            waveform[i_sample] = 6000 * sin(2 * M_PI * freq * i_sample * dt);
        } else {
            freq = 1000;
            waveform[i_sample] = 5000 * sin(2 * M_PI * freq * i_sample * dt);
        }
    }

    sound1.MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav
    delete[](waveform);
    return 0;