/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "CanIf.h"
#include "Det.h"
#include "Dem.h"
#include "Utl.h"

#if 0
#include "CanIf_Cbk.h"
#include "<Module>_CanIf.h"
#include "<Module>_Cbk.h"
#endif


#define PARENT(n)   ((n)>>1)
#define CHILD_L(n)  ((n)<<1)        /* + 1 */
#define CHILD_R(n)  (((n)<<1)+1)    /* +2  */


typedef struct tagHeapType {
    uint16 key;
    uint16 value;
} HeapType;

#define HEAP_SIZE   ((uint8)16)

static uint8 N;
static uint16 Arr[64+1];

void Heap_Test(void);
void Heap_Init(uint16 *Heap);

void Heap_Up(uint16 *Heap,uint16 Position);
void Heap_Down(uint16 *Heap,uint16 Position);

void Heap_Push(uint16 *Heap,uint16 Item);
uint16 Heap_Pop(uint16 *Heap);


void Heap_Init(uint16 *Heap)
{
    Utl_MemSet((void*)Heap,'\0',HEAP_SIZE);
    N=(uint8)0x00;
    Heap[0]=0xffff;
}

#if 0
Heap_Push(Heap,Item);

Item=Heap_Pop(Heap);

Item=Heap_Search(Heap,Item);

Item=Heap_Replace(Heap,Item);

#endif

void Heap_Up(uint16 *Heap,uint16 Position)
{
    uint16 v;
/*
def _siftup(heap, pos):
    endpos = len(heap)
    startpos = pos
    newitem = heap[pos]
    # Bubble up the smaller child until hitting a leaf.
    childpos = 2*pos + 1    # leftmost child position
    while childpos < endpos:
        # Set childpos to index of smaller child.
        rightpos = childpos + 1
        if rightpos < endpos and not heap[childpos] < heap[rightpos]:
            childpos = rightpos
        # Move the smaller child up.
        heap[pos] = heap[childpos]
        pos = childpos
        childpos = 2*pos + 1
    # The leaf at pos is empty now.  Put newitem there, and bubble it up
    # to its final resting place (by sifting its parents down).
    heap[pos] = newitem
    _siftdown(heap, startpos, pos)

*/
    v=Heap[Position];

    while (Heap[PARENT(Position)]<=v) {
        Heap[Position]=Heap[PARENT(Position)];
          Position>>=1;
    }
    Heap[Position]=v;
}

void Heap_Down(uint16 *Heap,uint16 Position)
{
/*
  def _siftdown(heap, startpos, pos):
    newitem = heap[pos]
    # Follow the path to the root, moving parents down until finding a place
    # newitem fits.
    while pos > startpos:
        parentpos = (pos - 1) >> 1
        parent = heap[parentpos]
        if newitem < parent:
            heap[pos] = parent
            pos = parentpos
            continue
        break
    heap[pos] = newitem
*/
    uint16 i,j,val;

    val=Heap[Position];
    while (Position<=(N>>1)) {
        j=Position<<1;
        if (j<N) {
            if (Heap[j]<Heap[j+1]) {
                j++;
            }
        }
        if (val>=Heap[j]) {
/*            goto label0;  */
            break;
        }
        Heap[Position]=Heap[j];
        Position=j;
    }
label0:
    Heap[Position]=val;
}

void Heap_Push(uint16 *Heap,uint16 Item)
{
    N+=1;
    Heap[N]=Item;

    Heap_Up(Heap,N);
}


uint16 Heap_Pop(uint16 *Heap)
{
    uint16 largest;

    largest=Heap[1];
    Heap[1]=Heap[N];
    N-=1;
    Heap_Down(Heap,1);

    return largest;
}

void Heap_Test(void)
{
    uint16 idx;
    uint16 largest;
    Utl_Randomize(4711);

    Heap_Init(Arr);

    for (idx=0;idx<64;++idx) {
        /* Arr[idx]=*/
        Heap_Push(Arr,Utl_Random());
    }

    for (idx=0;idx<64;++idx) {
        largest=Heap_Pop(Arr);
    }
}
