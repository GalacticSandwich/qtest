
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "qtest_testing.h"

static test* test_ind_alloc( char const* name, void ( *proc )( bool* ) )
{
    test* t = ( test* ) malloc( sizeof( test ) );

    strcpy( t->name, name );
    t->proc = proc;
    t->status = false;

    return t;
}

static void test_ind_run( test* t )
{
    ( *( t->proc ) )( t->status );
}

test_set* tests_alloc( char const* name )
{
    test_set* set = ( test_set* ) malloc( sizeof( test_set ) );

    strcpy( set->name, name );
    set->size = 0;

    return tests;
}

void tests_add( test_set* set, char const* name, void ( *proc )( bool* ) )
{
    test* t = test_ind_alloc( name, proc );

    set->tests[ set->size++ ] = t;
}

void tests_run( test_set* set, int n )
{
    if ( set->size < n ) return;

    test_ind_run( set->tests[ n ] );
}

void tests_runall( test_set* set )
{
    for ( int i = 0; i < set->size; i++ )
        test_ind_run( set->tests[ i ] );
}

void tests_free( test_set* set )
{
    for ( int i = 0; i < set->size; i++ )
        free( set->tests[ i ] );

    free( set );
}