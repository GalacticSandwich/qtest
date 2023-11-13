
#ifndef _QTEST_TESTING_H_
#define _QTEST_TESTING_H_

#include <stdbool.h>

#define NAME_MAXL 256
#define TESTS_MAXL 2048

typedef struct {
    char name[ NAME_MAXL ];
    void ( *proc )( bool* );
    bool status;
} test;

typedef struct {
    int size;
    char name[ NAME_MAXL ];
    test* tests[ TESTS_MAXL ];
} test_set;

test_set* tests_alloc( char const* name );

void tests_add( test_set* set, char const* name, void ( *proc )( bool* ) );

void tests_run( test_set* set, int n );

void tests_runall( test_set* set );

void tests_free( test_set* set );

#endif
