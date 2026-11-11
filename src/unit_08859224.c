/* unit_08859224: 0x08859224-0x088592A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_0899CD34;
extern int func_088592E4(char *);
extern s32 sceGeListEnQueue(char *, s32, s32, s32);
extern int sceGeListSync(s32, s32);

void func_08859224(char *arg0) {
    s32 temp_a2;

    temp_a2 = *(s32 *)(arg0 + 4) ^ 1;
    *(s32 *)(arg0 + 4) = temp_a2;
    sceGeListSync(sceGeListEnQueue(&D_0899CD34 + (temp_a2 * 0x30), 0, -1, 0), 0);
    *(char **)(arg0 + 0x80198) = (char *) (arg0 + (*(s32 *)(arg0 + 4) << 0x12) + 0x198);
    func_088592E4(arg0);
}
