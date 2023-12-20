#ifndef VALENTINEASSEMBLER_UNIVERSALGETOPT_HPP
#define VALENTINEASSEMBLER_UNIVERSALGETOPT_HPP

namespace uni {

    extern int opterr,             /* if error message should be printed */
    optind,             /* index into parent argv vector */
    optopt,                 /* character checked for validity */
    optreset;               /* reset getopt */
    extern char *optarg;                /* argument associated with option */

    int getopt(int nargc, char *const nargv[], const char *ostr);
}

#endif //VALENTINEASSEMBLER_UNIVERSALGETOPT_HPP
