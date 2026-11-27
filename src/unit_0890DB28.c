/* unit_0890DB28: 0x0890DB28-0x0890DB88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DB28: finds the first free slot (word 0 == 0) among 16
 * two-word entries at D_09A5F120, stores arg0 in its first word, arg1 then
 * arg1 - 12 in its second word (D_09A5F124), returns the index, or -1 when
 * no slot is free. Derived from the assembly only. */

typedef int s32;

extern s32 D_09A5F120[];
extern s32 D_09A5F124[];

s32 func_0890DB28(s32 arg0, s32 arg1) {
    s32 i;
    s32 *p;

    i = 0;
    p = D_09A5F120;
    do {
        if (*p == 0) {
            D_09A5F120[i * 2] = arg0;
            D_09A5F124[i * 2] = arg1;
            D_09A5F124[i * 2] = arg1 - 12;
            return i;
        }
        i++;
        p += 2;
    } while (i < 16);
    return -1;
}
