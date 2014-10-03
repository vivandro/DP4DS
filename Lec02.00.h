#include <vector>

namespace VVDP4DS {

  // Uses an auxiliary vector<T> to store the merge before saving it to the
  // destination.
  template<typename T>
  void sorted_merge(T beg1, T end1, T beg2, T end2, T beg_dest, T end_dest) {
    std::vector<typename T::value_type> aux; // Interesting : was stumped for a
                                             // moment while I tried to figure out
                                             // how to get the type for aux vector.
    while( (beg1 != end1)
           && (beg2 != end2) ) {
      if (*beg1 < *beg2) {
        aux.push_back(*beg1);
        ++beg1;
      } else {
        aux.push_back(*beg2);
        ++beg2;
      }
    }

    // due to the nature of the exit conditions of the while loop above, only
    // one of the two while loops below will actually be entered.
    while(beg1 != end1) {
      aux.push_back(*beg1);
      ++beg1;
    }

    while(beg2 != end2) {
      aux.push_back(*beg2);
      ++beg2;
    }

    // we had to copy the results entirely into the auxiliary vector in order
    // to allow for overlapping source and destinations - which are required
    // in merge sort.
    for(T i = aux.begin(); ( (i != aux.end()) && (beg_dest != end_dest) ); ++i, ++beg_dest) {
      *beg_dest = *i;
    }
  }

  template<typename T>
  void sort_merge(T beg, T end) {
    if(beg == end) return; // an empty array is already sorted.
    if( (beg+1) ==end ) return; // an single entry is already sorted.

    T mid = beg + (end - beg)/2;
    sort_merge(beg, mid); // the entry at mid is not sorted since mid is used just as a sentinel here.
    sort_merge(mid, end); // this call actually sorts the mid entry.
    sorted_merge(beg, mid, mid, end, beg, end);
  }
}
