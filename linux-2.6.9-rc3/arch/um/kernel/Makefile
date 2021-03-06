# 
# Copyright (C) 2002 Jeff Dike (jdike@karaya.com)
# Licensed under the GPL
#

extra-y := vmlinux.lds uml.lds dyn.lds

# Descend into ../util for make clean.  This is here because it doesn't work
# in arch/um/Makefile.

subdir- = ../util

obj-y = checksum.o config.o exec_kern.o exitcode.o frame_kern.o frame.o \
	helper.o init_task.o irq.o irq_user.o ksyms.o main.o mem.o mem_user.o \
	physmem.o process.o process_kern.o ptrace.o reboot.o resource.o \
	sigio_user.o sigio_kern.o signal_kern.o signal_user.o smp.o \
	syscall_kern.o syscall_user.o sysrq.o sys_call_table.o tempfile.o \
	time.o time_kern.o tlb.o trap_kern.o trap_user.o uaccess_user.o \
	um_arch.o umid.o user_util.o

obj-$(CONFIG_BLK_DEV_INITRD) += initrd_kern.o initrd_user.o
obj-$(CONFIG_GPROF)	+= gprof_syms.o
obj-$(CONFIG_GCOV)	+= gmon_syms.o
obj-$(CONFIG_TTY_LOG)	+= tty_log.o

obj-$(CONFIG_MODE_TT) += tt/
obj-$(CONFIG_MODE_SKAS) += skas/

user-objs-$(CONFIG_TTY_LOG) += tty_log.o

USER_OBJS := $(filter %_user.o,$(obj-y))  $(user-objs-y) config.o helper.o \
	main.o process.o tempfile.o time.o tty_log.o umid.o user_util.o
USER_OBJS := $(foreach file,$(USER_OBJS),$(obj)/$(file))

CFLAGS_frame.o := $(patsubst -fomit-frame-pointer,,$(USER_CFLAGS))

# This has to be separate because it needs be compiled with frame pointers
# regardless of how the rest of the kernel is built.

$(obj)/frame.o: $(src)/frame.c
	$(CC) $(CFLAGS_$(notdir $@)) -c -o $@ $<

$(USER_OBJS) : %.o: %.c
	$(CC) $(CFLAGS_$(notdir $@)) $(USER_CFLAGS) -c -o $@ $<

QUOTE = 'my $$config=`cat $(TOPDIR)/.config`; $$config =~ s/"/\\"/g ; $$config =~ s/\n/\\n"\n"/g ; while(<STDIN>) { $$_ =~ s/CONFIG/$$config/; print $$_ }'

$(obj)/config.o : $(obj)/config.c

quiet_cmd_quote = QUOTE $@
cmd_quote = $(PERL) -e $(QUOTE) < $< > $@

targets += config.c
$(obj)/config.c : $(src)/config.c.in $(TOPDIR)/.config FORCE
	$(call if_changed,quote)
