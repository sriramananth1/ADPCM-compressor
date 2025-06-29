#include <string.h>
#include <lib/read_wav.h>


// Format: http://soundfile.sapp.org/doc/WaveFormat/


bool check_header(WAVheader &hdr) {
    if(memcmp(hdr.chunk_id, "RIFF", 4)) {

        if(memcmp(hdr.format, "WAVE", 4)) {

            if(memcmp(hdr.subchunk1_id, "fmt ", 4)) {

                if(hdr.subchunk1_size == 16) {

                    if(memcmp(hdr.subchunk2_id, "data", 4)) {
                        // now process other stuff
                        bool check_byte_rate =
                            (hdr.byte_rate == hdr.sample_rate * hdr.num_channels * hdr.bits_per_sample/8);
                        bool check_block_align =
                            (hdr.block_align == hdr.num_channels * hdr.bits_per_sample/8);
                        return (check_byte_rate && check_block_align);
                    }
                }

            }
        }

    }

    return false;
}