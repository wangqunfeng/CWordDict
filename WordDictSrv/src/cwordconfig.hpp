#ifndef CWORDCONFIG_HPP_INCLUDED
#define CWORDCONFIG_HPP_INCLUDED

#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG_SWITCH 1

#if DEBUG_SWITCH!=0
#define DEBUG_INFO(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl
#else
#define DEBUG_INFO(msg)
#endif


#if DEBUG_SWITCH!=0
#define DEBUG_WARN(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl; \
    if(errno) perror(msg)
#else
#define DEBUG_INFO(msg)
#endif

#if DEBUG_SWITCH!=0
#define DEBUG_EXIT(msg) \
    std::cerr << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << (msg) << std::endl; \
    if(errno) perror(msg); \
    exit(EXIT_FAILURE)
#else
#define DEBUG_INFO(msg)
#endif

#endif // CWORDCONFIG_HPP_INCLUDED
