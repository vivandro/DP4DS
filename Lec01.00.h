
// This assumes availability of a random access iterator. So STL vector
// as well as C arrays will work.
// To avoid namespace collision I'm wrapping all of my code within VVDP4DS
// namespace.

// Insertion Sort

namespace VVDP4DS {

template<typename T>
void swap(T &i, T &j) {
  T temp = i;
  i = j;
  j = temp;
}

template<typename T>
T min(T a, T b) {
  return (*a > *b) ? b : a;
}

template<typename T>
T find_min(T beg, T end) {
  T curr_min = beg;
  for(T i = beg; i != end; ++i) {
    curr_min = VVDP4DS::min(curr_min, i); // Had to add the namespace
                                          // since g++ on Mac was automatically
                                          // including algorithm.h and causing
                                          // namespace conflicts.
  }
  return curr_min;
}

template<typename T>
// Sort items in ascending order.
// To make this more generic, we could allow the user to pass us a predicate
// that returns true if i and j do not need swapping.
void sort_insertion(T beg, T end) {
  if(beg == end) return; // an empty array is already sorted

  if( (beg+1) == end ) return; // an array with a single element is already sorted

  T min = find_min(beg, end);
  swap(*beg, *min);
  sort_insertion(beg+1, end); // tail recursion will make this implementation as
                              // efficient as the one using a loop. recursion
                              // makes it easy to understand as well as easy to
                              // maintain and less prone to bugs due to the
                              // lesser number of lines of code.
}// sort_insertion


}
