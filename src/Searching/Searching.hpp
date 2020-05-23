#ifndef SEARCHING_SEARCHING_HPP
#define SEARCHING_SEARCHING_HPP

// requires a pair of iterators for a half open sequence, and a target value
// returns the iterator for the first found target value (if any),
//   or the past the end iterator for the given sequence otherwise
template <typename BidirectionalIterator, typename T>
constexpr BidirectionalIterator linearSearch(BidirectionalIterator first,
                                             BidirectionalIterator last,
                                             const T&              value) {
  T lastVal = *(--last); // last element
  *(last)   = value;     // sentinel
  while (*first++ != value) {
    ;
  }
  *(last) = lastVal; // put the last element back
  --first;
  return *first == value ? first : ++last;
}

// requires a pair of iterators for a half open sorted sequence, and a target
// value returns the iterator for the target value (if any),
//   or the past the end iterator for the given sequence otherwise
// the code is more readable with RandomAccessIterator
template <typename RandomAccessIterator, typename T>
constexpr RandomAccessIterator binaryFind(RandomAccessIterator first,
                                          RandomAccessIterator last,
                                          const T&             value) {
  auto pastTheEnd = last;
  auto mid        = first + (last - first) / 2;
  --last;
  while (first <= last) {
    if (value < *mid) {
      last = mid - 1;
      mid  = first + (last - first) / 2;
    } else if (value > *mid) {
      first = mid + 1;
      mid   = first + (last - first) / 2;
    } else {
      return mid;
    }
  }
  return pastTheEnd;
}

#endif // SEARCHING_SEARCHING_HPP
