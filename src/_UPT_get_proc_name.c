/* libunwind - a platform-independent unwind library
   Copyright (C) 2003 Hewlett-Packard Co
	Contributed by David Mosberger-Tang <davidm@hpl.hp.com>

This file is part of libunwind.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */

#include "_UPT_internal.h"

#if defined(UNW_TARGET_IA64)
# define TARGET_ELF64
#elif defined(UNW_TARGET_X86)
# define TARGET_ELF32
#else
# warning Do not know object-file format of target arch.  Please implement.
#endif

int
_UPT_get_proc_name (unw_addr_space_t as, unw_word_t ip,
		    char *buf, size_t buf_len, unw_word_t *offp, void *arg)
{
  struct UPT_info *ui = arg;

#if defined(TARGET_ELF64)
  return _Uelf64_get_proc_name (ui->pid, ip, buf, buf_len, offp);
#elif defined(TARGET_ELF32)
  return _Uelf32_get_proc_name (ui->pid, ip, buf, buf_len, offp);
#endif
  return -UNW_ENOINFO;
}