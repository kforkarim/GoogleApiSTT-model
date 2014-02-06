//
//  wav_to_flac.h
//
//  Created by Jason Hurt on 7/6/12.
#ifdef __cplusplus
extern "C"
#endif

#ifndef Lucidity_wav_to_flac_h
#define Lucidity_wav_to_flac_h

int convertWavToFlac(const char *wave_file_in, const char *flac_file_out);

FILE *fopen$UNIX2003( const char *filename, const char *mode )
{
    return fopen(filename, mode);
}

size_t fwrite$UNIX2003( const void *a, size_t b, size_t c, FILE *d )
{
    return fwrite(a, b, c, d);
}

#endif
