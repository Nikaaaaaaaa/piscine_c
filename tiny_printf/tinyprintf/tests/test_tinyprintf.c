#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(tinyprintf, simple_string, .init = redirect_all_std)
{
    int result = tinyprintf("Hello World!");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello World!");
    cr_assert_eq(result, 12);
}

Test(tinyprintf, percent, .init = redirect_all_std)
{
    int result = tinyprintf("%%");
    fflush(stdout);
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(result, 1);
}

Test(tinyprintf, signed_decimal, .init = redirect_all_std)
{
    int result = tinyprintf("%d", 42);
    fflush(stdout);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(result, 2);
}

Test(tinyprintf, signed_decimal_neg, .init = redirect_all_std)
{
    int result = tinyprintf("%d", -42);
    fflush(stdout);
    cr_assert_stdout_eq_str("-42");
    cr_assert_eq(result, 3);
}

Test(tinyprintf, unsigned_dec, .init = redirect_all_std)
{
    int result = tinyprintf("%u", 42);
    fflush(stdout);
    cr_assert_stdout_eq_str("42");
    cr_assert_eq(result, 2);
}

Test(tinyprintf, string, .init = redirect_all_std)
{
    int result = tinyprintf("%s", "Hello World!");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello World!");
    cr_assert_eq(result, 12);
}

Test(tinyprintf, string_null, .init = redirect_all_std)
{
    int result = tinyprintf("%s", (char *)NULL);
    fflush(stdout);
    cr_assert_stdout_eq_str("(null)");
    cr_assert_eq(result, 6);
}

Test(tinyprintf, char, .init = redirect_all_std)
{
    int result = tinyprintf("%c", 'A');
    fflush(stdout);
    cr_assert_stdout_eq_str("A");
    cr_assert_eq(result, 1);
}

Test(tinyprintf, unknown, .init = redirect_all_std)
{
    int result = tinyprintf("Good morning ACU! %t Tinyprintf is cool");
    fflush(stdout);
    cr_assert_stdout_eq_str("Good morning ACU! %t Tinyprintf is cool");
    cr_assert_eq(result, 39);
}

Test(tinyprintf, multiple, .init = redirect_all_std)
{
    int result = tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello [42] world!");
    cr_assert_eq(result, 17);
}

Test(tinyprintf, percent_case, .init = redirect_all_std)
{
    int result = tinyprintf("%%s", "in your head");
    fflush(stdout);
    cr_assert_stdout_eq_str("%s");
    cr_assert_eq(result, 2);
}

Test(tinyprintf, tricky_case, .init = redirect_all_std)
{
    int result =
        tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    fflush(stdout);
    cr_assert_stdout_eq_str("42 is the answer... 42 too.");
    cr_assert_eq(result, 27);
}
