/* Machine-dependent pthreads configuration and inline functions.
   Sparc v9 version.
   Copyright (C) 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Richard Henderson <rth@tamu.edu>.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If
   not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifndef PT_EI
# define PT_EI extern inline
#endif


/* Spinlock implementation; required.  */
PT_EI long int
testandset (int *spinlock)
{
  int ret;

  __asm__ __volatile__("ldstub %1,%0"
	: "=r" (ret), "=m" (*spinlock) : "m" (*spinlock));

  return ret;
}


/* Memory barrier; default is to do nothing */
#define MEMORY_BARRIER() \
     __asm__ __volatile__("membar #LoadLoad | #LoadStore | #StoreLoad | #StoreStore" : : : "memory")
/* Read barrier.  */
#define READ_MEMORY_BARRIER() \
     __asm__ __volatile__("membar #LoadLoad | #LoadStore" : : : "memory")
/* Write barrier.  */
#define WRITE_MEMORY_BARRIER() \
     __asm__ __volatile__("membar #StoreLoad | #StoreStore" : : : "memory")


/* Get some notion of the current stack.  Need not be exactly the top
   of the stack, just something somewhere in the current frame.  */
#define CURRENT_STACK_FRAME  (stack_pointer + (2 * 128))
register char *stack_pointer __asm__ ("%sp");


/* Registers %g6 and %g7 are reserved by the ABI for "system use".  It
   happens that Solaris uses %g6 for the thread pointer -- we do the same.  */
struct _pthread_descr_struct;
register struct _pthread_descr_struct *__thread_self __asm__ ("%g6");

/* Return the thread descriptor for the current thread.  */
#define THREAD_SELF  __thread_self

/* Initialize the thread-unique value.  */
#define INIT_THREAD_SELF(descr, nr)  (__thread_self = (descr))


/* Compare-and-swap for semaphores. */

#define HAS_COMPARE_AND_SWAP
PT_EI int
__compare_and_swap (long int *p, long int oldval, long int newval)
{
  long int readval;

  __asm__ __volatile__ ("casx	[%4], %2, %0"
			: "=r"(readval), "=m"(*p)
			: "r"(oldval), "m"(*p), "r"(p), "0"(newval));
  MEMORY_BARRIER();
  return readval == oldval;
}

/* Access to data in the thread descriptor is easy.  */
#define THREAD_GETMEM(descr, member) __thread_self->member
#define THREAD_GETMEM_NC(descr, member) __thread_self->member
#define THREAD_SETMEM(descr, member, value) __thread_self->member = (value)
#define THREAD_SETMEM_NC(descr, member, value) __thread_self->member = (value)

/* We want the OS to assign stack addresses.  */
#define FLOATING_STACKS 1

/* Maximum size of the stack if the rlimit is unlimited.  */
#define ARCH_STACK_MAX_SIZE     32*1024*1024
