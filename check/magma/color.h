/*
 * color.h
 *
 *  Created on: 23 авг. 2017 г.
 *      Author:
 */

#ifndef MAGMA_COLOR_H_
#define MAGMA_COLOR_H_

#define MAGMA_COLOR_RESET "\033[m"

#define MAGMA_COLOR_RED "\033[0;31m"
#define MAGMA_COLOR_GREEN "\033[0;32m"
#define MAGMA_COLOR_YELLOW "\033[0;33m"
#define MAGMA_COLOR_BLUE "\033[0;34m"
#define MAGMA_COLOR_PURPLE "\033[0;35m"
#define MAGMA_COLOR_CYAN "\033[0;36m"
#define MAGMA_COLOR_WHITE "\033[0;37m"

#define MAGMA_COLOR_RED_BOLD "\033[1;31m"
#define MAGMA_COLOR_GREEN_BOLD "\033[1;32m"
#define MAGMA_COLOR_YELLOW_BOLD "\033[1;33m"
#define MAGMA_COLOR_BLUE_BOLD "\033[1;34m"
#define MAGMA_COLOR_PURPLE_BOLD "\033[1;35m"
#define MAGMA_COLOR_CYAN_BOLD "\033[1;36m"
#define MAGMA_COLOR_WHITE_BOLD "\033[1;37m"

#define MAGMA_COLOR_RED_UNDERLINE "\033[4;31m"
#define MAGMA_COLOR_GREEN_UNDERLINE "\033[4;32m"
#define MAGMA_COLOR_YELLOW_UNDERLINE "\033[4;93m"
#define MAGMA_COLOR_BLUE_UNDERLINE "\033[4;34m"
#define MAGMA_COLOR_PURPLE_UNDERLINE "\033[4;35m"
#define MAGMA_COLOR_CYAN_UNDERLINE "\033[4;36m"
#define MAGMA_COLOR_WHITE_UNDERLINE "\033[4;37m"

#define MAGMA_COLOR_RED_INTENSE "\033[0;91m"
#define MAGMA_COLOR_GREEN_INTENSE "\033[0;92m"
#define MAGMA_COLOR_YELLOW_INTENSE "\033[0;93m"
#define MAGMA_COLOR_BLUE_INTENSE "\033[0;94m"
#define MAGMA_COLOR_PURPLE_INTENSE "\033[0;95m"
#define MAGMA_COLOR_CYAN_INTENSE "\033[0;96m"
#define MAGMA_COLOR_WHITE_INTENSE "\033[0;97m"

#define MAGMA_COLOR_RED_INTENSE_BOLD "\033[1;91m"
#define MAGMA_COLOR_GREEN_INTENSE_BOLD "\033[1;92m"
#define MAGMA_COLOR_YELLOW_INTENSE_BOLD "\033[1;93m"
#define MAGMA_COLOR_BLUE_INTENSE_BOLD "\033[1;94m"
#define MAGMA_COLOR_PURPLE_INTENSE_BOLD "\033[1;95m"
#define MAGMA_COLOR_CYAN_INTENSE_BOLD "\033[1;96m"
#define MAGMA_COLOR_WHITE_INTENSE_BOLD "\033[1;97m"

const    chr_t * color_blue(void);
const    chr_t * color_blue_bold(void);
const    chr_t * color_blue_intense(void);
const    chr_t * color_blue_intense_bold(void);
const    chr_t * color_blue_underline(void);
const    chr_t * color_cyan(void);
const    chr_t * color_cyan_bold(void);
const    chr_t * color_cyan_intense(void);
const    chr_t * color_cyan_intense_bold(void);
const    chr_t * color_cyan_underline(void);
const    chr_t * color_green(void);
const    chr_t * color_green_bold(void);
const    chr_t * color_green_intense(void);
const    chr_t * color_green_intense_bold(void);
const    chr_t * color_green_underline(void);
const    chr_t * color_purple(void);
const    chr_t * color_purple_bold(void);
const    chr_t * color_purple_intense(void);
const    chr_t * color_purple_intense_bold(void);
const    chr_t * color_purple_underline(void);
const    chr_t * color_red(void);
const    chr_t * color_red_bold(void);
const    chr_t * color_red_intense(void);
const    chr_t * color_red_intense_bold(void);
const    chr_t * color_red_underline(void);
const    chr_t * color_reset(void);
bool_t   color_supported(void);
const    chr_t * color_white(void);
const    chr_t * color_white_bold(void);
const    chr_t * color_white_intense(void);
const    chr_t * color_white_intense_bold(void);
const    chr_t * color_white_underline(void);
const    chr_t * color_yellow(void);
const    chr_t * color_yellow_bold(void);
const    chr_t * color_yellow_intense(void);
const    chr_t * color_yellow_intense_bold(void);
const    chr_t * color_yellow_underline(void);



#endif /* MAGMA_COLOR_H_ */