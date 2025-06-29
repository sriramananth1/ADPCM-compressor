#ifndef READ_WAV
#define READ_WAV

struct WAVheader {
    char chunk_id[4] = { 'R', 'I', 'F', 'F'}; // fixed
    int chunk_size;
    char format[4] = {'W', 'A', 'V', 'E'}; // fixed

    char subchunk1_id[4] = {'f', 'm', 't', ' '}; // fixed
    int subchunk1_size = 16; // fixed 
    short audio_format; // from here on out, use dtypes to rep # of bytes
    short num_channels; // can be 1 or 2 (mono, stereo)
    int sample_rate; // usually 44100, can be 8000
    int byte_rate; // SampleRate * NumChannels * BitsPerSample/8
    short block_align; // NumChannels * BitsPerSample/8
    short bits_per_sample; // basically, ensure the above jawn is an integer

    // data subchunk

    char subchunk2_id[4] = {'d','a','t','a'};
    int subchunk2_size; // NumSamples * NumChannels * BitsPerSample/8 -> number of bytes in data
}



#endif