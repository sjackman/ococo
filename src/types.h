#pragma once

#include <unistd.h>

#ifdef _LIBCPP_VERSION
	#include <cinttypes>
#else
	#include <tr1/cinttypes>
#endif

namespace ococo {

const int fasta_line_l  = 50;
const int stats_delim_l = 10;

typedef uint8_t nt4_t;
typedef uint8_t nt16_t;
typedef uint8_t nt256_t;

/******************
 *                *
 *   Structures   *
 *                *
 ******************/

/*****************
 *** Auxiliary ***
 *****************/

struct single_seq_serial_t {
    bool seq_active;
    int64_t seq_len;
    char seq_name[1000];
    char seq_comment[1000];
};

/************************************
 *** Single position uncompressed ***
 ************************************/

struct pos_stats_uncompr_t {
    nt16_t nt16;

    int32_t counters[4];
    int32_t sum;
};

/**************************
 *** Translation tables ***
 **************************/

static const uint8_t nt256_nt4[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 1, 4, 4, 4, 2,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 0, 4, 1, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

static const uint8_t nt16_nt4[] = {4, 0, 1, 4, 2, 4, 4, 4,
                                   3, 4, 4, 4, 4, 4, 4, 4};

static const uint8_t nt256_nt16[] = {
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    1,  2,  4,  8,  15, 15, 15, 15, 15, 15, 15, 15, 15, 0 /*=*/, 15, 15,
    15, 1,  14, 2,  13, 15, 15, 4,  11, 15, 15, 12, 15, 3,       15, 15,
    15, 15, 5,  6,  8,  15, 7,  9,  15, 10, 15, 15, 15, 15,      15, 15,
    15, 1,  14, 2,  13, 15, 15, 4,  11, 15, 15, 12, 15, 3,       15, 15,
    15, 15, 5,  6,  8,  15, 7,  9,  15, 10, 15, 15, 15, 15,      15, 15,

    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15,
    15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,      15, 15};

static const uint8_t nt16_nt256[] = "=ACMGRSVTWYHKDBN";

static const uint8_t nt4_nt256[] = "ACGTN";

static const uint8_t nt4_nt16[] = {1, 2, 4, 8, 15};
}
