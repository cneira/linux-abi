obj-y = bitops.o bugs.o checksum.o fault.o ksyms.o ldt.o ptrace.o \
	ptrace_user.o semaphore.o sigcontext.o syscalls.o sysrq.o

obj-$(CONFIG_HIGHMEM) += highmem.o
obj-$(CONFIG_MODULES) += module.o

USER_OBJS := bugs.o ptrace_user.o sigcontext.o fault.o
USER_OBJS := $(foreach file,$(USER_OBJS),$(obj)/$(file))

SYMLINKS = bitops.c semaphore.c highmem.c module.c
SYMLINKS := $(foreach f,$(SYMLINKS),$(src)/$f)

clean-files := $(SYMLINKS)

bitops.c-dir = lib
semaphore.c-dir = kernel
highmem.c-dir = mm
module.c-dir = kernel

define make_link
	-rm -f $1
	ln -sf $(TOPDIR)/arch/i386/$($(notdir $1)-dir)/$(notdir $1) $1
endef

$(USER_OBJS) : %.o: %.c
	$(CC) $(CFLAGS_$(notdir $@)) $(USER_CFLAGS) -c -o $@ $<

$(SYMLINKS): 
	$(call make_link,$@)

subdir- := util
