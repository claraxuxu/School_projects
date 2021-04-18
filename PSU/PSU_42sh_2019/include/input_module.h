/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef INPUT_MODULE_H_INCLUDED
#define INPUT_MODULE_H_INCLUDED

#include <stdlib.h>
#include "istl/hash_table.h"
#include "istl/vector.h"
#include "istl/string.h"

typedef enum StandardDev {STD_IN, STD_OUT} (devt_t);

typedef struct Redirection {
    char type[2 + 1];   //!< Redirection operator (<, >>, <<<, ...)
    char *from;     //!< If input: right argument, if output: left argument
    char *to;       //!< If input: left argument, if output: right argument
} (rd_t);

typedef struct Redirection (rdr_t);

#define RT_NULL (0x00)
#define RT_FD (0x01) 
#define RT_FN (0x02)

typedef struct Command {
    vector_t *args;  //!< Command name at 0 followed by arguments
    vector_t *rds;   //!< All command redirections
    char op[3];     //!< Command chain operator (&, ||, ;, ...)
    int pipe[2];
} (cmd_t);

/*!
    \brief Reads user input from keyboard and fills
    the vector of commands
    \details This function is responsible for handling
    the entire user input expression and does:
    - aliases expansion
    - globbings expansion
    - variable expansion
    - line editing
    - redirections (extraction)
    - history
    \param[out] expr Vector to store commands into. Has to be initialised.
    \return Error code corresponding to what have failed
*/
int input_read(vector_t *expr, char *hfile);

/*!
    \brief Reads the commands vector and executes them
    one by one.
    \details Here we execute the commands and handle:
    - parentheses
    - backticks
    - operators
    - redirections (evaluation)
    \param[in] expr Vector containing all the commands to execute
    \return Error code of the last executed command
*/
int input_eval(vector_t *expr);

/*!
    \brief Reads user input
    \details Handles multiline input, expands variables and globbings.
    BEWARE: doesn't handle any parentheses or backticks and let them as
    they are
*/
int prompt_cmd(char **prompt, char *hfile);

/*!
    \brief Takes user input and expands parts not requiring execution
    \param[in,out] prompt User input possibly containing variables,
    globbings and such
*/
int expand_cmd_args(cmd_t *prompt);

list_t *extract_all_args(string_t const *argline);

/*!
    \brief Transforms user input into the vector of commands
    \details Extracts redirections and direct command arguments. Doesn't
    handle any parantheses or backticks.
*/
int prompt_format(char const *prompt, vector_t *expr);

char **vector_to_char(vector_t *expr);

int cmd_from_match(map_t *match, cmd_t *cmd);

int cmd_extract_rdrs(cmd_t *);

int cmd_pipes(cmd_t const *);

typedef int (*rdr_extr_ft)(cmd_t *, int[]);

typedef struct ExtrPair {
    char op[2 + 1];
    rdr_extr_ft extr;
} (epair_t);

rdr_extr_ft get_rdr_extr(char const *);
int extract_r_rdr(cmd_t *, int[3]);
int extract_dr_rdr(cmd_t *, int[3]);
int extract_l_rdr(cmd_t *, int[3]);
int extract_dl_rdr(cmd_t *, int[3]);

int apply_pipes(int fds[2]);
int reset_io(devt_t);

extern const epair_t RPAIRS[];

#endif
