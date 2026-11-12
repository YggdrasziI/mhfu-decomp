/* unit_088EF348: 0x088EF348-0x088EF380 (ULES01213)
 *
 * Bounds (hypothesis): four forwarders that pass the address of D_09A4F0D4 to
 * func_088AD378 / func_088AD46C, then an empty function; the code around is
 * unrelated. Other parameters, if any, are passed through unchanged.
 */

typedef int s32;

extern char D_09A4F0D4[];
extern void func_088AD378(char *, s32);
extern void func_088AD46C(char *, s32);

void func_088EF348(s32 arg0, s32 arg1) { func_088AD378(D_09A4F0D4, arg1); }
void func_088EF354(s32 arg0, s32 arg1, s32 arg2) { func_088AD46C(D_09A4F0D4, arg1); }
void func_088EF360(s32 arg0, s32 arg1) { func_088AD378(D_09A4F0D4, arg1); }
void func_088EF36C(s32 arg0, s32 arg1) { func_088AD46C(D_09A4F0D4, arg1); }
void func_088EF378(void) {}
