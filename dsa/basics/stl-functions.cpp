#include <bits/stdc++.h>
using namespace std;

int main () {
    // vectors
    vector<int>v(5); //size 5, all elements 0 intially 
    vector<int>::iterator it; // iterator for traversing the vector

    for(it = v.begin(); it != v.end(); it++) {
        cout << *it << "\n"; // dereference the iterator to access the current element
    }

    for (int i= 0; i< v.size(); i++) {
        v[i] = i+1;
    }

    v.push_back(6); // append 6 to the end of the vector

    // strings
    string s = "Hello world";
    string s1(s); // copy constructor
    string s2(s,2,4); // substring starting at index 2 with length 4

    string s3 = s.substr(2,4); // substring starting at index 2 with length 4

    if (s1.compare(s2) == 0) { // compare returns 0 when the strings are equal
        cout << "s1 and s2 are equal\n";
    }

    // pair
    pair<int, char> p;
    pair<int, char> p1(1, 'a'); // initialize the pair with first = 1 and second = 'a'

    cout<< p1.first << " " << p1.second << "\n"; // access the first and second elements of the pair
    
    p = make_pair(2, 'b'); // assign a pair with first = 2 and second = 'b'

    // set
    set<int> st; // stores unique elements in sorted order
    vector<int> arr = {1, 2, 2, 3, 3, 3}; // contains duplicate elements
    for (int x : arr) { // insert each element into the set
        st.insert(x);
    }

    set<int> :: iterator it1;
    for (it1 = st.begin(); it1 != st.end(); it1++) {
        cout << *it1 << " "; 
    }

    // Output: 1 2 3

    if (st.find(3) != st.end()) { // find returns an iterator to the first matching element, or st.end() if it is not found in O(log n) time complexity
        cout << "\n3 is present in the set\n";
    }

    // set operations use balanced binary search trees, so insert, find, and erase take O(log n) time.
    st.erase(3); // remove 3 from the set

    // map
    map<int, char> mp; // stores key-value pairs with unique keys in sorted order
    mp[1] = 'a';
    mp[2] = 'b';

    map<int, char>::iterator it2;
    for (it2 = mp.begin(); it2 != mp.end(); it2++) {
        cout << it2->first << " " << it2->second << "\n";
    }

    // sort
    sort(v.begin(), v.end());

    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    sort(v.begin(), v.end(), greater<int>()); // sort in descending order

    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    // binary search 
    sort(v.begin(), v.end());
    if (binary_search(v.begin(), v.end(), 3)) {
        cout << "\n3 is present in the vector\n";
    }

    // lower bound
    vector<int>::iterator lb = lower_bound(v.begin(), v.end(), 3); // returns an iterator to the first element not less than 3, or v.end() if none exists
    if (lb != v.end()) {
        cout << "Lower bound of 3: " << *lb << "\n";
    }

    // upper bound
    vector<int>::iterator ub = upper_bound(v.begin(), v.end(), 3); // returns an iterator to the first element greater than 3, or v.end() if none exists
    if (ub != v.end()) {
        cout << "Upper bound of 3: " << *ub << "\n";
    }

    

    return 0;
}