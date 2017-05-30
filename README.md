# Linux-ABI
This repository contains kernels patched with linux-ABI-ibcs https://sourceforge.net/projects/linux-abi/ at that time the current  implementation for SYSV systems (mainly xenix and sco) were missing features that made microfocus cobol failed to execute. 
This repo contains custom patches to make System V Release 5 (mainly SCO openserver) aplications work, in this case Microfocus cobol.


* Current documentation to implement rest of calls
  http://www.sco.com/developers/devspecs/gabi41.pdf


# IBCS enabled Kernels
 Kernel linux-2.6.9-rc3 has Microfocus Cobol and SCO openserver 5 applications tested and working with custom patching for Microfocus Cobol which does not work out of the box due to needed syscalls implemented in this fork.
   
