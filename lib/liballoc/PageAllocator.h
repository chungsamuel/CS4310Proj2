/*
 * Copyright (C) 2009 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBALLOC_PAGEALLOCATOR_H
#define __LIBALLOC_PAGEALLOCATOR_H

#include <FreeNOS/System.h>
#include <Types.h>
#include "Allocator.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup liballoc
 * @{
 */

/**
 * Allocates virtual memory using the memory server.
 */
class PageAllocator : public Allocator
{
  public:

    /**
     * Class constructor.
     *
     * @param range Block of continguous memory to be managed.
     */
    PageAllocator(const Range range);

    /**
     * Get memory available.
     *
     * @return Size of memory available by the Allocator.
     */
    virtual Size available() const;

    /**
     * Allocate memory.
     *
     * @param args Contains the requested size and alignment on input.
     *             On output, contains the actual allocated address.
     *
     * @return Result value.
     */
    virtual Result allocate(Range & args);

    /**
     * Release memory.
     *
     * @param addr Points to memory previously returned by allocate().
     * @return Result value.
     *
     * @see allocate
     */
    virtual Result release(Address addr);

  private:

    /** Total number of bytes allocated. */
    Size m_allocated;
};

/**
 * @}
 * @}
 */

#endif /* __LIBALLOC_PAGEALLOCATOR_H */
