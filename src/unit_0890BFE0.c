/* unit_0890BFE0: 0x0890BFE0-0x0890C200 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Compares the string at a with the string at b and stores a number in
 * *out (0 by default):
 * - b null: returns 1;
 * - b starting with 'P' (then optional 'C', 'V') followed by 'v', and a
 *   starting with 'P' or '*': returns 1;
 * - a starting with '!' or '*': walks '!'-separated fields; on a field
 *   equal to the start of b, parses the decimal digits up to the next '!'
 *   into *out and returns 1; returns 0 when no field matches;
 * - otherwise skips matching 'P'/'R' markers with their 'C'/'V' qualifiers,
 *   then returns 1 when the rest of both strings are equal, 0 otherwise.
 *
 * The `volatile` read of the 'V' test keeps the reload of *a for the loop
 * test, as in the original (a plain read is shared with the loop test).
 */

typedef int s32;

s32 func_0890BFE0(char *a, char *b, s32 *out) {
    char *q;
    s32 e;
    s32 c;
    s32 n;

    *out = 0;
    q = b;
    if (b == 0) {
        return 1;
    }
    if (*b == 'P') {
        q++;
        if (*q == 'C') {
            q++;
        }
        if (*q == 'V') {
            q++;
        }
        if (*q == 'v') {
            if (*a == 'P' || *a == '*') {
                return 1;
            }
        }
        q = b;
    }
    switch (*a) {
    case '*':
    case '!':
        if (*a++ != *q++) {
            return 0;
        }
        while (1) {
            c = *a;
            if (c == *q++) {
                a++;
                if (c == '!') {
                    n = 0;
                    e = *a;
                    if (e != '!') {
                        do {
                            n = n * 10 + (char)e - '0';
                            a++;
                            e = *a;
                        } while (e != '!');
                    }
                    *out = n;
                    return 1;
                }
                continue;
            }
            while (*a++ != '!') {
            }
            while (*a++ != '!') {
            }
            if (*a == 0) {
                return 0;
            }
            q = b + 1;
        }
    }
    while (((c = *a) == 'P' || c == 'R') && c == *q) {
        q++;
        a++;
        if (*q == 'C') {
            if (*a == 'C') {
                a++;
            }
            q++;
        }
        c = *a;
        if (c == 'C') {
            return 0;
        }
        if (*q == 'V') {
            if (c == 'V') {
                a++;
            }
            q++;
        }
        if (*(volatile char *)a == 'V') {
            return 0;
        }
    }
    if (c == *q) {
        do {
            if (*a == 0) {
                return 1;
            }
            a++;
            q++;
        } while (*a == *q);
    }
    return 0;
}
