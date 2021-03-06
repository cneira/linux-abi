#include <stdio.h>
#include <asm/ptrace.h>
#include <asm/user.h>

#define PRINT_REG(name, val) printf("#define HOST_%s %d\n", (name), (val))

int main(int argc, char **argv)
{
	printf("/* Automatically generated by "
	       "arch/um/kernel/skas/util/mk_ptregs */\n");
	printf("\n");
	printf("#ifndef __SKAS_PT_REGS_\n");
	printf("#define __SKAS_PT_REGS_\n");
	printf("\n");
	printf("#define HOST_FRAME_SIZE %d\n", FRAME_SIZE);
	printf("#define HOST_FP_SIZE %d\n", 
	       sizeof(struct user_i387_struct) / sizeof(unsigned long));
	printf("#define HOST_XFP_SIZE %d\n", 
	       sizeof(struct user_fxsr_struct) / sizeof(unsigned long));

	PRINT_REG("IP", EIP);
	PRINT_REG("SP", UESP);
	PRINT_REG("EFLAGS", EFL);
	PRINT_REG("EAX", EAX);
	PRINT_REG("EBX", EBX);
	PRINT_REG("ECX", ECX);
	PRINT_REG("EDX", EDX);
	PRINT_REG("ESI", ESI);
	PRINT_REG("EDI", EDI);
	PRINT_REG("EBP", EBP);
	PRINT_REG("CS", CS);
	PRINT_REG("SS", SS);
	PRINT_REG("DS", DS);
	PRINT_REG("FS", FS);
	PRINT_REG("ES", ES);
	PRINT_REG("GS", GS);
	printf("\n");
	printf("#endif\n");
	return(0);
}

/*
 * Overrides for Emacs so that we follow Linus's tabbing style.
 * Emacs will notice this stuff at the end of the file and automatically
 * adjust the settings for this buffer only.  This must remain at the end
 * of the file.
 * ---------------------------------------------------------------------------
 * Local variables:
 * c-file-style: "linux"
 * End:
 */
