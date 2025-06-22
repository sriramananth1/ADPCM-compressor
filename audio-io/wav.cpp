#include <iostream>
#include <fstream>
#include <string>

// Format: http://soundfile.sapp.org/doc/WaveFormat/

// Riff Chunk

const std::string chunk_id = "RIFF";
const std::string chunk_size = "----"; // unknown at the moment, only can see this when file is written to
const std::string format = "WAVE";

// FMT Subchunk 

const std::string subchunk1_id = "fmt "; // note, we use strings of fixed lengths (above and below) because these are fixed byte length
const int subchunk1_size = 16; // fixed
const int audio_format = 1; // pcm 
const int num_channels = 2; // stereo - right and left speakers do diff things at diff times
const int sample_rate = 44100; // number of samples/second
const int byte_rate = sample_rate * num_channels * (subchunk1_size / 8); // as defined by link
const int block_align = num_channels * (subchunk1_size / 8); // also as defined by link
const int bits_per_sample = 16;

// Data subchunk

const std::string subchunk2_id = "data"; 
const std::string subchunk2_size = "----";

void write_as_bytes(std::ofstream &file, int value, int byte_size) { // write a value to a file
    file.write(reinterpret_cast<const char*>(&value), byte_size); 

    // So what does this above thing do?
    // 1. Call file that you're sending to 
    // 2. std::ofstream has built-in method reinterpret_cast, which takes in reference to value and turns it into const char pointer
}

int main() {
    
    std::ofstream wav;
    wav.open("test.wav", std::ios::binary);
    
    if(wav.is_open()) {
        wav << chunk_id;
        wav << chunk_size;
        wav << format;

        wav << subchunk1_id;

        // we can write normally since the above are just strings
        write_as_bytes(wav, subchunk1_size, 4);
        write_as_bytes(wav, audio_format, 2);
        write_as_bytes(wav, num_channels, 2);
        write_as_bytes(wav, sample_rate, 4);
        write_as_bytes(wav, byte_rate, 4);
        write_as_bytes(wav, block_align, 2);
        write_as_bytes(wav, bits_per_sample, 2);

        wav << subchunk2_id;
        wav << subchunk2_size; 
    }

    return 0; 
}