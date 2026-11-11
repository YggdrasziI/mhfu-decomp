/* unit_088B0C68: 0x088B0C68-0x088B0C8C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088AD09C(char *);
extern char func_088B047C;

s32 func_088B0C68(void) {
    func_088AD09C(&func_088B047C);
    return 0;
}
