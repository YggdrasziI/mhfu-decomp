/* unit_088AD2FC: 0x088AD2FC-0x088AD348 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

char *func_088AD2FC(char *arg0) {
    char *temp_v1;
    char *var_a0;
    s32 temp_a1;
    s32 var_a2;

    temp_a1 = *(s32 *)(arg0 + 0x10);
    var_a2 = 0;
    if (temp_a1 > 0) {
        temp_v1 = (char *) (*(s32 **)(arg0 + 0xC));
        var_a0 = temp_v1;
loop_2:
        if (*(s32 *)var_a0 == 0) {
            return temp_v1 + (var_a2 * 0xC);
        }
        var_a2 += 1;
        var_a0 += 0xC;
        if (var_a2 >= temp_a1) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
