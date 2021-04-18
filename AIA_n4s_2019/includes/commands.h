/*
** EPITECH PROJECT, 2020
** commands.h
** File description:
** commands related to Need4stek AI
*/

#include "macros.h"
#include "structures.h"

#ifndef COMMANDS_H
#define COMMANDS_H

// COMMANDS sent to the API
static command_t commands[] = {
    {"START_SIMULATION",            "start",        NONE,       ONE},
    {"STOP_SIMULATION",             "stop",         NONE,       ONE},
    {"CAR_FORWARD:",                "forward",      FLOAT,      ONE},
    {"CAR_BACKWARDS:",              "backwards",    FLOAT,      ONE},
    {"WHEELS_DIR:",                 "whdir",        FLOAT,      ONE},
    {"GET_INFO_LIDAR",              "lidar",        NONE,       TWO},
    {"GET_CURRENT_SPEED",           "curr_speed",   NONE,       THREE},
    {"GET_CURRENT_WHEELS",          "curr_wheels",  NONE,       THREE},
    {"CYCLE_WAIT:",                 "wait",         INT,        THREE},
    {"GET_CAR_SPEED_MAX",           "getmaxspeed",  NONE,       THREE},
    {"GET_CAR_SPEED_MIN",           "getminspeed",  NONE,       THREE},
    {"GET_INFO_SIMULATION_TIME",    "getsimtime",   NONE,       FOUR},
    {NULL,                          NULL,           NONE,       API_ERROR}
};

#endif /* COMMANDS_H */
