/*
** EPITECH PROJECT, 2020
** structures.h
** File description:
** project structures
*/

#ifndef STRUCTURES_H
#define STRUCTURES_H

// BOOLEANS
#ifndef TRUE
#define TRUE (1)
#endif

#ifndef FALSE
#define FALSE (!TRUE)
#endif

#ifndef NULL
#define NULL (void *)0
#endif

// CUSTOM TYPES
typedef short int       bool_t;
typedef const char      cchar_t;
typedef const int       cint_t;
typedef unsigned int    uint_t;
typedef unsigned char   uchar_t;

// ENUMS
// VALUES -- return codes from the API
typedef enum return_codes
{
    SIM_NOT_LAUNCHED, NO_ERR, SIM_RUNNING, ERROR, CHKPT_ERR,
    NET_ERR, SRV_ERR, CLIENT_ERR, EOF_REACHED, SIM_ENDED_OK,
    EMPTY_CMD, UNKNOWN_CMD, WRG_ARGS, TOO_MNY_ARGS, PIPE_ERR,
    UNEXPECTED_ARG, CAM_ERR, CMD_NOT_FND, SIM_ALREADY_RNG, CYCLE_DONE,
    SENSOR_ERR, SECNE_ERR, TIMER_GET_ERR, LOAD_MAP_ERR
} valueid_t;

typedef enum add_info_s
{
    FIRSTCP_CLEARED, CP_CLEARED, LAP_CLEARED,
    TRACK_CLEARED, INFO_ERROR
} additional_info_t;

typedef enum format_s
{
    API_ERROR, ONE, TWO, THREE, FOUR, NOFORMAT
} format_t;

typedef enum expected_value_response
{
    NONE, INT, FLOAT
} expect_t;

// STRUCTURES
typedef struct data_s
{
    format_t format;
    void *data;
} data_t;

typedef struct vector_s
{
    long x;
    long y;
} vector_t;

typedef struct command_s
{
    char *command;
    char *simplified_command;
    expect_t expected_response;
    format_t value;
} command_t;

typedef struct answer_s
{
    additional_info_t misc_info;
    valueid_t value;
    bool_t is_ok;
    char *code_verbose;
    data_t data;
} answer_t;

typedef struct status_s
{
    float speed;
    float middle;
    float left;
    float right;
    vector_t direction;
} status_t;

typedef struct question_s
{
    char *str;
    float flt;
    int nb;
} question_t;

#endif /* STRUCTURES_H */
